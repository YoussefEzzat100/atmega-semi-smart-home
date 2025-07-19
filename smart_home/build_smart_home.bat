@echo off
set PROJECT_DIR="C:\Users\M S i\Desktop\NTI summer training\my drivers\youssef\smart_home"
set OUTPUT=smart_home.elf
set HEX=smart_home.hex

avr-gcc -mmcu=atmega32 -DF_CPU=1000000UL ^
    %PROJECT_DIR%\smart_home.c ^
    %PROJECT_DIR%\..\MCAL\DIO\DIO_implementation.c ^
    %PROJECT_DIR%\..\MCAL\ADC\ADC_implementation.c ^
    %PROJECT_DIR%\..\HAL\LCD\LCD_implementation.c ^
    -o %OUTPUT%

avr-objcopy -O ihex -R .eeprom %OUTPUT% %HEX%

echo.
echo Build done.
pause
