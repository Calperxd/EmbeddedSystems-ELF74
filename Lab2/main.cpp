#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

uint32_t SysTicks1ms;
static bool ganhou = false;
static bool Led1=false;

void GpioPortJIntHandler(void)
{ 
    ganhou = 1;
}

void SysTickIntHandler(void)
{
    SysTicks1ms++;
}

void GpioPortJIntHandler(void)
{ 
}

int SetupCore(void)
{
    SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_240), 25000000);
    return 0;
}

int SetupSystick()
{
    SysTicks1ms = 0;
    SysTickDisable();
    SysTickPeriodSet(25000);
    SysTickIntRegister(SysTickIntHandler);
    SysTickIntEnable();
    SysTickEnable();
    return 0;
}

int SetupGPIO(void)
{ 
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION)) {}
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)) {}
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ)) {}
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);
    GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    return 0;
}

int main(void)
{
    SetupCore();
    SetupSystick();
    SetupGPIO();
    uint32_t time = 0;
    uint32_t start_time = SysTicks1ms;
    uint32_t time_limit = SysTicks1ms + 3000;
    
    while(GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_1)){}
    printf("\nStart");
    Led1=!Led1;
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, Led1 << 1);

    while(true)
    { 
        time = SysTicks1ms + 1000;
        if(SysTicks1ms <= time) 
        {
            printf("%i", (time - start_time));
        }
        
        if(SysTicks1ms <= time_limit)
        {
            uint32_t bt_flag = GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_0) == 0;
        if ()
        {
        }
        if(ganhou)
        {
            time -= start_time;
            printf("Ganhou!");
            printf("Tempo: %i", time);
            break;
        }
        }
        else 
        {
            printf("Perdeu!");
            break;
        }
    }
}