
int submit_nonce_1(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  char local_810 [16];
  undefined2 uStack_800;
  undefined1 local_7fe;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  *(undefined4 *)(param_2 + 0x4c) = param_3;
  regen_hash(param_2);
  if (*(int *)(param_2 + 0xdc) == 0) {
    update_work_stats_isra_55(param_1 + 0x24,param_2);
    iVar1 = fulltest(param_2 + 0xc0,param_2 + 0xa0);
    if (iVar1 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 1;
      }
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
        iVar1 = 0;
      }
      else {
        builtin_strncpy(local_810,"Share above targ",0x10);
        uStack_800 = 0x7465;
        local_7fe = 0;
        _applog(6,local_810,0);
      }
    }
    return iVar1;
  }
  inc_hw_errors(param_1);
  return 0;
}

