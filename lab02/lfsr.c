#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
  uint16_t x = *reg;
  uint16_t xor = (x & 0x1) ^ ((x >> 2) & 0x1) ^ ((x >> 3) & 0x1) ^ ((x >> 5) & 0x1);
  x >>= 1; // shift register to the right
  x &= ~(1 << 15); // clear the left most bit
  *reg = x | (xor << 15); // set the left most bit to the value of xor 
}

