
/* WARNING: Unknown calling convention */

int32_t set_chain_hwsweep_clk_mode_ctrl
                  (uint8_t which_chain,uint8_t core_num_dec_lock_en,uint8_t clk_mode_margin,
                  uint8_t core_clk_mode_sel)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (which_chain,'\x01',0,0xec,
                     core_clk_mode_sel & 3 | (clk_mode_margin & 1) << 2 |
                     (core_num_dec_lock_en & 1) << 3);
  return iVar1;
}

