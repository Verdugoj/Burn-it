/**
 * This software is copyrighted by Bosch Connected Devices and Solutions GmbH, 2016.
 * The use of this software is subject to the XDK SDK EULA
 */
/**
 * @defgroup pad PAD
 * @ingroup
 *
 * @{
 * @brief  Printing Accel Data using USB printf periodically,triggered by a timer(free Rtos)
 *  \tableofcontents
 *  \section intro_sec PAD
 * Demo application of printing BMA Accelerometer data on serial port(USB virtual com port)
 * every one second, initiated by auto reloaded timer(freeRTOS)
 */
/* header definition ******************************************************** */
#ifndef XDK110_ACCELEROMETER_H_
#define XDK110_ACCELEROMETER_H_

/* public interface declaration ********************************************* */

/* public type and macro definitions */

/* public function prototype declarations */

/**
 * @brief The function initializes BMA(accelerometer)creates and starts a autoreloaded
 * timer task which gets and prints the accel raw data
 *
 */
extern void accelerometerSensorInit(void);

/**
 *  @brief API to de-initialize the PAD module
 */
extern void accelerometerSensorDeinit(void);

/* public global variable declarations */

/* inline function definitions */

#endif /* XDK110_ACCELEROMETER_H_ */

/**@}*/

/** ************************************************************************* */
