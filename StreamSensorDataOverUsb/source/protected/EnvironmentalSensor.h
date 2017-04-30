/**
 * This software is copyrighted by Bosch Connected Devices and Solutions GmbH, 2016.
 * The use of this software is subject to the XDK SDK EULA
 */
/**
 * @defgroup ped PED
 * @ingroup
 *
 * @{
 * @brief  Printing Environmental Data using USB printf periodically,triggered by a timer(free Rtos)
 *  \tableofcontents
 *  \section intro_sec PED
 * Demo application of printing BME280 Environmental data on serial port(USB virtual com port)
 * every one second, initiated by auto reloaded timer(freeRTOS)
 */
/* header definition ******************************************************** */
#ifndef XDK110_ENVIRONMENTALSENSOR_H_
#define XDK110_ENVIRONMENTALSENSOR_H_

/* public interface declaration ********************************************* */

/* public type and macro definitions */

/* public function prototype declarations */

/**
 * @brief The function initializes BME(Environmental)creates and starts a autoreloaded
 * timer task which gets and prints the Environmental raw data and actual data
 *
 */
extern void environmentalSensorInit(void);

/**
 *  @brief API to deinitialize the PED module
 */
extern void environmentalSensorDeinit(void);

/* public global variable declarations */

/* inline function definitions */

#endif /* XDK110_ENVIRONMENTALSENSOR_H_ */

/**@}*/

/** ************************************************************************* */
