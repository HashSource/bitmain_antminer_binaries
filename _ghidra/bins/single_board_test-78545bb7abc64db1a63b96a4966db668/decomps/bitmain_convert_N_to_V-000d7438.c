
/* WARNING: Unknown calling convention */

double bitmain_convert_N_to_V(int32_t N)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  anon_union_160_2_9472fda9_for_eeprom_data_t_2 *paVar5;
  double *pdVar6;
  double dVar7;
  
  if ((!_g_power_state.power_Calibrated) || (!_g_is_use_calibration_data)) {
    dVar7 = bitmain_convert_N_to_V_furmula(N);
    return dVar7;
  }
  if (_g_power_state.eeprom.num < 2) {
    return -1.0;
  }
  pdVar6 = _g_power_state.eeprom.vol;
  dVar7 = -1.0;
  iVar1 = 0;
  paVar5 = &_g_power_state.eeprom.field_2;
  do {
    uVar4 = (uint)paVar5->N[0];
    iVar2 = iVar1 + 1;
    uVar3 = (uint)((anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar5->N + 1))->N[0];
    if (N < (int)uVar4) {
      if ((int)uVar3 <= N) goto LAB_000d7472;
    }
    else if ((N <= (int)uVar3) || (N <= (int)uVar4)) {
LAB_000d7472:
      dVar7 = *pdVar6 + ((_g_power_state.eeprom.vol[iVar1 + 1] - *pdVar6) /
                        (double)(longlong)(int)(uVar3 - uVar4)) * (double)(longlong)(int)(N - uVar4)
      ;
    }
    pdVar6 = pdVar6 + 1;
    iVar1 = iVar2;
    paVar5 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar5->N + 1);
    if (_g_power_state.eeprom.num + -1 <= iVar2) {
      return dVar7;
    }
  } while( true );
}

