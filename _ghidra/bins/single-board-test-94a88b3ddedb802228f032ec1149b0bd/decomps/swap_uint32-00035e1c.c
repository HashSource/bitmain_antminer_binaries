
int swap_uint32(uint param_1)

{
  return (param_1 >> 0x18) +
         param_1 * 0x1000000 + (param_1 >> 8 & 0xff) * 0x10000 + (param_1 >> 0x10 & 0xff) * 0x100;
}

