
/* WARNING: Unknown calling convention */

int32_t set_asic_hwsweep_clk_mode_cfg0
                  (uint8_t which_chain,uint32_t which_asic_address,uint32_t clk_mode_cfg0)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0xe4,clk_mode_cfg0);
  return iVar1;
}

