
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
    dVar6 = 21.6;
    break;
  default:
    goto switchD_001ce4fe_caseD_63;
  case 0x6a:
    dVar6 = 16.0;
  }
  switch(_g_power_state.power_version) {
  case 0x62:
  case 100:
  case 0x65:
  case 0x66:
    dVar5 = 17.0;
    break;
  default:
switchD_001ce4fe_caseD_63:
    return 0.0;
  case 0x6a:
    if ((int)((uint)(dVar6 < 0.0) << 0x1f) < 0) {
      return 0.0;
    }
    dVar5 = 12.0;
  }
  if (((int)((uint)(dVar6 + 0.5 < cal_v) << 0x1f) < 0) ||
     ((int)((uint)(cal_v < dVar5 - 0.5) << 0x1f) < 0)) {
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
        if (bVar1) goto LAB_001ce5a4;
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
LAB_001ce5a4:
  return (float)cal_v;
}

