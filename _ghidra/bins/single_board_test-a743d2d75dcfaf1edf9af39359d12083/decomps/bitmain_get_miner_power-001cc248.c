
/* WARNING: Unknown calling convention */

int32_t bitmain_get_miner_power(void)

{
  uint uVar1;
  int32_t iVar2;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (uVar1 = bitmain_power_open(), (int)uVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_miner_power");
    _applog(0,tmp42,false);
  }
  else if (_g_power_state.power_version == 0xc1) {
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[2] = '\x04';
    send_data[3] = '\b';
    send_data[4] = '\f';
    send_data[5] = '\0';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    read_back_data[7] = '\0';
    iVar2 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,8);
    if (iVar2 == 0) {
      uVar1 = read_back_data._4_4_ & 0xffff;
    }
    else {
      builtin_strncpy(tmp42,"get power status failed\n",0x18);
      tmp42[0x18] = '\0';
      _applog(0,tmp42,false);
      snprintf(tmp42,0x800,"can nont get power ret = 0x%x\n",0x80000300);
      _applog(0,tmp42,false);
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

