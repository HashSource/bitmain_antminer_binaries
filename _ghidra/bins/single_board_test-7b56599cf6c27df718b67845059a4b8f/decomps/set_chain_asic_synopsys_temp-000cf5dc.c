
/* WARNING: Unknown calling convention */

int32_t set_chain_asic_synopsys_temp
                  (uint8_t which_chain,uint32_t which_asic_address,_Bool ts_soft_rstn,_Bool ts_cload
                  ,_Bool run_en,_Bool ts_pd)

{
  int32_t iVar1;
  uint reg_data;
  
  reg_data = 0x20000;
  if (!ts_soft_rstn) {
    reg_data = 0;
  }
  if (ts_cload) {
    reg_data = reg_data | 0x1000000;
  }
  if (run_en) {
    reg_data = reg_data | 0x10000000;
  }
  if (ts_pd) {
    reg_data = reg_data | 0x80000000;
  }
  iVar1 = send_set_config_command(which_chain,'\x01',which_asic_address,0xb0,reg_data);
  return iVar1;
}

