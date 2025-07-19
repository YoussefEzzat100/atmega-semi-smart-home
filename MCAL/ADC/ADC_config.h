#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

// ==========================
// Reference Voltage Options
// ==========================
// AREF: External voltage reference
// AVCC: AVCC with external capacitor at AREF pin
// INTERNAL: Internal 2.56V with external cap at AREF
#define REFERENCE_VOLTAGE   AVCC

#define AREF        0
#define AVCC        1
#define INTERNAL    2

// ==========================
// Adjustment Options
// ==========================
// LEFT:  Use ADCH only (8-bit precision)
// RIGHT: Use ADCLH (10-bit precision)
#define ADJUST   RIGHT

#define LEFT    1
#define RIGHT   0

// ==========================
// Prescaler Options
// ==========================
// Recommended for 10-bit resolution: 50–200 kHz ADC clock
#define PRESCALER   PRESCALER_DIVISION_BY_128

#define PRESCALER_DIVISION_BY_2     0
#define PRESCALER_DIVISION_BY_4     1
#define PRESCALER_DIVISION_BY_8     2
#define PRESCALER_DIVISION_BY_16    3
#define PRESCALER_DIVISION_BY_32    4
#define PRESCALER_DIVISION_BY_64    5
#define PRESCALER_DIVISION_BY_128   6

// ==========================
// Auto Trigger Options
// ==========================
#define ADATE   ENABLE

#define ENABLE   1
#define DISABLE  0

// ==========================
// ADC Enable/Disable
// ==========================
#define ADEN     ENABLE

// ==========================
// Auto Trigger Source
// ==========================
#define AUTO_TRIGGER_SOURCE   Free_Running_Mode

#define Free_Running_Mode             0
#define Analog_Comparator             1
#define External_Interrupt_Request_0  2
#define Timer_Counter0_Compare_Match  3
#define Timer_Counter0_Overflow       4
#define Timer_Counter1_Compare_MatchB 5
#define Timer_Counter1_Overflow       6
#define Timer_Counter1_Capture_Event  7

#endif
