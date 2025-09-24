
int32_t bitmain_set_voltage(double v)

{
  byte *pbVar1;
  uint32_t uVar2;
  int32_t iVar3;
  byte *pbVar4;
  double *pdVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  float f_tgt_vol;
  uint8_t cmd [10];
  char tmp42 [2048];
  
  uVar2 = _g_power_state.power_version;
  uVar7 = _g_power_state.power_version - 100;
  bVar8 = 0x61 < _g_power_state.power_version;
  if (_g_power_state.power_version != 0x62) {
    bVar8 = 1 < uVar7;
  }
  if (bVar8 && (_g_power_state.power_version != 0x62 && uVar7 != 2)) {
    if ((_g_power_state.power_open == 0) && (iVar3 = bitmain_power_open(), iVar3 < 0)) {
      snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
               "bitmain_set_voltage");
      _applog(0,tmp42,false);
      return iVar3;
    }
    uVar7 = bitmain_convert_V_to_N(v);
    if (0xff < uVar7) {
      return -0x7ffffcff;
    }
    iVar3 = _bitmain_set_DA_conversion_N(_g_power_state.power_fd,(uint8_t)uVar7);
    return iVar3;
  }
  f_tgt_vol = (float)v;
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\b';
  cmd[3] = 0x83;
  cmd[4] = '\0';
  cmd[5] = '\0';
  cmd[6] = '\0';
  cmd[7] = '\0';
  cmd[8] = '\0';
  cmd[9] = '\0';
  memset(tmp42,0,0x20);
  if ((_g_power_state.power_Calibrated != false) && (_g_is_use_calibration_data != false)) {
    if (uVar2 == 0x62) {
LAB_000cd7a4:
      if (1 < _g_power_state.eeprom.num) {
        pdVar5 = _g_power_state.eeprom.vol;
        iVar6 = 1;
        do {
          dVar11 = *pdVar5;
          pdVar5 = pdVar5 + 1;
          if (((dVar11 - 0.001 < v) &&
              (dVar9 = *pdVar5, (int)((uint)(v < dVar9 + 0.001) << 0x1f) < 0)) ||
             (((int)((uint)(v < dVar11 + 0.001) << 0x1f) < 0 &&
              (dVar9 = _g_power_state.eeprom.vol[iVar6], dVar9 - 0.001 < v)))) {
            dVar10 = *(double *)(_g_power_state.eeprom.sn + iVar6 * 8 + 0x10);
            dVar10 = dVar10 + ((*(double *)(_g_power_state.eeprom.sn + iVar6 * 8 + 0x18) - dVar10) /
                              (dVar9 - dVar11)) * (v - dVar11);
            if (22.1 < dVar10) {
              return -1;
            }
            if ((int)((uint)(dVar10 < 16.5) << 0x1f) < 0) {
              return -1;
            }
            f_tgt_vol = (float)dVar10;
            goto LAB_000cd852;
          }
          bVar8 = iVar6 < _g_power_state.eeprom.num + -1;
          iVar6 = iVar6 + 1;
        } while (bVar8);
      }
      return -1;
    }
    if (0x61 < uVar2) {
      if (uVar7 < 3) {
        if ((uVar2 == 0x62) || (0x61 < uVar2)) goto LAB_000cd7a4;
      }
      else if (uVar2 == 0x62) {
        f_tgt_vol = 0.0;
LAB_000cd852:
        if ((int)((uint)(f_tgt_vol < 0.0) << 0x1f) < 0) {
          return -1;
        }
        goto LAB_000cd70e;
      }
    }
    f_tgt_vol = 0.0;
  }
LAB_000cd70e:
  pbVar4 = cmd;
  cmd._8_2_ = 0;
  cmd._4_4_ = f_tgt_vol;
  do {
    pbVar1 = pbVar4 + 3;
    pbVar4 = pbVar4 + 2;
    cmd._8_2_ = cmd._8_2_ + (ushort)*pbVar4 + (ushort)*pbVar1 * 0x100;
  } while (cmd + 6 != pbVar4);
  iVar3 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,10,(uint8_t *)tmp42,10);
  return iVar3;
}

