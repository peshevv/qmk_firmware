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
    _QWERTY,
    _NUM,
    _NAV,
    _GAME,
    _FUNC

};

enum custom_keycodes {
  SBKSP,
  PgBck = SAFE_RANGE,
  PgFwd,
  SCRTGL // Scroll Toggle
};

#define RAISE LT(_NUM, KC_ENT)
#define LOWER LT(_NAV, KC_ENT)
#define NAV_TB LT(_NAV, KC_TAB)
#define NAV_A LT(_NAV, KC_A)
#define GAME TG(_GAME)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* This is at est
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  TAB   |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  CTRL  |   Z  |   X  |   C  |   V  |   B  | SHIFT| GAME |  | Home | Del  |   N  |   M  | ,  < | . >  | /  ? | RCTRL  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | XXXX | GUI  | ALT  |ShftBk| Enter|  | Bspc | Space| GUI  | ALT  | XXXX |
 *                        |      |      |      |      | Nav  |  | Num  |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
*/
    [_QWERTY] = LAYOUT(
      KC_ESC,  KC_Q, KC_W,  KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,   KC_O,     KC_P, KC_BSLASH,
      KC_TAB,  KC_A, KC_S,  KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,   KC_L,  KC_SCLN,   KC_QUOT,
      KC_LCTL, KC_Z, KC_X,  KC_C,    KC_V,    KC_B, KC_LSFT, KC_INS,    KC_HOME, KC_DEL,    KC_N,    KC_M, KC_COMM, KC_DOT,  KC_SLSH,   KC_RCTL,
                         SCRTGL, KC_LGUI, KC_LALT,  KC_SPC,  LOWER,      RAISE,  SBKSP, KC_RALT, KC_LGUI,  KC_F13
    ),
/*
 * Lower Layer: NUM/symb
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   $  |   +  |   (  |   )  |   @  |                              |   ^  |   -  |   =  |   _  |   *  |    \   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   !  |   #  |   {  |   }  |   ~  |      |      |  |      |      |   &  |   [  |   ]  |   %  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
	[_NUM] = LAYOUT(
	 KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PIPE,
	_______,  KC_DLR, KC_PLUS, KC_LPRN, KC_RPRN,   KC_AT,                                         KC_CIRC, KC_MINS,  KC_EQL, KC_UNDS, KC_ASTR, KC_BSLS,
	_______, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD, _______, _______,     _______, _______, KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, _______, _______,
							   KC_MUTE, _______, _______, _______, _______,     _______, _______, _______, _______, _______
	),

/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      | RESET|EEPROM| DEBUG  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | F12    | F1   | F2   | F3   | F4   | F5   |                              | F6   | F7   | F8   | F9   | F10  | F11    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | SHIFT  | TOG  | HUI  | SAI  | VAI  | MOD  |      |      |  |      |      |      |Pause |PrevTr|NextTr|      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNC] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                         _______, _______, _______,   RESET, EEP_RST,   DEBUG,
       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
      KC_LSFT, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, _______,    GAME,     _______, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
                                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
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
                                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
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
       KC_HOME,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         _______, _______, _______, _______, _______, _______,
       _______,    KC_A,    KC_S,    KC_W,    KC_D,    KC_E,                                         _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
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
//       _______, _______, 00000_______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _NAV, _FUNC);
}

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

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

//static void render_qmk_logo(void) {
//  static const char PROGMEM qmk_logo[] = {
//    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
//
//  oled_write_P(qmk_logo, false);
//}

static void render_status(void) {
    // QMK Logo and version information
//    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Fn\n"), false);
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

    // Host Keyboard LED Status
//    uint8_t led_usb_state = host_keyboard_leds();
//    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
//    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
//    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

//Render-HSV Code Start

//void write_int_to_string(char* ref, uint8_t wpm) {
//    // Words per minute is just assumed to remain under a thousand.
//    char wpm_string[4];
//    itoa(wpm, wpm_string, 10);
//    strcat(ref, wpm_string);
//}
//
//void oled_write_with_int(char* str, uint8_t number) {
//    write_int_to_string(str, number);
//    oled_write_ln(str, false);
//}
//
//static void render_hsv(void) {
//    char hue[32] = "HUE:    ";
//    oled_write_with_int(hue, rgblight_get_hue());
//
//    char sat[32] = "SAT:    ";
//    oled_write_with_int(sat, rgblight_get_sat());

//
//    char val[32] = "VAL:    ";
//    oled_write_with_int(val, rgblight_get_val());
//}

//Render-HSV Code End
void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
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

//void keyboard_post_init_user(void) {
//    rgblight_enable();
//    rgblight_sethsv(16,16,150);
//}
