#include QMK_KEYBOARD_H
#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"
#include "color.h"
#include "print.h"


enum layer_names {
    _BASE,
    _LOWER,
	 _RAISE,
    _ADJUST
};

#define LOWER   LT(_LOWER, KC_SPACE)
#define RAISE   LT(_RAISE, KC_TAB)
#define ADJUST  LT(_ADJUST, KC_SPACE)
#define CTLTAB  LCTL_T(KC_TAB)
#define SFTBSPC LSFT_T(KC_BSPC)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CTLTAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SFTENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI, LOWER,   RAISE,      SFTBSPC, KC_SPC,  KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GESC, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                      XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_CAPS,  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                     XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, _______, XXXXXXX,    _______, ADJUST,  _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CTLTAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,                      KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, _______,    _______, ADJUST,  _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_P, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_TW,RGB_TOG,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

bool set_scrolling = false;

#ifndef MIN
#    define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
void trackball_set_hsv(uint8_t hue, uint8_t sat, uint8_t brightness) {
    RGB rgb = hsv_to_rgb((HSV){hue, sat, brightness});
    uint8_t white = MIN(rgb.r, MIN(rgb.g, rgb.b));
    rgb.r -= white;
    rgb.g -= white;
    rgb.b -= white;

    pimoroni_trackball_set_rgbw(rgb.r, rgb.g, rgb.b, white);
}

void trackball_sync_led(void) {
   #ifdef PIMORONI_TRACKBALL_ENABLE
      trackball_set_hsv(rgblight_get_hue(), rgblight_get_sat(), 255);
   #endif
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
   #ifdef CONSOLE_ENABLE
      if (mouse_report.x | mouse_report.y) {
         uprintf("\n%d %d", mouse_report.x, mouse_report.y);
      }
   #endif 

   if(set_scrolling) {
      if (mouse_report.x > 0) {
         mouse_report.h = 1;
      } else if (mouse_report.x < 0) {
         mouse_report.h = -1;
      } else {
         mouse_report.h = 0;
      }

      if (mouse_report.y > 0) {
         mouse_report.v = 1;
      } else if (mouse_report.y < 0) {
         mouse_report.v = -1;
      } else {
         mouse_report.v = 0;
      }

      mouse_report.x = 0;
      mouse_report.y = 0;
   }
   return mouse_report;
}
#endif //PIMORONI_TRACKBALL_ENABLE

#ifdef OLED_ENABLE
void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
   if(!is_keyboard_master()) {
      oled_render_logo();
   }
   return false;
}
#endif //OLED_ENABLE

uint8_t layer_hue_offset = -80;
uint8_t min_layer_sat = 255;
uint8_t base_hue;
void keyboard_post_init_user(void) {
   base_hue = rgblight_get_hue();
   #ifdef PIMORONI_TRACKBALL_ENABLE
      pointing_device_set_cpi(40000);
      trackball_sync_led();
   #endif
   debug_enable=true;
   print("x : y");
}

layer_state_t layer_state_set_user(layer_state_t state) {
   
   rgblight_sethsv_noeeprom(base_hue + (layer_hue_offset * get_highest_layer(state)) % 255,
      MIN(min_layer_sat, rgblight_get_sat()),
      rgblight_get_val()
   );

   #ifdef PIMORONI_TRACKBALL_ENABLE
      trackball_sync_led();
   #endif
   
   return state;                       
}
   
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if(get_mods() & MOD_MASK_SHIFT) {
      set_scrolling = true;
   } else {
      if(set_scrolling) set_scrolling = false;
   }
   return true;
}

//uint8_t pointing_device_handle_buttons(uint8_t buttons, bool pressed, pointing_device_buttons_t button) {//

//}