#ifndef FLASH_MEMORY_FILLING_H
#define FLASH_MEMORY_FILLING_H

#include<stdint.h>
#include<stdbool.h>
#include "mcc_generated_files/mcc.h"
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {
#endif
 
 
uint16_t dataBlock[32];  

void memory_initialize(void);

void data_recv_handle(uint8_t* data);

void data_send_handle(uint8_t addr);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // FLASH_MEMORY_FILLING_H