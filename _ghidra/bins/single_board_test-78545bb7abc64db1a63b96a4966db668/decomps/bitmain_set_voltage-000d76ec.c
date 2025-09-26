
int32_t bitmain_set_voltage(double v)

{
  byte *pbVar1;
  int32_t iVar2;
  byte *pbVar3;
  double *pdVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 uVar14;
  float f_tgt_vol;
  uint8_t cmd [10];
  uint8_t reply [32];
  char tmp42 [2048];
  
  uVar7 = _g_power_state.power_version - 100;
  uVar5 = _g_power_state.power_version & 0xfffffff7;
  bVar8 = 0x61 < uVar5;
  if (uVar5 != 0x62) {
    bVar8 = 1 < uVar7;
  }
  if (bVar8 && (uVar5 != 0x62 && uVar7 != 2)) {
    if ((_g_power_state.power_open == 0) && (iVar2 = bitmain_power_open(), iVar2 < 0)) {
      snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
               "bitmain_set_voltage");
      _applog(0,tmp42,false);
      return iVar2;
    }
    uVar5 = bitmain_convert_V_to_N(v);
    if (0xff < uVar5) {
      return -0x7ffffcff;
    }
    iVar2 = _bitmain_set_DA_conversion_N(_g_power_state.power_fd,(uint8_t)uVar5);
    dVar9 = bitmain_V_diff_of_N(uVar5);
    diff_V = (float)dVar9;
    return iVar2;
  }
  f_tgt_vol = (float)v;
  reply[4] = '\0';
  reply[5] = '\0';
  reply[6] = '\0';
  reply[7] = '\0';
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\b';
  cmd[3] = 0x83;
  cmd[4] = '\0';
  cmd[5] = '\0';
  cmd[6] = '\0';
  cmd[7] = '\0';
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
  cmd[8] = '\0';
  cmd[9] = '\0';
  if ((_g_power_state.power_Calibrated) && (_g_is_use_calibration_data)) {
    switch(_g_power_state.power_version) {
    case 0x62:
    case 100:
    case 0x65:
    case 0x66:
      if ((_g_power_state.power_version != 0x62) &&
         ((_g_power_state.power_version < 0x62 || (2 < uVar7)))) {
switchD_000d7954_caseD_1:
        f_tgt_vol = 0.0;
        goto LAB_000d77a4;
      }
      dVar10 = 21.6;
      dVar9 = 17.0;
      break;
    default:
      switch(_g_power_state.power_version - 0x62) {
      case 0:
      case 2:
      case 3:
      case 4:
        f_tgt_vol = 0.0;
        break;
      default:
        goto switchD_000d7954_caseD_1;
      }
      goto LAB_000d78fc;
    case 0x6a:
      dVar10 = 16.0;
      dVar9 = 12.0;
    }
    if (1 < _g_power_state.eeprom.num) {
      pdVar4 = _g_power_state.eeprom.vol;
      iVar6 = 1;
      do {
        dVar13 = *pdVar4;
        pdVar4 = pdVar4 + 1;
        if (((dVar13 - 0.001 < v) &&
            (dVar11 = *pdVar4, (int)((uint)(v < dVar11 + 0.001) << 0x1f) < 0)) ||
           (((int)((uint)(v < dVar13 + 0.001) << 0x1f) < 0 &&
            (dVar11 = _g_power_state.eeprom.vol[iVar6], dVar11 - 0.001 < v)))) {
          dVar12 = *(double *)(_g_power_state.eeprom.sn + iVar6 * 8 + 0x10);
          dVar12 = dVar12 + ((*(double *)(_g_power_state.eeprom.sn + iVar6 * 8 + 0x18) - dVar12) /
                            (dVar11 - dVar13)) * (v - dVar13);
          if ((dVar10 + 0.5 < dVar12) || ((int)((uint)(dVar12 < dVar9 - 0.5) << 0x1f) < 0))
          goto LAB_000d790c;
          f_tgt_vol = (float)dVar12;
          goto LAB_000d78fc;
        }
        bVar8 = iVar6 < _g_power_state.eeprom.num + -1;
        iVar6 = iVar6 + 1;
      } while (bVar8);
      if (v <= _g_power_state.eeprom.vol[0] - 0.001) {
        dVar13 = _g_power_state.eeprom.vol[_g_power_state.eeprom.num + -1];
        if (-1 < (int)((uint)(v < dVar13 + 0.001) << 0x1f)) goto LAB_000d790c;
        uVar14 = *(undefined8 *)(_g_power_state.eeprom.sn + _g_power_state.eeprom.num * 8 + 0x10);
        dVar11 = (double)uVar14 -
                 *(double *)(_g_power_state.eeprom.sn + _g_power_state.eeprom.num * 8 + 8);
        dVar12 = dVar13 - _g_power_state.eeprom.vol[_g_power_state.eeprom.num + -2];
      }
      else {
        dVar11 = _g_power_state.eeprom.field_2.V[1] - _g_power_state.eeprom.field_2.V[0];
        dVar12 = _g_power_state.eeprom.vol[1] - _g_power_state.eeprom.vol[0];
        uVar14 = _g_power_state.eeprom.field_2.V[0];
        dVar13 = _g_power_state.eeprom.vol[0];
      }
      dVar13 = (double)uVar14 + (dVar11 / dVar12) * (v - dVar13);
      if ((dVar13 <= dVar10 + 0.5) && (-1 < (int)((uint)(dVar13 < dVar9 - 0.5) << 0x1f))) {
        f_tgt_vol = (float)dVar13;
LAB_000d78fc:
        if (-1 < (int)((uint)(f_tgt_vol < 0.0) << 0x1f)) goto LAB_000d77a4;
      }
    }
LAB_000d790c:
    builtin_strncpy(tmp42,"calibration convert error \n",0x1c);
    _applog(3,tmp42,false);
    iVar2 = -1;
  }
  else {
LAB_000d77a4:
    pbVar3 = cmd;
    cmd._8_2_ = 0;
    cmd._4_4_ = f_tgt_vol;
    do {
      pbVar1 = pbVar3 + 3;
      pbVar3 = pbVar3 + 2;
      cmd._8_2_ = cmd._8_2_ + (ushort)*pbVar3 + (ushort)*pbVar1 * 0x100;
    } while (pbVar3 != cmd + 6);
    iVar2 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,10,reply,10);
  }
  return iVar2;
}

