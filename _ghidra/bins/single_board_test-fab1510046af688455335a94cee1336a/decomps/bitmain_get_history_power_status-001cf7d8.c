
/* WARNING: Unknown calling convention */

int32_t bitmain_get_history_power_status(void)

{
  int32_t iVar1;
  uint8_t send_data [6];
  uint8_t read_back_data [14];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_history_power_status");
    _applog(0,tmp42,false);
  }
  else {
    if (_g_power_state.power_version - 0xc1 < 2) {
      send_data[0] = 'U';
      send_data[1] = 0xaa;
      send_data[2] = '\x04';
      send_data[3] = '\n';
      read_back_data[0] = '\0';
      read_back_data[1] = '\0';
      read_back_data[2] = '\0';
      read_back_data[3] = '\0';
      send_data[4] = '\x0e';
      send_data[5] = '\0';
      read_back_data[4] = '\0';
      read_back_data[5] = '\0';
      read_back_data[6] = '\0';
      read_back_data[7] = '\0';
      read_back_data[8] = '\0';
      read_back_data[9] = '\0';
      read_back_data[10] = '\0';
      read_back_data[0xb] = '\0';
      read_back_data[0xc] = '\0';
      read_back_data[0xd] = '\0';
      iVar1 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,0xe);
      if (iVar1 == 0) {
        if (read_back_data._8_4_ != -0x7ffffd00) {
          iVar1._0_1_ = read_back_data[8];
          iVar1._1_1_ = read_back_data[9];
          iVar1._2_1_ = read_back_data[10];
          iVar1._3_1_ = read_back_data[0xb];
          return iVar1;
        }
      }
      else {
        builtin_strncpy(tmp42,"get power status failed\n",0x18);
        tmp42[0x18] = '\0';
        _applog(0,tmp42,false);
      }
      snprintf(tmp42,0x800,"can nont get history power status; ret = 0x%x\n",0x80000300);
      _applog(0,tmp42,false);
    }
    iVar1 = -1;
  }
  return iVar1;
}

