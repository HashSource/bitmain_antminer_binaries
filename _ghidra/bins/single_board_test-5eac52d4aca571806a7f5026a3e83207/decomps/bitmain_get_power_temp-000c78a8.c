
/* WARNING: Unknown calling convention */

int bitmain_get_power_temp(power_temp_t *p_power_temp)

{
  int32_t iVar1;
  uint uVar2;
  int iVar3;
  uint8_t send_data [6];
  uint8_t recv_data [12];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar3 = bitmain_power_open(), iVar3 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_power_temp");
    _applog(0,tmp42,false);
  }
  else if (_g_power_state.power_version < 0xc1) {
    iVar3 = -1;
  }
  else {
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[2] = '\x04';
    send_data[3] = '\t';
    send_data[4] = '\r';
    send_data[5] = '\0';
    iVar1 = exec_power_cmd(_g_power_state.power_fd,send_data,6,recv_data,0xc);
    if (iVar1 == 0) {
      iVar3 = 0;
      if ((p_power_temp != (power_temp_t *)0x0) && (recv_data[3] == '\t')) {
        uVar2 = (uint)(ushort)recv_data._4_2_;
        if (uVar2 < 0xb) {
          iVar1 = -0x1e;
        }
        else if (uVar2 < 0x5f8) {
          iVar1 = serch_ntc_table(uVar2);
        }
        else {
          iVar1 = 0x7d;
        }
        uVar2 = (uint)(ushort)recv_data._6_2_;
        p_power_temp->temp_pfc = iVar1;
        if (uVar2 < 0xb) {
          iVar1 = -0x1e;
        }
        else if (uVar2 < 0x5f8) {
          iVar1 = serch_ntc_table(uVar2);
        }
        else {
          iVar1 = 0x7d;
        }
        uVar2 = (uint)(ushort)recv_data._8_2_;
        p_power_temp->temp_llc1 = iVar1;
        if (uVar2 < 0xb) {
          iVar1 = -0x1e;
        }
        else if (uVar2 < 0x5f8) {
          iVar1 = serch_ntc_table(uVar2);
        }
        else {
          iVar1 = 0x7d;
        }
        p_power_temp->temp_llc2 = iVar1;
        return 0;
      }
    }
    else {
      iVar3 = -0x7ffffd00;
      builtin_strncpy(tmp42,"get power status failed\n",0x18);
      tmp42[0x18] = '\0';
      _applog(0,tmp42,false);
    }
  }
  return iVar3;
}

