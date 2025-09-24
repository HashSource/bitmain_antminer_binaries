
/* WARNING: Unknown calling convention */

int32_t get_asic_clock_delay_control(uint8_t which_chain,uint32_t which_asic_address)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0x3c,0x80000000);
  return iVar1;
}

