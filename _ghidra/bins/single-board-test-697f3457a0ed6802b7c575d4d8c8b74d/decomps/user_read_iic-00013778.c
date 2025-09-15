
int user_read_iic(runtime_base_t *runtime,int chip_addr,uint8_t i2c_dev_addr,uint8_t i2c_reg_addr,
                 uint8_t *i2c_reg_data,int len)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint8_t i2c_reg_addr_local;
  uint8_t i2c_dev_addr_local;
  int chip_addr_local;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  reg_list_item_t itemreg;
  int fd;
  int chainid;
  int i;
  int ret;
  
  ret = 1;
  iVar2 = runtime->chain_id;
  iVar3 = runtime->chain_status[iVar2].fd;
  iVar1 = user_i2c_state(runtime,chip_addr);
  if (iVar1 == 0) {
    iVar1 = (*runtime->i2c_recv)(iVar3,(uint8_t)chip_addr,i2c_dev_addr,i2c_reg_addr,len);
    if (iVar1 == 0) {
      itemreg.chainid = (uint8_t)iVar2;
      itemreg.reg_addr = ' ';
      itemreg.reg_data = 0;
      itemreg.age = 0;
      itemreg.chip_addr = (uint8_t)chip_addr;
      for (i = 0; i < len; i = i + 1) {
        iVar1 = read_reg_item(&itemreg,500);
        if ((iVar1 < 1) || ((itemreg.reg_data & 0xc0000000) != 0)) {
          if ((use_syslog != false) || ((opt_log_output != false || (0 < opt_log_level)))) {
            snprintf(tmp42,0x400,
                     "Read i2c failed chipaddr=%02x, i2c-regaddr=%02x i2c-regdata=%08x\n",chip_addr,
                     (uint)i2c_reg_addr,itemreg.reg_data);
            _applog(1,tmp42,false);
          }
          ret = 1;
        }
        else {
          i2c_reg_data[i] = (uint8_t)itemreg.reg_data;
          ret = 0;
        }
      }
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
        snprintf(tmp42,0x400,"Read i2c failed chipaddr=%02x, i2c-regaddr=%02x\n",chip_addr,
                 (uint)i2c_reg_addr);
        _applog(1,tmp42,false);
      }
      ret = 1;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"i2c state check failed\n",0x18);
      _applog(2,tmp42,false);
    }
    ret = 1;
  }
  return ret;
}

