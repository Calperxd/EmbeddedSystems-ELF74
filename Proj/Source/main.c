#include "uart.h"
#include "threads.h"
int main()
{
    UARTStartup();
    tx_kernel_enter();
}