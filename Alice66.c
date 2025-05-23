/* Copyright 2025 Epomaker
 * Copyright 2025 Epomaker <https://github.com/Epomaker>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../lib/rdr_lib/rdr_common.h"

void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

led_config_t g_led_config = { {
	{ 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , 13       , NO_LED   , NO_LED    },
	{ 14       , 15       , 16       , 17       , 18       , 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , NO_LED    },
	{ 29       , 30       , 31       , 32       , 33       , 34       , 35       , 36       , 37       , 38       , 39       , 40       , NO_LED   , 41       , 42       , NO_LED    },
	{ 43       , 44       , 45       , 46       , 47       , 48       , 49       , 50       , 51       , 52       , 53       , 54       , NO_LED   , 55       , 56       , NO_LED    },
	{ 57       , 58       , 59       , NO_LED   , NO_LED   , 60       , NO_LED   , NO_LED   , NO_LED   , 61       , 62       , NO_LED   , NO_LED   , 63       , 64       , 65        }
}, {
    // "Fine-tuned" complex configuration
    { 14, 12},  { 28, 12},  { 42, 12},  { 56, 12},  { 70, 12},   { 84, 12},  { 98, 12},  { 112, 12}, { 126, 12}, { 140, 12}, { 154, 12}, { 168, 12}, { 182, 12}, { 196, 12},
    { 14, 24},  { 28, 24},  { 42, 24},  { 56, 24},  { 70, 24},   { 84, 24},  { 98, 24},  { 112, 24}, { 126, 24}, { 140, 24}, { 154, 24}, { 168, 24}, { 182, 24}, { 196, 24}, { 210, 24},
    { 14, 36},  { 28, 36},  { 42, 36},  { 56, 36},  { 70, 36},   { 84, 36},  { 98, 36},  { 112, 36}, { 126, 36}, { 140, 36}, { 154, 36}, { 168, 36},             { 196, 36}, { 210, 36},
    { 14, 48},  { 28, 48},  { 42, 48},  { 56, 48},  { 70, 48},   { 84, 48},  { 98, 48},  { 112, 48}, { 126, 48}, { 140, 48}, { 154, 48}, { 168, 48}, { 170, 48}, { 200, 48},
    { 14, 60},  { 28, 60},  { 42, 60},                           { 84, 60},                                      { 140, 60}, { 154, 60},             { 170, 60}, { 200, 60}, { 210, 60},

    { 225, 65}, { 225, 65}, { 225, 65}, { 225, 65}, { 225, 65},  { 225, 65}, { 225, 65},
    { 225, 65}, { 225, 65}, { 225, 65}, { 225, 65}, { 225, 65},  { 225, 65}, { 225, 65},
    { 225, 65}, { 225, 65}, { 225, 65}, { 225, 65}, { 225, 65},  { 225, 65}, { 225, 65}
}, {
	1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,
    1,  1,  1,          1,              1,  1,      1,  1,  1,

    0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();
    return false;
}

void notify_usb_device_state_change_user(enum usb_device_state usb_device_state)  {
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if(usb_device_state == USB_DEVICE_STATE_CONFIGURED) {
            Usb_If_Ok_Led = true;
        } else {
            Usb_If_Ok_Led = false;
        }
    } else {
        Usb_If_Ok_Led = false;
    }
}

void housekeeping_task_user(void) {
    es_chibios_user_idle_loop_hook();
    User_Keyboard_Reset();
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
    User_Keyboard_Post_Init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    Usb_Change_Mode_Delay = 0;
    Usb_Change_Mode_Wakeup = false;

    return User_process_record_user(keycode, record);
}
