// Copyright 2024 Protesilaos Stavrou <info@protesilaos.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _MAIN 0
#define _EXT 1
#define _FN 2
#define _TODO 3

#define my_CTRL OSM(MOD_LCTL | MOD_RCTL)
#define my_SHFT OSM(MOD_LSFT | MOD_RSFT)
#define my_ALT OSM(MOD_LALT | MOD_RALT)
#define my_GUI OSM(MOD_LGUI | MOD_RGUI)
#define my_CA OSM(MOD_LCTL | MOD_LALT)
#define my_SPC LT(_EXT,KC_SPC)
#define my_ENT LT(_EXT,KC_ENT)

/*

TODO 2024-04-21: This is a work-in-progress as I use the keys for a
while to decide if I like them or not.

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    OSL(_FN),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      my_GUI,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, my_GUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      my_CA,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    my_ALT,          my_ALT,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, my_CA,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    my_SHFT, my_CTRL, my_ENT,                    my_SPC,  my_CTRL, my_SHFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_EXT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,                             KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,  KC_LPRN, KC_RPRN,                           KC_HOME,  KC_PGDN, KC_PGUP, KC_END, _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_EQUAL,KC_TILDE, KC_MINUS,KC_DQUO,                           KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      QK_REP, _______, KC_PLUS, KC_UNDS,  KC_GRAVE,KC_QUOT, KC_ESC,          KC_DEL,  KC_BSLS, KC_PIPE,  KC_LT,   KC_GT,  _______, QK_REP,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______,  KC_TAB,                  KC_BSPC, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_VAI, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_SPI, _______, _______, _______, _______, _______,                            _______, _______, KC_APP , _______, KC_PSCR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, _______, KC_PSCR, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, _______, _______, KC_APP , _______, _______, KC_VOLU,          KC_MNXT, _______, _______, _______, _______, _______, QK_BOOT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_MUTE, KC_VOLD,                   KC_MPRV, KC_MPLY, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_TODO] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

/*  NOTE 2024-08-18: A recent update to QMK has made the following
    produce a rainbow effect instead of the colour values I had
    specified.  The rainbow is fine, but now I can no longer
    colour-code them.  So I am disabling this for the time being and
    may enable a different backlight effect just for further
    experimentation.  It is not important though. */

/* void oneshot_mods_changed_user(uint8_t mods) {
 *   if (mods & MOD_MASK_SHIFT) {
 *     rgblight_enable();
 *     rgblight_sethsv(20,255,25);
 *   }
 *   if (mods & MOD_MASK_CTRL) {
 *     rgblight_enable();
 *     rgblight_sethsv(0,255,25);
 *   }
 *   if (mods & MOD_MASK_ALT) {
 *     rgblight_enable();
 *     rgblight_sethsv(180,255,25);
 *   }
 *   if (mods & MOD_MASK_GUI) {
 *     rgblight_enable();
 *     rgblight_sethsv(210,255,25);
 *   }
 *   if (!mods) {
 *     rgblight_disable();
 *   }
 * }
 *
 * // TODO 2024-04-21: This is promising, though I need to make it switch
 * // RGB effect than just a static colour.  This way, I can have, say, a
 * // rainbow effect when the mod is on but otherwise use a subtle static
 * // colour.
 * void oneshot_locked_mods_changed_user(uint8_t mods) {
 *   if (mods & MOD_MASK_SHIFT) {
 *     rgblight_enable();
 *     rgblight_sethsv(20,255,255);
 *   }
 *   if (mods & MOD_MASK_CTRL) {
 *     rgblight_enable();
 *     rgblight_sethsv(0,255,255);
 *   }
 *   if (mods & MOD_MASK_ALT) {
 *     rgblight_enable();
 *     rgblight_sethsv(180,255,255);
 *   }
 *   if (mods & MOD_MASK_GUI) {
 *     rgblight_enable();
 *     rgblight_sethsv(210,255,255);
 *   }
 *   if (!mods) {
 *     rgblight_disable();
 *   }
 * } */
