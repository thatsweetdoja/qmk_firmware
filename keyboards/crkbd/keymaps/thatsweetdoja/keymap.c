#include QMK_KEYBOARD_H
#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"
#include "color.h"
#include "print.h"


enum layer_names {
    _BASE,
    _SYM,
    _NUM,
	 _NAV,
    _ADJ
};

enum custom_keycodes {
  TB_SCR = SAFE_RANGE, //set trackball scrolling mode
};

#define SYM     LT(_SYM, KC_SPACE)
#define NUM     LT(_NUM, KC_TAB)
#define ADJGUI  LT(_ADJ, KC_LGUI)
#define CTLTAB  LCTL_T(KC_TAB)
#define CTLCAP  LCTL_T(KC_CAPS)
#define SFTBSPC RSFT_T(KC_BSPC)
#define G_SLSH  LGUI_T(KC_SLSH)
#define A_DOT   LALT_T(KC_DOT)
#define LCTLSFT LCTL(KC_LSFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CTLTAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M,    KC_COMM, A_DOT,   G_SLSH,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         ADJGUI,  SYM,     NUM,        SFTBSPC, KC_SPC,  KC_SCLN
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3(   
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GESC, KC_0,    KC_6,    KC_7,    KC_8,    KC_9,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CTLTAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_COMM, A_DOT,   G_SLSH,   KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, _______,    _______, _______,  _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GESC, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_BSPC,                      KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CTLCAP,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENTER,                     KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, LCTLSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, _______, XXXXXXX,    _______, _______,  _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GESC, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_BSPC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CTLTAB,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENTER,                     TB_SCR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, _______,    _______, _______,  _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJ] = LAYOUT_split_3x6_3(
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


#ifndef MIN
#    define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
uint8_t tb_hue, tb_sat;
int8_t tb_precision_speed = 3;
bool tb_rgb_control = false, tb_set_scrolling = false, tb_rgb_changed = false;

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
   
   if (mouse_report.x | mouse_report.y | mouse_report.buttons) {
      if(tb_rgb_control) {           //rgb control mode (up/down hue, left/right sat)
         tb_rgb_changed = true;
         if(mouse_report.x) {
            if(mouse_report.x > 0) {
               if(tb_sat < 255) tb_sat++;
            } else {
               if(tb_sat > 0) tb_sat--;
            }
            mouse_report.x = 0;
         }
         if(mouse_report.y) {
            tb_hue = (tb_hue + ((mouse_report.y > 0) ? 1 : -1)) % 255;
            mouse_report.y = 0;
         }
         trackball_set_hsv(tb_hue, tb_sat, 255);
         if(mouse_report.buttons) {
            rgblight_sethsv(tb_hue, tb_sat, rgblight_get_val());
            mouse_report.buttons = 0;
         }
      } else if(IS_LAYER_ON(_NUM)) { //precision mode (slow pointer speed)
         if(mouse_report.x) {
            mouse_report.x = (mouse_report.x > 0) ? tb_precision_speed : -tb_precision_speed;
         }
         if(mouse_report.y) {
            mouse_report.y = (mouse_report.y > 0) ? tb_precision_speed : -tb_precision_speed;
         }
      } else if(IS_LAYER_ON(_SYM)) { //scroll mode
         mouse_report.x = 0;
         if(mouse_report.y) {
            mouse_report.v = (mouse_report.y > 0) ? 1 : -1;
            mouse_report.y = 0;
         }
      }
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


void keyboard_post_init_user(void) {
   #ifdef PIMORONI_TRACKBALL_ENABLE
      tb_hue = rgblight_get_hue();
      tb_sat = rgblight_get_sat();
      trackball_sync_led();
      pointing_device_set_cpi(35000);
   #endif
}

//uint8_t layer_hue_offset = 40;
//uint8_t min_layer_sat = 255;
//uint8_t base_hue;
layer_state_t layer_state_set_user(layer_state_t state) {
//   uint8_t sat = rgblight_get_sat();
//   uint8_t val = rgblight_get_val();
//
//   if(get_highest_layer(state) == _ADJ) {
//      rgblight_sethsv(base_hue, sat, val);
//   } else {
//      rgblight_sethsv_noeeprom(base_hue + (layer_hue_offset * get_highest_layer(state)) % 255,
//         MIN(min_layer_sat, sat), val);
//   }
   #ifdef PIMORONI_TRACKBALL_ENABLE
      if(IS_LAYER_ON_STATE(state, _ADJ)) {
         tb_rgb_control = true;
      } else if(tb_rgb_changed) {
         tb_rgb_control = false;
         trackball_sync_led();
         tb_rgb_changed = false;  
      }
   #endif
   return state;                       
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   uint8_t mod_state = get_mods();
   switch (keycode) {
      case TB_SCR:
         if (record->event.pressed) {
            tb_set_scrolling = !tb_set_scrolling;
         } 
         break;       
      case KC_BSPC: {
            static bool delkey_registered;
            if (record->event.pressed) {
               if (mod_state & MOD_MASK_SHIFT) {
                  del_mods(MOD_MASK_SHIFT);
                  register_code(KC_DEL);
                  delkey_registered = true;
                  set_mods(mod_state);
                  return false;
               }
            } else {
               if (delkey_registered) {
                  unregister_code(KC_DEL);
                  delkey_registered = false;
                  return false;
               }
            }
            return true;
      }
      case RGB_HUI:
         if(!record->event.pressed) {
            //base_hue = rgblight_get_hue(); // on key release, update base hue
            #ifdef PIMORONI_TRACKBALL_ENABLE
               trackball_sync_led();
            #endif
         }
         return true;
      case RGB_HUD:
         if(!record->event.pressed) {
            //base_hue = rgblight_get_hue();
            #ifdef PIMORONI_TRACKBALL_ENABLE
               trackball_sync_led();
            #endif
         }
         return true;
      case KC_LGUI:
         if(record->event.pressed) {
            #ifdef PIMORONI_TRACKBALL_ENABLE
               tb_rgb_control = true;
            #endif
         } else {
            #ifdef PIMORONI_TRACKBALL_ENABLE
               tb_rgb_control = false;
               trackball_sync_led();
               if(tb_rgb_changed) {
                  unregister_mods(MOD_MASK_GUI);
                  tb_rgb_changed = false;
                  return false;
               }
            #endif
         }
         return true;
      default:
         return true; // Process all other keycodes normally
   }
   return true;
}

