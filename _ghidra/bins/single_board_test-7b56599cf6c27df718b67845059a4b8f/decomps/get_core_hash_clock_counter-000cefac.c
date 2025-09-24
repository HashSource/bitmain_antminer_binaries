
/* WARNING: Unknown calling convention */

int32_t get_core_hash_clock_counter(uint8_t which_chain,uint8_t mode,uint32_t which_asic_address)

{
  int32_t iVar1;
  
  send_set_config_command(which_chain,mode,which_asic_address,0x3c,0x80008301);
  usleep(10000);
  iVar1 = send_set_config_command(which_chain,mode,which_asic_address,0x3c,0x80000400);
  return iVar1;
}

