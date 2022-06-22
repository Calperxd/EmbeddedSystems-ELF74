#include "Protocol.h"

static uint8_t buffer[4];
static uint8_t lastChar = 0;

void addBuffer(uint8_t value)
{
    buffer[lastChar] = value;
    lastChar++;
}

uint8_t getBufferLength(void)
{
    return lastChar;
}

static void turnOnLed(uint8_t led)
{
    switch (led)
    {
        case 49:
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1 , GPIO_PIN_1);
            break;
        case 50:
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 , GPIO_PIN_0);
            break;
        case 51:
            GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_4 , GPIO_PIN_4);
            break;
        case 52:
            GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_0 , GPIO_PIN_0);
            break;
        case 88:
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1 , GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 , GPIO_PIN_0);
            GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_4 , GPIO_PIN_4);
            GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_0 , GPIO_PIN_0);
            break;
    }
}

static void turnOffLed(uint8_t led)
{
    switch (led)
    {
        case 49:
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1 , 0x0);
            break;
        case 50:
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 , 0x0);
            break;
        case 51:
            GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_4 , 0x0);
            break;
        case 52:
            GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_0 , 0x0);
            break;
        case 88:
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1 , 0x0);
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 , 0x0);
            GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_4 , 0x0);
            GPIOPinWrite(GPIO_PORTF_AHB_BASE, GPIO_PIN_0 , 0x0);
            break;
        
    }
}


// index 0 - start
// index 1 - hardware
// index 2 - led
// index 3 - on/off
bool validateBuffer(void)
{
    if (buffer[0] != 35) return false;
    if (buffer[1] != 82) 
    {
        if (buffer[1] != 84) return false;
        if (buffer[2] != 88) return false;
    }
    if (buffer[2] > 52) 
    {
        if (buffer[2] != 88) return false;
    }
    if (buffer[2] < 48) return false;
    if (buffer[3] > 49) return false;
    if (buffer[3] < 48) return false;

    // on
    if (buffer[3] == 49)
    {
        turnOnLed(buffer[2]);
    }
    //off
    else
    {
        turnOffLed(buffer[2]);
    }
    return true;
}

void clearBuffer(void)
{
    // default value
    for (uint8_t i = 0; i < 4; i++)
    {
        buffer[i] = 255;
    }   
    lastChar = 0;
}


uint8_t* getBufferAddress(void)
{
    return &buffer[0];
}

void addBufferAt(uint8_t val, uint8_t index)
{
    buffer[index] = val;
}