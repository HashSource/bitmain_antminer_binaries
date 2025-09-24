
/* WARNING: Unknown calling convention */

float bitmain_get_power_ac_power(void)

{
  int32_t iVar1;
  bool bVar2;
  uint8_t auStack_838 [8];
  uint8_t auStack_830 [4];
  undefined1 uStack_82c;
  undefined1 uStack_82b;
  undefined1 uStack_82a;
  undefined1 uStack_829;
  undefined4 uStack_810;
  char acStack_80c [2048];
  
  bVar2 = 0x61 < _g_power_state.power_version;
  if (_g_power_state.power_version != 0x62) {
    bVar2 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar2 || (_g_power_state.power_version == 0x62 || _g_power_state.power_version - 100 == 2)) {
    auStack_838[0] = 'U';
    auStack_838[1] = 0xaa;
    auStack_838[2] = '\x04';
    auStack_838[3] = '\b';
    auStack_838[4] = '\x04';
    auStack_838[5] = '\b';
    memset(auStack_830,0,0x20);
    iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,auStack_838,6,auStack_830,10);
    if (iVar1 == 0) {
      uStack_810 = (float)CONCAT13(uStack_829,CONCAT12(uStack_82a,CONCAT11(uStack_82b,uStack_82c)));
      return uStack_810;
    }
    uStack_810._0_1_ = 'G';
    uStack_810._1_1_ = 'e';
    uStack_810._2_1_ = 't';
    uStack_810._3_1_ = ' ';
    builtin_strncpy(acStack_80c,"ac power failed\n",0x10);
    acStack_80c[0x10] = 0;
    _applog(3,(char *)&uStack_810,false);
  }
  return 0.0;
}

