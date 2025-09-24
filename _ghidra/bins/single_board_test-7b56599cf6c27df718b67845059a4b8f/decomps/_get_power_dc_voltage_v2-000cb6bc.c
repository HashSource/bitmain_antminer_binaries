
/* WARNING: Unknown calling convention */

int32_t _get_power_dc_voltage_v2(void)

{
  float fVar1;
  int32_t iVar2;
  bool bVar3;
  uint8_t cmd [6];
  uint8_t reply [32];
  float f_vol;
  char acStack_80c [2048];
  
  bVar3 = 0x61 < _g_power_state.power_version;
  if (_g_power_state.power_version != 0x62) {
    bVar3 = 1 < _g_power_state.power_version - 100;
  }
  if (bVar3 && (_g_power_state.power_version != 0x62 && _g_power_state.power_version - 100 != 2)) {
    return 0;
  }
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\x04';
  cmd[3] = '\x04';
  cmd[4] = '\x04';
  cmd[5] = '\x04';
  memset(reply,0,0x20);
  iVar2 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,10);
  if (iVar2 == 0) {
    f_vol = (float)CONCAT13(reply[7],CONCAT12(reply[6],CONCAT11(reply[5],reply[4])));
    fVar1 = f_vol * 100.0 + 1e-05;
    return (uint)(0.0 < fVar1) * (int)(longlong)fVar1;
  }
  f_vol = (float)0x20746547;
  builtin_strncpy(acStack_80c,"power dc_volt value failed\n",0x1c);
  _applog(3,(char *)&f_vol,false);
  return 0;
}

