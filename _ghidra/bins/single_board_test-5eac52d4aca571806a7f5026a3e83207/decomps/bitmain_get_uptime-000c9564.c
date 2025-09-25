
/* WARNING: Unknown calling convention */

int32_t bitmain_get_uptime(void)

{
  int32_t iVar1;
  uint uVar2;
  bool bVar3;
  uint8_t auStack_838 [8];
  uint8_t auStack_830 [4];
  int32_t iStack_82c;
  char acStack_810 [28];
  undefined2 uStack_7f4;
  
  uVar2 = _g_power_state.power_version & 0xfffffff7;
  bVar3 = 0x61 < uVar2;
  if (uVar2 != 0x62) {
    bVar3 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar3 || (uVar2 == 0x62 || _g_power_state.power_version - 100 == 2)) {
    auStack_838[0] = 'U';
    auStack_838[1] = 0xaa;
    auStack_838[2] = '\x04';
    auStack_838[3] = '\r';
    auStack_838[4] = '\x04';
    auStack_838[5] = '\r';
    memset(auStack_830,0,0x20);
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,auStack_838,6,auStack_830,10);
    if (iVar1 == 0) {
      return iStack_82c;
    }
    builtin_strncpy(acStack_810,"Get power update time failed",0x1c);
    uStack_7f4 = 10;
    _applog(3,acStack_810,false);
  }
  return -1;
}

