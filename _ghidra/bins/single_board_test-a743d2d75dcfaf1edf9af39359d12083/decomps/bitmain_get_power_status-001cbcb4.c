
/* WARNING: Unknown calling convention */

int32_t bitmain_get_power_status(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (uVar2 = bitmain_power_open(), (int)uVar2 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_power_status");
    _applog(0,tmp42,false);
  }
  else {
    bVar3 = 0x61 < _g_power_state.power_version;
    if (_g_power_state.power_version != 0x62) {
      bVar3 = 1 < _g_power_state.power_version - 100;
    }
    if (!bVar3 || (_g_power_state.power_version == 0x62 || _g_power_state.power_version - 100 == 2))
    {
      tmp42[0] = '\0';
      tmp42[1] = '\0';
      tmp42[2] = '\0';
      tmp42[3] = '\0';
      read_back_data[0] = 'U';
      read_back_data[1] = 0xaa;
      read_back_data[2] = '\x04';
      read_back_data[3] = '\x0e';
      read_back_data[4] = '\x04';
      read_back_data[5] = '\x0e';
      tmp42[4] = '\0';
      tmp42[5] = '\0';
      tmp42[6] = '\0';
      tmp42[7] = '\0';
      tmp42[8] = '\0';
      tmp42[9] = '\0';
      tmp42[10] = '\0';
      tmp42[0xb] = '\0';
      tmp42[0xc] = '\0';
      tmp42[0xd] = '\0';
      tmp42[0xe] = '\0';
      tmp42[0xf] = '\0';
      tmp42[0x10] = '\0';
      tmp42[0x11] = '\0';
      tmp42[0x12] = '\0';
      tmp42[0x13] = '\0';
      uVar2 = exec_power_cmd_v2(_g_power_state.power_fd,read_back_data,6,(uint8_t *)tmp42,0xe);
      if (uVar2 != 0) {
        builtin_strncpy(tmp42,"can nont get power statu",0x18);
        tmp42[0x18] = 's';
        tmp42[0x19] = '\n';
        tmp42[0x1a] = '\0';
        _applog(0,tmp42,false);
      }
    }
    else {
      if (_g_power_state.power_version == 0xc1) {
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
        iVar1 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,0xe);
        uVar2 = read_back_data._4_4_;
      }
      else {
        send_data[0] = 'U';
        send_data[1] = 0xaa;
        send_data[2] = '\x04';
        send_data[3] = '\n';
        send_data[4] = '\x0e';
        send_data[5] = '\0';
        read_back_data[0] = '\0';
        read_back_data[1] = '\0';
        read_back_data[2] = '\0';
        read_back_data[3] = '\0';
        read_back_data[4] = '\0';
        read_back_data[5] = '\0';
        read_back_data[6] = '\0';
        read_back_data[7] = '\0';
        iVar1 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,8);
        uVar2 = read_back_data._4_4_ & 0xffff;
      }
      if (iVar1 != 0) {
        uVar2 = 0x80000300;
        builtin_strncpy(tmp42,"get power status failed\n",0x18);
        tmp42._24_2_ = (ushort)(byte)tmp42[0x19] << 8;
        _applog(0,tmp42,false);
      }
      if (uVar2 == 0x80000300) {
        builtin_strncpy(tmp42,"can nont get power statu",0x18);
        tmp42[0x18] = 's';
        tmp42[0x19] = '\n';
        tmp42[0x1a] = '\0';
        _applog(0,tmp42,false);
        return -0x7ffffd00;
      }
    }
  }
  return uVar2;
}

