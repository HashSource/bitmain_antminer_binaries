
/* WARNING: Unknown calling convention */

int32_t set_clock_select_control_by_coreId
                  (uint8_t which_chain,uint32_t which_asic_address,uint32_t which_core,
                  uint8_t clk_sel)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (which_chain,'\0',which_asic_address,0x3c,
                     (clk_sel & 3) << 1 | 0x8b00 | (which_core & 0xff) << 0x10);
  return iVar1;
}

