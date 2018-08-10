/*
ut47
*/

#include QMK_KEYBOARD_H


// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LAT 3
#define _LOWER 4
#define _RAISE 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define _NOPE_ KC_NO

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LAT MO(_LAT)

#define HELLO LALT(LCTL(KC_DEL))
#define MC_REIZ RALT(LSFT(KC_8))
#define MC_DEGR RALT(LSFT(KC_5))
#define MC_PLMN RALT(LSFT(KC_7))
#define MC_ACNT RALT(KC_QUOT)
#define MC_APOS RALT(LSFT(KC_QUOT))
#define MC_EUR RALT(KC_4)
#define MC_LBRC RALT(KC_2)
#define MC_RBRC RALT(KC_3)
#define MC_DASH RALT(KC_MINS)
#define MC_HYPN RALT(LSFT(KC_MINS))
#define MC_PRGR RALT(LSFT(KC_4))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(

  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    HELLO,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_LCTL,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
  KC_LGUI, KC_APP,  KC_LALT, RAISE,   LOWER,      KC_ENT,        KC_SPC,  LAT,     KC_VOLD, KC_VOLU, KC_MUTE

  ),  

  [_LAT] = LAYOUT(

  KC_CAPS, KC_EXLM,    KC_AT,      RALT(KC_E),   RALT(KC_R),   KC_HASH,     MC_PLMN,    RALT(KC_U),    RALT(KC_I),  RALT(KC_O), MC_DEGR, _______,
  _______, RALT(KC_A), RALT(KC_S), KC_AMPR,      KC_PIPE,      RALT(KC_G),  KC_PERC,    KC_CIRC,       RALT(KC_K),  RALT(KC_L), MC_ACNT, _______,
  _______, RALT(KC_Z), KC_CIRC,    RALT(KC_C),   KC_TILD,      MC_HYPN,     RALT(KC_N), MC_DASH,       MC_LBRC,     MC_RBRC,    MC_PRGR, _______,
  _______, _______,    _______,    _______,      _______,            _______,           _______,       _______,     _______,    _______, _______

  ),  

  [_LOWER] = LAYOUT(

  KC_ESC,   KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_TILD, KC_GRV,  KC_HOME, KC_UP,   KC_END,   KC_CIRC, KC_PAUS,
  _______,  KC_LCTL, KC_LSFT, KC_LCBR, KC_RCBR, KC_MINS, KC_INS,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_COLN, _______,
  _______,  KC_UNDS, KC_EQL,  KC_PPLS, KC_ASTR, KC_AMPR, KC_DEL,  KC_BSPC, KC_DQUO, KC_QUOT,  KC_NUBS, _______,
  KC_APP,   _______, _______, _______, _______,      _______,     _______, _______, _______, _______,  _______

  ),

  [_RAISE] = LAYOUT(

  KC_ESC,  KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_PGUP,    KC_PGDN,  KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_PSCR,
  _______, KC_1,      KC_2,      KC_3,      KC_4,      KC_5,       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_LALT,
  _______, KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_CALC,    KC_DEL,   KC_BSPC,  KC_DLR,  MC_EUR,  MC_REIZ, _______,
  _______, _______,   _______,   _______,   _______,        _______,         _______,  _______, _______, _______, _______
  ),  

  [_ADJUST] =  LAYOUT(

  _NOPE_,  _NOPE_,  _NOPE_,  _NOPE_,  RESET,   _NOPE_, _NOPE_, _NOPE_, _NOPE_, _NOPE_, _NOPE_, _NOPE_,
  _NOPE_,  _NOPE_,  _NOPE_,  _NOPE_,  _NOPE_,  _NOPE_, _NOPE_, _NOPE_, _NOPE_, _NOPE_, _NOPE_, _NOPE_,
  _NOPE_,  _NOPE_,  _NOPE_,  _NOPE_,  _NOPE_,  _NOPE_, _NOPE_, _NOPE_, _NOPE_, _NOPE_, _NOPE_, _NOPE_,
  _______, _______, _______, _______, _______, _______, _______, _______, _NOPE_, _NOPE_, _NOPE_
  )

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); 
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}