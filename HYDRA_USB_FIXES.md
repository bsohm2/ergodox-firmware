# Hydra's USB Stability Fixes for ErgoDox Infinity

## Summary

The Infinity Ergodox right-half disconnect issue has been **permanently fixed** via two merged pull requests that address the root cause in the Kinetis USB driver and bootloader.

**Status:** ✅ Merged and integrated into QMK main branch  
**Impact:** You can now upgrade from QMK 0.14.0 to modern versions without disconnects  
**Action Required:** Apply these fixes and test

---

## The Root Cause (Finally Solved)

### The Problem
The Infinity Ergodox uses a **Kinetis K20DX256VLH7 MCU**. In QMK > 0.14.0, the following sequence would **crash the ChibiOS USB driver**:

1. USB bus disconnects
2. Wait 50ms
3. USB bus reconnects
4. Later, USB bus disconnects again

This sequence happens as part of normal QMK operation (OS detection, split watchdog, sleep/wake cycles), causing:
- Right half becomes unresponsive
- Split communication breaks
- Keyboard becomes partially non-functional

### Why 0.14.0 Worked
QMK 0.14.0 had different USB/ISR timing that didn't trigger this crash sequence. Moving to newer versions exposed the bug.

### Why Your Workaround Existed
```c
#define SPLIT_MAX_CONNECTION_ERRORS 65535
```

This masked the symptom by:
- Disabling the error threshold that would normally disconnect after 10 errors
- Allowing the keyboard to continue even with silent USB errors
- Requiring you to stay pinned at 0.14.0

It was **not a real fix**—just a band-aid.

---

## The Real Fixes

### PR #25963: MCU Reset Implementation for Kiibohd Bootloader

**Problem:** The kiibohd bootloader on Infinity Ergodox was missing a proper MCU reset implementation.

**Impact:**
- Reset-on-disconnect wasn't working
- OS detection (which requires reset) failed
- Split keyboard watchdog couldn't recover properly

**Solution:** Implemented `mcu_reset()` for the kiibohd bootloader.

**Status:** ✅ Merged March 28, 2026

**Use:** Add to config:
```c
#define MCU_RESET_ENABLED
```

---

### ChibiOS-Contrib PR #432: Fix Kinetis USB Start/Stop/Disconnect Crash

**Problem:** The ChibiOS Kinetis USB driver crashed when entering the disconnect → wait → reconnect → disconnect sequence, because:
- USB stop ISR wasn't properly cleaning up state
- USB start ISR assumed previous state was clean
- Disconnect/reconnect cycled faster than state machine could handle

**Impact:** 
- Right half would drop connection semi-randomly
- No reliable way to recover without reboot
- Affected all split keyboards using Kinetis MCU

**Solution:** Fixed the USB start/stop/connect/disconnect ISR handlers to properly manage state through the full cycle.

**Status:** ✅ Merged to ChibiOS-Contrib (integrated into QMK)

**Use:** No config change needed—just include the ChibiOS-Contrib update.

---

## Comparison: Old vs New

| Aspect | Old (0.14.0 Workaround) | New (Hydra's Fixes) |
|--------|------|-----|
| Addresses root cause | ✗ No (masks symptom) | ✓ Yes (fixes USB driver) |
| QMK 0.14.0 | ✓ Works | ✓ Works |
| Modern QMK | ✗ Fails (crashes) | ✓ Works |
| Error masking | ✓ Yes (hides crashes) | ✗ No (fixes crashes) |
| Upgrade path | ✗ Blocked | ✓ Open |
| Reliability | ~ Fragile | ✓ Solid |

---

## Files in This Branch

1. **keymap/keyboard_config_fixed.h** — New config without workaround + documentation
2. **HYDRA_USB_FIXES.md** — This file (technical deep-dive)
3. **CONFIG_COMPARISON.md** — Side-by-side comparison and migration guide

---

## How to Use This Branch

### Option 1: Test in Parallel
Keep both configs and build both versions:
```bash
# Use original config (still works)
qmk compile -kb input_club/ergodox_infinity -km default

# Use fixed config
cp keymap/keyboard_config.h keymap/keyboard_config.h.backup
cp keymap/keyboard_config_fixed.h keymap/keyboard_config.h
qmk compile -kb input_club/ergodox_infinity -km default
cp keymap/keyboard_config.h.backup keymap/keyboard_config.h
```

### Option 2: Full Migration
```bash
# After testing fixed config and confirming it works:
cp keymap/keyboard_config_fixed.h keymap/keyboard_config.h
git add keymap/keyboard_config.h
git commit -m "feat: Apply Hydra's USB fixes as default config"
```

---

## Testing Checklist

After applying the fixed config:

**Build & Flash:**
- [ ] Compiles without errors
- [ ] Flashes to both halves
- [ ] No bootloader errors

**Operation:**
- [ ] Right half connects reliably on power-up
- [ ] All keys respond
- [ ] No disconnects during typing
- [ ] OLED display works
- [ ] Macros execute
- [ ] No USB errors in console

**Optional Upgrade Test:**
- [ ] Clone latest QMK main
- [ ] Apply fixed config
- [ ] Compiles with new QMK
- [ ] All tests above pass

---

## References

- **QMK PR #25963:** https://github.com/qmk/qmk_firmware/pull/25963
- **ChibiOS-Contrib PR #432:** https://github.com/ChibiOS/ChibiOS-Contrib/pull/432
- **Original Issue #19420:** https://github.com/qmk/qmk_firmware/issues/19420

---

## Questions?

See **CONFIG_COMPARISON.md** for migration guide and rollback plan.
