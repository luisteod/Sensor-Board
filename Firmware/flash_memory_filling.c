#include "flash_memory_filling.h"


void memory_initialize(uint8_t TAG)
{
    // Auxiliar buffer for writing a word in flash memory
    static uint16_t ramBuff[ERASE_FLASH_BLOCKSIZE];

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

//void data_recv_handle(uint8_t* data)
//{
//    static volatile uint16_t* ramBuff;
//
//    // If the last byte is diferent of 0, so it's for PIC write calibration values in memory
//    if(data[5] != 0)
//    {
//        for(int i=1; i<6; i++)
//        {
//            FLASH_WriteWord(FIRST_ROW_WORD + (uint16_t)i, ramBuff, (uint16_t)data[i]);
//        }
//    }
//    // If last byte is equal 0, so the master want's PIC to send calibration data stored in flash
//    else
//    {
//        // Nothing to be done here!
//    }
//}


