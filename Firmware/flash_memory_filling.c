#include "flash_memory_filling.h"

// Inicializacao da memoria
const uint8_t status_in_flash[STATUS_ARRAY_SIZE] = {PREAMBLE, STATUS_DEFAULT, 0, 0, 0, 0, 0, 0};
const uint8_t default_in_flash[DEFAULT_ARRAY_SIZE] = {  1,  1,  1,  1,  1,  1,
                                                        2,  2,  2,  2,  2,  2,
                                                        3,  3,  3,  3,  3,  3,
                                                        4,  4,  4,  4,  4,  4,
                                                        5,  5,  5,  5,  5,  5,
                                                        6,  6,  6,  6,  6,  6,
                                                        7,  7,  7,  7,  7,  7,
                                                        8,  8,  8,  8,  8,  8,
                                                        9,  9,  9,  9,  9,  9,
                                                        10, 10, 10, 10, 10, 10,
                                                        11, 11, 11, 11, 11, 11,
                                                        12, 12, 12, 12, 12, 12  };




void memory_initialize(uint8_t TAG)
{
    // Auxiliar buffer for writing a word inf flash memory
    static volatile uint16_t *ramBuff;

    if(FLASH_ReadWord(STATUS_ARRAY_ADDR) != PREAMBLE)
    {

        // Inicia a rotina de escrita default(HARD CODE) na flash
        
        FLASH_WriteWord(STATUS_ARRAY_ADDR,     ramBuff, PREAMBLE);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 1, ramBuff, STATUS_DEFAULT );
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 2, ramBuff, 0);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 3, ramBuff, 0);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 4, ramBuff, 0);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 5, ramBuff, 0);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 6, ramBuff, 0);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 7, ramBuff, 0);


        
        
            
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


