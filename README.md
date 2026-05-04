# ergodox-infinity-brandon

GitHub Actions build for QMK 0.14.0 firmware targeting the **ErgoDox Infinity** keyboard with a custom keymap.

## Why this exists

Modern QMK (post-0.14.0) causes the right (slave) half of the ErgoDox Infinity to drop out after a few keypresses. The root cause is a ChibiOS IRQ priority conflict: the IS31FL3731 LED driver communicates over I2C at the same interrupt priority as the USART used for split communication (both default to 12). I2C bursts from the LED driver starve the UART RX ISR, causing the slave half to lose sync and disconnect.

Disabling `LED_MATRIX_ENABLE` works around the dropout but kills the LEDs. Adjusting IRQ priorities in the ChibiOS drivers made things worse. Rather than continue patching a moving target, this repo pins to **QMK 0.14.0**, which did not have this conflict and worked correctly on this hardware.

## What's in this repo

```
.github/workflows/build.yml   — GitHub Actions workflow (builds QMK 0.14.0)
keymap/keymap.c               — Custom keymap
keymap/config.h               — Keymap config overrides
```

The keymap uses `EEP_RST` (the 0.14.0 name) rather than the modern `EE_CLR` for the EEPROM reset key.

## Building

Trigger manually from the **Actions** tab → **Build Ergodox Infinity** → **Run workflow**.

The workflow:
1. Clones QMK at tag `0.14.0`
2. Initializes the required submodules (ChibiOS, LUFA)
3. Installs the ARM toolchain and build dependencies
4. Copies `keymap/` into `keyboards/ergodox_infinity/keymaps/brandon/`
5. Runs `qmk compile -kb ergodox_infinity -km brandon`
6. Uploads the resulting `.bin` as the `ergodox-infinity-brandon` artifact

## Flashing

Download the artifact zip from the completed Actions run, extract it, then flash each half:

```bash
unzip ergodox-infinity-brandon.zip
dfu-util -D ergodox_infinity_brandon.bin
```

Put each half into bootloader mode before flashing (hold the reset button on the PCB, or use the `QK_BOOT` key if already on QMK firmware). Flash left half first, then right.
