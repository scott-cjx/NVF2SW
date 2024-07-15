#include "pkg.h"
#include "app_pdl.h"

#include <stdint.h>
#include <stdbool.h>

#if PKG_PEDAL && SMALL_GENERAL
#pragma message "pkg_pdl.c"

uint16_t adc_vals[5];

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{

}

void setup_pkg()
{
    if (HAL_ADCEx_Calibration_Start(&hadc, ADC_SINGLE_ENDED) !=  HAL_OK)
    {
        // Error_Handler();
    }

    if (HAL_ADC_Start_DMA(&hadc,
        (uint32_t *) aADCxConvertedData,
        ADC_CONVERTED_DATA_BUFFER_SIZE
        ) != HAL_OK)
    {
        // Error_Handler();
    }

    
}

void task_pkg()
{
    
}

#endif /* PKG_PEDAL */
