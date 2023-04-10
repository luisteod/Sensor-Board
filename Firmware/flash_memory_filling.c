#include "flash_memory_filling.h"

#define FLASH_ROW_ADDR 0x0780
#define PREAMBLE 0x1555

// Inicializacao da memoria
uint16_t dataBlock[] = 
{
    PREAMBLE, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008  , 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000D, 0x000F,
    0x0010  , 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
    0x0018  , 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F
};

void memory_initialize(void)
{
    if(FLASH_ReadWord(FLASH_ROW_ADDR) != PREAMBLE)
    {
        // Inicia a rotina de escrita default(HARD CODE) na flash
        if(FLASH_WriteBlock(FLASH_ROW_ADDR, dataBlock) == -1)
            printf("memory inicialization failed");
        else
            printf("sucess memory inicialization");
    }
}

