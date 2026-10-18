// This QMK keymap does the following:
// + Replace Caps Lock with hold-for-control and tap-for-esc.
// + Replace Escape with tap-once-for-esc and double-tap-for-caps-lock.

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum tap_dance_keys {
  TD_ESC_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Escape and twice for Caps Lock.
  [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

// NOTE: The order is important here as, per the keymap documentation, 'higher
//       layers have higher priority within the stack of layers'. Thus
//       LAYOUT_WIN_FN comes after LAYOUT_GAMING and LAYOUT_WIN_BASE so that its
//       mappings override those in the aforementioned two layers when it is
//       active (ie. while Fn is held down).
enum layers {
  LAYOUT_MAC_BASE,
  LAYOUT_MAC_FN,
  LAYOUT_WIN_BASE,
  LAYOUT_GAMING,
  LAYOUT_WIN_FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYOUT_MAC_BASE] = LAYOUT_tkl_ansi(
    TD(TD_ESC_CAPS), KC_BRID,  KC_BRIU,  KC_MCTL, KC_LPAD,  RM_VALD,  RM_VALU,           KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU, KC_SNAP, KC_SIRI, RM_NEXT,
    KC_GRV,          KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,              KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,          KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,              KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,              KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,    KC_V,     KC_B,     KC_N,              KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,
    KC_LCTL,         KC_LOPTN, KC_LCMMD, KC_SPC,  KC_RCMMD, KC_ROPTN, MO(LAYOUT_MAC_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [LAYOUT_MAC_FN] = LAYOUT_tkl_ansi(
    KC_TRNS, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, RM_TOGG,
    KC_TRNS, BT_HST1,  BT_HST2, BT_HST3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    RM_TOGG, RM_NEXT,  RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, BAT_LVL, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [LAYOUT_WIN_BASE] = LAYOUT_tkl_ansi(
    TD(TD_ESC_CAPS), KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_PSCR, KC_CTANA, RM_NEXT,
    KC_GRV,          KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,              KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_INS,   KC_HOME, KC_PGUP,
    KC_TAB,          KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,              KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, KC_DEL,   KC_END,  KC_PGDN,
    LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,              KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,
    KC_LSFT,         KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,              KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,
    KC_LCTL,         KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, MO(LAYOUT_WIN_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [LAYOUT_GAMING] = LAYOUT_tkl_ansi(
    KC_ESC, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [LAYOUT_WIN_FN] = LAYOUT_tkl_ansi(
    KC_TRNS, KC_BRID,           KC_BRIU, KC_TASK, KC_FILE, RM_VALD,           RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, RM_TOGG,
    KC_TRNS, BT_HST1,           BT_HST2, BT_HST3, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    RM_TOGG, RM_NEXT,           RM_VALU, RM_HUEU, RM_SATU, RM_SPDU,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, RM_PREV,          RM_VALD, RM_HUED, RM_SATD, RM_SPDD,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, BAT_LVL,           NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, TG(LAYOUT_GAMING), KC_TRNS, KC_TRNS, KC_TRNS, TG(LAYOUT_GAMING), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};
