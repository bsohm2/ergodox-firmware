# QMK CLI Quick Reference

Essential QMK commands for building and flashing your ErgoDox Infinity firmware.
n## About This Document

This is a **quick reference guide** for essential QMK CLI commands used to build and flash your ErgoDox Infinity firmware.

**Use this when:** Youre building firmware locally, flashing custom changes, or troubleshooting build errors.

**Assumes:** You have QMK installed and your repo cloned to ~/.config/qmk/keyboards/input_club/ergodox_infinity/keymaps/default/

## Installation

### macOS
```bash
brew install qmk/qmk/qmk
```

### Linux (Ubuntu/Debian)
```bash
sudo apt-get install qmk-cli
```

### Windows
```bash
pip install qmk
```

## Setup

First-time setup:
```bash
qmk setup
```

This clones the QMK firmware repository and installs dependencies.

## Building Firmware

### Build for ErgoDox Infinity
```bash
qmk compile -kb ergodox_infinity -km default
```

**Breakdown:**
- `-kb` = keyboard (ergodox_infinity)
- `-km` = keymap (default)
- Output: `ergodox_infinity_default.bin`

### Build with explicit QMK path
```bash
cd /path/to/qmk_firmware
make ergodox_infinity:default
```

### Build and flash immediately
```bash
qmk flash -kb ergodox_infinity -km default
```

(You'll be prompted to enter bootloader mode)

## Flashing Firmware

### Using dfu-util (recommended for split keyboards)

1. **Download artifact** from GitHub Actions or use your compiled `.bin` file

2. **Put left half in bootloader mode:**
   - Hold the RESET button on the PCB while plugging in USB
   - Or press the RESET key if already on QMK firmware

3. **Flash left half:**
   ```bash
   dfu-util -D ergodox_infinity_default.bin
   ```

4. **Put right half in bootloader mode:**
   - Unplug left half first
   - Hold RESET button on right PCB
   - Plug right half into USB

5. **Flash right half:**
   ```bash
   dfu-util -D ergodox_infinity_default.bin
   ```

### Check DFU devices
```bash
dfu-util -l
```

Should show:
```
Found DFU: [0483:df11] ver=2200, devnum=13, cfg=1, intf=0, path="1-1", alt=0, name="@Internal Flash  /0x08000000/512 *"
```

## Debugging

### Check keyboard connection
```bash
qmk doctor
```

Shows:
- Python version
- QMK home
- Git status
- ARM toolchain

### Verbose build (see all compile output)
```bash
qmk compile -kb ergodox_infinity -km default -v
```

### List available keymaps
```bash
qmk list-keymaps -kb ergodox_infinity
```

Shows all keymaps for this keyboard.

### Create new keymap from template
```bash
qmk new-keymap -kb ergodox_infinity -km my_custom_map
```

Creates `keyboards/ergodox_infinity/keymaps/my_custom_map/` with template files.

## Configuration Files

### Keyboard config
```
qmk_firmware/keyboards/ergodox_infinity/config.h
```

### Keymap files
```
qmk_firmware/keyboards/ergodox_infinity/keymaps/default/
  ├── keymap.c       (layer definitions, macros)
  └── config.h       (feature toggles)
```

## Common Edits

### Enable a feature
In `keymap/config.h`:
```c
#define OLED_DRIVER_ENABLE
```

### Disable a feature
In `keymap/config.h`:
```c
// #define OLED_DRIVER_ENABLE
```

### Adjust tapping term (modifier timing)
In `keymap/config.h`:
```c
#define TAPPING_TERM 200  // milliseconds
```

### Add SEND_STRING macros
In `keymap/config.h`:
```c
#define ENABLE_SEND_STRING
```

In `keymap/keymap.c`:
```c
case MY_MACRO:
  if (record->event.pressed) {
    SEND_STRING("Your text here");
  }
  return false;
```

## Tips

### Speed up builds
Enable ninja (faster build tool):
```bash
qmk compile -kb ergodox_infinity -km default --use-ninja
```

### Clean build
```bash
qmk clean
```

Removes all compiled artifacts. Useful if build is stuck or corrupted.

### Check file size
```bash
arm-none-eabi-size path/to/.build/ergodox_infinity_default.elf
```

Shows program size. Useful if firmware is too large for chip.

### Keyboard test mode
Flash and then:
```bash
qmk doctor -a
```

Shows HID reports for every keypress (good for debugging key events).

## Troubleshooting

### "Command not found: qmk"
- Ensure QMK is installed: `pip install qmk`
- Or use full path: `/usr/local/bin/qmk`

### "Can't find ARM toolchain"
```bash
qmk setup  # Re-run setup to install toolchain
```

### "dfu-util not found"
macOS:
```bash
brew install dfu-util
```

Linux:
```bash
sudo apt-get install dfu-util
```

### Keyboard not detected in DFU
- Check USB cable (should be connected to left half only)
- Try different USB port
- Hold RESET button longer (2-3 seconds)
- Make sure bootloader is actually running (look for DFU device with `dfu-util -l`)

### Build fails with "toolchain not found"
```bash
qmk setup --with-tests
```

This installs the ARM compiler explicitly.

### Firmware too large
Disable features in config.h:
```c
// #define OLED_DRIVER_ENABLE
// #define WPM_ENABLE
```

## Useful Links

- **QMK Docs**: https://docs.qmk.fm/
- **ErgoDox Infinity**: https://docs.qmk.fm/keyboards/ergodox_infinity/
- **Keycode Reference**: https://docs.qmk.fm/keycodes
- **Feature Reference**: https://docs.qmk.fm/features/
