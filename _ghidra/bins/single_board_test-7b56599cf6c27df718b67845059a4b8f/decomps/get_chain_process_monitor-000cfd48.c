
/* WARNING: Unknown calling convention */

int32_t get_chain_process_monitor(uint8_t which_chain,uint8_t pm_sel)

{
  int32_t iVar1;
  
  iVar1 = get_core_process_monitor(which_chain,'\x01',0,pm_sel);
  return iVar1;
}

