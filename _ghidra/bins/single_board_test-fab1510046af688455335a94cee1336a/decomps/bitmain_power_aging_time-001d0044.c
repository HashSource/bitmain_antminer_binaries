
/* WARNING: Unknown calling convention */

int32_t bitmain_power_aging_time(void)

{
  uint32_t fd;
  uint uVar1;
  int32_t iVar2;
  short sVar3;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (uVar1 = bitmain_power_open(), (int)uVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_power_aging_time");
    _applog(0,tmp42,false);
  }
  else {
    fd = _g_power_state.power_fd;
    sVar3 = 3;
    do {
      send_data[1] = 0xaa;
      read_back_data[0] = '\0';
      read_back_data[1] = '\0';
      read_back_data[2] = '\0';
      read_back_data[3] = '\0';
      read_back_data[4] = '\0';
      read_back_data[5] = '\0';
      read_back_data[6] = '\0';
      read_back_data[7] = '\0';
      send_data[0] = 'U';
      send_data[2] = '\x04';
      send_data[4] = '\x04';
      send_data[3] = '\v';
      send_data[5] = '\v';
      iVar2 = exec_power_cmd_v2(fd,send_data,6,read_back_data,8);
      if (iVar2 == 0) {
        uVar1 = read_back_data._4_4_ & 0xffff;
        if (uVar1 != 0) {
          return uVar1;
        }
      }
      else {
        builtin_strncpy(tmp42,"get power aging time failed\n",0x1c);
        tmp42[0x1c] = '\0';
        _applog(0,tmp42,false);
        uVar1 = 0x80000300;
      }
      sVar3 = sVar3 + -1;
    } while (sVar3 != 0);
  }
  return uVar1;
}

