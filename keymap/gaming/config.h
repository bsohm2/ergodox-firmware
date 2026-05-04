#define NO_USB_STARTUP_CHECK

// Disable QMK's "auto-disconnect after 10 serial errors" behavior
#define SPLIT_MAX_CONNECTION_ERRORS 65535

// Gaming-optimized settings
// Disable tap-hold to reduce input latency
#define TAPPING_TERM 0

// Reduce OLED update frequency for performance
#define OLED_DRIVER_ENABLE
#define OLED_BRIGHTNESS 127
#define OLED_UPDATE_INTERVAL 100

// Enable minimal features
#define ENABLE_SEND_STRING

// Disable WPM counter in gaming mode (reduces overhead)
// #define WPM_ENABLE

// Faster key repeat for rapid inputs
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 1000
