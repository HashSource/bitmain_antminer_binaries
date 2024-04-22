
void software_set_address(int addrInterval)

{
  uchar chain;
  uint uVar1;
  int addrInterval_local;
  char tmp42 [2048];
  uchar check_bit;
  uchar chip_addr;
  uint j;
  uint i;
  
  dev->check_bit = '\0';
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"--- %s\n","software_set_address");
    _applog(5,tmp42,false);
  }
  dev->addrInterval = (uchar)addrInterval;
  check_bit = dev->addrInterval + 0xff;
  while (check_bit != '\0') {
    check_bit = check_bit >> 1;
    dev->check_bit = dev->check_bit + '\x01';
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      chip_addr = '\0';
      chain = (uchar)i;
      chain_inactive(chain);
      cgsleep_ms(0x1e);
      chain_inactive(chain);
      cgsleep_ms(0x1e);
      chain_inactive(chain);
      cgsleep_ms(0x1e);
      for (j = 0; uVar1 = __aeabi_idiv(0x100,dev->addrInterval), j < uVar1; j = j + 1) {
        set_address(chain,'\0',chip_addr);
        chip_addr = dev->addrInterval + chip_addr;
        set_core_number_BM1390(chain,chip_addr);
        cgsleep_ms(0x1e);
      }
    }
  }
  return;
}

