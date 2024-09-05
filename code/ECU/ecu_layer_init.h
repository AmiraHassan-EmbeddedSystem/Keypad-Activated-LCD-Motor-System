/* 
 * File:   ecu_layer_init.h
 * Author: ah427
 *
 * Created on 29 ?????, 2024, 06:25 ?
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

/* SECTION: Include */
#include "KEYPAD/ecu_keypad.h"
#include "LED/led.h"
#include "LCD/ecu_lcd.h"
#include "Relay/ecu_relay.h"
/* SECTION: Macro Declarations */
#define _XTAL_FREQ 80000000UL

/* SECTION: Macro Function Declarations */
/* SECTION: Data Type Declarations */
/* SECTION: Interface Function Declarations */
void ecu_initialize(void);
#endif	/* ECU_LAYER_INIT_H */

