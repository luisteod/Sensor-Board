#include "flash_memory_filling.h"

extern volatile uint8_t i2cDataRead[CALIBRATION_BYTES];
static uint16_t ramBuff[ERASE_FLASH_BLOCKSIZE]; // Auxiliar buffer for writing a word in flash memory

void memory_initialize(uint8_t TAG)
{

    if(FLASH_ReadWord(STATUS_ARRAY_ADDR) != PREAMBLE)
    {         
        FLASH_WriteWord(STATUS_ARRAY_ADDR,     ramBuff, PREAMBLE);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 1, ramBuff, STATUS_DEFAULT );
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 2, ramBuff, (uint16_t)default_in_flash[TAG - 1][0]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 3, ramBuff, (uint16_t)default_in_flash[TAG - 1][1]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 4, ramBuff, (uint16_t)default_in_flash[TAG - 1][2]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 5, ramBuff, (uint16_t)default_in_flash[TAG - 1][3]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 6, ramBuff, (uint16_t)default_in_flash[TAG - 1][4]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 7, ramBuff, (uint16_t)default_in_flash[TAG - 1][5]);
    }
}

void data_recv_handler(void)
{
    
    //If the last byte is diferent of 0, so it's for PIC save calibration bytes in flash memory
    if(i2cDataRead[CALIBRATION_BYTES - 1] != 0x00)
    {
        for(uint16_t i = 0; i < CALIBRATION_BYTES; i++)
        {
            FLASH_WriteWord(STATUS_ARRAY_ADDR + (i + 1), ramBuff, (uint16_t)i2cDataRead[i]); // +1 is to do not write in the PREAMBLE ADDR
        }
    }
    // If last byte is equal 0, so the master want's PIC to send calibration data stored in flash
    else
    {
        // Nothing to be done here!
    }
}


