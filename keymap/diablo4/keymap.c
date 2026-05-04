/* ErgoDox Infinity - Diablo 4 optimized keymap
 * 6 skill slots + potions + utilities for Sanctuary farming
 * Designed for fast skill casting with precise positioning via Force Move
 */
#include QMK_KEYBOARD_H

enum layers {
  DIABLO = 0,
  DIABLO_HOTBAR,
  DIABLO_INVENTORY,
  DIABLO_FUNCTION
};

enum custom_keycodes {
  // Skill slots (simulates LMB clicks in D4)
  D4_SKILL_1 = SAFE_RANGE,
  D4_SKILL_2,
  D4_SKILL_3,
  D4_SKILL_4,
  D4_SKILL_5,
  D4_SKILL_6,
  // Utilities
  D4_POTION,
  D4_TOWN_PORTAL,
  D4_FORCE_MOVE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DIABLO] = LAYOUT_ergodox(
    // Left hand - Movement + Skill access
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
    KC_TAB,  D4_SKILL_1, D4_SKILL_2, D4_SKILL_3, D4_SKILL_4, D4_SKILL_5, KC_LBRC,
    KC_LCTL, KC_A,    KC_S,    D4_POTION, KC_F,   D4_SKILL_6,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    D4_TOWN_PORTAL, KC_RBRC,
    KC_LALT, KC_NO,   KC_LCTL, KC_LGUI, MO(DIABLO_HOTBAR),
                                                  KC_PSCR, KC_HOME,
                                                           KC_END,
                                        KC_SPC,  KC_ENT,  MO(DIABLO_INVENTORY),
    // Right hand - Inventory, minimap, utilities
    KC_EQL,  KC_I,    KC_C,    KC_M,    KC_S,    KC_L,    KC_BSPC,
    KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
             KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, MO(DIABLO_FUNCTION),
    KC_RCTL, KC_MENU,
    KC_RALT,
    KC_RGUI, KC_SPC,  KC_ENT
  ),

  [DIABLO_HOTBAR] = LAYOUT_ergodox(
    // Left hand - Alternate skill bindings
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,
    KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_NO,   KC_TRNS,
                                                           KC_TRNS,
                                        KC_NO,   KC_NO,   KC_TRNS,
    // Right hand - Secondary utilities
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_F12,
             KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO,   KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [DIABLO_INVENTORY] = LAYOUT_ergodox(
    // Left hand - Inventory management
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // Right hand - Quick access stash/sorting
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [DIABLO_FUNCTION] = LAYOUT_ergodox(
    // Left hand
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_NO,   KC_TRNS,
                                                           KC_TRNS,
                                        KC_NO,   KC_NO,   KC_TRNS,
    // Right hand - Game controls
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
             KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_TRNS,
    KC_TRNS, KC_NO,   KC_MENU, KC_ESC,  KC_NO,   KC_NO,   KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Skill slots 1-6 send key presses to D4
    case D4_SKILL_1:
      if (record->event.pressed) {
        SEND_STRING("1");
      }
      return false;
    case D4_SKILL_2:
      if (record->event.pressed) {
        SEND_STRING("2");
      }
      return false;
    case D4_SKILL_3:
      if (record->event.pressed) {
        SEND_STRING("3");
      }
      return false;
    case D4_SKILL_4:
      if (record->event.pressed) {
        SEND_STRING("4");
      }
      return false;
    case D4_SKILL_5:
      if (record->event.pressed) {
        SEND_STRING("5");
      }
      return false;
    case D4_SKILL_6:
      if (record->event.pressed) {
        SEND_STRING("6");
      }
      return false;
    case D4_POTION:
      if (record->event.pressed) {
        SEND_STRING("q");  // Default D4 potion key
      }
      return false;
    case D4_TOWN_PORTAL:
      if (record->event.pressed) {
        SEND_STRING("t");  // Default D4 town portal key
      }
      return false;
    case D4_FORCE_MOVE:
      if (record->event.pressed) {
        // Force move is typically scroll wheel, but can map to key
        SEND_STRING("shift");
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
  // Display D4 mode indicator
  oled_write_P(PSTR("DIABLO 4\n"), false);

  // Display current layer
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state)) {
    case DIABLO:
      oled_write_P(PSTR("Skills\n"), false);
      break;
    case DIABLO_HOTBAR:
      oled_write_P(PSTR("Alt\n"), false);
      break;
    case DIABLO_INVENTORY:
      oled_write_P(PSTR("Inv\n"), false);
      break;
    case DIABLO_FUNCTION:
      oled_write_P(PSTR("Func\n"), false);
      break;
    default:
      oled_write_P(PSTR("???\n"), false);
  }

  // Display active skills
  oled_write_P(PSTR("---\n"), false);
  oled_write_P(PSTR("S1-6 Active\n"), false);
  
  // Display master/slave status
  if (is_keyboard_master()) {
    oled_write_P(PSTR("Master\n"), false);
  } else {
    oled_write_P(PSTR("Slave\n"), false);
  }
}
#endif
