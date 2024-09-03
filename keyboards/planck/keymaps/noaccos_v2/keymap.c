#include QMK_KEYBOARD_H

enum planck_layers {
  _MAIN,
  _LOWER,
  _RAISE,
  _ADJUST,
  _TTY,
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

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define TTY    OSL(_TTY)

#define ACUTE_A UP(aacute, Aacute)
#define ACUTE_E UP(eacute, Eacute)
#define ACUTE_I UP(iacute, Iacute)
#define ACUTE_O UP(oacute, Oacute)
#define ACUTE_U UP(uacute, Uacute)
#define GRAVE_A UP(agrave, Agrave)
#define GRAVE_E UP(egrave, Egrave)
#define GRAVE_I UP(igrave, Igrave)
#define GRAVE_O UP(ograve, Ograve)
#define GRAVE_U UP(ugrave, Ugrave)

#define KIL LCTL(LALT(KC_DEL))
#define TTY1 LCTL(LALT(KC_F1))
#define TTY2 LCTL(LALT(KC_F2))
#define TTY3 LCTL(LALT(KC_F3))
#define TTY4 LCTL(LALT(KC_F4))
#define TTY5 LCTL(LALT(KC_F5))
#define TTY6 LCTL(LALT(KC_F6))
#define TTY7 LCTL(LALT(KC_F7))
#define TTY8 LCTL(LALT(KC_F8))
#define TTY9 LCTL(LALT(KC_F9))
#define TTY10 LCTL(LALT(KC_F10))
#define TTY11 LCTL(LALT(KC_F11))
#define TTY12 LCTL(LALT(KC_F12))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Main
 * ,-----------------------------------------------------------------------------------.
 * |      |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Shift |Lower |Space | Ret  |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MAIN] = LAYOUT_planck_grid(
    XXXXXXX, KC_QUOT, KC_COMM, KC_DOT, KC_P,  KC_Y,   KC_F,    KC_G,  KC_C,    KC_R,    KC_L,     XXXXXXX,
    XXXXXXX, KC_A,    KC_O,    KC_E,   KC_U,  KC_I,   KC_D,    KC_H,  KC_T,    KC_N,    KC_S,     XXXXXXX,
    XXXXXXX, KC_SCLN, KC_Q,    KC_J,   KC_K,  KC_X,   KC_B,    KC_M,  KC_W,    KC_V,    KC_Z,     XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT, LOWER, KC_SPC, KC_LSFT, RAISE, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  À   |  Ò   |  È   |  Ù   |  Ì   |      |   {  |   }  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  M7  |  M8  |  M2  |  M1  |  M3  |  `   |  \   |  /   |  -   |  =   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Ctrl | Adj  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
    XXXXXXX, GRAVE_A, GRAVE_O, GRAVE_E, GRAVE_U, GRAVE_I, KC_NO,   KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, XXXXXXX,
    XXXXXXX, KC_BTN7, KC_BTN8, KC_BTN2, KC_BTN1, KC_BTN3, KC_GRV,  KC_BSLS, KC_QUES, KC_UNDS, KC_PLUS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, ADJUST,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Á   |  Ó   |  É   |  Ú   |  Í   | Esc  | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Bspc | Del  | Tab  | Caps |  ~   |  |   |  ?   |  _   |  +   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Alt  | Adj  |Super |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
    XXXXXXX, ACUTE_A, ACUTE_O, ACUTE_E, ACUTE_U, ACUTE_I, KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_BSPC, KC_DEL,  KC_TAB,  KC_CAPS, KC_TILD, KC_PIPE, KC_QUES, KC_UNDS, KC_PLUS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, ADJUST,  KC_LCTL, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  | UC+  | Play | Prev | Vol- | Vol+ | Next |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  | UC-  |      | Home | Pg-  | Pg+  | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  | F12  |      |      | Kil  | TTY  |      | BOOT |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   UC_PREV, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   UC_NEXT, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
    XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KIL,     TTY,     XXXXXXX, QK_BOOT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* TTY
 * ,-----------------------------------------------------------------------------------.
 * |      | TTY1 | TTY2 | TTY3 | TTY4 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | TTY5 | TTY6 | TTY7 | TTY8 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | TTY9 |TTY10 |TTY11 |TTY12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_TTY] = LAYOUT_planck_grid(
    XXXXXXX, TTY1,    TTY2,    TTY3,    TTY4,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    XXXXXXX, TTY5,    TTY6,    TTY7,    TTY8,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    XXXXXXX, TTY9,    TTY10,   TTY11,   TTY12,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX
)
};
// clang-format on
