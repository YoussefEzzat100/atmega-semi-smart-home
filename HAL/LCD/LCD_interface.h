#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#include"../../MCAL/DIO/DIO_interface.h"
//#include<util/delay.h>
#include"LCD_private.h"

typedef enum{
    CMD_REG_LCD,
    DATA_REG_LCD,
}LCD_SELEC_REG;

// enum for turn on or off lcd

typedef enum{
    LCD_OFF,
    LCD_ON,
}LCD_STATE;


typedef enum {
    LCD_MODE_4BIT,
    LCD_MODE_8BIT,
} LCD_DATA_MODE;



typedef enum{
    WRITE,
    READ,
}LCD_USER_MODE;

//enum for selecting proper reg for mode



typedef struct {
    DIO_PORT data_port;
    DIO_PORT ctrl_port;
    DIO_PIN rs_pin;
    DIO_PIN rw_pin;
    DIO_PIN en_pin;
    LCD_DATA_MODE mode;
} LCD_Config;


extern LCD_Config lcd_config;
//static LCD_CONFIG lcd_cfg;



// Clear and return
#define LCD_CLR_DISPLAY_SCREEN         0x01
#define LCD_RETURN_HOME                0x02

// Entry mode set
#define LCD_ENTRY_DEC                  0x04  // Cursor moves left
#define LCD_ENTRY_INC                  0x06  // Cursor moves right (default)

// Display control
#define LCD_DISPLAY_OFF_CURSOR_OFF     0x08
#define LCD_DISPLAY_OFF_CURSOR_ON      0x0A
#define LCD_DISPLAY_ON_CURSOR_OFF      0x0C
#define LCD_DISPLAY_ON_CURSOR_ON       0x0E
#define LCD_DISPLAY_ON_CURSOR_BLINK    0x0F

// Cursor or display shift
#define LCD_SHIFT_CURSOR_LEFT          0x10
#define LCD_SHIFT_CURSOR_RIGHT         0x14
#define LCD_SHIFT_DISPLAY_LEFT         0x18
#define LCD_SHIFT_DISPLAY_RIGHT        0x1C

// Line control (DDRAM addresses)
#define LCD_FORCE_CURSOR_1ST_LINE      0x80
#define LCD_FORCE_CURSOR_2ND_LINE      0xC0

#define LCD_LINE1_BASE                 LCD_FORCE_CURSOR_1ST_LINE
#define LCD_LINE2_BASE                 LCD_FORCE_CURSOR_2ND_LINE







void LCD_INIT(DIO_PORT,DIO_PORT,DIO_PIN,DIO_PIN,DIO_PIN,LCD_DATA_MODE);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STR(const char *);
void LCD_CREATE_CUSTOM_CHAR(unsigned char, unsigned char *);
void LCD_send_nibble(unsigned char);

void LCD_CLR();






#endif