
void push_info_when_new_voltage(void *param_1,undefined4 param_2,int param_3,char param_4)

{
  int iVar1;
  undefined auStack_c [4];
  
  if (param_4 != '\0') {
    test_vol_pre_7563 = 0;
  }
  if (test_vol_pre_7563 == 0) {
    getBoardTestVoltageAndFreq(0,&test_vol_pre_7563,auStack_c);
  }
  if (test_vol_pre_7563 != param_3) {
    iVar1 = scan_vol_level_num * 0x585dc;
    scan_vol_level_num = scan_vol_level_num + 1;
    memcpy(g_freq_info_all_vol_level + iVar1,param_1,0x585dc);
    memset((void *)((int)param_1 + 0x4008),0,0x50000);
    memset((void *)((int)param_1 + 0x54088),0,0x500);
    memset((void *)((int)param_1 + 0x54008),0,0x40);
    test_vol_pre_7563 = param_3;
  }
  return;
}

