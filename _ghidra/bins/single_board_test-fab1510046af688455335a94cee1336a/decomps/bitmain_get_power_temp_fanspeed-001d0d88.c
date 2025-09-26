
/* WARNING: Unknown calling convention */

int32_t bitmain_get_power_temp_fanspeed(void)

{
  uint uVar1;
  int32_t iVar2;
  bool bVar3;
  uint8_t cmd [6];
  uint8_t reply [14];
  char cStack_80a;
  char cStack_809;
  
  iVar2 = 0;
  if ((_g_power_state.power_open == 0) && (iVar2 = bitmain_power_open(), iVar2 < 0)) {
    snprintf((char *)reply,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_power_temp_fanspeed");
    _applog(0,(char *)reply,false);
  }
  else {
    uVar1 = _g_power_state.power_version & 0xfffffff7;
    bVar3 = 0x61 < uVar1;
    if (uVar1 != 0x62) {
      bVar3 = 1 < _g_power_state.power_version - 100;
    }
    if (!bVar3 || (uVar1 == 0x62 || _g_power_state.power_version - 100 == 2)) {
      reply[0] = '\0';
      reply[1] = '\0';
      reply[2] = '\0';
      reply[3] = '\0';
      cmd[0] = 'U';
      cmd[1] = 0xaa;
      cmd[2] = '\x04';
      cmd[3] = '\t';
      cmd[4] = '\x04';
      cmd[5] = '\t';
      reply[4] = '\0';
      reply[5] = '\0';
      reply[6] = '\0';
      reply[7] = '\0';
      reply[8] = '\0';
      reply[9] = '\0';
      reply[10] = '\0';
      reply[0xb] = '\0';
      stack0xfffff7f4 = stack0xfffff7f4 & 0xffff0000;
      iVar2 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,0xe);
      if (iVar2 != 0) {
        builtin_memcpy(reply,"can nont get p",0xe);
        cStack_80a = 'o';
        cStack_809 = 'w';
        _applog(0,(char *)reply,false);
      }
    }
  }
  return iVar2;
}

