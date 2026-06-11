#define NO_USB_STARTUP_CHECK

// Modern QMK split recovery path (enabled by QMK PR #25963, which added
// mcu_reset support for the kiibohd bootloader): if the slave half stops
// hearing from the master, the watchdog reboots it so it reconnects
// instead of staying dead.
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

// Caps Word: double-tap Shift to type one WORD in caps, auto-disables
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
