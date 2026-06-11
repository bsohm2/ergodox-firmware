/* ErgoDox Infinity custom keymap — modern QMK
 * Layers: QWERTY base, Symbols, Navigation, Function, Gaming (toggle), Gaming mods
 */
#include QMK_KEYBOARD_H

enum layers {
  QWERTY = 0,
  SYMBOLS,
  NAVIGATION,
  FUNCTION,
  GAMING,
  GAMING_MODS
};

// Tap dance: brackets become braces on double tap
enum {
  TD_LBRC,  // [ once, { twice
  TD_RBRC   // ] once, } twice
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_ergodox(
    // Left hand
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TD(TD_LBRC),
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(NAVIGATION),
    KC_LCTL, KC_LGUI, KC_LALT, KC_PGUP, KC_PGDN,
                                                  KC_PSCR, KC_HOME,
                                                           KC_END,
                                        KC_SPC,  KC_ENT,  MO(FUNCTION),
    // Right hand
    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    TD(TD_RBRC), KC_Y, KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS,
             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    MO(SYMBOLS), KC_N, KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
             KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_MUTE,
    KC_RCTL, TG(SYMBOLS),
    KC_RALT,
    KC_RGUI, KC_SPC,  KC_ENT
  ),

  [SYMBOLS] = LAYOUT_ergodox(
    // Left hand
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
    EE_CLR,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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

  [FUNCTION] = LAYOUT_ergodox(
    // Left hand — FN+Q toggles the Gaming layer
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
    KC_TRNS, TG(GAMING), KC_NO, KC_NO,  KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, DM_REC1, DM_PLY1, DM_REC2, DM_PLY2, DM_RSTP,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_NO,   KC_TRNS,
                                                           KC_TRNS,
                                        KC_NO,   KC_NO,   KC_TRNS,
    // Right hand
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
             KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_TRNS,
    KC_TRNS, KC_NO,   KC_MPRV, KC_MNXT, KC_NO,   KC_NO,   KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [GAMING] = LAYOUT_ergodox(
    // Left hand — WASD movement focused, plain mods, no tap-hold
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_RBRC,
    KC_LALT, KC_NO,   KC_LCTL, KC_LGUI, MO(GAMING_MODS),
                                                  KC_PSCR, KC_HOME,
                                                           KC_END,
                                        KC_SPC,  KC_ENT,  MO(FUNCTION),
    // Right hand
    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
             KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, MO(FUNCTION),
    KC_RCTL, TG(GAMING),
    KC_RALT,
    KC_RGUI, KC_SPC,  KC_ENT
  ),

  [GAMING_MODS] = LAYOUT_ergodox(
    // Left hand — quick ability access
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
    KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_NO,
    KC_TRNS, KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_NO,   KC_TRNS,
                                                           KC_TRNS,
                                        KC_NO,   KC_NO,   KC_TRNS,
    // Right hand
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
             KC_L,    KC_SCLN, KC_QUOT, KC_SLSH, KC_BSLS, KC_TRNS,
    KC_TRNS, KC_COMM, KC_DOT,  KC_EQL,  KC_MINS, KC_PLUS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO,   KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

};

tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
};

// Combo: J + K together = Escape
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[] = {
  COMBO(jk_combo, KC_ESC),
};

// Keep combos out of gaming — simultaneous presses are normal there
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (layer_state_is(GAMING)) {
    return false;
  }
  return true;
}
