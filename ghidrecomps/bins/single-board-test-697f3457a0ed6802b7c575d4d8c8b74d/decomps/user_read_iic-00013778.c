
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
      tmp42[0] = s_i2c_state_check_failed_00034290[0];
      tmp42[1] = s_i2c_state_check_failed_00034290[1];
      tmp42[2] = s_i2c_state_check_failed_00034290[2];
      tmp42[3] = s_i2c_state_check_failed_00034290[3];
      tmp42[4] = s_i2c_state_check_failed_00034290[4];
      tmp42[5] = s_i2c_state_check_failed_00034290[5];
      tmp42[6] = s_i2c_state_check_failed_00034290[6];
      tmp42[7] = s_i2c_state_check_failed_00034290[7];
      tmp42[8] = s_i2c_state_check_failed_00034290[8];
      tmp42[9] = s_i2c_state_check_failed_00034290[9];
      tmp42[10] = s_i2c_state_check_failed_00034290[10];
      tmp42[11] = s_i2c_state_check_failed_00034290[11];
      tmp42[12] = s_i2c_state_check_failed_00034290[12];
      tmp42[13] = s_i2c_state_check_failed_00034290[13];
      tmp42[14] = s_i2c_state_check_failed_00034290[14];
      tmp42[15] = s_i2c_state_check_failed_00034290[15];
      tmp42[16] = s_i2c_state_check_failed_00034290[16];
      tmp42[17] = s_i2c_state_check_failed_00034290[17];
      tmp42[18] = s_i2c_state_check_failed_00034290[18];
      tmp42[19] = s_i2c_state_check_failed_00034290[19];
      tmp42[20] = s_i2c_state_check_failed_00034290[20];
      tmp42[21] = s_i2c_state_check_failed_00034290[21];
      tmp42[22] = s_i2c_state_check_failed_00034290[22];
      tmp42[23] = s_i2c_state_check_failed_00034290[23];
      _applog(2,tmp42,false);
    }
    ret = 1;
  }
  return ret;
}

