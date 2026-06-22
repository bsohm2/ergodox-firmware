@echo off
:: install_task.bat — Auto-detects Python, patches linkedin_task.xml with real
:: paths, and imports the task into Windows Task Scheduler.
::
:: Prerequisites:
::   1. Run setup_env.bat as Administrator first
::   2. Reboot (or sign out/in) so env vars are visible
::   3. Run this script as Administrator
::
:: The task will run every Monday at 8:00 AM as the current user.

setlocal enabledelayedexpansion

net session >nul 2>&1
if %errorlevel% neq 0 (
    echo ERROR: This script must be run as Administrator.
    echo Right-click install_task.bat and choose "Run as administrator".
    pause
    exit /b 1
)

echo.
echo ============================================================
echo  LinkedIn Post Generator -- Task Scheduler Setup
echo ============================================================
echo.

:: ----- Locate Python -----
echo Detecting Python installation...
for /f "tokens=* usebackq" %%i in (`where python 2^>nul`) do (
    set PYTHON_PATH=%%i
    goto :found_python
)

echo ERROR: Python not found in PATH.
echo Install Python 3.12+ from python.org and check "Add to PATH" during setup.
pause
exit /b 1

:found_python
echo Found Python: %PYTHON_PATH%

:: Verify Python version
"%PYTHON_PATH%" --version 2>&1
if %errorlevel% neq 0 (
    echo ERROR: Python found but could not execute.
    pause
    exit /b 1
)

:: Verify anthropic package
echo Checking anthropic package...
"%PYTHON_PATH%" -c "import anthropic; print('anthropic', anthropic.__version__)" 2>&1
if %errorlevel% neq 0 (
    echo.
    echo ERROR: anthropic package not installed.
    echo Run:  pip install anthropic
    pause
    exit /b 1
)

:: ----- Resolve script path -----
set SCRIPT_DIR=%~dp0
set SCRIPT_DIR=%SCRIPT_DIR:~0,-1%
set SCRIPT_PATH=%SCRIPT_DIR%\linkedin_post_generator.py

if not exist "%SCRIPT_PATH%" (
    echo ERROR: Cannot find %SCRIPT_PATH%
    echo Make sure all files are in the same folder as this script.
    pause
    exit /b 1
)

echo Script path: %SCRIPT_PATH%

:: ----- Patch XML with real paths -----
set XML_TEMPLATE=%SCRIPT_DIR%\linkedin_task.xml
set XML_CONFIGURED=%SCRIPT_DIR%\linkedin_task_configured.xml

if not exist "%XML_TEMPLATE%" (
    echo ERROR: linkedin_task.xml not found in %SCRIPT_DIR%
    pause
    exit /b 1
)

echo.
echo Configuring task XML with detected paths...

:: Escape backslashes for PowerShell replacement (\ -> \\)
set PYTHON_ESC=%PYTHON_PATH:\=\\%
set SCRIPT_ESC=%SCRIPT_PATH:\=\\%
set WORKDIR_ESC=%SCRIPT_DIR:\=\\%

powershell -NoProfile -Command ^
  "(Get-Content '%XML_TEMPLATE%') ^
   -replace 'PYTHON_PATH_PLACEHOLDER', '%PYTHON_ESC%' ^
   -replace 'SCRIPT_PATH_PLACEHOLDER', '%SCRIPT_ESC%' ^
   -replace 'WORKING_DIR_PLACEHOLDER', '%WORKDIR_ESC%' ^
   | Set-Content -Encoding Unicode '%XML_CONFIGURED%'"

if %errorlevel% neq 0 (
    echo ERROR: Failed to generate configured XML.
    pause
    exit /b 1
)

echo Created: %XML_CONFIGURED%

:: ----- Register task -----
echo.
echo Registering task in Task Scheduler...
echo.
echo You will be prompted for your Windows account password so the task
echo can run even when you are not logged in.
echo.

set /p WIN_USER="Windows username (e.g. DESKTOP-ABC\Brandon or brandon@domain.com): "
set /p WIN_PASS="Windows account password: "

schtasks /create ^
  /xml "%XML_CONFIGURED%" ^
  /tn "LinkedIn Post Generator" ^
  /ru "%WIN_USER%" ^
  /rp "%WIN_PASS%" ^
  /f

if %errorlevel% neq 0 (
    echo.
    echo ERROR: Task registration failed. Common causes:
    echo   - Wrong username format (try COMPUTERNAME\Username)
    echo   - Wrong password
    echo   - Insufficient privileges
    pause
    exit /b 1
)

echo.
echo ============================================================
echo  Task registered successfully!
echo ============================================================
echo.
echo Task name : LinkedIn Post Generator
echo Schedule  : Every Monday at 8:00 AM
echo Command   : %PYTHON_PATH%
echo Script    : %SCRIPT_PATH%
echo.
echo To verify, open Task Scheduler and look under Task Scheduler Library.
echo.

:: ----- Optional dry-run -----
set /p DO_TEST="Run a dry-run test now? (y/N): "
if /i "%DO_TEST%"=="y" (
    echo.
    echo Triggering task now...
    schtasks /run /tn "LinkedIn Post Generator"
    if %errorlevel% neq 0 (
        echo ERROR: Could not trigger task.
    ) else (
        echo Task started. Check Task Scheduler history and your email inbox.
        echo Allow up to 60 seconds for the script to complete.
    )
)

echo.
pause
exit /b 0
