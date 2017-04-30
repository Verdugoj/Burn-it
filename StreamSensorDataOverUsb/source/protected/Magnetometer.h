/**
 * This software is copyrighted by Bosch Connected Devices and Solutions GmbH, 2016.
 * The use of this software is subject to the XDK SDK EULA
 */

/* header definition ******************************************************** */
#ifndef XDK110_MAGNETOMETER_H_
#define XDK110_MAGNETOMETER_H_

/* public interface declaration ********************************************* */

/* public type and macro definitions */

/* public function prototype declarations */

/**
 * @brief The function initializes BMM150(magnetometer)creates and starts a autoreloaded
 * timer task which gets and prints the Magnetometer lsb and converted data.
 */
void magnetometerSensorInit(void);

/**
 *  @brief API to de-initialize the PMD module
 */
void magnetometerSensorDeinit(void);

/* public global variable declarations */

/* inline function definitions */

#endif /* XDK110_MAGNETOMETER_H_ */

/** ************************************************************************* */
