
/* WARNING: Unknown calling convention */

int32_t _get_power_dc_voltage_v2(void)

{
  int32_t iVar1;
  uint uVar2;
  float fVar3;
  uint8_t cmd [6];
  uint8_t reply [32];
  float f_vol;
  char acStack_814 [2044];
  
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\x04';
  cmd[3] = '\x04';
  cmd[4] = '\x04';
  cmd[5] = '\x04';
  reply[4] = '\0';
  reply[5] = '\0';
  reply[6] = '\0';
  reply[7] = '\0';
  reply[8] = '\0';
  reply[9] = '\0';
  reply[10] = '\0';
  reply[0xb] = '\0';
  reply[0xc] = '\0';
  reply[0xd] = '\0';
  reply[0xe] = '\0';
  reply[0xf] = '\0';
  reply[0x10] = '\0';
  reply[0x11] = '\0';
  reply[0x12] = '\0';
  reply[0x13] = '\0';
  reply[0x14] = '\0';
  reply[0x15] = '\0';
  reply[0x16] = '\0';
  reply[0x17] = '\0';
  reply[0x18] = '\0';
  reply[0x19] = '\0';
  reply[0x1a] = '\0';
  reply[0x1b] = '\0';
  reply[0x1c] = '\0';
  reply[0x1d] = '\0';
  reply[0x1e] = '\0';
  reply[0x1f] = '\0';
  reply[0] = '\0';
  reply[1] = '\0';
  reply[2] = '\0';
  reply[3] = '\0';
  iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,10);
  if (iVar1 != 0) {
    f_vol = (float)0x20746547;
    builtin_strncpy(acStack_814,"power dc_volt value failed\n",0x1c);
    _applog(3,(char *)&f_vol,false);
    return 0;
  }
  f_vol = (float)reply._4_4_;
  fVar3 = (float)reply._4_4_ * 100.0 + 1e-05;
  uVar2 = (uint)(0.0 < fVar3) * (int)(longlong)fVar3;
  if ((_g_power_state.power_Calibrated != false) && (_g_is_use_calibration_data != false)) {
    fVar3 = bitmain_convert_calibration_V_to_origin_V((double)uVar2 / 100.0);
    return (int)(fVar3 * 100.0);
  }
  return uVar2;
}

