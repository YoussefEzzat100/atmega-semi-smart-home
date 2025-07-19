#include"LCD_interface.h"
#include<util/delay.h>
#include "LCD_private.h"





LCD_Config lcd_config;

void LCD_INIT(DIO_PORT PORT_DATA, DIO_PORT PORT_CTRL, DIO_PIN rs, DIO_PIN rw, DIO_PIN en, LCD_DATA_MODE mode)
{
    // Store config for permanent use
    lcd_config.data_port = PORT_DATA;
    lcd_config.ctrl_port = PORT_CTRL;
    lcd_config.rs_pin = rs;
    lcd_config.rw_pin = rw;
    lcd_config.en_pin = en;
    lcd_config.mode = mode;

    // Set directions
    DIO_set_pin_direction(PORT_CTRL, rs, OUTPUT);
    DIO_set_pin_direction(PORT_CTRL, rw, OUTPUT);
    DIO_set_pin_direction(PORT_CTRL, en, OUTPUT);

    if (mode == LCD_MODE_8BIT) {
        for (int i = 0; i < 8; i++)
            DIO_set_pin_direction(PORT_DATA, i, OUTPUT);
    } else {
        for (int i = 4; i <= 7; i++)
            DIO_set_pin_direction(PORT_DATA, i, OUTPUT);
    }

    _delay_ms(30);

    if (mode == LCD_MODE_4BIT) {
        LCD_send_nibble(0x03); _delay_ms(5);
        LCD_send_nibble(0x03); _delay_us(150);
        LCD_send_nibble(0x03);
        LCD_send_nibble(0x02); // Set 4-bit
        LCD_CMD(0x28); // 4-bit mode, 2 lines
    } else {
        LCD_CMD(0x38); // 8-bit mode, 2 lines
    }

    LCD_CMD(0x0C); // Display ON, cursor OFF
    LCD_CMD(0x06); // Entry mode
    LCD_CMD(0x01); // Clear display
    _delay_ms(2);
}


void LCD_CMD(unsigned char CMDLCD_CMD)
{
    DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.rs_pin, 0); // Command mode
    DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.rw_pin, 0); // Write mode

    if (lcd_config.mode == LCD_MODE_8BIT) {
        for (int i = 0; i < 8; i++)
        {
            DIO_set_pin_value(lcd_config.data_port, i, (CMDLCD_CMD >> i) & 1);

        }
        DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.en_pin, 1);
        _delay_us(1);
        DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.en_pin, 0);
        _delay_ms(2);
    }
    else {
        LCD_send_nibble(CMDLCD_CMD >> 4);
        LCD_send_nibble(CMDLCD_CMD & 0x0F);
    }
}


void LCD_send_nibble(unsigned char nibble)
{
    for (int i = 0; i < 4; i++)
        DIO_set_pin_value(lcd_config.data_port, i + 4, (nibble >> i) & 1);

    DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.en_pin, 1);
    _delay_us(1);
    DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.en_pin, 0);
    _delay_us(100);
}








void LCD_DATA(unsigned char data)
{
    DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.rs_pin, 1); // RS = 1 → Data
    DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.rw_pin, 0); // RW = 0 → Write

    if (lcd_config.mode == LCD_MODE_8BIT) {
        for (int i = 0; i < 8; i++)
            DIO_set_pin_value(lcd_config.data_port, i, (data >> i) & 1);

        DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.en_pin, 1);
        _delay_us(1);
        DIO_set_pin_value(lcd_config.ctrl_port, lcd_config.en_pin, 0);
        _delay_ms(2);
    } else {
        LCD_send_nibble(data >> 4);
        LCD_send_nibble(data & 0x0F);
    }
}



void LCD_STR(const char *str)
{
    while (*str)
        LCD_DATA(*str++);
}



void LCD_CREATE_CUSTOM_CHAR(unsigned char location, unsigned char *pattern)
{
    location &= 0x07; // Only 0-7 allowed
    LCD_CMD(0x40 + (location * 8)); // Set CGRAM address

    for (unsigned char i = 0; i < 8; i++)
    {
        LCD_DATA(pattern[i]); // Write each row of the pattern
    }

    // Return to DDRAM (display)
    LCD_CMD(0x80);
}


void LCD_CLR()
{
    LCD_CMD(0x01);     // Clear screen command
    _delay_ms(2);      // Wait for LCD to finish
}

