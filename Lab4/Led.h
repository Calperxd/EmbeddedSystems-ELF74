#ifndef LED_H
#define LED_H

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

void SetupLeds(void);
void TestLeds(void);

#endif