#include "ecu_layer_init.h"

keypad_t keypad = {
    .keypad_row[0].Direction = GPIO_OUTPUT,
    .keypad_row[0].Logic = GPIO_LOW,
    .keypad_row[0].Port = GPIO_PORTC,
    .keypad_row[0].Pin = GPIO_PIN0,
    
    .keypad_row[1].Direction = GPIO_OUTPUT,
    .keypad_row[1].Logic = GPIO_LOW,
    .keypad_row[1].Port = GPIO_PORTC,
    .keypad_row[1].Pin = GPIO_PIN1,
    
    .keypad_row[2].Direction = GPIO_OUTPUT,
    .keypad_row[2].Logic = GPIO_LOW,
    .keypad_row[2].Port = GPIO_PORTC,
    .keypad_row[2].Pin = GPIO_PIN2,
    
    .keypad_row[3].Direction = GPIO_OUTPUT,
    .keypad_row[3].Logic = GPIO_LOW,
    .keypad_row[3].Port = GPIO_PORTC,
    .keypad_row[3].Pin = GPIO_PIN3,
    
    .keypad_col[0].Direction = GPIO_INPUT,
    .keypad_col[0].Logic = GPIO_LOW,
    .keypad_col[0].Port = GPIO_PORTC,
    .keypad_col[0].Pin = GPIO_PIN4,
    
    .keypad_col[1].Direction = GPIO_INPUT,
    .keypad_col[1].Logic = GPIO_LOW,
    .keypad_col[1].Port = GPIO_PORTC,
    .keypad_col[1].Pin = GPIO_PIN5,
    
    .keypad_col[2].Direction = GPIO_INPUT,
    .keypad_col[2].Logic = GPIO_LOW,
    .keypad_col[2].Port = GPIO_PORTC,
    .keypad_col[2].Pin = GPIO_PIN6,
    
    .keypad_col[3].Direction = GPIO_INPUT,
    .keypad_col[3].Logic = GPIO_LOW,
    .keypad_col[3].Port = GPIO_PORTC,
    .keypad_col[3].Pin = GPIO_PIN7,
};

led_t led_wrong = {
    .port_name = GPIO_PORTD,
    .pin = GPIO_PIN0,
    .led_status = LED_OFF
};

led_t led_correct = {
    .port_name = GPIO_PORTD,
    .pin = GPIO_PIN1,
    .led_status = LED_OFF
};

lcd_8bit_mode lcd = {
    .rs.Direction = GPIO_OUTPUT,
    .rs.Logic = GPIO_LOW,
    .rs.Port = GPIO_PORTD,
    .rs.Pin = GPIO_PIN3,
    
    .en.Direction = GPIO_OUTPUT,
    .en.Logic = GPIO_LOW,
    .en.Port = GPIO_PORTD,
    .en.Pin = GPIO_PIN4,
    
    .data[0].Direction = GPIO_OUTPUT,
    .data[0].Logic = GPIO_LOW,
    .data[0].Port = GPIO_PORTB,
    .data[0].Pin = GPIO_PIN0,
    
    .data[1].Direction = GPIO_OUTPUT,
    .data[1].Logic = GPIO_LOW,
    .data[1].Port = GPIO_PORTB,
    .data[1].Pin = GPIO_PIN1,
    
    .data[2].Direction = GPIO_OUTPUT,
    .data[2].Logic = GPIO_LOW,
    .data[2].Port = GPIO_PORTB,
    .data[2].Pin = GPIO_PIN2,
    
    .data[3].Direction = GPIO_OUTPUT,
    .data[3].Logic = GPIO_LOW,
    .data[3].Port = GPIO_PORTB,
    .data[3].Pin = GPIO_PIN3,
    
    .data[4].Direction = GPIO_OUTPUT,
    .data[4].Logic = GPIO_LOW,
    .data[4].Port = GPIO_PORTB,
    .data[4].Pin = GPIO_PIN4,
    
    .data[5].Direction = GPIO_OUTPUT,
    .data[5].Logic = GPIO_LOW,
    .data[5].Port = GPIO_PORTB,
    .data[5].Pin = GPIO_PIN5,
    
    .data[6].Direction = GPIO_OUTPUT,
    .data[6].Logic = GPIO_LOW,
    .data[6].Port = GPIO_PORTB,
    .data[6].Pin = GPIO_PIN6,
    
    .data[7].Direction = GPIO_OUTPUT,
    .data[7].Logic = GPIO_LOW,
    .data[7].Port = GPIO_PORTB,
    .data[7].Pin = GPIO_PIN7,
    
};

Relay_t relay = { 
    .Port = GPIO_PORTD, 
    .Pin = GPIO_PIN2, 
    .Status = RELAY_TURN_OFF
};

void ecu_initialize(void){
    Keypad_initialize(&keypad);
    
    led_initialize(&led_wrong);
    led_initialize(&led_correct);
    lcd_8bit_initialize(&lcd);
    Relay_initialize(&relay);

}
