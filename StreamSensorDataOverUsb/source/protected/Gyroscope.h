/**
 * This software is copyrighted by Bosch Connected Devices and Solutions GmbH, 2016.
 * The use of this software is subject to the XDK SDK EULA
 */

/* header definition ******************************************************** */
#ifndef XDK110_GYROSCOPE_H_
#define XDK110_GYROSCOPE_H_

/* public interface declaration ********************************************* */

/* public type and macro definitions */

/* public function prototype declarations */

/**
 * @brief The function initializes BMG160 sensor and creates, starts timer task in autoreloaded mode
 * every three second which reads and prints the Gyro sensor data
 */
void gyroscopeSensorInit(void);

/**
 *  @brief  the function to deinitialize the BMG160 Sensor
 *
 */
void gyroscopeSensorDeinit(void);

/* public global variable declarations */

/* inline function definitions */

#endif /* XDK110_GYROSCOPE_H_ */

/** ************************************************************************* */
