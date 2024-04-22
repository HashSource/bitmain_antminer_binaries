
void check_asic_num(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  reg_list_item_t item_r;
  int asicid;
  
  (*runtime->read_register)(runtime->chain_status[runtime->chain_id].fd,1,'\0','\0');
  item_r.chainid = (uint8_t)runtime->chain_id;
  item_r.chip_addr = '\0';
  item_r.reg_addr = '\0';
  item_r.reg_data = 0;
  item_r.age = 0;
  runtime->chain_status[runtime->chain_id].real_asic_num = 0;
  for (asicid = 0; asicid < app_conf->asic_num; asicid = asicid + 1) {
    iVar1 = read_reg_item(&item_r,500);
    if (0 < iVar1) {
      runtime->chain_status[runtime->chain_id].real_asic_num =
           runtime->chain_status[runtime->chain_id].real_asic_num + 1;
    }
  }
  return;
}

