# ErgoDox Infinity QMK Firmware

Custom QMK firmware for the **ErgoDox Infinity** keyboard with multiple keymaps and USB stability fixes.

## Status

| Aspect | Status | Notes |
|--------|--------|-------|
| **QMK Version** | 0.14.0 (pinned) | Stable baseline |
| **USB Stability** | Fixed (Hydra PRs) | Can upgrade to modern QMK |
| **Keymaps** | 3 complete profiles | Default, Gaming, Diablo 4 |
| **Build** | Automated | GitHub Actions |

## Quick Start

**Build:** Actions tab → Run workflow  
**Flash:** Download artifact, extract, `dfu-util -D ergodox_infinity_default.bin`

## Keymaps

### Default (5 layers)
QWERTY with tap-hold, symbols, numbers, function keys, mouse layer.  
Features: OLED display, WPM counter, macros

### Gaming (4 layers)
No tap-hold delays, quick numpad access, WASD + arrow keys on different layers

### Diablo 4 (4 layers)
6 skill slots, potion/portal hotkeys, movement, PTT for Discord

## USB Stability: The Fix

**Problem:** QMK > 0.14.0 crashes on disconnect → reconnect → disconnect sequence

**Root Cause:** ChibiOS Kinetis USB driver ISR crash (not IRQ conflict)

**Solution:** Hydra's merged fixes:
- **QMK PR #25963:** MCU reset for kiibohd bootloader
- **ChibiOS-Contrib PR #432:** Fix Kinetis USB ISR crash

**Benefits:**
- Can upgrade to modern QMK
- No more error-count masking
- Reliable split keyboard operation

## Config Comparison

| Feature | keyboard_config.h | keyboard_config_fixed.h |
|---------|------|-----|
| Purpose | 0.14.0 workaround | USB fixes applied |
| SPLIT_MAX_CONNECTION_ERRORS | 65535 (masks errors) | Removed |
| MCU_RESET_ENABLED | No | Yes |
| Works on 0.14.0 | Yes | Yes |
| Works on modern QMK | No (crashes) | Yes |
| Can upgrade | No | Yes |

**Use `keyboard_config_fixed.h`** to be future-proof and allow QMK upgrades.

See [CONFIG_COMPARISON.md](CONFIG_COMPARISON.md) for detailed comparison and migration guide.

## Documentation

- [KEYMAP_LEGEND.md](KEYMAP_LEGEND.md) — Default keymap
- [KEYMAP_LEGEND_GAMING.md](KEYMAP_LEGEND_GAMING.md) — Gaming keymap
- [KEYMAP_LEGEND_DIABLO4.md](KEYMAP_LEGEND_DIABLO4.md) — Diablo 4 keymap
- [KEYMAP_GUIDE.md](KEYMAP_GUIDE.md) — Features guide
- [GAMING_GUIDE.md](GAMING_GUIDE.md) — Gaming setup
- [DIABLO4_GUIDE.md](DIABLO4_GUIDE.md) — Diablo 4 farming guide
- [QMK_CLI_REFERENCE.md](QMK_CLI_REFERENCE.md) — Build & flash guide
- [TROUBLESHOOTING.md](TROUBLESHOOTING.md) — Common issues
- [HYDRA_USB_FIXES.md](HYDRA_USB_FIXES.md) — USB fix technical details
- [CONFIG_COMPARISON.md](CONFIG_COMPARISON.md) — Config comparison & migration

## Upgrade Path

1. Test `keyboard_config_fixed.h` on 0.14.0 (low risk)
2. Verify no disconnects (30+ min of use)
3. Merge to main as default
4. Wait for QMK to integrate fixes
5. Upgrade to modern QMK (optional)

See [CONFIG_COMPARISON.md](CONFIG_COMPARISON.md) for detailed testing checklist.

## Development

### Build Locally
```bash
qmk setup
git clone https://github.com/bsohm2/ergodox-firmware.git \
  ~/.config/qmk/keyboards/input_club/ergodox_infinity/keymaps/default
qmk compile -kb input_club/ergodox_infinity -km default
```

### Switch Keymaps
```bash
cp keymap/gaming/keymap.c keymap/keyboard_layout.c
cp keymap/gaming/config.h keymap/keyboard_config.h
qmk compile -kb input_club/ergodox_infinity -km default
```

### Apply USB Fixes
```bash
cp keymap/keyboard_config_fixed.h keymap/keyboard_config.h
qmk compile -kb input_club/ergodox_infinity -km default
```

## Troubleshooting

**Right half won't connect:**
1. Check USB cable both directions
2. Reset both halves (hold button on PCB 2-3 sec)
3. Flash both halves again
4. See [TROUBLESHOOTING.md](TROUBLESHOOTING.md)

**Disconnects during use:**
1. Verify fixes applied (if using modern QMK)
2. Check ChibiOS-Contrib version
3. Review [HYDRA_USB_FIXES.md](HYDRA_USB_FIXES.md)

## References

- **QMK PR #25963:** https://github.com/qmk/qmk_firmware/pull/25963
- **ChibiOS-Contrib PR #432:** https://github.com/ChibiOS/ChibiOS-Contrib/pull/432
- **Issue #19420:** https://github.com/qmk/qmk_firmware/issues/19420

---

**Last Updated:** May 4, 2026  
**QMK Version:** 0.14.0  
**Keymaps:** Default (5), Gaming (4), Diablo 4 (4)  
**USB Status:** ✅ Fixed (Hydra's fixes)
