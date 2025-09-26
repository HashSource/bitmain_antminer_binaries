
/* WARNING: Unknown calling convention */

int32_t bitmain_get_reset_rc(void)

{
  int32_t iVar1;
  bool bVar2;
  uint8_t auStack_838 [8];
  uint8_t auStack_830 [4];
  int32_t iStack_82c;
  char acStack_810 [32];
  undefined2 uStack_7f0;
  undefined1 uStack_7ee;
  
  bVar2 = 0x61 < _g_power_state.power_version;
  if (_g_power_state.power_version != 0x62) {
    bVar2 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar2 || (_g_power_state.power_version == 0x62 || _g_power_state.power_version - 100 == 2)) {
    auStack_838[0] = 'U';
    auStack_838[1] = 0xaa;
    auStack_838[2] = '\x04';
    auStack_838[3] = '\f';
    auStack_838[4] = '\x04';
    auStack_838[5] = '\f';
    memset(auStack_830,0,0x20);
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,auStack_838,6,auStack_830,10);
    if (iVar1 == 0) {
      return iStack_82c;
    }
    builtin_strncpy(acStack_810,"Get power reset root cause faile",0x20);
    uStack_7f0 = 0xa64;
    uStack_7ee = 0;
    _applog(3,acStack_810,false);
  }
  return -1;
}

