
/* WARNING: Unknown calling convention */

int32_t get_core_process_monitor
                  (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,uint8_t pm_sel)

{
  int32_t iVar1;
  
  send_set_config_command(which_chain,mode,which_asic_address,0x3c,pm_sel & 3 | 0x80008f04);
  usleep(10000);
  iVar1 = send_set_config_command(which_chain,mode,which_asic_address,0x3c,pm_sel & 3 | 0x80001004);
  return iVar1;
}

