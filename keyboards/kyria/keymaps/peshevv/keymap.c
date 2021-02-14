/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.1
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <string.h>
#include <stdio.h>


enum layers {
    _MAC,
    _QWERTY,
    _NUM,
    _NAV,
    _GAME,
    _GAMERAISE,
	

};

enum custom_keycodes {
  SBKSP,
  PgBck = SAFE_RANGE,
  PgFwd,
  SCRTGL, // Scroll Toggle
  Snip
};

// Combo Initialization
 enum combos {
     CAP_LOCK
 };
 const uint16_t PROGMEM capslock_combo[] = {KC_SPC, KC_BSPC, COMBO_END};

 combo_t key_combos[COMBO_COUNT] = {COMBO(capslock_combo, KC_CAPS)};


#define RAISE LT(_NUM, KC_DEL)
#define LOWER LT(_NAV, KC_ENT)
#define HOME_D LSFT_T(KC_D)
#define HOME_K RSFT_T(KC_K)
#define GAME TO(_GAME)
#define GRAISE MO(_GAMERAISE)
#define WinOS TO(_QWERTY)
#define MacOS TO(_MAC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* This is at est
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  TAB   |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  CTRL  |   Z  |   X  |   C  |   V  |   B  | SHIFT| Ins  |  |PrntSc| Del  |   N  |   M  | ,  < | . >  | /  ? | RCTRL  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |SCRTGL| GUI  | ALT  |ShftBk| Enter|  | Bspc | Space| GUI  | ALT  | F13  |
 *                        |      |      |      |      | Nav  |  | Num  |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
*/
    [_QWERTY] = LAYOUT(
      KC_ESC,  KC_Q, KC_W,  KC_E,   KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,   KC_O,     KC_P, KC_BSLASH,
      KC_TAB,  KC_A, KC_S,HOME_D,   KC_F,    KC_G,                                          KC_H,    KC_J,  HOME_K,   KC_L,  KC_SCLN,   KC_QUOT,
      KC_LCTL, KC_Z, KC_X,  KC_C,   KC_V,    KC_B, KC_LSFT, KC_INS,     KC_PSCR, KC_DEL,    KC_N,    KC_M, KC_COMM, KC_DOT,  KC_SLSH,   KC_RCTL,
                         SCRTGL, KC_LGUI, KC_LALT,  KC_SPC,  LOWER,       RAISE,KC_BSPC, KC_RALT, KC_LGUI,  KC_F13
    ),

/* This is at est
 * Base Layer: MAC
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  TAB   |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  CTRL  |   Z  |   X  |   C  |   V  |   B  | SHIFT| Ins  |  |PrntSc| Del  |   N  |   M  | ,  < | . >  | /  ? | RCTRL  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |SCRTGL| GUI  | ALT  |ShftBk| Enter|  | Bspc | Space| GUI  | ALT  | F13  |
 *                        |      |      |      |      | Nav  |  | Num  |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
*/
    [_MAC] = LAYOUT(
      KC_ESC,  KC_Q, KC_W,  KC_E,   KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,   KC_O,     KC_P, KC_BSLASH,
      KC_TAB,  KC_A, KC_S,HOME_D,   KC_F,    KC_G,                                          KC_H,    KC_J,  HOME_K,   KC_L,  KC_SCLN,   KC_QUOT,
      KC_LOPT, KC_Z, KC_X,  KC_C,   KC_V,    KC_B, KC_LSFT, KC_INS,     KC_PSCR, KC_DEL,    KC_N,    KC_M, KC_COMM, KC_DOT,  KC_SLSH,   KC_ROPT,
                         SCRTGL, KC_LCTL, KC_LCMD,  KC_SPC,  LOWER,       RAISE,KC_BSPC, KC_RCMD, KC_RCTL,  KC_F13
    ),
    
/*
 * Lower Layer: NUM/symb
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |    |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   $  |   +  |   (  |   )  |   @  |                              |   ^  |   -  |   =  |   _  |   *  |    \   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   !  |   #  |   {  |   }  |   ~  |      |      |  |      |      |   &  |   [  |   ]  |   %  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PIPE,
    _______,  KC_DLR, KC_PLUS, KC_LPRN, KC_RPRN,   KC_AT,                                         KC_CIRC, KC_MINS,  KC_EQL, KC_UNDS, KC_ASTR, KC_BSLS,
    _______, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD,   WinOS,   MacOS,        Snip, _______, KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, _______, _______,
                               KC_MUTE, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

/*
 * NAV Layer: Arrow Keys, Media, Page
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |TabBk |TabNx |      |                              |      |      |  MUp |      |EEPROM|        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |Left | Down |  Up  | Right|       |                              |      |MLeft |MDown |MRight|MB1   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------' *
 */
    [_NAV] = LAYOUT(
      _______, _______,   PgBck,   PgFwd, _______, _______,                                           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
      _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSPC,                                           KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                    GAME, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

 /*
  * GAME Layer: Gaming Layer
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |   1  |   2  |   3  |   4  |   5  |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |   D  |   S  |   W  |   D  |   E  |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_GAME] = LAYOUT(
       _______,    KC_1, KC_2,    KC_3,    KC_4,    KC_5,                                         _______, _______, _______, _______, _______, _______,
        KC_TAB,    KC_C, KC_Q,    KC_W,    KC_E,    KC_R,                                         _______, _______, _______, _______, _______, _______,
          KC_C, KC_LSFT, KC_A,    KC_S,    KC_D, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,  KC_SPC,  GRAISE,     _______, _______, _______, _______, _______
     ),

  /*
   * Layer template
   *
   * ,-------------------------------------------.                              ,-------------------------------------------.
   * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
   * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
   * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
   *                        |      |      |      |      |      |  |      |      |      |      |      |
   *                        |      |      |      |      |      |  |      |      |      |      |      |
   *                        `----------------------------------'  `----------------------------------'
   */
      [_GAMERAISE] = LAYOUT(
        _______,  KC_6,  KC_7,   KC_8,    KC_9,    KC_0,                                         _______, _______, _______, _______, _______, _______,
        _______, KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_F5,                                         _______, _______, _______, _______, _______, _______,
        _______, KC_F6, KC_F7,  KC_F8,   KC_F9,  KC_F10, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                          TO(_QWERTY), _______, _______, _______, _______,     _______, _______, _______, _______, _______
      ),


// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
//     ),
};

//layer_state_t layer_state_set_user(layer_state_t state) {
////    return update_tri_layer_state(state, _NUM, _NAV, _SPAN);
//}

// Custom Keycodes
bool bksp = false;
bool mouseScroll = true;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SBKSP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                bksp = true;
            }
            else {
                unregister_code(KC_LSFT);
                if (bksp) {
                    tap_code(KC_BSPC);
                }
            }
            return false;
            break;
        case PgFwd:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_PGDN)));
            }
            else { }
            return false;
            break;
        case PgBck:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_PGUP)));
            }
            else { }
            return false;
            break;
        case Snip:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LGUI("s")));
            }
            else { }
            return false;
            break;
        case SCRTGL:
            if (record->event.pressed) {
                if (mouseScroll) {
                    mouseScroll = false;
                } else {
                    mouseScroll = true;
                }
            }
            else { }
            return false;
            break;

    }
    bksp = false;
    return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

#define IDLE_FRAMES 5
#define ANIM_SIZE 764

static void render_anim(void) {
    static const char PROGMEM idle[ANIM_SIZE] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16,  8,  8,  4,  4,  4,  8, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24,100,130,  2,  2,  2,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 56,  4,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
        32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1,  0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8, 23,  0, 15,  1,  2,  1, 15,  0, 15,  2,  5,  8

    };
    oled_write_raw_P(idle, ANIM_SIZE);

}

static void render_status(void) {
    // QMK Logo and version information
//    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Windows\n"), false);
            break;
        case _MAC:
            oled_write_P(PSTR("Mac\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
    
    oled_write_P(PSTR("Scroll: "), false);
    if (mouseScroll) {
        oled_write_P(PSTR("Mouse\n"), false);
    } else {
        oled_write_P(PSTR("Arrow\n"), false);
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
//        render_kyria_logo();
        render_anim();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(_NUM)) {
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (mouseScroll) {
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        } else {
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code16(C(KC_PGDN));
        } else {
            tap_code16(C(KC_PGUP));
        }
    }
}
#endif

