
int user_check_communication(runtime_base_t *runtime)

{
  int iVar1;
  int iVar2;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  reg_list_item_t item;
  uint8_t regaddr;
  uint8_t chipaddr;
  int count_max;
  int chainid;
  int count;
  
  iVar2 = runtime->chain_id;
  count = 0;
  item.chainid = (uint8_t)iVar2;
  item.chip_addr = '\0';
  item.reg_addr = '\0';
  item.reg_data = 0;
  item.age = 0;
  do {
    (*runtime->read_register)(runtime->chain_status[iVar2].fd,1,'\0','\0');
    iVar1 = read_reg_item(&item,500);
    if (-1 < iVar1) {
      return count;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s  failed %d\n","user_check_communication",count);
      _applog(2,tmp42,false);
    }
    sleep(1);
    count = count + 1;
  } while (count < 3);
  return -1;
}

