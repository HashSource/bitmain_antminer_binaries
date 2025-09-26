
/* WARNING: Unknown calling convention */

int32_t set_chain_asic_address_ex(uint8_t which_chain,uint32_t addr_interval,uint32_t asic_num)

{
  uint32_t uVar1;
  uint32_t which_asic_address;
  
  if (asic_num != 0) {
    uVar1 = 0;
    which_asic_address = 0;
    do {
      send_set_address_command(which_chain,which_asic_address);
      uVar1 = uVar1 + 1;
      usleep(10000);
      which_asic_address = which_asic_address + addr_interval;
    } while (uVar1 != asic_num);
    return 0;
  }
  return 0;
}

