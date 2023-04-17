/**
  @Sensor Header File

  @Company:
    MTW Solucoes e Servicos em Tecnologia e Participacoes Ltda.

  @File Name:
    sensor.h

  @Summary:
    This is the specific Sensor file using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for Sensor Board.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F15223
        Driver Version    :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

#ifndef SENSOR_H
#define SENSOR_H

/**
  Section: Included Files
*/

#include <xc.h>

#define SB_DC5V                1
#define SB_OUTPUT              2
#define SB_DC20V               3
#define SB_INPUT               4
#define SB_DC50V               5
#define SB_AC250V              6
#define SB_AC50V               7
#define SB_AC5A                8
#define SB_AC1A                9
#define SB_AUDIOIN_MIC         10
#define SB_AUDIOOUT_SPK        11
#define SB_ISOURCE             12

#define MIN_SENSOR_BOARD_TYPE  1
#define MAX_SENSOR_BOARD_TYPE  12

#define CALIBRATION_BYTES   6

#define TRUE                1
#define FALSE               0

/*
 * Global variables
 */
uint8_t error_flag;


/* function declaration*/
uint8_t getSensorBoardType(void);


uint8_t SensorBoardType_validation (uint8_t SensorBoardType);

void error_signal(void);

#endif // PIN_MANAGER_H
/**
 End of File
*/