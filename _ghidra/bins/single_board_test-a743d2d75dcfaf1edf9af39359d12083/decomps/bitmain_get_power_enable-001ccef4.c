
/* WARNING: Unknown calling convention */

int32_t bitmain_get_power_enable(void)

{
  int32_t iVar1;
  bool bVar2;
  uint8_t auStack_838 [8];
  uint8_t auStack_830 [4];
  char cStack_82c;
  char acStack_810 [20];
  undefined2 uStack_7fc;
  undefined1 uStack_7fa;
  
  bVar2 = 0x61 < _g_power_state.power_version;
  if (_g_power_state.power_version != 0x62) {
    bVar2 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar2 || (_g_power_state.power_version == 0x62 || _g_power_state.power_version - 100 == 2)) {
    auStack_838[0] = 'U';
    auStack_838[1] = 0xaa;
    auStack_838[2] = '\x04';
    auStack_838[3] = '\x05';
    auStack_838[4] = '\x04';
    auStack_838[5] = '\x05';
    memset(auStack_830,0,0x20);
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,auStack_838,6,auStack_830,8);
    if (iVar1 == 0) {
      return (uint)(cStack_82c == '\x01');
    }
    builtin_strncpy(acStack_810,"power 0x05 cmd faile",0x14);
    uStack_7fc = 0xa64;
    uStack_7fa = 0;
    _applog(3,acStack_810,false);
  }
  return -1;
}

