#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include <util/delay.h>
void ADC_INIT()
{
    // === Reference Voltage ===
    ADMUX &= ADC_VOLTAGE_REF_clr_msk;

#if REFERENCE_VOLTAGE == AREF
    // Nothing to set (both REFS0 and REFS1 = 0)
#elif REFERENCE_VOLTAGE == AVCC
    ADMUX |= ADC_VOLTAGE_REF_AVCC;
#elif REFERENCE_VOLTAGE == INTERNAL
    ADMUX |= ADC_VOLTAGE_REF_2_56v;
#endif

    // === Adjust Result Direction ===
#if ADJUST == LEFT
    SET_BIT(ADMUX, 5);  // ADLAR = 1 (Left adjust)
#else
    CLEAR_BIT(ADMUX, 5); // ADLAR = 0 (Right adjust)
#endif

    // === Prescaler Setting ===
    ADCSRA &= ADC_PRESCALER_clr_msk;

#if PRESCALER == PRESCALER_DIVISION_BY_2
    ADCSRA |= ADC_PRESCALER_2_msk;
#elif PRESCALER == PRESCALER_DIVISION_BY_4
    ADCSRA |= ADC_PRESCALER_4_msk;
#elif PRESCALER == PRESCALER_DIVISION_BY_8
    ADCSRA |= ADC_PRESCALER_8_msk;
#elif PRESCALER == PRESCALER_DIVISION_BY_16
    ADCSRA |= ADC_PRESCALER_16_msk;
#elif PRESCALER == PRESCALER_DIVISION_BY_32
    ADCSRA |= ADC_PRESCALER_32_msk;
#elif PRESCALER == PRESCALER_DIVISION_BY_64
    ADCSRA |= ADC_PRESCALER_64_msk;
#elif PRESCALER == PRESCALER_DIVISION_BY_128
    ADCSRA |= ADC_PRESCALER_128_msk;
#endif

    // === Auto Trigger Setting ===
#if ADATE == ENABLE
    SET_BIT(ADCSRA, 5);  // ADATE bit enable
    SFIOR_REG &= ADC_AUTO_TRIG_SRC_clr_msk;

#if AUTO_TRIGGER_SOURCE == Free_Running_Mode
    SFIOR_REG |= ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk;
#elif AUTO_TRIGGER_SOURCE == Analog_Comparator
    SFIOR_REG |= ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk;
#elif AUTO_TRIGGER_SOURCE == External_Interrupt_Request_0
    SFIOR_REG |= ADC_AUTO_TRIG_SRC_EXTI0_msk;
#elif AUTO_TRIGGER_SOURCE == Timer_Counter0_Compare_Match
    SFIOR_REG |= ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk;
#elif AUTO_TRIGGER_SOURCE == Timer_Counter0_Overflow
    SFIOR_REG |= ADC_AUTO_TRIG_SRC_TIMER0_OVF_msk;
#elif AUTO_TRIGGER_SOURCE == Timer_Counter1_Compare_MatchB
    SFIOR_REG |= ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk;
#elif AUTO_TRIGGER_SOURCE == Timer_Counter1_Overflow
    SFIOR_REG |= ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk;
#elif AUTO_TRIGGER_SOURCE == Timer_Counter1_Capture_Event
    SFIOR_REG |= ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk;
#endif

#else
    CLEAR_BIT(ADCSRA, 5);  // ADATE = 0
#endif

    // === Enable ADC ===
#if ADEN == ENABLE
    SET_BIT(ADCSRA, 7);
#else
    CLEAR_BIT(ADCSRA, 7);
#endif
}

void ADC_CONVERT(ADC_CHANNELS channel)
{
    // Clear previous channel bits
    ADMUX &= ADC_CHANNEL_SELECTOR_clr_msk;

    // Set new channel
    ADMUX |= channel;

    _delay_us(10);

    // Start conversion
    SET_BIT(ADCSRA, 6); // ADSC = 1
    while (GET_BIT(ADCSRA, 6));
}

unsigned short int ADC_GET_READ()
{
    // Wait until conversion is complete (ADIF = 1)
    while (GET_BIT(ADCSRA, 4) == 0);

    // Clear ADIF by writing 1
    SET_BIT(ADCSRA, 4);

#if ADJUST == LEFT
    // 8-bit left adjusted result (ADCH only)
    return (unsigned short int)(ADCH);
#else
    // 10-bit right adjusted result from ADCLH
    return ADCLH; // Access both ADCL and ADCH as 16-bit
#endif
}
