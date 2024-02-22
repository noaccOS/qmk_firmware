#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_ADJUST,
    
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

#define CTL_BSP CTL_T(KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define GUI_ENT GUI_T(KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,       KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_SMCL,    KC_Q,    KC_J,    KC_K,    KC_X,       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         CTL_BSP, SFT_SPC,   LOWER,      RAISE, GUI_ENT
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       RGB_TOG, KC_MNXT, KC_MPLY, KC_MPRV, XXXXXXX,    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,    KC_4,    KC_5,    KC_6, KC_PMNS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT,    KC_PAST,    KC_1,    KC_2,    KC_3, KC_PSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
