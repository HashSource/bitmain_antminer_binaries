
/* WARNING: Unknown calling convention */

int32_t get_asic_process_monitor(uint8_t which_chain,uint32_t which_asic_address,uint8_t pm_sel)

{
  int32_t iVar1;
  
  iVar1 = get_core_process_monitor(which_chain,'\0',which_asic_address,pm_sel);
  return iVar1;
}

