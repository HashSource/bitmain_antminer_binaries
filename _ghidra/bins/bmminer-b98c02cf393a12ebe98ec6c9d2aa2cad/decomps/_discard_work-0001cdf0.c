
void _discard_work(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  char local_820 [12];
  undefined4 uStack_814;
  char local_810 [2036];
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(local_820,0x800,"Discard work called with NULL work from %s %s:%d",param_2,param_3,
               param_4);
      _applog(3,local_820,0);
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
        builtin_strncpy(local_820,"Discarded wo",0xc);
        uStack_814._0_3_ = 0x6b72;
        _applog(7,local_820,0);
      }
    }
    else if ((opt_debug != '\0') &&
            (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      builtin_strncpy(local_820,"Discarded cl",0xc);
      uStack_814._0_1_ = 'o';
      uStack_814._1_1_ = 'n';
      uStack_814._2_1_ = 'e';
      uStack_814._3_1_ = 'd';
      builtin_strncpy(local_810," or rolled work",0x10);
      _applog(7,local_820,0);
    }
    _free_work(param_1,param_2,param_3,param_4);
  }
  return;
}

