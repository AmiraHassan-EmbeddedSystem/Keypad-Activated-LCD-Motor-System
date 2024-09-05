/* 
 * File:   ecu_keypad.h
 * Author: ah427
 *
 * Created on 29 ?????, 2024, 06:04 ?
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* SECTION: Include */
#include "../../MCAL/GPIO/hal_gpio.h"

/* SECTION: Macro Declarations */
#define KEYPAD_MAX_ROW      4
#define KEYPAD_MAX_COLUMN   4

/* SECTION: Macro Function Declarations */
/* SECTION: Data Type Declarations */
typedef struct{
    pin_config_t keypad_row[KEYPAD_MAX_ROW];
    pin_config_t keypad_col[KEYPAD_MAX_COLUMN];
}keypad_t;

/* SECTION: Interface Function Declarations */
Std_ReturnType Keypad_initialize(const keypad_t *_keypad);
Std_ReturnType Keypad_read_value(const keypad_t *_keypad, uint8 *value);

#endif	/* ECU_KEYPAD_H */

