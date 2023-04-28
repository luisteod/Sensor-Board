#ifndef FLASH_MEMORY_FILLING_H
#define FLASH_MEMORY_FILLING_H

#define STATUS_ARRAY_ADDR   0x780 
#define PREAMBLE_ADDR       0x780
#define STATUS_ADDR         0x781
#define CAL_MSB_ADDR        0x782
#define CAL_LSB_ADDR        0x783
#define LOW_CAL_MSB_ADDR    0x784
#define LOW_CAL_LSB_ADDR    0x785
#define HIGH_CAL_MSB_ADDR   0x786
#define HIGH_CAL_LSB_ADDR   0x787
#define LED_DATA_ADDR       0x788
#define BOARD_TYPE_ADDR     0x789

#define CMD_CAL                 0x80
#define CMD_LOW_CAL             0x40
#define CMD_HIGH_CAL            0x20
#define CMD_LED                 0x10

#define CMD_I2C_POS             0
#define STATUS_I2C_POS          0
#define BOARD_TYPE_I2C_POS      1
#define CAL_MSB_I2C_POS         2
#define CAL_LSB_I2C_POS         3
#define LOW_CAL_MSB_I2C_POS     4
#define LOW_CAL_LSB_I2C_POS     5
#define HIGH_CAL_MSB_I2C_POS    6
#define HIGH_CAL_LSB_I2C_POS    7
#define LED_DATA_I2C_POS        8

#define STATUS_ARRAY_SIZE   8
#define DEFAULT_ARRAY_ADDR  0x040
#define PREAMBLE            0x55
#define STATUS_DEFAULT      0x00

#include <stdint.h>
#include <stdbool.h>
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

/* @Author : Luis
 * @Description : Intializes or not, the memory of the chip when reseted.
 * @Params : TAG of the chip.
 * @Return : Nothing.
 */
void memory_initialize(uint8_t TAG);

/* @Author : Luis
 * @Description : When receives 5 bytes of the MTW protocol, save things in flash 
                  OR when receives a command byte to read values send bytes.
 * @Params : Nothing
 * @Return : Nothing
 */
void data_recv_handler(void);

//void send_data(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // FLASH_MEMORY_FILLING_H