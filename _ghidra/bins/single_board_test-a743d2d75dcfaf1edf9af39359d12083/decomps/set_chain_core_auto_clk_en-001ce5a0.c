
/* WARNING: Unknown calling convention */

int32_t set_chain_core_auto_clk_en(uint8_t which_chain,uint8_t mode_mask,_Bool auto_clk_en)

{
  int32_t iVar1;
  _Bool in_stack_00000000;
  
  iVar1 = set_auto_clk_en(which_chain,'\0',(uint)mode_mask,auto_clk_en,in_stack_00000000);
  return iVar1;
}

