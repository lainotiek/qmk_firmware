/*
DZ60
*/

#include QMK_KEYBOARD_H

// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LAT 3
#define _NAV 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  ACCENT,
  DBLARR,
  TILDE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define _NOPE_ KC_NO

#define NAV MO(_NAV)
#define LAT MO(_LAT)
#define WIN MO(_WIN)

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
#define MC_LT   LSFT(KC_COMM)
#define MC_GT   LSFT(KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(

  KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F10,   KC_F11,  _NOPE_, KC_BSPC,
  KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MC_LBRC,  MC_RBRC, KC_CALC,
  KC_LCTL, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LAT,     KC_RCTL,  KC_ENT,
  KC_LSFT, _NOPE_,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LSFT,  _NOPE_,  _NOPE_,
  KC_F12,  KC_LGUI,  KC_LALT,  NAV,      KC_ENT,       KC_SPC,  KC_LCTL,  KC_VOLD, _NOPE_,  KC_VOLU, KC_MUTE

  ),  

  [_LAT] = LAYOUT(

  KC_CAPS, MC_ACNT,    MC_DEGR,    MC_PRGR,      MC_EUR,      MC_HYPN,    MC_APOS, MC_PLMN,     KC_8,       KC_9,       MC_DEGR, MC_DASH,  MC_HYPN, _NOPE_, RESET,
  KC_TAB,  KC_EXLM,    KC_AT,      RALT(KC_E),   KC_EQL,      KC_PERC,    KC_CIRC, RALT(KC_U),  RALT(KC_I), RALT(KC_O), MC_DEGR, KC_PGUP,  KC_PGDN, KC_CALC,
  KC_LCTL, RALT(KC_A), RALT(KC_S), KC_COLN,      KC_QUES,     RALT(KC_G), KC_PIPE, KC_AMPR,     RALT(KC_K), RALT(KC_L), _______, _______,  _______,
  KC_LSFT, _NOPE_,     RALT(KC_Z), MC_REIZ,      RALT(KC_C),  KC_UNDS,    TILDE,   RALT(KC_N),  MC_DASH,    MC_PRGR,    _______, _______,  _______, _NOPE_,
  _______, _______,    _______,      _______,    KC_CAPS,     KC_SPC,     _NOPE_,     _______,     _NOPE_,     _______,    _______

  ),  

  [_NAV] = LAYOUT(

  KC_F12,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  _NOPE_, KC_PAUS,
  KC_TAB,  KC_LBRC,  KC_RBRC, KC_LPRN, KC_RPRN, KC_PIPE, KC_INS,  KC_HOME,  KC_UP,    KC_END,   KC_P,     KC_PGUP,  KC_PGDN, KC_B,
  KC_LCTL, KC_LCTL,  KC_LSFT, KC_LCBR, KC_RCBR, KC_MINS, KC_NUBS, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_SCLN,  _______,  KC_CAPS,
  KC_LSFT, _NOPE_,   KC_NUBS, DBLARR,  MC_LT,   MC_GT,   KC_COLN, KC_DEL,   KC_BSPC,  KC_DQUO,  KC_QUOT,  KC_SLSH,  KC_NUBS, _NOPE_,
  _______, _______,  _______, _______, KC_ENT,        _______,  _NOPE_,     _______, _NOPE_,  _______, _______

  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DBLARR:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      break;
    case TILDE:
      if (record->event.pressed) {
        SEND_STRING("~ ");
      }
      break;
  }
  return true;
};