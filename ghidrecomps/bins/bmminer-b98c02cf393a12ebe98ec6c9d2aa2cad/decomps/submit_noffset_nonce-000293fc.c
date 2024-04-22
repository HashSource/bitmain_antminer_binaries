
undefined4
submit_noffset_nonce(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_81c;
  char acStack_818 [2052];
  
  local_81c = make_work();
  _copy_work(local_81c,param_2,param_4);
  iVar1 = local_81c;
  *(undefined4 *)(local_81c + 0x4c) = param_3;
  regen_hash(local_81c);
  if (*(int *)(iVar1 + 0xdc) != 0) {
    _free_work(&local_81c,"cgminer.c",DAT_00029508,0x232f);
    inc_hw_errors(param_1);
    return 0;
  }
  update_work_stats_isra_55(param_1 + 0x24,local_81c);
  if ((opt_benchfile != 0) && (opt_benchfile_display != '\0')) {
    benchfile_dspwork(local_81c,param_3);
  }
  iVar1 = fulltest(local_81c + 0xc0,local_81c + 0xa0);
  if (iVar1 == 0) {
    _free_work(&local_81c,"cgminer.c",DAT_00029508,0x233f);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      snprintf(acStack_818,0x800,"%s %d: Share above target",
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 4) + 8),
               *(undefined4 *)(*(int *)(param_1 + 0x24) + 8));
      _applog(6,acStack_818,0);
      return 1;
    }
  }
  else {
    submit_work_async(local_81c);
  }
  return 1;
}

