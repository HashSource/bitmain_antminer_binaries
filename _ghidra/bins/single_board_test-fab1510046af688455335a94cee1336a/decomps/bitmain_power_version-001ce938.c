
/* WARNING: Unknown calling convention */

int32_t bitmain_power_version(void)

{
  uint32_t fd;
  uint uVar1;
  int32_t iVar2;
  uint8_t send_data [6];
  uint8_t read_back_data [8];
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (uVar1 = bitmain_power_open(), (int)uVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_power_version");
    _applog(0,tmp42,false);
  }
  else {
    fd = _g_power_state.power_fd;
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    read_back_data[7] = '\0';
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[2] = '\x04';
    send_data[3] = '\x02';
    send_data[4] = '\x06';
    send_data[5] = '\0';
    iVar2 = exec_power_cmd(_g_power_state.power_fd,send_data,6,read_back_data,8);
    if (iVar2 != 0) {
      builtin_strncpy(tmp42,"get power version failed\n",0x1a);
      _applog(0,tmp42,false);
      builtin_strncpy(tmp42,"check power version failed, use v2 protocal to try it again\n",0x3c);
      tmp42[0x3c] = '\0';
      _applog(0,tmp42,false);
      read_back_data[0] = '\0';
      read_back_data[1] = '\0';
      read_back_data[2] = '\0';
      read_back_data[3] = '\0';
      read_back_data[4] = '\0';
      read_back_data[5] = '\0';
      read_back_data[6] = '\0';
      read_back_data[7] = '\0';
      send_data[0] = 'U';
      send_data[1] = 0xaa;
      send_data[2] = '\x04';
      send_data[3] = '\x02';
      send_data[4] = '\x04';
      send_data[5] = '\x02';
      iVar2 = exec_power_cmd_v2(fd,send_data,6,read_back_data,8);
      if (iVar2 != 0) {
        tmp42[0] = 'g';
        tmp42[1] = 'e';
        tmp42[2] = 't';
        tmp42[3] = ' ';
        tmp42[4] = 'p';
        tmp42[5] = 'o';
        tmp42[6] = 'w';
        tmp42[7] = 'e';
        tmp42[8] = 'r';
        tmp42[9] = ' ';
        tmp42[10] = 'v';
        tmp42[0xb] = 'e';
        tmp42[0xc] = 'r';
        tmp42[0xd] = 's';
        tmp42[0xe] = 'i';
        tmp42[0xf] = 'o';
        tmp42[0x10] = 'n';
        tmp42[0x11] = ' ';
        tmp42[0x12] = 'f';
        tmp42[0x13] = 'a';
        tmp42[0x14] = 'i';
        tmp42[0x15] = 'l';
        tmp42[0x16] = 'e';
        tmp42[0x17] = 'd';
        tmp42[0x18] = '\n';
        tmp42[0x19] = '\0';
        _applog(0,tmp42,false);
        return -0x7ffffd00;
      }
    }
    uVar1 = read_back_data._4_4_ & 0xffff;
    if (uVar1 != 0) {
      _g_power_state.power_version = uVar1;
    }
  }
  return uVar1;
}

