
void pf_power_down(uint32_t chain)

{
  uint32_t chain_local;
  char tmp42 [256];
  
  builtin_strncpy(tmp42,"power down reset low",0x14);
  tmp42[0x14] = '\0';
  puts(tmp42);
  chain_reset_low(chain);
  usleep(10000);
  bitmain_power_off();
  sleep(1);
  return;
}

