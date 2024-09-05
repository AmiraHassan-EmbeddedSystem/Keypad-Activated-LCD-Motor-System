/*
 * File:   project.c
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41 ?
 */


#include <xc.h>
#include <builtins.h>
#include "project.h"
#define _XTAL_FREQ 80000000UL

void initialization(void);

uint8 keypad_value = 0;
uint8 secret_value = '8';

void main(void) {
    initialization();
    while(1){
        Keypad_read_value(&keypad, &keypad_value);
        if(keypad_value == secret_value){
            led_turn_off(&led_wrong);
            led_turn_on(&led_correct); 
            Relay_Turn_On(&relay);
            
            lcd_8bit_send_string_pos(&lcd, "PASSWORD", 2, 1);
            lcd_8bit_send_string_pos(&lcd, "IS", 2, 10);
            lcd_8bit_send_string_pos(&lcd, "CORRECT", 2, 13);
            lcd_8bit_send_command(&lcd, LCD_SHIFT_RIGHT);
            __delay_ms(15);
            lcd_8bit_send_command(&lcd, LCD_SHIFT_LEFT);
            __delay_ms(15);        
            
        }
        else if(keypad_value == 0){
            
        }
        else{
            led_turn_off(&led_correct);
            led_turn_on(&led_wrong); 
            Relay_Turn_Off(&relay);
            
            lcd_8bit_send_string_pos(&lcd, "   ", 2, 17);
            lcd_8bit_send_string_pos(&lcd, "PASSWORD", 2, 1);
            lcd_8bit_send_string_pos(&lcd, "IS", 2, 10);
            lcd_8bit_send_string_pos(&lcd, "WRONG", 2, 13);
            lcd_8bit_send_command(&lcd, LCD_SHIFT_RIGHT);
            __delay_ms(15);
            lcd_8bit_send_command(&lcd, LCD_SHIFT_LEFT);
            __delay_ms(15);
        }
        
//        led_turn_on(&led_red1);
//        led_turn_on(&led_red2);
//                    led_turn_on(&led_yellow1);
//            led_turn_on(&led_yellow2); 
       
        
    }
    
    return;
}

void initialization(void){
    ecu_initialize();
}
