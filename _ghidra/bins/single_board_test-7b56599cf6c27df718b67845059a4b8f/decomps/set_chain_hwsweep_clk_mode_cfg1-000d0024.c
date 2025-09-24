
/* WARNING: Unknown calling convention */

int32_t set_chain_hwsweep_clk_mode_cfg1(uint8_t which_chain,uint32_t clk_mode_cfg1)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\x01',0,0xe8,clk_mode_cfg1);
  return iVar1;
}

