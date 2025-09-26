
/* WARNING: Unknown calling convention */

int32_t bitmain_get_err_code(_Bool clean_cache,_Bool print)

{
  int32_t iVar1;
  uint uVar2;
  bool bVar3;
  uint8_t auStack_840 [8];
  uint uStack_838;
  uint uStack_834;
  uint uStack_830;
  uint uStack_82c;
  undefined4 uStack_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  char acStack_818 [20];
  undefined2 uStack_804;
  undefined1 uStack_802;
  
  uVar2 = _g_power_state.power_version & 0xfffffff7;
  bVar3 = 0x61 < uVar2;
  if (uVar2 != 0x62) {
    bVar3 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar3 || (uVar2 == 0x62 || _g_power_state.power_version - 100 == 2)) {
    uStack_834 = 0;
    uStack_830 = 0;
    uStack_82c = 0;
    uStack_828 = 0;
    uStack_824 = 0;
    uStack_820 = 0;
    uStack_81c = 0;
    uStack_838 = 0;
    auStack_840[0] = 'U';
    auStack_840[1] = 0xaa;
    auStack_840[2] = '\x04';
    auStack_840[3] = '\x0e';
    auStack_840[4] = '\x04';
    auStack_840[5] = '\x0e';
    if (clean_cache) {
      auStack_840[4] = '\x04';
      auStack_840[5] = 0x8e;
      auStack_840[0] = 'U';
      auStack_840[1] = 0xaa;
      auStack_840[2] = '\x04';
      auStack_840[3] = 0x8e;
    }
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,auStack_840,6,(uint8_t *)&uStack_838,0xe);
    uVar2 = uStack_830;
    if (iVar1 == 0) {
      if (print) {
        snprintf(acStack_818,0x800,
                 "Get power code[0-3 4-7 8-11 12-13] %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x, power_code:0x%08x\n"
                 ,uStack_838 & 0xff,uStack_838 >> 8 & 0xff,uStack_838 >> 0x10 & 0xff,
                 uStack_838 >> 0x18,uStack_834 & 0xff,uStack_834 >> 8 & 0xff,
                 uStack_834 >> 0x10 & 0xff,uStack_834 >> 0x18,uStack_830 & 0xff,
                 uStack_830 >> 8 & 0xff,uStack_830 >> 0x10 & 0xff,uStack_830 >> 0x18,
                 uStack_82c & 0xff,uStack_82c >> 8 & 0xff,uStack_830);
        _applog(3,acStack_818,false);
      }
      return uVar2;
    }
    builtin_strncpy(acStack_818,"Get power code faile",0x14);
    uStack_804 = 0xa64;
    uStack_802 = 0;
    _applog(3,acStack_818,false);
  }
  return -1;
}

