
uint32_t calculate_hardware_sweep_timeout(uint32_t freq,uint32_t max_nonce,uint32_t timeout_clock)

{
  undefined4 uVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t timeout_clock_local;
  uint32_t max_nonce_local;
  uint32_t freq_local;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t timeout;
  
  uVar1 = __aeabi_uidiv(max_nonce,freq);
  iVar2 = __aeabi_uidiv(uVar1,timeout_clock);
  uVar3 = iVar2 + 1;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : hardware sweep timeout = %d, freq = %d\n","calculate_hardware_sweep_timeout",uVar3,
         freq);
  snprintf(tmp1,0x100,"hardware sweep timeout = %d, freq = %d",uVar3,freq);
  log_to_file(tmp1,time_stamp);
  return uVar3;
}

