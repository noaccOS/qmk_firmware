#include QMK_KEYBOARD_H

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

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Main(Dvorak)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NumP | Caps | GUI  | CTRL |Lower |    Space    |Raise | Alt  | GUI  | App  | Game |
 * `-----------------------------------------------------------------------------------'
 */
[_MAIN] = LAYOUT_planck_grid(
    KC_TAB,       KC_QUOT,     KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,       KC_A,        KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
    KC_LSFT,      KC_SCLN,     KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
    MO(_NUMPAD),  KC_CAPS,     KC_LGUI, KC_LCTL, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LALT, KC_RGUI, KC_APP,  TG(_GAME)
),

/* Game(QWERTY)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NumP | Caps | GUI  | CTRL |Lower |    Space    |Raise | Alt  | GUI  | App  | Game |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_planck_grid(
    KC_TAB,     KC_Q,      KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_ESC,     KC_A,      KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
    KC_LSFT,    KC_Z,      KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    _______,    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______

),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  Á   |  Ó   |  É   |  Ú   |  Í   |      |   {  |   }  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |  |   ?  |   _  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             | ADJ  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM,            KC_AT,              KC_HASH,            KC_DLR,             KC_PERC,            KC_CIRC, KC_AMPR,        KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  XP(aacute, Aacute), XP(oacute, Oacute), XP(eacute, Eacute), XP(uacute, Uacute), XP(iacute, Iacute), KC_NO,   KC_LCBR,        KC_RCBR,    KC_LBRC, KC_RBRC, _______,
    _______, KC_NO,              KC_NO,              KC_NO,              KC_NO,              KC_NO,              KC_NO,   KC_PIPE,        KC_QUES,    KC_UNDS, KC_PLUS, _______,
    _______, _______,        _______,        _______,       _______,        _______,        _______, MO(_ADJUST),    _______,    _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  À   | Ò    | È    | Ù    | Ì    |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | HOME | END  |      |      |  \   |  /   |  -   |  =   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | ADJ  |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,               KC_2,               KC_3,               KC_4,               KC_5,               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,
    KC_DEL,  XP(agrave, Agrave), XP(ograve, Ograve), XP(egrave, Egrave), XP(ugrave, Ugrave), XP(igrave, Igrave), KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
    _______, KC_NO,              KC_NO,              KC_HOME,            KC_END,             KC_NO,              KC_NO,   KC_BSLS, KC_SLSH, KC_MINS, KC_EQL,   _______,
    _______, _______,        _______,        _______,       MO(_ADJUST),    _______,       _______, _______, KC_NO,   KC_NO,   KC_NO,    KC_NO
),

/* Adjust (Lower + Raise) TODO: MEDIA
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |UCmod |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, UC_MOD,  MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |  7   |  8   |  9   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |  4   |  5   |  6   |  *   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  | F12  |      |      |  1   |  2   |  3   |  -   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |  0   |      |  .   |  +   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    _______,   KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_NO,    KC_NO,    KC_7,    KC_8,    KC_9,     KC_SLSH,  _______,
    _______,   KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_NO,    KC_NO,    KC_4,    KC_5,    KC_5,     KC_ASTR,  _______,
    _______,   KC_F9,     KC_F10,   KC_F11,   KC_F12,   KC_NO,    KC_NO,    KC_1,    KC_2,    KC_3,     KC_MINS,  _______,
    _______,   KC_NO,     _______,  KC_NO,    KC_NO,    _______,  _______,  KC_0,    KC_NO,   KC_DOT,   KC_PLUS,  _______
)
};
