#include <stdio.h>
#include <stdint.h>

typedef union {
    struct {
        uint16_t adc_value : 12;
        uint16_t channel   : 4;
    };
    uint16_t adc_reg;
} ADC_Result;

int main() {
    uint16_t reg;
    printf("Enter ADC Values in Hexadecimal format : ");
    scanf("%hx", &reg); // Read hexadecimal input

    ADC_Result result;
    result.adc_reg = reg;

    printf("Channel: %u\n", result.channel);
    printf("ADC Value: %u", result.adc_value);
    return 0;
}
