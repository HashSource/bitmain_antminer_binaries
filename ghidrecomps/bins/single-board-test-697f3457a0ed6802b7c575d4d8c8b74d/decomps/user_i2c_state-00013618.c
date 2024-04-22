
int user_i2c_state(runtime_base_t *runtime,int chip_addr)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int chip_addr_local;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  reg_list_item_t item;
  int chainid;
  int check_loop;
  
  iVar3 = runtime->chain_id;
  check_loop = 3;
  do {
    (*runtime->i2c_status)(runtime->chain_status[iVar3].fd,(uint8_t)chip_addr);
    item.reg_data = 0;
    item.age = 0;
    item.chip_addr = (uint8_t)chip_addr;
    item.chainid = (uint8_t)runtime->chain_id;
    item.reg_addr = ' ';
    item._3_1_ = 0;
    iVar2 = read_reg_item(&item,1000);
    if (iVar2 < 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
        snprintf(tmp42,0x400,"chipaddr %02x - i2c no-response\n",chip_addr);
        _applog(1,tmp42,false);
      }
    }
    else {
      if (-1 < (int)item.reg_data) break;
      if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
        snprintf(tmp42,0x400,"chipaddr %02x - i2c is busy\n",chip_addr);
        _applog(1,tmp42,false);
      }
    }
    iVar2 = check_loop + -1;
    bVar1 = 0 < check_loop;
    check_loop = iVar2;
  } while (bVar1);
  if (check_loop < 1) {
    iVar3 = -1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

