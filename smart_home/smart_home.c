#include <util/delay.h>
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"

unsigned short int LDR_READ;
unsigned short int LM_READ;
float light = 0;
float tempreature = 0;

// Simple function to convert number (0–255) to string and print with LCD_STR
void LCD_PRINT_NUMBER(unsigned char num)
{
    char str[4];
    str[0] = (num / 100) + '0';
    str[1] = ((num / 10) % 10) + '0';
    str[2] = (num % 10) + '0';
    str[3] = '\0';

    // Skip leading zeros
    if (str[0] == '0') {
        if (str[1] == '0') {
            LCD_STR(&str[2]);  // single digit
        } else {
            LCD_STR(&str[1]);  // two digits
        }
    } else {
        LCD_STR(str);          // full number
    }
}

int main()
{
    ADC_INIT();
    LCD_INIT(PORT_B, PORT_A, 5, 6, 7, 1);
    LCD_CLR();
    LCD_CMD(LCD_FORCE_CURSOR_1ST_LINE);
    LCD_STR("smart home sys");
    _delay_ms(1000);

    while (1)
    {
        ADC_CONVERT(PIN_1);
        _delay_us(20);
        LDR_READ = ADC_GET_READ();
        light = LDR_READ * 5.0 / 1023.0;
        
        ADC_CONVERT(PIN_0);
        _delay_us(20);
        LM_READ = ADC_GET_READ();
        tempreature = LM_READ * 500.0 / 1023.0; // Assuming LM35 gives 10mV/°C
        
        LCD_CLR();
        LCD_CMD(LCD_FORCE_CURSOR_1ST_LINE);
        LCD_STR("TEMP = ");
        
        // Cast float to integer and print
        unsigned char display_temp = (unsigned char)tempreature;
        LCD_PRINT_NUMBER(display_temp);
        LCD_STR(" C");
            
        LCD_CMD(LCD_FORCE_CURSOR_2ND_LINE);
        LCD_STR("LIGHT = ");
        
        unsigned char display_light = (unsigned char)(light * 100 / 5);  // % of light
        LCD_PRINT_NUMBER(display_light);
        LCD_STR(" percent");
        
        _delay_ms(1500);
        if (tempreature>50 || LDR_READ < 512)
        {
            DIO_set_pin_value(PORT_A,PIN_4,HIGH);
            DIO_set_pin_value(PORT_A,PIN_2,HIGH);
            DIO_set_pin_value(PORT_A,PIN_3,LOW);
        }
        else
        {
            DIO_set_pin_value(PORT_A,PIN_4,LOW);
            DIO_set_pin_value(PORT_A,PIN_2,LOW);
            DIO_set_pin_value(PORT_A,PIN_3,HIGH);
        }


    }

    return 0;
}
