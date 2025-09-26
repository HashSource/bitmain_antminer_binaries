
/* WARNING: Unknown calling convention */

int32_t set_asic_clock_select_control
                  (uint8_t which_chain,uint32_t which_asic_address,uint8_t pulse_mode,
                  uint8_t clk_sel)

{
  int32_t iVar1;
  uint8_t in_stack_00000000;
  
  iVar1 = set_clock_select_control(which_chain,'\0',which_asic_address,clk_sel,in_stack_00000000);
  return iVar1;
}

