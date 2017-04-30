/**
 * This software is copyrighted by Bosch Connected Devices and Solutions GmbH, 2016.
 * The use of this software is subject to the XDK SDK EULA
 */

/* module includes ********************************************************** */

/* system header files */
#include <stdio.h>
#include "BCDS_Basics.h"

/* own header files */

/* additional interface header files */
#include "FreeRTOS.h"
#include "timers.h"
#include "Accelerometer.h"
#include "Gyroscope.h"
#include "LightSensor.h"
#include "InertialSensor.h"
#include "Magnetometer.h"
#include "EnvironmentalSensor.h"

/* constant definitions ***************************************************** */

/* local variables ********************************************************** */

/* global variables ********************************************************* */

/* inline functions ********************************************************* */

/* local functions ********************************************************** */

/* global functions ********************************************************** */
/**
 * @brief The function initializes printSensorData which calls the individual sensor data print functions
 * The functions prints the raw data of the sensors
 */
void init(void)
{
   accelerometerSensorInit();
   gyroscopeSensorInit();
   inertialSensorInit();
   lightsensorInit();
   magnetometerSensorInit();
   environmentalSensorInit();
}

/**
 * @brief This is a template function where the user can write his custom application.
 *
 */
void appInitSystem(xTimerHandle xTimer)
{
    BCDS_UNUSED(xTimer);
    init();
}

/**
 *  @brief API to Deinitialize the PSD module
 */
void deinit(void)
{
    accelerometerSensorDeinit();
    gyroscopeSensorDeinit();
    inertialSensorDeinit();
    lightsensorDeinit();
    magnetometerSensorDeinit();
    environmentalSensorDeinit();
}

/** ************************************************************************* */
