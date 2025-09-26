
/* WARNING: Unknown calling convention */

int32_t set_chain_clock_select_control(uint8_t which_chain,uint8_t pulse_mode,uint8_t clk_sel)

{
  int32_t iVar1;
  uint8_t in_stack_00000000;
  
  iVar1 = set_clock_select_control(which_chain,'\x01',0,clk_sel,in_stack_00000000);
  return iVar1;
}

