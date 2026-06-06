#define NO_USB_STARTUP_CHECK

// Disable QMK's "auto-disconnect after 10 serial errors" behavior
#define SPLIT_MAX_CONNECTION_ERRORS 65535

// Gaming-optimized settings
// Disable tap-hold to reduce input latency
#undef TAPPING_TERM
#define TAPPING_TERM 0

// Enable minimal features
#define ENABLE_SEND_STRING

// Faster key repeat for rapid inputs
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 1000
