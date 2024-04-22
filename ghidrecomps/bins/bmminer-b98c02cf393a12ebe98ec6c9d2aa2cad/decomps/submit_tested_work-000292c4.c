
int submit_tested_work(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_810 [2048];
  
  update_work_stats_isra_55(param_1 + 0x24);
  iVar1 = fulltest(param_2 + 0xc0,param_2 + 0xa0);
  if (iVar1 == 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      snprintf(acStack_810,0x800,"%s %s %d: Share above target",DAT_00029358,
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 4) + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x24) + 8));
      _applog(6,acStack_810,0);
    }
    return 0;
  }
  uVar2 = make_work();
  _copy_work(uVar2,param_2,0);
  submit_work_async(uVar2);
  return iVar1;
}

