
/* WARNING: Unknown calling convention */

int32_t _get_power_dc_voltage_v2(void)

{
  int32_t iVar1;
  uint uVar2;
  float fVar3;
  float extraout_s5;
  uint8_t cmd [6];
  uint8_t reply [32];
  float f_vol;
  char acStack_80c [2048];
  
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\x04';
  cmd[3] = '\x04';
  cmd[4] = '\x04';
  cmd[5] = '\x04';
  memset(reply,0,0x20);
  iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,10);
  if (iVar1 != 0) {
    f_vol = (float)0x20746547;
    builtin_strncpy(acStack_80c,"power dc_volt value failed\n",0x1c);
    _applog(3,(char *)&f_vol,false);
    return 0;
  }
  f_vol = (float)CONCAT13(reply[7],CONCAT12(reply[6],CONCAT11(reply[5],reply[4])));
  fVar3 = f_vol * 100.0 + 1e-05;
  uVar2 = (uint)(0.0 < fVar3) * (int)(longlong)fVar3;
  if ((_g_power_state.power_Calibrated != false) && (_g_is_use_calibration_data != false)) {
    fVar3 = bitmain_convert_calibration_V_to_origin_V((double)uVar2 / 100.0);
    return (int)(fVar3 * extraout_s5);
  }
  return uVar2;
}

