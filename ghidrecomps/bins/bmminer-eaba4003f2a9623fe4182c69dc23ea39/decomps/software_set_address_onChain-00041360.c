
void software_set_address_onChain(int chainIndex)

{
  uchar chain;
  uint uVar1;
  int chainIndex_local;
  char tmp42 [2048];
  uint i;
  uchar check_bit;
  uchar chip_addr;
  uint j;
  
  dev->check_bit = '\0';
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"--- %s\n","software_set_address_onChain");
    _applog(7,tmp42,false);
  }
  dev->addrInterval = '\x02';
  check_bit = dev->addrInterval + 0xff;
  while (check_bit != '\0') {
    check_bit = check_bit >> 1;
    dev->check_bit = dev->check_bit + '\x01';
  }
  chip_addr = '\0';
  chain = (uchar)chainIndex;
  chain_inactive(chain);
  cgsleep_ms(0x1e);
  chain_inactive(chain);
  cgsleep_ms(0x1e);
  chain_inactive(chain);
  cgsleep_ms(0x1e);
  for (j = 0; uVar1 = __aeabi_idiv(0x100,dev->addrInterval), j < uVar1; j = j + 1) {
    set_address(chain,'\0',chip_addr);
    chip_addr = dev->addrInterval + chip_addr;
    cgsleep_ms(0x1e);
  }
  return;
}

