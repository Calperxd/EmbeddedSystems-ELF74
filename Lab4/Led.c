#include "Led.h"


void SetupLeds(void)
{
    // Setup for LEDS N1 and N0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
    }
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Setup for LEDS PF4 and PF0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }
    GPIOPinTypeGPIOOutput(GPIO_PORTF_AHB_BASE, GPIO_PIN_4 | GPIO_PIN_0);
}


void TestLeds(void)
{
    volatile uint32_t ui32Loop;
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1 , GPIO_PIN_1);
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 , GPIO_PIN_0);
    GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_4 , GPIO_PIN_4);
    GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_0 , GPIO_PIN_0);
    for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
    {
    }
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1 , 0x0);
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 , 0x0);
    GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_4 , 0x0);
    GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_0 , 0x0);
    for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
    {
    }
}