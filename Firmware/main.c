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
#
/*
                         Main application
 */

//Efetiva a operação de escrita/deleção
void flash_block_commit()
{
    NVMCON1bits.WREN = 1; // Enable write/erase
    INTCONbits.GIE = 0; // Disable global interrupts
    // The next three steps are the required unlock sequence
    NVMCON2 = 0x55; // First unlock code
    NVMCON2 = 0xAA; // Second unlock code
    NVMCON1bits.WR = 1; // Initiate write/erase cycle
    INTCONbits.GIE = 1; // Enable global interrupts
    NVMCON1bits.WREN = 0; // Disable further write/erase cycles
}
// Deleta a memoria em um "row"
void flash_block_delete(uint8_t addr)
{
    NVMCON1bits.NVMREGS = 0; // Point to PFM
    //add enderecamento correto
    NVMADR = addr; // 14-bit PFM address ; Must start at beginning of PFM row
    NVMCON1bits.FREE = 1; // Specify an erase operation
    NVMCON1bits.WREN = 1; // Enable write/erase cycle
    flash_block_commit(); // Where the delete operation effectively takes place
}
// flash writing func
void flash_block_write(uint8_t addr, uint8_t data)
{   
    //add enderacamento correto
    flash_block_delete(addr); //Deleta a info que esta nesse endereço para que algoseja escrito
    NVMCON1bits.LWLO = 1; ?// Habilita os "write latches"
            /*
             * Escreva a operação de escrita aqui
             */
    
    flash_block_commit(); //Efetiva a escrita
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        // Add your application code
        
        //Guarda os valores do input do PIC 
        uint8_t v[3];
        uint8_t TAG = 0;

        v[0] = PORTC & 0x3C;
        v[1] = PORTA & 0x30;
        //shifta os bits para o devido local
        v[2] = v[0]>>2;
        //armazana o identificador do pic 
        TAG = v[2] | v[1]; 
        LED_SetHigh();
        
        
        I2C1_Open();
        I2C1_Write(TAG);
        I2C1_Close();
        __delay_ms(1000);
    }
}
/**
 End of File
*/