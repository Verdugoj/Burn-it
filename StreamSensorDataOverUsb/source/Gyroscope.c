/**
 * This software is copyrighted by Bosch Connected Devices and Solutions GmbH, 2016.
 * The use of this software is subject to the XDK SDK EULA
 */
//lint -esym(956,*) /* Suppressing "Non const, non volatile static or external variable" lint warning*/

/* module includes ********************************************************** */

/* system header files */
#include <stdio.h>
#include "BCDS_Basics.h"

/* own header files */
#include "Gyroscope.h"

/* additional interface header files */
#include "BCDS_Basics.h"
#include "BCDS_Retcode.h"
#include "FreeRTOS.h"
#include "timers.h"
#include "BCDS_Gyroscope.h"
#include "XdkSensorHandle.h"
#include "BCDS_Assert.h"

/* local prototypes ********************************************************* */

/* constant definitions ***************************************************** */
#define THREESECONDDELAY                UINT32_C(3000)     /**< three second is represented by this macro */
#define TIMERBLOCKTIME                  UINT32_C(0xffff)   /**< Macro used to define blocktime of a timer */
#define ZERO                            UINT8_C(0)         /**< default value */
#define ONE                             UINT8_C(1)         /**< default value */
#define TIMER_NOT_ENOUGH_MEMORY            (-1L)/**<Macro to define not enough memory error in timer*/
#define TIMER_AUTORELOAD_ON             UINT32_C(1)             /**< Auto reload of timer is enabled*/

/* local variables ********************************************************** */

/* global variables ********************************************************* */
/* variable to store timer handle*/
xTimerHandle printTimerHandle;

/* inline functions ********************************************************* */

/* local functions ********************************************************** */
/**
 * @brief Read data from Gyro sensor and print through the USB
 *
 * @param[in] pxTimer timer handle
 */
void printSensorData(void *pvParameters)
{
    BCDS_UNUSED(pvParameters);
    Retcode_T advancedApiRetValue =(Retcode_T) RETCODE_FAILURE;

    Gyroscope_XyzData_T getRawData = { INT32_C(0), INT32_C(0), INT32_C(0) };
    Gyroscope_XyzData_T getMdegData = { INT32_C(0), INT32_C(0), INT32_C(0) };

    /* read Raw sensor data */
    advancedApiRetValue = Gyroscope_readXyzValue(xdkGyroscope_BMG160_Handle, &getRawData);
    if (RETCODE_OK == advancedApiRetValue)
    {
        printf("BMG160 Gyro Raw Data :\n\rx =%ld\n\ry =%ld\n\rz =%ld\n\r",
                (long int) getRawData.xAxisData, (long int) getRawData.yAxisData, (long int) getRawData.zAxisData);

    }
    else
    {
        printf("GyrosensorReadRawData Failed\n\r");
    }
    /* read sensor data in milli Deg*/
    advancedApiRetValue = Gyroscope_readXyzDegreeValue(xdkGyroscope_BMG160_Handle, &getMdegData);
    if (RETCODE_OK == advancedApiRetValue)
    {
        printf("BMG160 Gyro Converted Data :\n\rx =%ld mDeg\n\ry =%ld mDeg\n\rz =%ld mDeg\n\r",
                (long int) getMdegData.xAxisData, (long int) getMdegData.yAxisData, (long int) getMdegData.zAxisData);

    }
    else
    {
        printf("GyrosensorReadInMilliDeg Failed\n\r");
    }

}

/* global functions ********************************************************* */
/**
 * @brief The function initializes BMG160 sensor and creates, starts timer task in autoreloaded mode
 * every three second which reads and prints the Gyro sensor data
 */
void gyroscopeSensorInit(void)
{
    Retcode_T returnValue = (Retcode_T)RETCODE_FAILURE;

    /* Return value for Timer start */
    int8_t retValPerSwTimer = TIMER_NOT_ENOUGH_MEMORY;

    /*initialize Gyro sensor*/
    returnValue = Gyroscope_init(xdkGyroscope_BMG160_Handle);

    if (RETCODE_OK == returnValue)
    {
        uint32_t Ticks = THREESECONDDELAY;

        if (Ticks != UINT32_MAX) /* Validated for portMAX_DELAY to assist the task to wait Infinitely (without timing out) */
        {
            Ticks /= portTICK_RATE_MS;
        }
        if (UINT32_C(0) == Ticks) /* ticks cannot be 0 in FreeRTOS timer. So ticks is assigned to 1 */
        {
            Ticks = UINT32_C(1);
        }
        /* create timer task to read and print Gyro sensor data every three seconds*/
        printTimerHandle = xTimerCreate(
                (const char * const ) "printSensorData", Ticks,
                TIMER_AUTORELOAD_ON, NULL, printSensorData);

        /* timer create fail case */
        if (NULL == printTimerHandle)
        {
            /* Assertion Reason: "This software timer was not Created, Due to Insufficient heap memory" */
            assert(false);
        }

        /*start the created timer*/
        retValPerSwTimer = xTimerStart(printTimerHandle, TIMERBLOCKTIME);

        /* LSD timer start fail case */
        if (TIMER_NOT_ENOUGH_MEMORY == retValPerSwTimer)
        {
            /* Assertion Reason: "This software timer was not started, Due to Insufficient heap memory" */
            assert(false);
        }
        printf("GyroInit Success\n\r");
    }
    else
    {
        printf("GyroInit Failed\n\r");
    }

}

/**
 *  @brief  The function to de-initialize the Gyroscope
 *
 */
void gyroscopeSensorDeinit(void)
{
    Retcode_T returnValue = (Retcode_T)RETCODE_FAILURE;
    returnValue = Gyroscope_deInit(xdkGyroscope_BMG160_Handle);
    if (RETCODE_OK == returnValue)
    {
        printf("gyroscopeSensor Deinit Success\n\r");
    }
    else
    {
        printf("gyroscopeSensor Deinit Failed\n\r");
    }
}

/** ************************************************************************* */
