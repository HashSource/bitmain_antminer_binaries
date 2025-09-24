
/* WARNING: Unknown calling convention */

uint32_t bitmain_get_voltage(void)

{
  undefined4 uVar1;
  int32_t iVar2;
  uint32_t uVar3;
  anon_union_160_2_9472fda9_for_eeprom_data_t_2 *paVar4;
  int iVar5;
  bool bVar6;
  double dVar7;
  double dVar8;
  uint uVar9;
  double dVar10;
  float fVar11;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  char tmp42 [2048];
  
  bVar6 = 0x61 < _g_power_state.power_version;
  if (_g_power_state.power_version != 0x62) {
    bVar6 = 1 < _g_power_state.power_version - 100;
  }
  if (bVar6 && (_g_power_state.power_version != 0x62 && _g_power_state.power_version - 100 != 2)) {
    if ((_g_power_state.power_open == 0) && (uVar3 = bitmain_power_open(), (int)uVar3 < 0)) {
      snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
               "bitmain_get_voltage");
      _applog(0,tmp42,false);
      return uVar3;
    }
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[2] = '\x04';
    send_data[3] = '\x03';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    send_data[4] = '\a';
    send_data[5] = '\0';
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    read_back_data[7] = '\0';
    iVar2 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,8);
    if (iVar2 != 0) {
      builtin_strncpy(tmp42,"get AD conversion N failed\n",0x1c);
      _applog(0,tmp42,false);
      uVar1 = tmp42._20_4_;
      builtin_strncpy(tmp42,"can nont get voltage\n",0x16);
      tmp42._22_2_ = SUB42(uVar1,2);
      _applog(0,tmp42,false);
      return 0x80000300;
    }
    dVar7 = bitmain_convert_N_to_V(read_back_data._4_4_ & 0xffff);
    return (uint)(0.0 < dVar7 * 100.0) * (int)(longlong)(dVar7 * 100.0);
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x03';
  send_data[4] = '\x04';
  send_data[5] = '\x03';
  memset(read_back_data,0,0x20);
  iVar2 = exec_power_cmd_v2(_g_power_state.power_fd,send_data,6,read_back_data,10);
  if (iVar2 != 0) {
    builtin_strncpy(tmp42,"Get power set_volt value failed\n",0x20);
    tmp42[0x20] = '\0';
    _applog(3,tmp42,false);
    return 0;
  }
  fVar11 = (float)read_back_data._4_4_ * 100.0 + 1e-05;
  uVar9 = (uint)(0.0 < fVar11) * (int)(longlong)fVar11;
  if ((_g_power_state.power_Calibrated != false) && (_g_is_use_calibration_data != false)) {
    if (_g_power_state.power_version != 0x62) {
      if (_g_power_state.power_version < 0x62) {
        return 0;
      }
      if (2 < _g_power_state.power_version - 100) {
        return 0;
      }
      if ((_g_power_state.power_version != 0x62) && (_g_power_state.power_version < 0x62)) {
        return 0;
      }
    }
    dVar7 = (double)uVar9 / 100.0;
    if ((22.1 < dVar7) || ((int)((uint)(dVar7 < 16.5) << 0x1f) < 0)) {
      return 0;
    }
    if (0 < _g_power_state.eeprom.num + -1) {
      paVar4 = &_g_power_state.eeprom.field_2;
      iVar5 = 1;
      do {
        dVar8 = paVar4->V[0];
        paVar4 = (anon_union_160_2_9472fda9_for_eeprom_data_t_2 *)(paVar4->V + 1);
        if ((dVar8 - 0.001 < dVar7) && ((int)((uint)(dVar7 < paVar4->V[0] + 0.001) << 0x1f) < 0)) {
          dVar10 = _g_power_state.eeprom.vol[iVar5 + -1];
          fVar11 = (float)(dVar10 + ((_g_power_state.eeprom.vol[iVar5] - dVar10) /
                                    (paVar4->V[0] - dVar8)) * (dVar7 - dVar8)) * 100.0;
          return (uint)(0.0 < fVar11) * (int)fVar11;
        }
        bVar6 = iVar5 < _g_power_state.eeprom.num + -1;
        iVar5 = iVar5 + 1;
      } while (bVar6);
    }
    return (uint)(0.0 < (float)dVar7 * 100.0) * (int)((float)dVar7 * 100.0);
  }
  return uVar9;
}

