
/* WARNING: Unknown calling convention */

void disable_pic_circuit(void)

{
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      pic_voltage_clamp_disable((uint8_t)chain);
    }
  }
  return;
}

