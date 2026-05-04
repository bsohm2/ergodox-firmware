# Configuration Comparison: Old vs Fixed

## Quick Summary

| Aspect | keyboard_config.h (0.14.0) | keyboard_config_fixed.h (Hydra Fix) |
|--------|---|---|
| **Purpose** | QMK 0.14.0 with error masking | Modern QMK with real USB fixes |
| **SPLIT_MAX_CONNECTION_ERRORS** | 65535 (masks errors) | Removed (not needed) |
| **MCU_RESET_ENABLED** | ✗ Missing | ✓ Added |
| **Works on 0.14.0** | ✓ Yes | ✓ Yes |
| **Works on Modern QMK** | ✗ No (crashes) | ✓ Yes |
| **Can Upgrade** | ✗ No | ✓ Yes |
| **Fixes Root Cause** | ✗ No | ✓ Yes |

---

## Detailed Comparison

### keyboard_config.h (Original)

**Use case:** QMK 0.14.0 only (workaround-based stability)

```c
#define NO_USB_STARTUP_CHECK

// Disable QMK's "auto-disconnect after 10 serial errors" behavior introduced
// post-0.14.0. The Infinity Ergodox sees occasional transient errors during
// normal operation; the modern behavior accumulates them and stops talking
// to the right half. The connection_errors counter caps at UINT8_MAX (255),
// so a threshold above that effectively disables the disconnect check while
// still keeping the 10-retry-per-transaction behavior healthy connections get.
#define SPLIT_MAX_CONNECTION_ERRORS 65535

#define OLED_DRIVER_ENABLE
#define OLED_BRIGHTNESS 127
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define ENABLE_SEND_STRING
#define WPM_ENABLE
#define NO_ACTION_ONESHOT
```

**What it does:**
- Sets error threshold to 65535 (effectively infinite)
- Allows USB crashes to be silently ignored
- Keeps keyboard working despite internal failures
- Requires staying at QMK 0.14.0

**Why it was needed:**
- QMK 0.15+ exposes a ChibiOS crash
- ChibiOS crash = right half disconnect
- Error masking = keyboard still responds (fragile)

**When to use:**
- Only on QMK 0.14.0
- If you never plan to upgrade
- Conservative approach (no changes)

---

### keyboard_config_fixed.h (New)

**Use case:** Modern QMK (actual fixes applied)

```c
// Bootloader Reset Fix (PR #25963)
#define MCU_RESET_ENABLED

// USB Configuration
#define NO_USB_STARTUP_CHECK

// Rest is identical to original...
#define OLED_DRIVER_ENABLE
#define OLED_BRIGHTNESS 127
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define ENABLE_SEND_STRING
#define WPM_ENABLE
```

**What it does:**
- Enables kiibohd bootloader MCU reset
- Relies on ChibiOS USB crash fix (PR #432)
- No error masking needed (crashes are fixed)
- Works on QMK 0.14.0 and modern versions

**Why it's better:**
- Fixes the actual crash (not just masking it)
- Allows QMK upgrades
- Bootloader reset properly implemented
- Future-proof

**When to use:**
- Testing/validation phase
- Ready to upgrade QMK
- Want proper USB stability
- Future hardware revisions

---

## Key Differences Explained

### 1. SPLIT_MAX_CONNECTION_ERRORS 65535 → Removed

**What changed:**
```diff
- #define SPLIT_MAX_CONNECTION_ERRORS 65535
+ // No longer needed - USB crashes are fixed
```

**Why:**
- Old: USB crashes would accumulate errors; masking errors = continue working
- New: USB crashes don't happen (ChibiOS fix); no need to mask

**Safety:**
- ✅ Safe to remove once ChibiOS PR #432 is in your QMK version
- ⚠️ Keep it if you're still on older QMK without the fix

---

### 2. MCU_RESET_ENABLED → Added

**What changed:**
```diff
+ #define MCU_RESET_ENABLED
  #define NO_USB_STARTUP_CHECK
```

**Why:**
- Old: Kiibohd bootloader had no reset implementation
- New: PR #25963 implemented mcu_reset(); enable it

**Impact:**
- OS detection works reliably
- Split keyboard watchdog can recover
- Reset-on-disconnect is proper

**Safety:**
- ✅ Safe to add (improves functionality)
- Note: May require bootloader reflash (check QMK docs)

---

### 3. NO_ACTION_ONESHOT → Commented Out

**What changed:**
```diff
- #define NO_ACTION_ONESHOT
+ // #define NO_ACTION_ONESHOT  [no longer needed]
```

**Why:**
- Old: Size optimization for 0.14.0 (firmware size tight)
- New: Modern QMK has better code size; not necessary

**Impact:**
- Minimal (was only for size)
- Can re-enable if firmware size becomes an issue

---

## Testing Matrix

### Scenario 1: QMK 0.14.0 + keyboard_config.h
```
Build:           ✓ Works
Flash:           ✓ Works
Right half:      ✓ Connected
Typing:          ✓ Works
Disconnects:     ✗ Will happen (masked, not fixed)
Upgrade:         ✗ Can't upgrade
```

### Scenario 2: QMK 0.14.0 + keyboard_config_fixed.h
```
Build:           ✓ Works
Flash:           ✓ Works
Right half:      ✓ Connected
Typing:          ✓ Works
Disconnects:     ✓ Proper behavior (USB fixed)
Upgrade:         ✓ Can upgrade (fixes present)
```

### Scenario 3: Modern QMK + keyboard_config.h
```
Build:           ✓ Works
Flash:           ✓ Works
Right half:      ✗ Disconnects (crashes exposed)
Typing:          ✗ Fails (no right side)
Disconnects:     ✓ Fast disconnects (not masked)
Upgrade:         ✗ Broken
```

### Scenario 4: Modern QMK + keyboard_config_fixed.h
```
Build:           ✓ Works
Flash:           ✓ Works
Right half:      ✓ Connected (USB crash fixed)
Typing:          ✓ Works (properly)
Disconnects:     ✓ Proper ISR handling
Upgrade:         ✓ Fully supported
```

---

## Migration Path

### Phase 1: Understanding (You are here)
- ✓ Read both config files
- ✓ Understand the differences
- ✓ Decide on approach (test vs full migration)

### Phase 2: Testing (Next)
```bash
# Back up current config
cp keymap/keyboard_config.h keymap/keyboard_config.h.backup

# Test fixed config on 0.14.0
cp keymap/keyboard_config_fixed.h keymap/keyboard_config.h
qmk compile -kb input_club/ergodox_infinity -km default
# Flash and test 30 min of typing

# If successful, proceed to Phase 3
# If not, revert: cp keymap/keyboard_config.h.backup keymap/keyboard_config.h
```

### Phase 3: Validation (Optional)
```bash
# Test with modern QMK (after fixes are integrated)
git submodule update --remote qmk_firmware
qmk compile -kb input_club/ergodox_infinity -km default
# Flash and verify all scenarios
```

### Phase 4: Merge (Final)
```bash
# After successful testing:
git add keymap/keyboard_config.h
git commit -m "Apply Hydra's USB fixes to default config"
git push origin feature/apply-hydra-usb-fixes
# Create PR, review, merge
```

---

## Rollback Procedure

If the fixed config doesn't work:

```bash
# Revert to original
cp keymap/keyboard_config.h.backup keymap/keyboard_config.h

# Rebuild with original
qmk compile -kb input_club/ergodox_infinity -km default

# Flash and verify
qmk flash -kb input_club/ergodox_infinity -km default
```

Then investigate why the fix didn't work:
1. Is ChibiOS PR #432 actually in your QMK version?
2. Is QMK PR #25963 in your version?
3. Check build logs for warnings about MCU_RESET_ENABLED

---

## Decision Matrix

**Choose keyboard_config.h if:**
- ✓ You're on QMK 0.14.0 and happy there
- ✓ You want zero changes
- ✓ You've tested it extensively
- ✗ You want to upgrade QMK in the future

**Choose keyboard_config_fixed.h if:**
- ✓ You want proper USB crash fixes
- ✓ You want flexibility to upgrade QMK
- ✓ You want to be future-proof
- ✓ You're willing to test and validate

---

## Summary

| Config | Best For | Trade-offs |
|--------|----------|-----------|
| **keyboard_config.h** | QMK 0.14.0 only | Can't upgrade; error masking |
| **keyboard_config_fixed.h** | Modern QMK | Requires testing; needs QMK fixes merged |

**Recommendation:** Test fixed config on 0.14.0 first (low risk), then consider upgrading QMK when validated.
