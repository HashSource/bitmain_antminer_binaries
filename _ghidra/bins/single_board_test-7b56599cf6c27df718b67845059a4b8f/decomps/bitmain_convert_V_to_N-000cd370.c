
int32_t bitmain_convert_V_to_N(double v)

{
  bool bVar1;
  double *pdVar2;
  uint uVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  int32_t local_14;
  
  if ((_g_power_state.power_Calibrated) && (_g_is_use_calibration_data)) {
    if (1 < _g_power_state.eeprom.num) {
      pdVar2 = _g_power_state.eeprom.vol;
      iVar4 = 1;
      do {
        dVar6 = *pdVar2;
        pdVar2 = pdVar2 + 1;
        if (((dVar6 - 0.001 < v) && (dVar5 = *pdVar2, (int)((uint)(v < dVar5 + 0.001) << 0x1f) < 0))
           || (((int)((uint)(v < dVar6 + 0.001) << 0x1f) < 0 &&
               (dVar5 = _g_power_state.eeprom.vol[iVar4], dVar5 - 0.001 < v)))) {
          uVar3 = (uint)(byte)_g_power_state.eeprom.sn[iVar4 + 0x17];
          dVar6 = round((double)(longlong)(int)uVar3 +
                        ((double)(longlong)
                                 (int)((byte)_g_power_state.eeprom.sn[iVar4 + 0x18] - uVar3) /
                        (dVar5 - dVar6)) * (v - dVar6));
          if ((uint)(longlong)dVar6 < 0x100) {
            return (uint)(longlong)dVar6;
          }
          return -1;
        }
        bVar1 = iVar4 < _g_power_state.eeprom.num + -1;
        iVar4 = iVar4 + 1;
      } while (bVar1);
    }
switchD_000cd392_caseD_23:
    return -1;
  }
  switch(_g_power_state.power_version) {
  case 0x22:
    local_14 = (int32_t)(longlong)(1215.89444 - v * 59.931507);
    break;
  default:
    goto switchD_000cd392_caseD_23;
  case 0x41:
  case 0x42:
    local_14 = (int32_t)(longlong)(765.411764 - v * 35.833333);
    break;
  case 0x43:
    local_14 = (int32_t)(longlong)(933.240365 - v * 59.806034);
    break;
  case 0x61:
    local_14 = (int32_t)(longlong)(1144.502262 - v * 52.243589);
    break;
  case 0x62:
  case 100:
  case 0x65:
  case 0x66:
    local_14 = (int32_t)(longlong)(0.0 - v);
    break;
  case 0x71:
  case 0x72:
  case 0x75:
  case 0x77:
    return (int32_t)(longlong)(1190.935338 - v * 78.742588);
  case 0x73:
  case 0x78:
    local_14 = (int32_t)(longlong)(1280.577821 - v * 73.979365);
    break;
  case 0x74:
  case 0x76:
    local_14 = (int32_t)(longlong)(1156.107585 - v * 76.090494);
    break;
  case 0xc1:
  case 0xc2:
    if ((_g_power_state.power_fw_version == 0x80000300) ||
       ((_g_power_state.power_fw_version & 0xff) < 4)) {
      local_14 = (int32_t)(longlong)(1275.0 - v * 85.0);
    }
    else {
      local_14 = (int32_t)(longlong)(1083.75 - v * 70.83333333333);
    }
  }
  return local_14;
}

