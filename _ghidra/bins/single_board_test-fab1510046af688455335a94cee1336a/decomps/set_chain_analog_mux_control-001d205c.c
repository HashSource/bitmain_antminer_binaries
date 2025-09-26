
/* WARNING: Unknown calling convention */

int32_t set_chain_analog_mux_control(uint8_t which_chain,uint8_t mux_sel)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\x01',0,0x54,mux_sel & 0xf);
  return iVar1;
}

