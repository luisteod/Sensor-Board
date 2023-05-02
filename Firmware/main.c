/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F15223
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"
#include "flash_memory_filling.h"
#include "sensor.h"
#include "mcc_generated_files/tmr0.h"


void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    uint8_t TAG = getSensorBoardType();

    if (SensorBoardType_validation(TAG)) {

        memory_initialize(TAG);
    } else {
        error_signal();
    }
    //Permite que o pic receba informa��o via I2C (Ativa )
    I2C1_Open();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Int  errupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1) {
        
        // Add your application code
        if (timer_event) {

            timer_event = false;
            LED_timer++;

            //If error, LED's toggle fast then normal
            if (error_flag == 1) {
                if (LED_timer == 5) {
                    LED_SetHigh();
                }
                if (LED_timer == 10) {
                    LED_SetLow();
                    LED_timer = 0;
                }
            } else {// LED indicates normal conditions
                if (LED_timer == 50) {
                    LED_SetHigh();
                }
                if (LED_timer == 100) {
                    LED_SetLow();
                    LED_timer = 0;
                }
            }
        }
        
        /* if the received data is equal to the bytes of mtw protocol of if
         * the command byte have the cal bit clear
         */
        if(i2c_recv_event)  
        {
             i2c_recv_event = false;
             data_recv_handler();
        }
    }
    
    
}
/**
 End of File
 */