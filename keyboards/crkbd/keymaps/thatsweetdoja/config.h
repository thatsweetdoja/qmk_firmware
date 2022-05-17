/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/*
#define VIAL_KEYBOARD_UID {0x3B, 0x6B, 0xA0, 0x29, 0x80, 0x56, 0xED, 0xD1}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
#define DYNAMIC_KEYMAP_LAYER_COUNT 3
*/

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define PIMORONI_TRACKBALL_ENABLE
#define PIMORONI_TRACKBALL_CLICK
// orientation pimoroni text on top and trackball text at the bottom
#define PIMORONI_TRACKBALL_ROTATE
#define PIMORONI_TRACKBALL_SCALE

//#define OLED_TIMEOUT 0
//#define SPLIT_WPM_ENABLE
//#define SPLIT_MODS_ENABLE
//#define SPLIT_WPM_ENABLE
//#define SPLIT_OLED_ENABLE

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 165
#define IGNORE_MOD_TAP_INTERRUPT

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

/* Select hand configuration */

//#define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2
#ifdef RGBLIGHT_ENABLE
#    undef  RGBLED_ANIM
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_EFFECT_TWINKLE_LIFE 500
#    undef  RGBLED_NUM
#    define RGBLED_NUM 54
#    undef  RGBLED_SPLIT
#    define RGBLED_SPLIT \
        { 27, 27 }
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP  17
#    define RGBLIGHT_SAT_STEP  17
#    define RGBLIGHT_VAL_STEP  17
#endif

