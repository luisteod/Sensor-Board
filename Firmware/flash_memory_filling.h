#ifndef FLASH_MEMORY_FILLING_H
#define FLASH_MEMORY_FILLING_H

#include<stdint.h>
#include<stdbool.h>
#include "mcc_generated_files/mcc.h"
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {
#endif
 
// Comeco da SAF
#define FLASH_ROW_ADDR 0x0780

uint16_t dataBlock[32];  

void memory_initialize(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // FLASH_MEMORY_FILLING_H