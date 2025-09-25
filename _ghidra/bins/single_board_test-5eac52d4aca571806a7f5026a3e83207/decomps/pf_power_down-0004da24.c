
void pf_power_down(uint32_t chain)

{
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : power down reset low\n","pf_power_down");
  builtin_strncpy(tmp1,"power down reset low",0x14);
  tmp1[0x14] = '\0';
  log_to_file(tmp1,time_stamp);
  bitmain_power_off();
  usleep(30000);
  chain_reset_low(chain);
  sleep(1);
  return;
}

