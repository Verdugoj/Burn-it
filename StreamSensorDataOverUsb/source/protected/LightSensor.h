/**
 * This software is copyrighted by Bosch Connected Devices and Solutions GmbH, 2016.
 * The use of this software is subject to the XDK SDK EULA
 */

/* header definition ******************************************************** */
#ifndef XDK110_LIGHTSENSOR_H_
#define XDK110_LIGHTSENSOR_H_

/* public interface declaration ********************************************* */

/* public type and macro definitions */

/* public function prototype declarations */

/**
 * @brief The function initializes light sensor and creates, starts timer task in autoreloaded mode
 * every three second which reads and prints the light sensor data
 */
void lightsensorInit(void);

/**
 *  @brief  the function to deinitialize
 *
 */
void lightsensorDeinit(void);

/* public global variable declarations */

/* inline function definitions */

#endif /* XDK110_LIGHTSENSOR_H_ */

/** ************************************************************************* */
