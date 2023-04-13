/**
  Generated Sensor File

  Company:
    MTW Solucoes e Servicos em Tecnologia e Participacoes Ltda.

  File Name:
    sensor.c

  Summary:
    This is the sensor board file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for sensor APIs.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F15223
        Driver Version    :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB             :  MPLAB X 6.00

   All rights reserved.
*/


#include "sensor.h"
#include "pin_manager.h"


uint8_t SensorBoardType_validation (uint8_t SensorBoardType)
{
    if(SensorBoardType>=MIN_SENSOR_BOARD_TYPE)
    {
        if(SensorBoardType<=MAX_SENSOR_BOARD_TYPE)
        {
            return(TRUE);
        }
    }
    
    return(FALSE);
}

  

/**
 End of File
*/