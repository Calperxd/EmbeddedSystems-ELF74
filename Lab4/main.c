#include "Led.h"
#include "Uart.h"
#include "Protocol.h"

void UARTIntHandler(void)
{
    uint32_t ui32Status;
    ui32Status = UARTIntStatus(UART0_BASE, true);
    UARTIntClear(UART0_BASE, ui32Status);
    while(UARTCharsAvail(UART0_BASE))
    {
        addBuffer(UARTCharGetNonBlocking(UART0_BASE));
    }
}


int main(void)
{
    SetupLeds();
    SetupUart();
    while (1)
    {
        if (getBufferLength() == 4)
        {
            IntDisable(INT_UART0);
            if(validateBuffer())
            {
                addBufferAt(64, 0);
                UARTSend(getBufferAddress(),4);
            }
            else 
            {
                addBufferAt(64, 0);
                UARTSend("Invalid",7);
            }
            clearBuffer();
            IntEnable(INT_UART0);
        }
    }
}