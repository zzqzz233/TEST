#ifndef __AT24C02_H
#define __AT24C02_H

#include "main.h"
#include "iic.h"

void Initial_24c02(void);
void Write_Bit_24c02(uint8_t addr,uint8_t data);
uint8_t Read_Bit_24c02(uint8_t addr);

#endif
