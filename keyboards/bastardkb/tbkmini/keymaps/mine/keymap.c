#include QMK_KEYBOARD_H

extern uint8_t is_master;

// markstos defines

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT
};

enum combos {
  JK_ESC
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
  // For Vim, put Escape on the home row
  [JK_ESC]    = COMBO(jk_combo, KC_ESC),
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3

// For _QWERTY layer
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_AGR  MT(MOD_LALT | MOD_RALT,KC_ESC) // Tap - Esc, Hold - Alt
#define OSL_FUN  OSL(_FUNC)
#define GUI_ENT  GUI_T(KC_ENT)
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define RSE_ESC  LT(_RAISE, KC_ESC)
#define OSM_SFT  OSM(MOD_LSFT)

#define OS_SALL  LGUI(KC_A) // SELECT
#define OS_COPY  LGUI(KC_C) // COPY
#define OS_PSTE  LGUI(KC_V) // PASTE
#define OS_LANG  LCTL(KC_SPC) // Ctrl Space - change language
#define OS_LANG  LCTL(KC_SPC) // Ctrl Space - change language


#define RCT_RT   LCA(KC_RGHT) // rectange right side
#define RCT_CT   LCA(KC_ENT) // rectange maximize windows
#define RCT_LT   LCA(KC_LEFT) // rectange left side

#define SCR_PT_C LGUI(LSFT(LCTL(KC_4))) // copy part of screen to clipboard
#define SCR_C LGUI(LSFT(LCTL(KC_3))) // copy whole screen to clipboard
#define SCR_PT_S LGUI(LSFT(KC_4)) // copy part of screen and save
#define SCR_S LGUI(LSFT(KC_3)) // copy whole screen and save



// For _RAISE layer
#define CTL_ESC  LCTL_T(KC_ESC)
#define CMD_ENT  LGUI(KC_ENT)
#define ALT_ENT  LGUI(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LALT),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_QUOT ,OSM_AGR,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LSFT),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,OSL_FUN,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM_LCTL, GUI_ENT, LOW_TAB,   RSE_ESC ,KC_SPC  ,OSM_SFT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX , KC_TILD,KC_GRV, KC_LBRC, KC_LCBR,                       KC_RCBR, KC_RBRC, KC_COMM,KC_DOT,  KC_SLSH, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  KC_TRNS, LOWER,    KC_TRNS, KC_TRNS, KC_COLON \
                                      //`--------------------------'  `--------------------------'
    ),


  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_DEL , OS_SALL, KC_UNDS, KC_PLUS, KC_PGUP,                      RCT_LT, RCT_CT, RCT_RT, KC_BSLS, KC_PIPE,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_END , KC_MINS, KC_EQL , KC_PGDN,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_APP ,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LT  , KC_GT  , OS_COPY, OS_PSTE, KC_SCLN,                      KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU,_______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, CMD_ENT, KC_ENT,    RAISE  , KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1  , KC_F2  , KC_F3   , KC_F4 ,  KC_F5 ,                     KC_F6   , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F11 , KC_F12 , RGB_TOG, RGB_MOD, XXXXXXX,                     RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, SCR_PT_C, SCR_S, SCR_PT_S, SCR_C,                       RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, QK_BOOT,XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC, ALT_ENT, KC_DEL,     XXXXXXX, FUNC   , XXXXXXX\
                                      //`--------------------------'  `--------------------------'
  )
};

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//       case LT(_RAISE, KC_BSPC):
//             return TAPPING_TERM_THUMB;
//       case LT(_LOWER, KC_TAB):
//             return TAPPING_TERM_THUMB;
//       default:
//             return TAPPING_TERM;
//     }
// }
