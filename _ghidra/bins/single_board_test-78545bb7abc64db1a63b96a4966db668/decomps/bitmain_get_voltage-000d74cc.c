
/* WARNING: Unknown calling convention */

uint32_t bitmain_get_voltage(void)

{
  undefined4 uVar1;
  int32_t iVar2;
  uint uVar3;
  bool bVar4;
  float fVar5;
  double dVar6;
  uint32_t local_84c;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  char tmp42 [2048];
  
  uVar3 = _g_power_state.power_version & 0xfffffff7;
  bVar4 = 0x61 < uVar3;
  if (uVar3 != 0x62) {
    bVar4 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar4 || (uVar3 == 0x62 || _g_power_state.power_version - 100 == 2)) {
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    read_back_data[7] = '\0';
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[2] = '\x04';
    send_data[3] = '\x03';
    send_data[4] = '\x04';
    send_data[5] = '\x03';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    iVar2 = exec_power_cmd_v2(_g_power_state.power_fd,send_data,6,read_back_data,10);
    if (iVar2 == 0) {
      tmp42[0] = read_back_data[4];
      tmp42[1] = read_back_data[5];
      tmp42[2] = read_back_data[6];
      tmp42[3] = read_back_data[7];
      fVar5 = (float)read_back_data._4_4_ * 100.0 + 1e-05;
      uVar3 = (uint)(0.0 < fVar5) * (int)(longlong)fVar5;
      if ((_g_power_state.power_Calibrated == false) || (_g_is_use_calibration_data == false)) {
        return uVar3;
      }
      fVar5 = bitmain_convert_calibration_V_to_origin_V((double)uVar3 / 100.0);
      local_84c = (uint)(0.0 < fVar5 * 100.0) * (int)(fVar5 * 100.0);
    }
    else {
      builtin_strncpy(tmp42,"Get power set_volt value failed\n",0x20);
      tmp42[0x20] = '\0';
      _applog(3,tmp42,false);
      local_84c = 0;
    }
  }
  else if ((_g_power_state.power_open == 0) &&
          (local_84c = bitmain_power_open(), (int)local_84c < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_voltage");
    _applog(0,tmp42,false);
  }
  else {
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
    if (iVar2 == 0) {
      dVar6 = bitmain_convert_N_to_V(read_back_data._4_4_ & 0xffff);
      local_84c = (uint)(0.0 < dVar6 * 100.0) * (int)(longlong)(dVar6 * 100.0);
    }
    else {
      builtin_strncpy(tmp42,"get AD conversion N failed\n",0x1c);
      _applog(0,tmp42,false);
      uVar1 = tmp42._20_4_;
      builtin_strncpy(tmp42,"can nont get voltage\n",0x16);
      tmp42._22_2_ = SUB42(uVar1,2);
      _applog(0,tmp42,false);
      local_84c = 0x80000300;
    }
  }
  return local_84c;
}

