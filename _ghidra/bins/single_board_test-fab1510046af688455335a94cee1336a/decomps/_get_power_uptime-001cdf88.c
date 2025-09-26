
/* WARNING: Unknown calling convention */

int32_t _get_power_uptime(void)

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
    cmd[3] = '\r';
    cmd[4] = '\x04';
    cmd[5] = '\r';
    memset(reply,0,0x20);
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,10);
    if (iVar1 == 0) {
      iVar1._0_1_ = reply[4];
      iVar1._1_1_ = reply[5];
      iVar1._2_1_ = reply[6];
      iVar1._3_1_ = reply[7];
      return iVar1;
    }
    builtin_strncpy(tmp42,"Get power update time failed",0x1c);
    tmp42[0x1c] = '\n';
    tmp42[0x1d] = '\0';
    _applog(3,tmp42,false);
  }
  return -1;
}

