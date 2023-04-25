#include "flash_memory_filling.h"

extern volatile uint8_t i2cDataRead[CALIBRATION_BYTES];
static uint16_t ramBuff[ERASE_FLASH_BLOCKSIZE]; // Auxiliar buffer for writing a word in flash memory
static uint8_t command;

// Debug variables
static uint8_t debug;

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
    command = i2cDataRead[0] & 0x80; // Extraction of the command
    
    //If the command is to Set calibration
    if(command)
    {
        for(uint16_t i = 1; i < CALIBRATION_BYTES; i++)
        {
            FLASH_WriteWord(STATUS_ARRAY_ADDR + (i + 1), ramBuff, (uint16_t)i2cDataRead[i]); // +1 is to do not write in the PREAMBLE ADDR
        }
    }
    
    // If command is to read calibration
    else if(!command)
    {
        
    }
}

void data_send_handle(void)
{
    
}


