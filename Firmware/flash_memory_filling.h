#ifndef FLASH_MEMORY_FILLING_H
#define FLASH_MEMORY_FILLING_H

#define STATUS_ARRAY_ADDR   0x780
#define STATUS_ARRAY_SIZE   8
#define DEFAULT_ARRAY_ADDR  0x788
#define DEFAULT_ARRAY_SIZE  72
#define PREAMBLE            0x55
#define STATUS_DEFAULT      0x00

#include<stdint.h>
#include<stdbool.h>
#include "mcc_generated_files/mcc.h"
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {
#endif
 
const uint8_t status_in_flash[STATUS_ARRAY_SIZE]        __at(STATUS_ARRAY_ADDR);
const uint8_t default_in_flash[DEFAULT_ARRAY_SIZE]      __at(DEFAULT_ARRAY_ADDR);

void memory_initialize(uint8_t TAG);

void data_recv_handle(uint8_t* data);

void data_send_handle(uint8_t addr);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // FLASH_MEMORY_FILLING_H