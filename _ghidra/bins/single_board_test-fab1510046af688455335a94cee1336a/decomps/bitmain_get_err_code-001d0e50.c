
/* WARNING: Unknown calling convention */

int32_t bitmain_get_err_code(_Bool clean_cache,_Bool print)

{
  int32_t iVar1;
  uint uVar2;
  bool bVar3;
  uint8_t auStack_840 [8];
  byte bStack_838;
  byte bStack_837;
  byte bStack_836;
  byte bStack_835;
  byte bStack_834;
  byte bStack_833;
  byte bStack_832;
  byte bStack_831;
  uint uStack_830;
  byte bStack_82c;
  byte bStack_82b;
  char acStack_818 [20];
  undefined2 uStack_804;
  undefined1 uStack_802;
  
  uVar2 = _g_power_state.power_version & 0xfffffff7;
  bVar3 = 0x61 < uVar2;
  if (uVar2 != 0x62) {
    bVar3 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar3 || (uVar2 == 0x62 || _g_power_state.power_version - 100 == 2)) {
    auStack_840[0] = 'U';
    auStack_840[1] = 0xaa;
    auStack_840[2] = '\x04';
    auStack_840[3] = '\x0e';
    auStack_840[4] = '\x04';
    auStack_840[5] = '\x0e';
    memset(&bStack_838,0,0x20);
    if (clean_cache) {
      auStack_840[5] = 0x8e;
      auStack_840[3] = 0x8e;
    }
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,auStack_840,6,&bStack_838,0xe);
    if (iVar1 == 0) {
      if (!print) {
        return uStack_830;
      }
      snprintf(acStack_818,0x800,
               "Get power code[0-3 4-7 8-11 12-13] %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x, power_code:0x%08x\n"
               ,(uint)bStack_838,(uint)bStack_837,(uint)bStack_836,(uint)bStack_835,(uint)bStack_834
               ,(uint)bStack_833,(uint)bStack_832,(uint)bStack_831,uStack_830 & 0xff,
               uStack_830 >> 8 & 0xff,uStack_830 >> 0x10 & 0xff,uStack_830 >> 0x18,(uint)bStack_82c,
               (uint)bStack_82b,uStack_830);
      _applog(3,acStack_818,false);
      return uStack_830;
    }
    builtin_strncpy(acStack_818,"Get power code faile",0x14);
    uStack_804 = 0xa64;
    uStack_802 = 0;
    _applog(3,acStack_818,false);
  }
  return -1;
}

