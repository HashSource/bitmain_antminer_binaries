
int32_t bitmain_set_voltage(double v)

{
  byte *pbVar1;
  uint32_t uVar2;
  int32_t iVar3;
  uint uVar4;
  byte *pbVar5;
  double *pdVar6;
  int iVar7;
  bool bVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  float f_tgt_vol;
  uint8_t cmd [10];
  uint8_t reply [32];
  char tmp42 [2048];
  
  uVar2 = _g_power_state.power_version;
  uVar4 = _g_power_state.power_version & 0xfffffff7;
  bVar8 = 0x61 < uVar4;
  if (uVar4 != 0x62) {
    bVar8 = 1 < _g_power_state.power_version - 100;
  }
  if (bVar8 && (uVar4 != 0x62 && _g_power_state.power_version - 100 != 2)) {
    if ((_g_power_state.power_open == 0) && (iVar3 = bitmain_power_open(), iVar3 < 0)) {
      snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
               "bitmain_set_voltage");
      _applog(0,tmp42,false);
      return iVar3;
    }
    uVar4 = bitmain_convert_V_to_N(v);
    if (uVar4 < 0x100) {
      iVar3 = _bitmain_set_DA_conversion_N(_g_power_state.power_fd,(uint8_t)uVar4);
      dVar9 = bitmain_V_diff_of_N(uVar4);
      diff_V = (float)dVar9;
      return iVar3;
    }
    return -0x7ffffcff;
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
  memset(reply,0,0x20);
  if ((_g_power_state.power_Calibrated == false) || (_g_is_use_calibration_data == false))
  goto LAB_001d0a6c;
  iVar7 = uVar2 - 0x62;
  switch(iVar7) {
  case 0:
  case 2:
  case 3:
  case 4:
    dVar9 = 21.6;
    break;
  default:
    switch(iVar7) {
    case 0:
    case 2:
    case 3:
    case 4:
      f_tgt_vol = 0.0;
      break;
    default:
      goto switchD_001d0c38_caseD_1;
    }
    goto LAB_001d0bfa;
  case 8:
    dVar9 = 16.0;
  }
  switch(iVar7) {
  case 0:
  case 2:
  case 3:
  case 4:
    dVar10 = 17.0;
    break;
  default:
switchD_001d0c38_caseD_1:
    f_tgt_vol = 0.0;
    goto LAB_001d0a6c;
  case 8:
    if ((int)((uint)(dVar9 < 0.0) << 0x1f) < 0) goto switchD_001d0c38_caseD_1;
    dVar10 = 12.0;
  }
  if (1 < _g_power_state.eeprom.num) {
    pdVar6 = _g_power_state.eeprom.vol;
    iVar7 = 1;
    do {
      dVar13 = *pdVar6;
      pdVar6 = pdVar6 + 1;
      if (((dVar13 - 0.001 < v) && (dVar11 = *pdVar6, (int)((uint)(v < dVar11 + 0.001) << 0x1f) < 0)
          ) || (((int)((uint)(v < dVar13 + 0.001) << 0x1f) < 0 &&
                (dVar11 = _g_power_state.eeprom.vol[iVar7], dVar11 - 0.001 < v)))) {
        dVar12 = *(double *)(_g_power_state.eeprom.sn + iVar7 * 8 + 0x10);
        dVar12 = dVar12 + ((*(double *)(_g_power_state.eeprom.sn + iVar7 * 8 + 0x18) - dVar12) /
                          (dVar11 - dVar13)) * (v - dVar13);
        if ((dVar9 + 0.5 < dVar12) || ((int)((uint)(dVar12 < dVar10 - 0.5) << 0x1f) < 0))
        goto LAB_001d0c0a;
        f_tgt_vol = (float)dVar12;
        goto LAB_001d0bfa;
      }
      bVar8 = iVar7 < _g_power_state.eeprom.num + -1;
      iVar7 = iVar7 + 1;
    } while (bVar8);
    if (v <= _g_power_state.eeprom.vol[0] - 0.001) {
      dVar13 = _g_power_state.eeprom.vol[_g_power_state.eeprom.num + -1];
      if ((-1 < (int)((uint)(v < dVar13 + 0.001) << 0x1f)) ||
         (dVar11 = *(double *)(_g_power_state.eeprom.sn + _g_power_state.eeprom.num * 8 + 0x10),
         dVar11 = dVar11 + ((dVar11 - *(double *)
                                       (_g_power_state.eeprom.sn + _g_power_state.eeprom.num * 8 + 8
                                       )) /
                           (dVar13 - _g_power_state.eeprom.vol[_g_power_state.eeprom.num + -2])) *
                           (v - dVar13), dVar9 + 0.5 < dVar11)) goto LAB_001d0c0a;
      bVar8 = dVar11 < dVar10 - 0.5;
    }
    else {
      dVar11 = _g_power_state.eeprom.field_2.V[0] +
               ((_g_power_state.eeprom.field_2.V[1] - _g_power_state.eeprom.field_2.V[0]) /
               (_g_power_state.eeprom.vol[1] - _g_power_state.eeprom.vol[0])) *
               (v - _g_power_state.eeprom.vol[0]);
      if (dVar9 + 0.5 < dVar11) goto LAB_001d0c0a;
      bVar8 = dVar11 < dVar10 - 0.5;
    }
    if (-1 < (int)((uint)bVar8 << 0x1f)) {
      f_tgt_vol = (float)dVar11;
LAB_001d0bfa:
      if (-1 < (int)((uint)(f_tgt_vol < 0.0) << 0x1f)) {
LAB_001d0a6c:
        pbVar5 = cmd;
        cmd._8_2_ = 0;
        cmd._4_4_ = f_tgt_vol;
        do {
          pbVar1 = pbVar5 + 3;
          pbVar5 = pbVar5 + 2;
          cmd._8_2_ = cmd._8_2_ + (ushort)*pbVar5 + (ushort)*pbVar1 * 0x100;
        } while (cmd + 6 != pbVar5);
        iVar3 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,10,reply,10);
        return iVar3;
      }
    }
  }
LAB_001d0c0a:
  builtin_strncpy(tmp42,"calibration convert error \n",0x1c);
  _applog(3,tmp42,false);
  return -1;
}

