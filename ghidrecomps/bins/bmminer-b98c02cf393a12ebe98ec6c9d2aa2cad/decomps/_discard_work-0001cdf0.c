
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _discard_work(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  undefined4 local_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined4 uStack_814;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf((char *)&local_820,0x800,"Discard work called with NULL work from %s %s:%d",param_2,
               param_3,param_4);
      _applog(3,&local_820,0);
    }
  }
  else {
    if (((*(char *)(iVar1 + 0x111) == '\0') && (*(int *)(iVar1 + 0xf0) == 0)) &&
       (*(char *)(iVar1 + 0x110) == '\0')) {
      iVar1 = *(int *)(iVar1 + 0x104);
      if (iVar1 != 0) {
        *(int *)(iVar1 + 0x7c) = *(int *)(iVar1 + 0x7c) + 1;
        *(int *)(iVar1 + 0x40) = *(int *)(iVar1 + 0x40) + -1;
        *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + -1;
      }
      bVar2 = 0xfffffffe < (uint)total_discarded;
      total_discarded._0_4_ = (uint)total_discarded + 1;
      total_discarded._4_4_ = total_discarded._4_4_ + (uint)bVar2;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        local_820._0_1_ = s_Discarded_work_0005c694[0];
        local_820._1_1_ = s_Discarded_work_0005c694[1];
        local_820._2_1_ = s_Discarded_work_0005c694[2];
        local_820._3_1_ = s_Discarded_work_0005c694[3];
        uStack_81c._0_1_ = s_Discarded_work_0005c694[4];
        uStack_81c._1_1_ = s_Discarded_work_0005c694[5];
        uStack_81c._2_1_ = s_Discarded_work_0005c694[6];
        uStack_81c._3_1_ = s_Discarded_work_0005c694[7];
        uStack_818._0_1_ = s_Discarded_work_0005c694[8];
        uStack_818._1_1_ = s_Discarded_work_0005c694[9];
        uStack_818._2_1_ = s_Discarded_work_0005c694[10];
        uStack_818._3_1_ = s_Discarded_work_0005c694[11];
        uStack_814._0_3_ = (undefined3)ram0x0005c6a0;
        _applog(7,&local_820,0);
      }
    }
    else if ((opt_debug != '\0') &&
            (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_820 = s_Discarded_cloned_or_rolled_work_0005c6a4._0_4_;
      uStack_81c = s_Discarded_cloned_or_rolled_work_0005c6a4._4_4_;
      uStack_818 = s_Discarded_cloned_or_rolled_work_0005c6a4._8_4_;
      uStack_814 = s_Discarded_cloned_or_rolled_work_0005c6a4._12_4_;
      local_810 = s_Discarded_cloned_or_rolled_work_0005c6a4._16_4_;
      uStack_80c = s_Discarded_cloned_or_rolled_work_0005c6a4._20_4_;
      uStack_808 = s_Discarded_cloned_or_rolled_work_0005c6a4._24_4_;
      uStack_804 = s_Discarded_cloned_or_rolled_work_0005c6a4._28_4_;
      _applog(7,&local_820,0);
    }
    _free_work(param_1,param_2,param_3,param_4);
  }
  return;
}

