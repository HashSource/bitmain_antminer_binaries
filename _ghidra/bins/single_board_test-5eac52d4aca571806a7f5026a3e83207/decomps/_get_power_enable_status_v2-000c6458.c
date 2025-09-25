
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
  if (!bVar3 || (uVar2 == 0x62 || _g_power_state.power_version - 100 == 2)) {
    cmd[0] = 'U';
    cmd[1] = 0xaa;
    cmd[2] = '\x04';
    cmd[3] = '\x05';
    cmd[4] = '\x04';
    cmd[5] = '\x05';
    memset(reply,0,0x20);
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,8);
    if (iVar1 == 0) {
      return (uint)(reply[4] == '\x01');
    }
    builtin_strncpy(tmp42,"power 0x05 cmd faile",0x14);
    tmp42[0x14] = 'd';
    tmp42[0x15] = '\n';
    tmp42[0x16] = '\0';
    _applog(3,tmp42,false);
  }
  return -1;
}

