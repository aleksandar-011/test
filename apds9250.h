#ifndef __APDS9250_H
#define __APDS9250_H

#include "stdint.h"

#define _APDS9250_I2C_ADDR_READ     0xA5 /* i2c read  address */
#define _APDS9250_I2C_ADDR_WRITE    0xA4 /* i2c write address */

#define _APDS9250_REG_MAIN_CTRL     0x00 /* (t)(rw) LS operation mode control, SW reset */
#define _APDS9250_REG_LS_MEAS_RATE  0x04 /* (t)(rw) LS measurement rate and resolution in active mode */
#define _APDS9250_REG_PART_ID       0x06 /*    (ro) Part number ID and revision ID */

#define _APDS9250_REG_LS_DATA_IR_0     0x0A /*    (ro) IR    ADC measurement data - LSB */
#define _APDS9250_REG_LS_DATA_IR_1     0x0B /*    (ro) IR    ADC measurement data - ISB */
#define _APDS9250_REG_LS_DATA_IR_2     0x0C /*    (ro) IR    ADC measurement data - MSB */
#define _APDS9250_REG_LS_DATA_GREEN_0  0x0D /*    (ro) Green ADC measurement data - LSB */
#define _APDS9250_REG_LS_DATA_GREEN_1  0x0E /*    (ro) Green ADC measurement data - ISB */
#define _APDS9250_REG_LS_DATA_GREEN_2  0x0F /*    (ro) Green ADC measurement data - MSB */
#define _APDS9250_REG_LS_DATA_BLUE_0   0x10 /*    (ro) Blue  ADC measurement data - LSB */
#define _APDS9250_REG_LS_DATA_BLUE_1   0x11 /*    (ro) Blue  ADC measurement data - ISB */
#define _APDS9250_REG_LS_DATA_BLUE_2   0x12 /*    (ro) Blue  ADC measurement data - MSB */
#define _APDS9250_REG_LS_DATA_RED_0    0x13 /*    (ro) Red   ADC measurement data - LSB */
#define _APDS9250_REG_LS_DATA_RED_1    0x14 /*    (ro) Red   ADC measurement data - ISB */
#define _APDS9250_REG_LS_DATA_RED_2    0x15 /*    (ro) Red   ADC measurement data - MSB */

#define _APDS9250_DATA_LS_MEAS_RATE_13bit 0x50	// 3.125ms
#define _APDS9250_DATA_LS_MEAS_RATE_16bit 0x40  // 25ms

#define _APDS9250_MASK_MAIN_STATUS_LS_DATA_STATUS 0x08

#define _APDS9250_CTRL_SW_RESET    (1 << 4) /* Trigger software reset */
#define _APDS9250_CTRL_CS_MODE_RGB (1 << 2) /* Channel Select 1 - RGB & IR mode */
#define _APDS9250_CTRL_LS_EN       (1 << 1) /* Light Sensor enabled */

void APDS9250_checkSensorsPresent(void);
void APDS9250_clearAckStatus(void);
void APDS9250_printAckStatus(void);
void APDS9250_readColourRegisters(void);
void APDS9250_softwareResetAndSensorActive(void);
void APDS9250_configureMeasurementRateAndResolution(void);
void APDS9250_startConversion_void(void);

void APDS9250_readGreenColor_void(void);
void APDS9250_readRedColor_void(void);
void APDS9250_readBlueColor_void(void);

void APDS9250_newDataAvalible_void(void);

#endif
