
undefined4 miner_thread(undefined4 *param_1)

{
  int iVar1;
  time_t tVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  char acStack_828 [16];
  char local_818 [28];
  undefined2 uStack_7fc;
  undefined1 local_7fa;
  
  iVar5 = param_1[9];
  iVar4 = *(int *)(iVar5 + 4);
  snprintf(acStack_828,0x10,"%d/Miner",*param_1);
  RenameThread(acStack_828);
  thread_reportout(param_1);
  iVar1 = (**(code **)(iVar4 + 0x34))(param_1);
  if (iVar1 != 0) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      builtin_strncpy(local_818,"Waiting on sem in miner thre",0x1c);
      uStack_7fc = 0x6461;
      local_7fa = 0;
      _applog(7,local_818,0);
    }
    _cgsem_wait(param_1 + 4,"cgminer.c","miner_thread",0x25d9);
    tVar2 = time((time_t *)0x0);
    pcVar3 = *(code **)(iVar4 + 0x3c);
    *(time_t *)(iVar5 + 0xe8) = tVar2;
    (*pcVar3)(param_1);
    (**(code **)(iVar4 + 0x58))(param_1);
    return 0;
  }
  dev_error(iVar5,0);
  return 0;
}

