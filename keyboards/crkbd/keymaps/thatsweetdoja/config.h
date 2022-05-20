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

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define MASTER_LEFT
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_MAX_CONNECTION_ERRORS 10
#define PIMORONI_TRACKBALL_ENABLE
#define POINTING_DEVICE_ROTATION_90

#define PIMORONI_SLAVE_SIDE
#ifdef  PIMORONI_SLAVE_SIDE
#   define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A
#   define SPLIT_POINTING_ENABLE
#   define POINTING_DEVICE_RIGHT
#   define RPC_M2S_BUFFER_SIZE 8
#endif

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 175
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define GRAVE_ESC_CTRL_OVERRIDE
#define TAPPING_TERM_PER_KEY

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

#define USE_SERIAL_PD2
#ifdef RGBLIGHT_ENABLE
#    undef  RGBLED_ANIM
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_EFFECT_TWINKLE_LIFE 175
#    define RGBLIGHT_EFFECT_TWINKLE_PROBABILITY 1/2
#    undef  RGBLED_NUM
#    define RGBLED_NUM 54
#    undef  RGBLED_SPLIT
#    define RGBLED_SPLIT \
        { 27, 27 }
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP  10
#    define RGBLIGHT_SAT_STEP  17
#    define RGBLIGHT_VAL_STEP  17
#endif