# ErgoDox Infinity QMK Firmware (Pinned 0.14.0)

Automated build for QMK 0.14.0 firmware targeting the **ErgoDox Infinity** keyboard with a custom keymap.

## Overview

Modern QMK (post-0.14.0) has a ChibiOS IRQ priority conflict where the IS31FL3731 LED driver and USART split-communication both operate at priority 12, causing the right (slave) half to drop out after a few keypresses. The UART RX ISR gets starved and loses sync with the slave half.

This repository pins to **QMK 0.14.0**, which did not have this conflict and works reliably with this hardware.

## Repository Contents

```
.github/workflows/build.yml   — Automated build workflow
keymap/keyboard_layout.c      — Custom keymap definition
keymap/keyboard_config.h      — Keymap configuration overrides
```

The keymap uses `EEP_RST` (QMK 0.14.0 syntax) rather than modern `EE_CLR` for EEPROM reset.

## Building the Firmware

1. Go to the **Actions** tab
2. Select **Build ErgoDox Infinity**
3. Click **Run workflow**

The workflow:
- Clones QMK at tag `0.14.0`
- Initializes submodules (ChibiOS, LUFA)
- Installs ARM toolchain and dependencies
- Copies `keymap/` to `keyboards/ergodox_infinity/keymaps/default/`
- Compiles with `qmk compile -kb ergodox_infinity -km default`
- Uploads `.bin` artifact as `ergodox-infinity-firmware`

## Flashing the Firmware

1. Download the artifact zip from the completed build
2. Extract: `unzip ergodox-infinity-firmware.zip`
3. Flash each half:
   ```bash
   dfu-util -D ergodox_infinity_default.bin
   ```

Put each half into bootloader mode before flashing (hold the reset button on the PCB, or press `QK_BOOT` if already on QMK). Flash the left half first, then the right.

## Why QMK 0.14.0?

This version avoids the IRQ priority conflict that breaks modern QMK on this hardware. Future QMK versions would require:
- Adjusting ChibiOS IRQ priorities (complex, error-prone)
- Disabling LED matrix (loses keyboard lighting)
- Porting fixes from moving codebase (maintenance burden)

Pinning to 0.14.0 provides a stable, working baseline for ErgoDox Infinity users.
