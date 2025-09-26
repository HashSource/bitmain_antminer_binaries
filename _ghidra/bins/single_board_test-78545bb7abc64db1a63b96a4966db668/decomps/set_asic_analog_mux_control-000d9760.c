
/* WARNING: Unknown calling convention */

int32_t set_asic_analog_mux_control(uint8_t which_chain,uint32_t which_asic_address,uint8_t mux_sel)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0x54,mux_sel & 0xf);
  return iVar1;
}

