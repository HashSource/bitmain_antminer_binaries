
/* WARNING: Unknown calling convention */

int32_t bitmain_get_power_input_status(void)

{
  int32_t iVar1;
  uint8_t send_data [6];
  uint8_t read_back_data [10];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_power_input_status");
    _applog(0,tmp42,false);
  }
  else {
    if (_g_power_state.power_version == 0xc1) {
      send_data[0] = 'U';
      send_data[1] = 0xaa;
      send_data[2] = '\x04';
      send_data[3] = '\r';
      read_back_data[0] = '\0';
      read_back_data[1] = '\0';
      read_back_data[2] = '\0';
      read_back_data[3] = '\0';
      send_data[4] = '\x11';
      send_data[5] = '\0';
      read_back_data[4] = '\0';
      read_back_data[5] = '\0';
      read_back_data[6] = '\0';
      read_back_data[7] = '\0';
      read_back_data[8] = '\0';
      read_back_data[9] = '\0';
      iVar1 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,10);
      if (iVar1 == 0) {
        if (read_back_data._4_4_ != -0x7ffffd00) {
          iVar1._0_1_ = read_back_data[4];
          iVar1._1_1_ = read_back_data[5];
          iVar1._2_1_ = read_back_data[6];
          iVar1._3_1_ = read_back_data[7];
          return iVar1;
        }
      }
      else {
        builtin_strncpy(tmp42,"get power input status faile",0x1c);
        tmp42[0x1c] = 'd';
        tmp42[0x1d] = '\n';
        tmp42[0x1e] = '\0';
        _applog(0,tmp42,false);
      }
      snprintf(tmp42,0x800,"can nont get power input status; ret = 0x%x\n",0x80000300);
      _applog(0,tmp42,false);
    }
    iVar1 = -1;
  }
  return iVar1;
}

