#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

// Define ADC Registers
#define ADMUX       (*(volatile unsigned char*)0x27)
#define ADCSRA      (*(volatile unsigned char*)0x26)
#define ADCH        (*(volatile unsigned char*)0x25)
#define ADCL        (*(volatile unsigned char*)0x24)
#define ADCLH       (*(volatile unsigned short int*)0x24) // 16-bit access
#define SFIOR_REG   (*(volatile unsigned char*)0x50)

// Bit Macros
#define SET_BIT(REG, BIT)     ((REG) |= (1 << (BIT)))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1 << (BIT)))
#define GET_BIT(REG, BIT)     (((REG) >> (BIT)) & 1)

// Masks for clearing specific bits
#define ADC_VOLTAGE_REF_clr_msk       0b00111111
#define ADC_CHANNEL_SELECTOR_clr_msk  0b11100000
#define ADC_PRESCALER_clr_msk         0b11111000
#define ADC_AUTO_TRIG_SRC_clr_msk     0b00011111

// Voltage Reference Macros
#define ADC_VOLTAGE_REF_AVCC          (1 << 6)
#define ADC_VOLTAGE_REF_2_56v         (3 << 6)

// Prescaler bit macros
#define ADC_PRESCALER_2_msk           0b00000001
#define ADC_PRESCALER_4_msk           0b00000010
#define ADC_PRESCALER_8_msk           0b00000011
#define ADC_PRESCALER_16_msk          0b00000100
#define ADC_PRESCALER_32_msk          0b00000101
#define ADC_PRESCALER_64_msk          0b00000110
#define ADC_PRESCALER_128_msk         0b00000111

// Auto Trigger Source Macros (shifted to bits 5:7 of SFIOR)
#define ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk     (0 << 5)
#define ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk      (1 << 5)
#define ADC_AUTO_TRIG_SRC_EXTI0_msk            (2 << 5)
#define ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk      (3 << 5)
#define ADC_AUTO_TRIG_SRC_TIMER0_OVF_msk       (4 << 5)
#define ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk      (5 << 5)
#define ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk       (6 << 5)
#define ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk      (7 << 5)

#endif
