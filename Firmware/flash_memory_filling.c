#include "flash_memory_filling.h"

extern volatile uint8_t i2cDataRead[I2C_READ_PROTOCOL_BYTES];
extern volatile uint8_t i2cDataWrite[I2C_WRITE_PROTOCOL_BYTES];
static uint16_t ramBuff[ERASE_FLASH_BLOCKSIZE]; // Auxiliar buffer for writing a word in flash memory

/*
 * Auxiliar functions
 */

void memory_initialize(uint8_t TAG) {

    if (FLASH_ReadWord(PREAMBLE_ADDR) != PREAMBLE) {
        FLASH_WriteWord(PREAMBLE_ADDR, ramBuff, PREAMBLE);
        FLASH_WriteWord(STATUS_ADDR, ramBuff, STATUS_DEFAULT);
        FLASH_WriteWord(CAL_MSB_ADDR, ramBuff, (uint16_t) default_in_flash[TAG - 1][0]);
        FLASH_WriteWord(CAL_LSB_ADDR, ramBuff, (uint16_t) default_in_flash[TAG - 1][1]);
        FLASH_WriteWord(LOW_CAL_MSB_ADDR, ramBuff, (uint16_t) default_in_flash[TAG - 1][2]);
        FLASH_WriteWord(LOW_CAL_LSB_ADDR, ramBuff, (uint16_t) default_in_flash[TAG - 1][3]);
        FLASH_WriteWord(HIGH_CAL_MSB_ADDR, ramBuff, (uint16_t) default_in_flash[TAG - 1][4]);
        FLASH_WriteWord(HIGH_CAL_LSB_ADDR, ramBuff, (uint16_t) default_in_flash[TAG - 1][5]);
        FLASH_WriteWord(LED_DATA_ADDR, ramBuff, 0x0000);
        FLASH_WriteWord(BOARD_TYPE_ADDR, ramBuff, (uint16_t) TAG);
    }
}

void data_recv_handler(void) {


    if (CMD_CAL & i2cDataRead[CMD_I2C_POS]) {

        FLASH_WriteWord(STATUS_ADDR, ramBuff, (uint16_t) CMD_CAL | (uint8_t) FLASH_ReadWord((uint16_t) STATUS_ADDR)); // saves status

        FLASH_WriteWord(CAL_MSB_ADDR, ramBuff, (uint16_t) i2cDataRead[CAL_MSB_I2C_POS]); // saves cal data
        FLASH_WriteWord(CAL_MSB_ADDR, ramBuff, (uint16_t) i2cDataRead[CAL_LSB_I2C_POS]); //saves cal data
    }
    if (CMD_LOW_CAL & i2cDataRead[CMD_I2C_POS]) {
        FLASH_WriteWord(STATUS_ADDR, ramBuff, (uint16_t) CMD_LOW_CAL | (uint8_t) FLASH_ReadWord((uint16_t) STATUS_ADDR));

        FLASH_WriteWord(LOW_CAL_MSB_ADDR, ramBuff, (uint16_t) i2cDataRead[LOW_CAL_MSB_I2C_POS]); // saves cal data
        FLASH_WriteWord(LOW_CAL_LSB_ADDR, ramBuff, (uint16_t) i2cDataRead[LOW_CAL_LSB_I2C_POS]); //saves cal data
    }
    if (CMD_HIGH_CAL & i2cDataRead[CMD_I2C_POS]) {
        FLASH_WriteWord(STATUS_ADDR, ramBuff, (uint16_t) CMD_HIGH_CAL | (uint8_t) FLASH_ReadWord((uint16_t) STATUS_ADDR));

        FLASH_WriteWord(HIGH_CAL_MSB_ADDR, ramBuff, (uint16_t) i2cDataRead[HIGH_CAL_MSB_I2C_POS]); // saves cal data
        FLASH_WriteWord(HIGH_CAL_LSB_ADDR, ramBuff, (uint16_t) i2cDataRead[HIGH_CAL_LSB_I2C_POS]); //saves cal data
    }
    if (CMD_LED & i2cDataRead[CMD_I2C_POS]) {
        FLASH_WriteWord(STATUS_ADDR, ramBuff, (uint16_t) CMD_LED | (uint8_t) FLASH_ReadWord((uint16_t) STATUS_ADDR));

        FLASH_WriteWord(LED_DATA_ADDR, ramBuff, i2cDataRead[LED_DATA_I2C_POS]);
    }

}

void send_data(void) {
    
    i2cDataWrite[STATUS_I2C_POS] = (uint8_t) FLASH_ReadWord(STATUS_ADDR);
    i2cDataWrite[BOARD_TYPE_I2C_POS] = (uint8_t) FLASH_ReadWord(BOARD_TYPE_ADDR);
    i2cDataWrite[CAL_MSB_I2C_POS] = (uint8_t) FLASH_ReadWord(CAL_MSB_ADDR);
    i2cDataWrite[CAL_LSB_I2C_POS] = (uint8_t) FLASH_ReadWord(CAL_LSB_ADDR);
    i2cDataWrite[LOW_CAL_MSB_I2C_POS] = (uint8_t) FLASH_ReadWord(LOW_CAL_MSB_ADDR);
    i2cDataWrite[LOW_CAL_LSB_I2C_POS] = (uint8_t) FLASH_ReadWord(LOW_CAL_LSB_ADDR);
    i2cDataWrite[HIGH_CAL_MSB_I2C_POS] = (uint8_t) FLASH_ReadWord(HIGH_CAL_MSB_ADDR);
    i2cDataWrite[HIGH_CAL_LSB_I2C_POS] = (uint8_t) FLASH_ReadWord(HIGH_CAL_LSB_ADDR);
    i2cDataWrite[LED_DATA_I2C_POS] = (uint8_t) FLASH_ReadWord(LED_DATA_ADDR);

}

