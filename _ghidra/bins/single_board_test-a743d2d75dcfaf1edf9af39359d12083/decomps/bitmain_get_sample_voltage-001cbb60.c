
/* WARNING: Unknown calling convention */

double bitmain_get_sample_voltage(void)

{
  int32_t iVar1;
  uint uVar2;
  double dVar3;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_sample_voltage");
    _applog(0,tmp42,false);
    dVar3 = (double)(longlong)iVar1;
  }
  else {
    send_data[1] = 0xaa;
    send_data[0] = 'U';
    send_data[2] = '\x04';
    send_data[3] = '\x04';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    read_back_data[7] = '\0';
    send_data[4] = '\b';
    send_data[5] = '\0';
    iVar1 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,8);
    if (iVar1 == 0) {
      uVar2 = read_back_data._4_4_ & 0xffff;
      if (_g_power_state.power_version < 0x78) {
        if ((0x74 < _g_power_state.power_version) || (_g_power_state.power_version == 0x71)) {
          return (double)(longlong)(int)uVar2 * 0.015876;
        }
        if (_g_power_state.power_version != 0x73) {
          return -1.0;
        }
      }
      else if (_g_power_state.power_version != 0x78) {
        if (_g_power_state.power_version == 0xc1) {
          return (double)(longlong)(int)uVar2 * 0.003965;
        }
        return -1.0;
      }
      return (double)(longlong)(int)uVar2 * 0.018957;
    }
    builtin_strncpy(tmp42,"get sample N failed\n",0x14);
    tmp42._20_2_ = (ushort)(byte)tmp42[0x15] << 8;
    _applog(0,tmp42,false);
    builtin_strncpy(tmp42,"can nont get voltage",0x14);
    tmp42[0x14] = '\n';
    tmp42[0x15] = '\0';
    _applog(0,tmp42,false);
    dVar3 = -2147482880.0;
  }
  return dVar3;
}

