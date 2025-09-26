
/* WARNING: Unknown calling convention */

double bitmain_get_sample_voltage(void)

{
  undefined4 uVar1;
  int32_t iVar2;
  uint uVar3;
  bool bVar4;
  double dVar5;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar2 = bitmain_power_open(), iVar2 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_sample_voltage");
    _applog(0,tmp42,false);
    return (double)(longlong)iVar2;
  }
  uVar3 = _g_power_state.power_version & 0xfffffff7;
  bVar4 = 0x61 < uVar3;
  if (uVar3 != 0x62) {
    bVar4 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar4 || (uVar3 == 0x62 || _g_power_state.power_version - 100 == 2)) {
    iVar2 = _get_power_dc_voltage_v2();
    if (iVar2 == 0) {
      builtin_strncpy(tmp42,"can nont get power statu",0x18);
      tmp42[0x18] = 's';
      tmp42[0x19] = '\n';
      tmp42[0x1a] = '\0';
      _applog(0,tmp42,false);
      return -1.0;
    }
    return (double)(longlong)iVar2;
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x04';
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[4] = '\b';
  send_data[5] = '\0';
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  iVar2 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,8);
  if (iVar2 != 0) {
    builtin_strncpy(tmp42,"get sample N failed\n",0x14);
    tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
    _applog(0,tmp42,false);
    uVar1 = tmp42._20_4_;
    builtin_strncpy(tmp42,"can nont get voltage\n",0x16);
    tmp42._22_2_ = SUB42(uVar1,2);
    _applog(0,tmp42,false);
    return -2147482880.0;
  }
  uVar3 = read_back_data._4_4_ & 0xffff;
  if (_g_power_state.power_version < 0x78) {
    if ((0x74 < _g_power_state.power_version) || (_g_power_state.power_version == 0x71)) {
      dVar5 = (double)(longlong)(int)uVar3 * 0.015876;
      goto LAB_000d61e8;
    }
    if (_g_power_state.power_version == 0x73) goto LAB_000d6164;
  }
  else {
    if (_g_power_state.power_version == 0x78) {
LAB_000d6164:
      return (double)diff_V + (double)(longlong)(int)uVar3 * 0.018957;
    }
    if (_g_power_state.power_version - 0xc1 < 2) {
      dVar5 = (double)(longlong)(int)uVar3 * 0.003965;
      goto LAB_000d61e8;
    }
  }
  dVar5 = -1.0;
LAB_000d61e8:
  return (double)diff_V + dVar5;
}

