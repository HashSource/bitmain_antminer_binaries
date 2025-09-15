
/* WARNING: Unknown calling convention */

void software_set_address_onChain(int chainIndex)

{
  uchar uVar1;
  int iVar2;
  uint uVar3;
  all_parameters *paVar4;
  undefined1 *puVar5;
  uchar address;
  uint uVar6;
  char tmp42 [2048];
  
  paVar4 = dev;
  uVar1 = opt_debug;
  puVar5 = (undefined1 *)((int)dev->temp + 0x16);
  dev->check_bit = '\0';
  if (((bool)uVar1) &&
     (((use_syslog != false || (opt_log_output != false)) || (uVar1 = '\0', 6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"--- %s\n","software_set_address_onChain");
    _applog(7,tmp42,false);
    puVar5 = (undefined1 *)((int)dev->temp + 0x16);
    uVar1 = dev->check_bit;
    paVar4 = dev;
  }
  puVar5[0x3a] = uVar1 + '\x02';
  paVar4->addrInterval = '\x04';
  uVar1 = (uchar)chainIndex;
  chain_inactive(uVar1);
  cgsleep_ms(0x1e);
  chain_inactive(uVar1);
  cgsleep_ms(0x1e);
  chain_inactive(uVar1);
  cgsleep_ms(0x1e);
  iVar2 = __aeabi_idiv(0x100,dev->addrInterval);
  if (iVar2 != 0) {
    address = '\0';
    uVar6 = 0;
    do {
      uVar6 = uVar6 + 1;
      set_address(uVar1,'\0',address);
      address = address + dev->addrInterval;
      cgsleep_ms(0x1e);
      uVar3 = __aeabi_idiv(0x100,dev->addrInterval);
    } while (uVar6 < uVar3);
  }
  return;
}

