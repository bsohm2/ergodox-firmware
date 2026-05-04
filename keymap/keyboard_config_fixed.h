// ============================================================================
// ErgoDox Infinity Configuration - USB Stability Fixed
// ============================================================================
//
// This configuration applies the fixes from:
//   - QMK PR #25963: MCU reset implementation for kiibohd bootloader
//   - ChibiOS-Contrib PR #432: Fix Kinetis USB stop/disconnect crash
//
// These fixes address the root cause of right-half disconnects in the
// Infinity Ergodox (Kinetis K20DX256VLH7 MCU) that plagued QMK > 0.14.0.
//
// Historical Context:
// ============================================================================
// The Infinity Ergodox experienced intermittent right-half disconnects when
// using modern QMK versions. The root cause was a crash in the ChibiOS
// Kinetis USB driver when the sequence of USB disconnect → wait → reconnect
// → disconnect occurred, which is part of normal QMK operation.
//
// Previous Workaround (0.14.0 pinned + SPLIT_MAX_CONNECTION_ERRORS):
//   - Disabled error threshold to mask the symptom
//   - Prevented upgrading QMK to newer versions
//   - Left the underlying crash unfixed
//
// New Solution (Hydra's PRs):
//   - Fixes USB start/stop/connect/disconnect in ChibiOS driver
//   - Implements proper MCU reset in bootloader
//   - Allows upgrading to modern QMK versions
//   - Eliminates the need for error-count masking
//
// Changes from keyboard_config.h:
// ============================================================================
// REMOVED: #define SPLIT_MAX_CONNECTION_ERRORS 65535
//   → No longer needed; root cause is fixed
//
// NEW: MCU_RESET_ENABLED (see below)
//   → Enables kiibohd bootloader MCU reset implementation
//
// ============================================================================

// Bootloader Reset Fix (PR #25963)
// Ensure MCU reset is properly implemented for kiibohd bootloader.
// This fixes reset-on-disconnect behavior that was previously missing.
#define MCU_RESET_ENABLED

// USB Configuration
// The Kinetis USB crash fix (ChibiOS-Contrib #432) handles the edge cases
// in disconnect/reconnect sequences, so we can use standard USB settings.
#define NO_USB_STARTUP_CHECK

// Enable OLED display
#define OLED_DRIVER_ENABLE
#define OLED_BRIGHTNESS 127

// Enable tap-hold functionality
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

// Enable macros
#define ENABLE_SEND_STRING

// Enable WPM counter for OLED
#define WPM_ENABLE

// ============================================================================
// RECOMMENDATIONS FOR MODERN QMK WITH THESE FIXES
// ============================================================================
//
// When upgrading to QMK versions that include these fixes, consider:
//
// 1. SPLIT_MAX_CONNECTION_ERRORS - NO LONGER NEEDED
//    The USB stability fixes eliminate the need for this workaround.
//    Remove it completely.
//
// 2. QMK Version - NOW FLEXIBLE
//    You can upgrade from 0.14.0 to the latest QMK that includes:
//    - PR #25963 merged (March 28, 2026)
//    - ChibiOS-Contrib #432 integrated
//
// 3. Testing Checklist After Upgrade:
//    ✓ Right half connects reliably on power-up
//    ✓ No disconnects during normal typing
//    ✓ No disconnects during sleep/wake cycles
//    ✓ Split keyboard watchdog works (OS detection on reconnect)
//    ✓ OLED display continues functioning
//
// 4. If Disconnects Still Occur:
//    - Check that both PRs are actually included in your QMK version
//    - Verify ChibiOS-Contrib is updated to latest
//    - Review your build logs for any warnings about USB/split
//    - Fall back to original config and compare
//
// ============================================================================
