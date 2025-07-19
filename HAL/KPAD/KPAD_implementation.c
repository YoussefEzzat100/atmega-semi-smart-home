#include "KPAD_interface.h"
#include "KPAD_config.h"
#include <util/delay.h>

const char keypad_key[4][4] = KPAD_KEYS;
const char keypad_rows[4] = {ROW_1, ROW_2, ROW_3, ROW_4};
const char keypad_columns[4] = {COL_1, COL_2, COL_3, COL_4};

void KPAD_INIT()
{
    // Set rows as OUTPUT
    DIO_set_pin_direction(KEYPAD_PORT, ROW_1, OUTPUT);
    DIO_set_pin_direction(KEYPAD_PORT, ROW_2, OUTPUT);
    DIO_set_pin_direction(KEYPAD_PORT, ROW_3, OUTPUT);
    DIO_set_pin_direction(KEYPAD_PORT, ROW_4, OUTPUT);

    // Set columns as INPUT
    DIO_set_pin_direction(KEYPAD_PORT, COL_1, INPUT);
    DIO_set_pin_direction(KEYPAD_PORT, COL_2, INPUT);
    DIO_set_pin_direction(KEYPAD_PORT, COL_3, INPUT);
    DIO_set_pin_direction(KEYPAD_PORT, COL_4, INPUT);

    // Enable internal pull-up resistors on columns
    DIO_set_pin_value(KEYPAD_PORT, COL_1, HIGH);
    DIO_set_pin_value(KEYPAD_PORT, COL_2, HIGH);
    DIO_set_pin_value(KEYPAD_PORT, COL_3, HIGH);
    DIO_set_pin_value(KEYPAD_PORT, COL_4, HIGH);
}

unsigned char KPAD_GET_PRESS_VALUE()
{
    unsigned char local_column, local_row;
    unsigned char flag = 0;
    unsigned char value = KPD_NOT_PRESSED;

    for (local_row = 0; local_row < 4; local_row++)
    {
        // Set all rows HIGH before pulling one LOW
        DIO_set_pin_value(KEYPAD_PORT, ROW_1, HIGH);
        DIO_set_pin_value(KEYPAD_PORT, ROW_2, HIGH);
        DIO_set_pin_value(KEYPAD_PORT, ROW_3, HIGH);
        DIO_set_pin_value(KEYPAD_PORT, ROW_4, HIGH);

        // Pull the current row LOW
        DIO_set_pin_value(KEYPAD_PORT, keypad_rows[local_row], LOW);

        for (local_column = 0; local_column < 4; local_column++)
        {
            if ((DIO_get_pin_value(KEYPAD_PORT, keypad_columns[local_column])) == 0)
            {
                _delay_ms(20);  // Debouncing
                while ((DIO_get_pin_value(KEYPAD_PORT, keypad_columns[local_column])) == 0);
                value = keypad_key[local_row][local_column];
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            break;
        }
    }

    return value;
}