@echo off
:: setup_env.bat — Sets system-wide environment variables for LinkedIn Post Generator.
:: Must be run as Administrator so Task Scheduler (and SYSTEM account) can read them.
::
:: Usage:
::   1. Right-click setup_env.bat → "Run as administrator"
::   2. Enter your credentials when prompted
::   3. Reboot or re-login for Task Scheduler to pick up the new variables

net session >nul 2>&1
if %errorlevel% neq 0 (
    echo ERROR: This script must be run as Administrator.
    echo Right-click setup_env.bat and choose "Run as administrator".
    pause
    exit /b 1
)

echo.
echo ============================================================
echo  LinkedIn Post Generator -- Environment Variable Setup
echo ============================================================
echo.
echo Enter your credentials below. Values are stored as system-level
echo environment variables (visible to Task Scheduler and all users).
echo.

set /p ANTHROPIC_KEY="Anthropic API key: "
set /p EMAIL_SENDER="Gmail sender address (e.g. you@gmail.com): "
set /p EMAIL_PASSWORD="Gmail App Password (16 chars, no spaces): "
set /p EMAIL_RECIPIENT="Recipient email address: "

echo.
echo Setting system environment variables...

setx ANTHROPIC_API_KEY "%ANTHROPIC_KEY%" /M
if %errorlevel% neq 0 goto :error

setx LI_EMAIL_SENDER "%EMAIL_SENDER%" /M
if %errorlevel% neq 0 goto :error

setx LI_EMAIL_PASSWORD "%EMAIL_PASSWORD%" /M
if %errorlevel% neq 0 goto :error

setx LI_EMAIL_RECIPIENT "%EMAIL_RECIPIENT%" /M
if %errorlevel% neq 0 goto :error

echo.
echo SUCCESS: All four variables set at the system (machine-wide) level.
echo.
echo Variables set:
echo   ANTHROPIC_API_KEY  = (hidden)
echo   LI_EMAIL_SENDER    = %EMAIL_SENDER%
echo   LI_EMAIL_PASSWORD  = (hidden)
echo   LI_EMAIL_RECIPIENT = %EMAIL_RECIPIENT%
echo.
echo IMPORTANT: Restart your PC (or sign out and back in) before running
echo install_task.bat so Task Scheduler picks up the new variables.
echo.
pause
exit /b 0

:error
echo.
echo ERROR: Failed to set one or more environment variables.
echo Make sure you are running as Administrator.
pause
exit /b 1
