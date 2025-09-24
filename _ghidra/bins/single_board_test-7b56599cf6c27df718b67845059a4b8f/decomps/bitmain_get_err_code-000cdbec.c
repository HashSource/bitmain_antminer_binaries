
/* WARNING: Unknown calling convention */

int32_t bitmain_get_err_code(_Bool clean_cache,_Bool print)

{
  int32_t iVar1;
  bool bVar2;
  uint8_t auStack_840 [8];
  uint8_t auStack_838 [4];
  byte bStack_834;
  byte bStack_833;
  byte bStack_832;
  byte bStack_831;
  uint uStack_830;
  char acStack_818 [2052];
  
  bVar2 = 0x61 < _g_power_state.power_version;
  if (_g_power_state.power_version != 0x62) {
    bVar2 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar2 || (_g_power_state.power_version == 0x62 || _g_power_state.power_version - 100 == 2)) {
    auStack_840[0] = 'U';
    auStack_840[1] = 0xaa;
    auStack_840[2] = '\x04';
    auStack_840[3] = '\x0e';
    auStack_840[4] = '\x04';
    auStack_840[5] = '\x0e';
    memset(auStack_838,0,0x20);
    if (clean_cache) {
      auStack_840[5] = 0x8e;
      auStack_840[3] = 0x8e;
    }
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,auStack_840,6,auStack_838,0xe);
    if (iVar1 == 0) {
      if (!print) {
        return uStack_830;
      }
      snprintf(acStack_818,0x800,
               "Get power error code[4-7 8-11] %02x%02x%02x%02x %02x%02x%02x%02x, err_code:0x%08x\n"
               ,(uint)bStack_834,(uint)bStack_833,(uint)bStack_832,(uint)bStack_831,
               uStack_830 & 0xff,uStack_830 >> 8 & 0xff,uStack_830 >> 0x10 & 0xff,uStack_830 >> 0x18
               ,uStack_830);
      _applog(3,acStack_818,false);
      return uStack_830;
    }
    builtin_strncpy(acStack_818,"Get power error code failed\n",0x1c);
    acStack_818[0x1c] = 0;
    _applog(3,acStack_818,false);
  }
  return -1;
}

