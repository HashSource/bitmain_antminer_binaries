
/* WARNING: Unknown calling convention */

int32_t bitmain_get_power_status_1(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  uint8_t cmd [6];
  uint8_t reply [23];
  char cStack_801;
  
  if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
    snprintf((char *)reply,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_power_status_1");
    _applog(0,(char *)reply,false);
  }
  else {
    uVar2 = _g_power_state.power_version & 0xfffffff7;
    bVar3 = 0x61 < uVar2;
    if (uVar2 != 0x62) {
      bVar3 = 1 < _g_power_state.power_version - 100;
    }
    if (!bVar3 || (uVar2 == 0x62 || _g_power_state.power_version - 100 == 2)) {
      cmd[0] = 'U';
      cmd[1] = 0xaa;
      cmd[2] = '\x04';
      cmd[3] = '\n';
      cmd[4] = '\x04';
      cmd[5] = '\n';
      reply[0] = '\0';
      reply[1] = '\0';
      reply[2] = '\0';
      reply[3] = '\0';
      reply[4] = '\0';
      reply[5] = '\0';
      reply[6] = '\0';
      reply[7] = '\0';
      reply[8] = '\0';
      reply[9] = '\0';
      reply[10] = '\0';
      reply[0xb] = '\0';
      reply[0xc] = '\0';
      reply[0xd] = '\0';
      reply[0xe] = '\0';
      reply[0xf] = '\0';
      reply[0x10] = '\0';
      reply[0x11] = '\0';
      reply[0x12] = '\0';
      reply[0x13] = '\0';
      stack0xfffff7fc = stack0xfffff7fc & 0xff000000;
      iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,0x17);
      if (iVar1 != 0) {
        builtin_memcpy(reply,"can nont get power stat",0x17);
        cStack_801 = 'u';
        _applog(0,(char *)reply,false);
      }
    }
    else {
      if (_g_power_state.power_version - 0xc1 < 2) {
        iVar1 = _bitmain_get_power_status_32bits(_g_power_state.power_fd);
      }
      else {
        iVar1 = _bitmain_get_power_status(_g_power_state.power_fd);
      }
      if (iVar1 == -0x7ffffd00) {
        builtin_memcpy(reply,"can nont get power stat",0x17);
        cStack_801 = 'u';
        _applog(0,(char *)reply,false);
        return -0x7ffffd00;
      }
    }
  }
  return iVar1;
}

