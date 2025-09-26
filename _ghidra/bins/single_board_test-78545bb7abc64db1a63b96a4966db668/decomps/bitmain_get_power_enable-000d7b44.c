
/* WARNING: Unknown calling convention */

int32_t bitmain_get_power_enable(void)

{
  int32_t iVar1;
  uint uVar2;
  bool bVar3;
  uint8_t auStack_838 [8];
  uint8_t auStack_830 [52];
  undefined2 uStack_7fc;
  undefined1 uStack_7fa;
  
  uVar2 = _g_power_state.power_version & 0xfffffff7;
  bVar3 = 0x61 < uVar2;
  if (uVar2 != 0x62) {
    bVar3 = 1 < _g_power_state.power_version - 100;
  }
  if (bVar3 && (uVar2 != 0x62 && _g_power_state.power_version - 100 != 2)) {
    return -1;
  }
  auStack_838[0] = 'U';
  auStack_838[1] = 0xaa;
  auStack_838[2] = '\x04';
  auStack_838[3] = '\x05';
  auStack_830[4] = '\0';
  auStack_830[5] = '\0';
  auStack_830[6] = '\0';
  auStack_830[7] = '\0';
  auStack_830[8] = '\0';
  auStack_830[9] = '\0';
  auStack_830[10] = '\0';
  auStack_830[0xb] = '\0';
  auStack_830[0xc] = '\0';
  auStack_830[0xd] = '\0';
  auStack_830[0xe] = '\0';
  auStack_830[0xf] = '\0';
  auStack_830[0x10] = '\0';
  auStack_830[0x11] = '\0';
  auStack_830[0x12] = '\0';
  auStack_830[0x13] = '\0';
  auStack_830[0x14] = '\0';
  auStack_830[0x15] = '\0';
  auStack_830[0x16] = '\0';
  auStack_830[0x17] = '\0';
  auStack_830[0x18] = '\0';
  auStack_830[0x19] = '\0';
  auStack_830[0x1a] = '\0';
  auStack_830[0x1b] = '\0';
  auStack_830[0x1c] = '\0';
  auStack_830[0x1d] = '\0';
  auStack_830[0x1e] = '\0';
  auStack_830[0x1f] = '\0';
  auStack_838[4] = '\x04';
  auStack_838[5] = '\x05';
  auStack_830[0] = '\0';
  auStack_830[1] = '\0';
  auStack_830[2] = '\0';
  auStack_830[3] = '\0';
  iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,auStack_838,6,auStack_830,8);
  if (iVar1 == 0) {
    return (uint)(auStack_830[4] == '\x01');
  }
  builtin_memcpy(auStack_830 + 0x20,"power 0x05 cmd faile",0x14);
  uStack_7fc = 0xa64;
  uStack_7fa = 0;
  _applog(3,(char *)(auStack_830 + 0x20),false);
  return -1;
}

