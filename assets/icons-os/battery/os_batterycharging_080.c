#include "lvgl/lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_CK_OS_BATTERYCHARGING_080
#define LV_ATTRIBUTE_IMG_CK_OS_BATTERYCHARGING_080
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_CK_OS_BATTERYCHARGING_080 uint8_t ck_os_batterycharging_080_map[] = {
  0x7c, 0xd2, 0x34, 0xff, 	/*Color of index 0*/
  0xe4, 0xe6, 0xe4, 0xff, 	/*Color of index 1*/
  0x6c, 0xfe, 0x6c, 0xff, 	/*Color of index 2*/
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 3*/

  0xaa, 0xa5, 0x55, 0x55, 0x5a, 0xaa, 0xaa, 
  0xaa, 0x95, 0x55, 0x55, 0x56, 0xaa, 0xaa, 
  0xaa, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 
  0xaa, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 
  0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 
  0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 
  0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 
  0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 
  0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0xaa, 
  0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0xaa, 
  0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0xaa, 
  0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0xaa, 
  0x55, 0xa0, 0x00, 0x00, 0x0a, 0x55, 0xaa, 
  0x55, 0xa0, 0x00, 0x00, 0x0a, 0x55, 0xaa, 
  0x55, 0xa0, 0x00, 0x00, 0x0a, 0xaa, 0xaa, 
  0x55, 0xa0, 0x00, 0x00, 0x0a, 0xaa, 0xaa, 
  0x55, 0xa0, 0x00, 0x00, 0x2a, 0x95, 0xaa, 
  0x55, 0xa0, 0x00, 0x00, 0xaa, 0x55, 0xaa, 
  0x55, 0xa0, 0x00, 0x02, 0xa9, 0x55, 0xaa, 
  0x55, 0xa0, 0x00, 0x0a, 0xa5, 0x56, 0xaa, 
  0x55, 0xa0, 0x00, 0x2a, 0x95, 0x56, 0xaa, 
  0x55, 0xa0, 0x00, 0xaa, 0x55, 0x5a, 0xaa, 
  0x55, 0xa0, 0x00, 0xa9, 0x55, 0x55, 0x55, 
  0x55, 0xa0, 0x00, 0xa5, 0x55, 0x55, 0x55, 
  0x55, 0xa0, 0x00, 0xa5, 0x55, 0x55, 0x55, 
  0x55, 0xa0, 0x00, 0xa5, 0x55, 0x55, 0x56, 
  0x55, 0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x5a, 
  0x55, 0xaa, 0xaa, 0xaa, 0xa9, 0x55, 0x6a, 
  0x55, 0x55, 0x55, 0x55, 0xa5, 0x55, 0xaa, 
  0x55, 0x55, 0x55, 0x55, 0xa5, 0x56, 0xaa, 
  0x55, 0x55, 0x55, 0x55, 0xa5, 0x5a, 0xaa, 
  0x55, 0x55, 0x55, 0x55, 0xa5, 0x6a, 0xaa, 
};

const lv_img_dsc_t ck_os_batterycharging_080 = {
  .header.always_zero = 0,
  .header.w = 28,
  .header.h = 32,
  .data_size = 240,
  .header.cf = LV_IMG_CF_INDEXED_2BIT,
  .data = ck_os_batterycharging_080_map,
};
