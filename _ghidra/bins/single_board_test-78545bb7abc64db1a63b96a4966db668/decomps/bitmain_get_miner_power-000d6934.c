
/* WARNING: Unknown calling convention */

int32_t bitmain_get_miner_power(void)

{
  int32_t iVar1;
  uint uVar2;
  undefined4 uVar3;
  bool bVar4;
  float fVar5;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_miner_power");
    _applog(0,tmp42,false);
    return iVar1;
  }
  uVar2 = _g_power_state.power_version & 0xfffffff7;
  bVar4 = 0x61 < uVar2;
  if (uVar2 != 0x62) {
    bVar4 = 1 < _g_power_state.power_version - 100;
  }
  if (bVar4 && (uVar2 != 0x62 && _g_power_state.power_version - 100 != 2)) {
    if (1 < _g_power_state.power_version - 0xc1) {
      return -1;
    }
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[2] = '\x04';
    send_data[4] = '\f';
    send_data[5] = '\0';
    send_data[3] = '\b';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    read_back_data[7] = '\0';
    iVar1 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,8);
    if (iVar1 == 0) {
      return read_back_data._4_4_ & 0xffff;
    }
    builtin_strncpy(tmp42,"get power status failed\n",0x18);
    tmp42[0x18] = '\0';
    _applog(0,tmp42,false);
    uVar3 = 0x80000300;
  }
  else {
    fVar5 = _get_power_ac_power();
    if ((int)fVar5 != 0) {
      return (int)fVar5;
    }
    uVar3 = 0;
  }
  snprintf(tmp42,0x800,"can nont get power ret = 0x%x\n",uVar3);
  _applog(0,tmp42,false);
  return -1;
}

