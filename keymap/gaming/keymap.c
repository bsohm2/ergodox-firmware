/* ErgoDox Infinity gaming keymap
 * Optimized for competitive gaming with WASD movement and enhanced controls
 */
#include QMK_KEYBOARD_H

enum layers {
  GAMING = 0,
  GAMING_MODS,
  GAMING_NUMPAD,
  GAMING_FUNCTION
};

enum custom_keycodes {
  GAME_MODE = SAFE_RANGE,
  BACK_TO_DEFAULT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [GAMING] = LAYOUT_ergodox(
    // Left hand - WASD movement focused
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_RBRC,
    KC_LALT, KC_NO,   KC_LCTL, KC_LGUI, MO(GAMING_MODS),
                                                  KC_PSCR, KC_HOME,
                                                           KC_END,
                                        KC_SPC,  KC_ENT,  MO(GAMING_NUMPAD),
    // Right hand - Ability keys and utilities
    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
             KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, MO(GAMING_FUNCTION),
    KC_RCTL, KC_MENU,
    KC_RALT,
    KC_RGUI, KC_SPC,  KC_ENT
  ),

  [GAMING_MODS] = LAYOUT_ergodox(
    // Left hand - Quick ability access (no tap-hold delays)
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
    KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_NO,
    KC_TRNS, KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_NO,   KC_TRNS,
                                                           KC_TRNS,
                                        KC_NO,   KC_NO,   KC_TRNS,
    // Right hand - More abilities and quick items
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
             KC_L,    KC_SCLN, KC_QUOT, KC_SLSH, KC_BSLS, KC_TRNS,
    KC_TRNS, KC_COMM, KC_DOT,  KC_EQL,  KC_MINS, KC_PLUS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO,   KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [GAMING_NUMPAD] = LAYOUT_ergodox(
    // Left hand - Quick item/spell access
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // Right hand - Numpad for quick ability selection (1-0)
    KC_TRNS, KC_NO,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO,
    KC_TRNS, KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,
             KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
    KC_TRNS, KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
             KC_TRNS, KC_P0,   KC_PDOT, KC_PENT, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [GAMING_FUNCTION] = LAYOUT_ergodox(
    // Left hand
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_NO,   KC_TRNS,
                                                           KC_TRNS,
                                        KC_NO,   KC_NO,   KC_TRNS,
    // Right hand - Game-specific utilities
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
             KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_TRNS,
    KC_TRNS, BACK_TO_DEFAULT, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GAME_MODE:
      if (record->event.pressed) {
        // Placeholder for game mode activation
      }
      return false;
    case BACK_TO_DEFAULT:
      if (record->event.pressed) {
        // Would switch to default keymap
        // In practice, user would flash default keymap to do this
      }
      return false;
  }
  return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

void oled_task_user(void) {
  // Display gaming mode indicator
  oled_write_P(PSTR("GAMING"), false);
  oled_write_P(PSTR("\n"), false);

  // Display current layer
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state)) {
    case GAMING:
      oled_write_P(PSTR("Base\n"), false);
      break;
    case GAMING_MODS:
      oled_write_P(PSTR("Mods\n"), false);
      break;
    case GAMING_NUMPAD:
      oled_write_P(PSTR("Items\n"), false);
      break;
    case GAMING_FUNCTION:
      oled_write_P(PSTR("Func\n"), false);
      break;
    default:
      oled_write_P(PSTR("???\n"), false);
  }

  // Display master/slave status
  oled_write_P(PSTR("---\n"), false);
  if (is_keyboard_master()) {
    oled_write_P(PSTR("Left\n"), false);
  } else {
    oled_write_P(PSTR("Right\n"), false);
  }
}
#endif
