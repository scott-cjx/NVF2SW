/*
 * Copyright (C) 2024 Scott CJX
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
