#ifndef FLASH_MEMORY_FILLING_H
#define FLASH_MEMORY_FILLING_H

#define STATUS_ARRAY_ADDR   0x780 
#define STATUS_ARRAY_SIZE   8
#define DEFAULT_ARRAY_ADDR  0x040
#define PREAMBLE            0x55
#define STATUS_DEFAULT      0x00

#include<stdint.h>
#include<stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "sensor.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {
#endif
 
const uint16_t default_in_flash[MAX_SENSOR_BOARD_TYPE][CALIBRATION_BYTES]  __at(DEFAULT_ARRAY_ADDR) = 
{
    {1,  1,  1,  1,  1,  1},
    {2,  2,  2,  2,  2,  2},
    {3,  3,  3,  3,  3,  3},
    {4,  4,  4,  4,  4,  4},
    {5,  5,  5,  5,  5,  5},
    {6,  6,  6,  6,  6,  6},
    {7,  7,  7,  7,  7,  7},
    {8,  8,  8,  8,  8,  8},
    {9,  9,  9,  9,  9,  9},
    {10, 10, 10, 10, 10, 10},
    {11, 11, 11, 11, 11, 11},
    {12, 12, 12, 12, 12, 12}
};

/*
 * @Author : Luis
 * 
 * @Description : Intializes or not, the memory of the chip when reseted.
 * 
 * @Params : TAG of the chip.
 * 
 * @Return : Nothing.
 */
void memory_initialize(uint8_t TAG);

void data_recv_handle(uint8_t* data);

void data_send_handle(uint8_t addr);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // FLASH_MEMORY_FILLING_H