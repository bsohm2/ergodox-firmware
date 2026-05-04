# ErgoDox Infinity Keymap Guide

## Layers

### Layer 0: QWERTY (Base Layer)
Standard QWERTY layout with ergonomic improvements:
- **Home row modifiers**: Hold A/S/D/F (left) or J/K/L/; (right) for Ctrl/Shift/Alt/GUI
- Tap for the letter, hold for the modifier
- Left bracket `[` → Toggle Symbols layer (hold) or press
- Right bracket `]` → Toggle Navigation layer (hold) or press
- Function key → Access Function layer

### Layer 1: SYMBOLS
Numbers, punctuation, and special characters:
- Row 1: F1-F5 | ! @ { } |
- Row 2: # $ ( ) `
- Row 3: % ^ [ ] ~
- Row 4: Numbers 1-9, 0, . on right side
- Row 5: F6-F12 on right side

### Layer 2: NAVIGATION
Arrow keys, page navigation, editing:
- **Right half**: Page Up/Down, Home/End, arrow keys
- **Left side**: Home row modifiers accessible
- **Bottom right**: Backspace/Delete for quick editing

### Layer 3: NUMPAD
Numeric keypad (NUM LOCK on):
- Standard numpad layout
- P0-P9, operations (+, -, *, /)
- P. for decimal, PENT for enter

### Layer 4: FUNCTION
Function keys and macros:
- **Left**: RESET key (bootloader mode)
- **Right**: F1-F12, macro keys
- **Macros**:
  - Email: developer@example.com
  - GitHub URL: https://github.com
  - C code snippet: auto-inserts basic C program

## Tap-Hold Modifiers

Home row keys have dual functionality (200ms tapping term):

| Key | Tap | Hold |
|-----|-----|------|
| A | A | Ctrl |
| S | S | Shift |
| D | D | Alt |
| F | F | GUI |
| J | J | GUI |
| K | K | Alt |
| L | L | Shift |
| ; | ; | Ctrl |

## Macros

Access from Function layer (right hand):

1. **Email macro** (row 2, col 2): Inserts `developer@example.com`
2. **URL macro** (row 2, col 3): Inserts `https://github.com`
3. **Code snippet** (row 2, col 4): Inserts basic C program template

Edit these in `keyboard_layout.c` in the `process_record_user()` function.

## OLED Display

Each half displays:
- **Layer name**: Current active layer (QWERTY, SYMBOLS, etc.)
- **Role**: Master or Slave (split keyboard status)
- **WPM**: Words per minute (typing speed)

## Customization

### Change Tapping Term
In `keyboard_config.h`:
```c
#define TAPPING_TERM 200  // milliseconds (default: 200)
```

Lower = easier to trigger modifiers by tapping quickly
Higher = allows holding longer before registering as tap

### Add New Macros
1. Add keycode to `enum custom_keycodes` in `keyboard_layout.c`
2. Add case in `process_record_user()` function
3. Use `SEND_STRING()` for text, `SS_TAP()` for keys, `SS_DELAY()` for timing

Example:
```c
case MY_MACRO:
  if (record->event.pressed) {
    SEND_STRING("My custom text");
  }
  return false;
```

### Modify Layer Layouts
Edit the `keymaps[][]` array in `keyboard_layout.c`. Use:
- `KC_*` for regular keys (KC_A, KC_1, etc.)
- `KC_TRNS` for transparent (pass through to layer below)
- `KC_NO` for disabled key
- `LCTL_T(KC_A)` for tap-hold combinations

## Building & Flashing

```bash
# Build
make ergodox_infinity:default

# Flash (put keyboard in bootloader mode first)
dfu-util -D ergodox_infinity_default.bin
```

For each half:
1. Hold reset button on PCB to enter bootloader
2. Run dfu-util command
3. Release reset button
4. Flash left half first, then right

## Troubleshooting

**Macros not working?**
- Ensure `ENABLE_SEND_STRING` is defined in config.h
- Check that keycode is in `process_record_user()`

**Tap-hold feels wrong?**
- Adjust `TAPPING_TERM` (lower = easier to tap, harder to hold)
- Try `PERMISSIVE_HOLD` (already enabled) to fix modifier+key combos

**OLED display not showing?**
- Enable with `OLED_DRIVER_ENABLE` in config.h
- Check brightness: `OLED_BRIGHTNESS 127` (0-255 range)

**Right half disconnects?**
- Already handled by `SPLIT_MAX_CONNECTION_ERRORS 65535`
- Ensure USB cable is seated fully on left half
