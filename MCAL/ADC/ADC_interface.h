#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

// List of ADC channels
typedef enum {
    ADC_0,
    ADC_1,
    ADC_2,
    ADC_3,
    ADC_4,
    ADC_5,
    ADC_6,
    ADC_7
} ADC_CHANNELS;

// Function prototypes
void ADC_INIT(void);
void ADC_CONVERT(ADC_CHANNELS channel);
unsigned short int ADC_GET_READ(void);

#endif
