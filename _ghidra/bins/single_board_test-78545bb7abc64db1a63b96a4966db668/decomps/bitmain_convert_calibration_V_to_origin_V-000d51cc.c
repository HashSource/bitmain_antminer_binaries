
float bitmain_convert_calibration_V_to_origin_V(double cal_v)

{
  bool bVar1;
  anon_union_160_2_9472fda9_for_eeprom_data_t_2 *paVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  
  switch(_g_power_state.power_version) {
  case 0x62:
  case 100:
  case 0x65:
  case 0x66:
    if (_g_power_state.power_version != 0x62) {
      if (_g_power_state.power_version < 0x62) {
        return 0.0;
      }
      if (2 < _g_power_state.power_version - 100) {
        return 0.0;
      }
    }
    dVar6 = 17.0;
    if (22.1 < cal_v) {
      return -1.0;
    }
    break;
  default:
    return 0.0;
  case 0x6a:
    dVar6 = 12.0;
    if (16.5 < cal_v) {
      return -1.0;
    }
  }
  if ((int)((uint)(cal_v < dVar6 - 0.5) << 0x1f) < 0) {
    return -1.0;
  }
  iVar4 = _g_power_state.eeprom.num + -1;
  if (0 < iVar4) {
    paVar2 = &_g_power_state.eeprom.field_2;
    iVar3 = 1;
    do {
      while( true ) {
        dVar6 = paVar2->V[0];
        paVar2 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar2->V + 1);
        if (dVar6 - 0.001 < cal_v) break;
        bVar1 = iVar4 <= iVar3;
        iVar3 = iVar3 + 1;
        if (bVar1) goto LAB_000d525e;
      }
      if ((int)((uint)(cal_v < paVar2->V[0] + 0.001) << 0x1f) < 0) {
        dVar5 = _g_power_state.eeprom.vol[iVar3 + -1];
        cal_v = dVar5 + ((_g_power_state.eeprom.vol[iVar3] - dVar5) / (paVar2->V[0] - dVar6)) *
                        (cal_v - dVar6);
        break;
      }
      bVar1 = iVar3 < iVar4;
      iVar3 = iVar3 + 1;
    } while (bVar1);
  }
LAB_000d525e:
  return (float)cal_v;
}

