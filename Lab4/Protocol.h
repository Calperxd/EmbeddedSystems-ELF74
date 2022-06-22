#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>
#include <stdbool.h>
#include "Led.h"

void addBuffer(uint8_t value);
uint8_t getBufferLength(void);
bool validateBuffer(void);
void clearBuffer(void);
uint8_t* getBufferAddress(void);
void addBufferAt(uint8_t val, uint8_t index);


#endif