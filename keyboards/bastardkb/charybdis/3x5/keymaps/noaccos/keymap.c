#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_ADJUST,
    
};

enum planck_layers {
  _MAIN,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD
};

enum unicode_names {
  agrave,
  egrave,
  igrave,
  ograve,
  ugrave,
  aacute,
  eacute,
  iacute,
  oacute,
  uacute,
  Agrave,
  Egrave,
  Igrave,
  Ograve,
  Ugrave,
  Aacute,
  Eacute,
  Iacute,
  Oacute,
  Uacute
};

const uint32_t PROGMEM unicode_map[] = {
  [agrave] = 0x00E0,
  [egrave] = 0x00E8,
  [igrave] = 0x00EC,
  [ograve] = 0x00F2,
  [ugrave] = 0x00F9,
  [aacute] = 0x00E1,
  [eacute] = 0x00E9,
  [iacute] = 0x00ED,
  [oacute] = 0x00F3,
  [uacute] = 0x00FA,
  [Agrave] = 0x00C0,
  [Egrave] = 0x00C8,
  [Igrave] = 0x00CC,
  [Ograve] = 0x00D2,
  [Ugrave] = 0x00D9,
  [Aacute] = 0x00C1,
  [Eacute] = 0x00C9,
  [Iacute] = 0x00CD,
  [Oacute] = 0x00D3,
  [Uacute] = 0x00DA
};

#define LOWER  MO(LAYER_LOWER)
#define RAISE  MO(LAYER_RAISE)
#define ADJUST MO(LAYER_ADJUST)

#define CTL_BSP CTL_T(KC_BSPC)
#define SFT_ENT SFT_T(KC_ENT)
#define GUI_ENT GUI_T(KC_ENT)

# define CTL_MOD LM(LAYER_BASE, MOD_LCTL)
# define ALT_MOD LM(LAYER_BASE, MOD_LALT)
# define GUI_MOD LM(LAYER_BASE, MOD_LALT)

#define KC_AC_A UP(aacute, Aacute)
#define KC_AC_E UP(eacute, Eacute)
#define KC_AC_I UP(iacute, Iacute)
#define KC_AC_O UP(oacute, Oacute)
#define KC_AC_U UP(uacute, Uacute)
#define KC_GR_A UP(agrave, Agrave)
#define KC_GR_E UP(egrave, Egrave)
#define KC_GR_I UP(igrave, Igrave)
#define KC_GR_O UP(ograve, Ograve)
#define KC_GR_U UP(ugrave, Ugrave)

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
                         SFT_ENT,  KC_SPC,   LOWER,      RAISE,  KC_BSP
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       RGB_TOG, KC_MNXT, KC_MPLY, KC_MPRV, XXXXXXX,    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_AC_A, KC_AC_O, KC_AC_E, KC_AC_U, KC_AC_I,    KC_PPLS,    KC_4,    KC_5,    KC_6, KC_PMNS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,    KC_PAST,    KC_1,    KC_2,    KC_3, KC_PSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,     ADJUST, ALT_MOD
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_GR_A,KC_GR_O,  KC_GR_E, KC_GR_U, KC_GR_I,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         GUI_MOD, CTL_MOD,  ADJUST,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_ADJUST] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_GR_A,KC_GR_O,  KC_GR_E, KC_GR_U, KC_GR_I,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_LALT, KC_LCTL, XXXXXXX,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
