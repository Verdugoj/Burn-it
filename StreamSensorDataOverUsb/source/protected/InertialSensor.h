/**
 * This software is copyrighted by Bosch Connected Devices and Solutions GmbH, 2016.
 * The use of this software is subject to the XDK SDK EULA
 */
/**
 * @defgroup pid PID
 * @ingroup
 *
 * @{
 * @brief  Printing Interial Data using USB printf periodically,triggered by a timer(free Rtos)
 *  \tableofcontents
 *  \section intro_sec PID
 * Demo lication of printing BMI160 Accel and Gyro data on serial port(USB virtual com port)
 * every one second, initiated by auto reloaded timer(freeRTOS)
 */

/* header definition ******************************************************** */
#ifndef XDK110_INERTIALSENSOR_H_
#define XDK110_INERTIALSENSOR_H_

/* public interface declaration ********************************************* */

/* public type and macro definitions */

/* public function prototype declarations */

/**
 * @brief The function initializes BMI(Interial-accel & gyro)creates and starts a auto reloaded
 * timer task which gets and prints the accel and gyro data.
 */
void inertialSensorInit(void);

/**
 *  @brief API to deinitialize the PID module
 */
void inertialSensorDeinit(void);

/* public global variable declarations */

/* inline function definitions */

#endif /* XDK110_INERTIALSENSOR_H_ */

/**@}*/

/** ************************************************************************* */
