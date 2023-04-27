#include "flash_memory_filling.h"

extern volatile uint8_t i2cDataRead[I2C_PROTOCOL_BYTES];
extern volatile uint8_t i2cDataWrite[I2C_PROTOCOL_BYTES - 1];
static uint16_t ramBuff[ERASE_FLASH_BLOCKSIZE]; // Auxiliar buffer for writing a word in flash memory
static uint8_t command;
static uint8_t low_cal;
static uint8_t high_cal;

/*
 * Auxiliar functions
 */
inline void send_normal_cal(void);
inline void send_high_cal(void);
inline void send_low_cal(void);

void memory_initialize(uint8_t TAG) {

    if (FLASH_ReadWord(STATUS_ARRAY_ADDR) != PREAMBLE) {
        FLASH_WriteWord(STATUS_ARRAY_ADDR, ramBuff, PREAMBLE);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 1, ramBuff, STATUS_DEFAULT);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 2, ramBuff, (uint16_t) default_in_flash[TAG - 1][0]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 3, ramBuff, (uint16_t) default_in_flash[TAG - 1][1]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 4, ramBuff, (uint16_t) default_in_flash[TAG - 1][2]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 5, ramBuff, (uint16_t) default_in_flash[TAG - 1][3]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 6, ramBuff, (uint16_t) default_in_flash[TAG - 1][4]);
        FLASH_WriteWord(STATUS_ARRAY_ADDR + 7, ramBuff, (uint16_t) default_in_flash[TAG - 1][5]);
    }
}

void data_recv_handler(void) {

    command = (0x80 & i2cDataRead[0]); // Extraction of the command write in flash or read from flash
    low_cal = (0x40 & i2cDataRead[0]);
    high_cal = (0x20 & i2cDataRead[0]);

    //If the command is to Set calibration
    if (command) {
        //Block for writing the sttus byte
        if(low_cal)
            FLASH_WriteWord(STATUS_ARRAY_ADDR + 1, ramBuff, 0x0001);
        else if(high_cal)
            FLASH_WriteWord(STATUS_ARRAY_ADDR + 1, ramBuff, 0x0002);
        else 
            FLASH_WriteWord(STATUS_ARRAY_ADDR + 1, ramBuff, 0x0003);
            
        for (uint16_t i = 0; i < I2C_PROTOCOL_BYTES - 1; i++) {
            FLASH_WriteWord(STATUS_ARRAY_ADDR + (i + 2), ramBuff, (uint16_t)i2cDataRead[i + 1]); // +1 is to do not write in the PREAMBLE ADDR
        }
    }//Preapares the Data for sending
    else {
        if (!low_cal && !high_cal) { // If high and Low cal is 0 then is to retrieve normal cal
            send_normal_cal();
        } else if (low_cal && !high_cal) { // retrieve low cal
            send_high_cal();
        } else if (high_cal && !low_cal) { //retrieve high cal
            send_low_cal();
        }

    }
}

inline void send_normal_cal(void) {
    i2cDataWrite[0] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 2);
    i2cDataWrite[1] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 3);
    i2cDataWrite[2] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 4);
    i2cDataWrite[3] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 5);
    i2cDataWrite[4] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 6);
    i2cDataWrite[5] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 7);
}
inline void send_high_cal(void) {
//    i2cDataWrite[0] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 1);
//    i2cDataWrite[1] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 2);
//    i2cDataWrite[2] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 3);
//    i2cDataWrite[3] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 4);
}
inline void send_low_cal(void) {
//    i2cDataWrite[0] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 9);
//    i2cDataWrite[1] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 10);
//    i2cDataWrite[2] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 11);
//    i2cDataWrite[3] = (uint8_t) FLASH_ReadWord(STATUS_ARRAY_ADDR + 12);

}