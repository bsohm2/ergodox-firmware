/* ErgoDox Infinity custom keymap layout
 * Features: OLED layer display, tap-hold modifiers, multiple layers, macros
 */
#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
  QWERTY = 0,
  SYMBOLS,
  NAVIGATION,
  NUMPAD,
  FUNCTION
};

// Macro IDs
enum custom_keycodes {
  MACRO_EMAIL = SAFE_RANGE,
  MACRO_URL,
  MACRO_CODE_SNIPPET
};

// Tap-hold definitions for home row modifiers
#define LCTL_A LCTL_T(KC_A)
#define LSFT_S LSFT_T(KC_S)
#define LALT_D LALT_T(KC_D)
#define LGUI_F LGUI_T(KC_F)

#define RGUI_J RGUI_T(KC_J)
#define RALT_K RALT_T(KC_K)
#define RSFT_L RSFT_T(KC_L)
#define RCTL_SCLN RCTL_T(KC_SCLN)

// Layer toggle/switch keys
#define SYM_TOG LT(SYMBOLS, KC_LBRC)
#define NAV_TOG LT(NAVIGATION, KC_RBRC)
#define NUM_TOG MO(NUMPAD)
#define FN_TOG MO(FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_ergodox(
    // Left hand
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    SYM_TOG,
    KC_LCTL, LCTL_A,  LSFT_S,  LALT_D,  LGUI_F,  KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    NAV_TOG,
    FN_TOG,  KC_LGUI, KC_LALT, KC_PGUP, KC_PGDN,
                                                  KC_PSCR, KC_HOME,
                                                           KC_END,
                                        KC_SPC,  KC_ENT,  KC_INS,
    // Right hand
    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    SYM_TOG, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
             KC_H,    RGUI_J,  RALT_K,  RSFT_L,  RCTL_SCLN, KC_QUOT,
    NAV_TOG, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
             KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_MUTE,
    KC_RCTL, KC_MENU,
    KC_RALT,
    KC_RGUI, KC_SPC,  KC_ENT
  ),

  [SYMBOLS] = LAYOUT_ergodox(
    // Left hand
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_NO,   KC_TRNS,
                                                           KC_TRNS,
                                        KC_NO,   KC_NO,   KC_TRNS,
    // Right hand
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
             KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
    KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
             KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
    KC_NO,   KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [NAVIGATION] = LAYOUT_ergodox(
    // Left hand
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // Right hand
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,
             KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_BSPC, KC_DEL,  KC_NO,   KC_NO,   KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [NUMPAD] = LAYOUT_ergodox(
    // Left hand
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // Right hand
    KC_TRNS, KC_NO,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO,
    KC_TRNS, KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,
             KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
    KC_TRNS, KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
             KC_TRNS, KC_P0,   KC_PDOT, KC_PENT, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [FUNCTION] = LAYOUT_ergodox(
    // Left hand
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_NO,   KC_TRNS,
                                                           KC_TRNS,
                                        KC_NO,   KC_NO,   KC_TRNS,
    // Right hand
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
             KC_NO,   MACRO_EMAIL, MACRO_URL, MACRO_CODE_SNIPPET, KC_NO, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MACRO_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("developer@example.com");
      }
      return false;
    case MACRO_URL:
      if (record->event.pressed) {
        SEND_STRING("https://github.com");
      }
      return false;
    case MACRO_CODE_SNIPPET:
      if (record->event.pressed) {
        SEND_STRING(
          "#include <stdio.h>" SS_DELAY(10)
          SS_TAP(X_ENT)
          SS_DELAY(10)
          "int main() {" SS_DELAY(10)
          SS_TAP(X_ENT)
          "  printf(\"Hello, World!\");" SS_DELAY(10)
          SS_TAP(X_ENT)
          "  return 0;" SS_DELAY(10)
          SS_TAP(X_ENT)
          "}"
        );
      }
      return false;
  }
  return true;
}

// Layer name display for OLED
const char *layer_names[] = {
  "QWERTY",
  "SYMBOLS",
  "NAVIGATION",
  "NUMPAD",
  "FUNCTION"
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

void oled_task_user(void) {
  // Display layer name
  oled_write_P(PSTR("Layer: "), false);
  oled_write(layer_names[get_highest_layer(layer_state)], false);
  oled_write_P(PSTR("\n"), false);

  // Display master/slave status
  if (is_keyboard_master()) {
    oled_write_P(PSTR("Master\n"), false);
  } else {
    oled_write_P(PSTR("Slave\n"), false);
  }

  // Display keyboard status
  oled_write_P(PSTR("---\n"), false);
  oled_write_P(PSTR("WPM: "), false);
  oled_write(get_u8_str(get_current_wpm(), ' '), false);
  oled_write_P(PSTR("\n"), false);
}
#endif
