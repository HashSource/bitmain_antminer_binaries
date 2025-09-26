
/* WARNING: Unknown calling convention */

int32_t _get_power_reset_rc(void)

{
  int32_t iVar1;
  bool bVar2;
  uint8_t cmd [6];
  uint8_t reply [32];
  char tmp42 [2048];
  
  bVar2 = 0x61 < _g_power_state.power_version;
  if (_g_power_state.power_version != 0x62) {
    bVar2 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar2 || (_g_power_state.power_version == 0x62 || _g_power_state.power_version - 100 == 2)) {
    cmd[0] = 'U';
    cmd[1] = 0xaa;
    cmd[2] = '\x04';
    cmd[3] = '\f';
    cmd[4] = '\x04';
    cmd[5] = '\f';
    memset(reply,0,0x20);
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,10);
    if (iVar1 == 0) {
      iVar1._0_1_ = reply[4];
      iVar1._1_1_ = reply[5];
      iVar1._2_1_ = reply[6];
      iVar1._3_1_ = reply[7];
      return iVar1;
    }
    builtin_strncpy(tmp42,"Get power reset root cause faile",0x20);
    tmp42[0x20] = 'd';
    tmp42[0x21] = '\n';
    tmp42[0x22] = '\0';
    _applog(3,tmp42,false);
  }
  return -1;
}

