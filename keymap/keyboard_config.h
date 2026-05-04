#define NO_USB_STARTUP_CHECK

// Disable QMK's "auto-disconnect after 10 serial errors" behavior introduced
// post-0.14.0. The Infinity Ergodox sees occasional transient errors during
// normal operation; the modern behavior accumulates them and stops talking
// to the right half. The connection_errors counter caps at UINT8_MAX (255),
// so a threshold above that effectively disables the disconnect check while
// still keeping the 10-retry-per-transaction behavior healthy connections get.
#define SPLIT_MAX_CONNECTION_ERRORS 65535

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

// Reduce firmware size on 0.14.0
#define NO_ACTION_ONESHOT
