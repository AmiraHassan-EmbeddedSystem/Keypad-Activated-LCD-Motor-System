#include "ecu_keypad.h"

static const uint8 keypad_matrix[KEYPAD_MAX_ROW][KEYPAD_MAX_COLUMN] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'},
};

Std_ReturnType Keypad_initialize(const keypad_t *_keypad)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _keypad){
        ret = E_NOT_OK;
    }
    else{
        ret = E_OK;
        uint8 L_counter_row = 0, L_counter_col = 0;
        
        for(L_counter_row = 0; L_counter_row < KEYPAD_MAX_ROW; L_counter_row++){
            ret &= gpio_pin_initialize(&(_keypad->keypad_row[L_counter_row]));
        }

        for(L_counter_col = 0; L_counter_col < KEYPAD_MAX_COLUMN; L_counter_col++){
            ret &= gpio_pin_initialize(&(_keypad->keypad_col[L_counter_col]));
        }
        
    }
    return ret;
}


Std_ReturnType Keypad_read_value(const keypad_t *_keypad, uint8 *value)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _keypad || NULL == value){
        ret = E_NOT_OK;
    }
    else{
        ret = E_OK;
        logic_t column_status = GPIO_LOW;
        uint8 L_counter_row = 0, L_counter_col = 0, L_counter = 0;
                
        for(L_counter_row = 0; L_counter_row < KEYPAD_MAX_ROW; L_counter_row++){
            
            for(L_counter = 0; L_counter < KEYPAD_MAX_ROW; L_counter++){
                ret &= gpio_pin_write_logic(&(_keypad->keypad_row[L_counter]), GPIO_LOW);
            }
            
//            for(L_counter_col = 0; L_counter_col < KEYPAD_MAX_COLUMN; L_counter_col++){
//                ret &= gpio_pin_write_logic(&(_keypad->keypad_col[L_counter_col]), GPIO_LOW);
//            }
            
            ret &= gpio_pin_write_logic(&(_keypad->keypad_row[L_counter_row]), GPIO_HIGH);
//            __delay_ms(20);

            for(L_counter_col = 0; L_counter_col < KEYPAD_MAX_COLUMN; L_counter_col++){
                ret &= gpio_pin_read_logic(&(_keypad->keypad_col[L_counter_col]), &column_status);

                if(GPIO_HIGH == column_status){
                    *value = keypad_matrix[L_counter_row][L_counter_col];
                }
            }
          }
        }  
    return ret;
}
