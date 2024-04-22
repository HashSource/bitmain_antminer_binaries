
/* WARNING: Unknown calling convention */

void set_iic_for_temperature(void)

{
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      set_iic_for_temperature_by_chain(i);
    }
  }
  return;
}

