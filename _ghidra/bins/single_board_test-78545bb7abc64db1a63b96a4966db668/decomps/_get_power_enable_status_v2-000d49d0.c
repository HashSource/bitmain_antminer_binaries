
/* WARNING: Unknown calling convention */

int32_t _get_power_enable_status_v2(void)

{
  int32_t iVar1;
  uint uVar2;
  bool bVar3;
  uint8_t cmd [6];
  uint8_t reply [32];
  char tmp42 [2048];
  
  uVar2 = _g_power_state.power_version & 0xfffffff7;
  bVar3 = 0x61 < uVar2;
  if (uVar2 != 0x62) {
    bVar3 = 1 < _g_power_state.power_version - 100;
  }
  if (bVar3 && (uVar2 != 0x62 && _g_power_state.power_version - 100 != 2)) {
    return -1;
  }
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\x04';
  cmd[3] = '\x05';
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
  reply[0x14] = '\0';
  reply[0x15] = '\0';
  reply[0x16] = '\0';
  reply[0x17] = '\0';
  reply[0x18] = '\0';
  reply[0x19] = '\0';
  reply[0x1a] = '\0';
  reply[0x1b] = '\0';
  reply[0x1c] = '\0';
  reply[0x1d] = '\0';
  reply[0x1e] = '\0';
  reply[0x1f] = '\0';
  cmd[4] = '\x04';
  cmd[5] = '\x05';
  reply[0] = '\0';
  reply[1] = '\0';
  reply[2] = '\0';
  reply[3] = '\0';
  iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,8);
  if (iVar1 == 0) {
    return (uint)(reply[4] == '\x01');
  }
  builtin_strncpy(tmp42,"power 0x05 cmd faile",0x14);
  tmp42[0x14] = 'd';
  tmp42[0x15] = '\n';
  tmp42[0x16] = '\0';
  _applog(3,tmp42,false);
  return -1;
}

