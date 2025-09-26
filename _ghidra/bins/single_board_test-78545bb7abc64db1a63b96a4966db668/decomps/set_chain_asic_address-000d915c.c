
/* WARNING: Unknown calling convention */

int32_t set_chain_asic_address(uint8_t which_chain,uint32_t addr_interval)

{
  int iVar1;
  int iVar2;
  uint32_t which_asic_address;
  
  iVar1 = __aeabi_uidiv(0x100);
  if (iVar1 != 0) {
    iVar2 = 0;
    which_asic_address = 0;
    do {
      send_set_address_command(which_chain,which_asic_address);
      iVar2 = iVar2 + 1;
      usleep(10000);
      which_asic_address = which_asic_address + addr_interval;
    } while (iVar2 != iVar1);
  }
  return 0;
}

