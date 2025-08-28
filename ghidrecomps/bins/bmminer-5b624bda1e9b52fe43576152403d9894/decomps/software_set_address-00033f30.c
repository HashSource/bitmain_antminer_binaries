
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void software_set_address(void)

{
  uchar uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  all_parameters *paVar5;
  int iVar6;
  uchar address;
  uint uVar7;
  char tmp42 [2048];
  
  paVar5 = dev;
  uVar1 = opt_debug;
  puVar4 = (undefined1 *)((int)dev->temp + 0x16);
  dev->check_bit = '\0';
  if (((bool)uVar1) &&
     (((use_syslog != false || (opt_log_output != false)) || (uVar1 = '\0', 6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"--- %s\n","software_set_address");
    _applog(7,tmp42,false);
    puVar4 = (undefined1 *)((int)dev->temp + 0x16);
    uVar1 = dev->check_bit;
    paVar5 = dev;
  }
  iVar6 = 0;
  puVar4[0x3a] = uVar1 + '\x02';
  paVar5->addrInterval = '\x04';
  while( true ) {
    if ((paVar5->chain_exist[iVar6] == 1) && (paVar5->chain_asic_num[iVar6] != '\0')) {
      uVar1 = (uchar)iVar6;
      chain_inactive(uVar1);
      cgsleep_ms(0x1e);
      chain_inactive(uVar1);
      cgsleep_ms(0x1e);
      chain_inactive(uVar1);
      cgsleep_ms(0x1e);
      iVar2 = __aeabi_idiv(0x100,dev->addrInterval);
      if (iVar2 != 0) {
        address = '\0';
        uVar7 = 0;
        do {
          uVar7 = uVar7 + 1;
          set_address(uVar1,'\0',address);
          address = address + dev->addrInterval;
          cgsleep_ms(0x1e);
          uVar3 = __aeabi_idiv(0x100,dev->addrInterval);
        } while (uVar7 < uVar3);
      }
    }
    paVar5 = dev;
    if (iVar6 == 0xf) break;
    iVar6 = iVar6 + 1;
    dev = paVar5;
  }
  dev = paVar5;
  return;
}

