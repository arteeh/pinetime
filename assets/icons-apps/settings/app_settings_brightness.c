#include "lvgl/lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_APP_SETTINGS_BRIGHTNESS
#define LV_ATTRIBUTE_IMG_APP_SETTINGS_BRIGHTNESS
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_APP_SETTINGS_BRIGHTNESS uint8_t app_settings_brightness_map[] = {
  0x6c, 0xfe, 0x6c, 0xff, 	/*Color of index 0*/
  0xe4, 0xe6, 0xe4, 0xff, 	/*Color of index 1*/

  0x00, 0x03, 0xc0, 0x00, 
  0x00, 0x03, 0xc0, 0x00, 
  0x00, 0x03, 0xc0, 0x00, 
  0x00, 0x03, 0xc0, 0x00, 
  0x06, 0x03, 0xc0, 0x60, 
  0x0f, 0x03, 0xc0, 0xf0, 
  0x0f, 0x80, 0x01, 0xf0, 
  0x07, 0xc0, 0x03, 0xe0, 
  0x03, 0x87, 0xe1, 0xc0, 
  0x01, 0x1f, 0xf8, 0x80, 
  0x00, 0x3f, 0xfc, 0x00, 
  0x00, 0x7f, 0xfe, 0x00, 
  0x00, 0x7c, 0x3e, 0x00, 
  0x00, 0xf8, 0x1f, 0x00, 
  0xfc, 0xf0, 0x0f, 0x3f, 
  0xfc, 0xf0, 0x0f, 0x3f, 
  0xfc, 0xf0, 0x0f, 0x3f, 
  0xfc, 0xf0, 0x0f, 0x3f, 
  0x00, 0xf8, 0x1f, 0x00, 
  0x00, 0x7c, 0x3e, 0x00, 
  0x00, 0x7f, 0xfe, 0x00, 
  0x00, 0x3f, 0xfc, 0x00, 
  0x01, 0x1f, 0xf8, 0x80, 
  0x03, 0x87, 0xe1, 0xc0, 
  0x07, 0xc0, 0x03, 0xe0, 
  0x0f, 0x80, 0x01, 0xf0, 
  0x0f, 0x03, 0xc0, 0xf0, 
  0x06, 0x03, 0xc0, 0x60, 
  0x00, 0x03, 0xc0, 0x00, 
  0x00, 0x03, 0xc0, 0x00, 
  0x00, 0x03, 0xc0, 0x00, 
  0x00, 0x03, 0xc0, 0x00, 
};

const lv_img_dsc_t app_settings_brightness = {
  .header.always_zero = 0,
  .header.w = 32,
  .header.h = 32,
  .data_size = 136,
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .data = app_settings_brightness_map,
};
