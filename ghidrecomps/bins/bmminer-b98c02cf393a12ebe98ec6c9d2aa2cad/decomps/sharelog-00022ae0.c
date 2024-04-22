
void sharelog(undefined4 param_1,int param_2)

{
  int iVar1;
  void *__ptr;
  void *__ptr_00;
  void *__ptr_01;
  size_t sVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  char acStack_c28 [1023];
  undefined uStack_829;
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined2 local_814;
  
  if (sharelog_file == (FILE *)0x0) {
    return;
  }
  uVar6 = *(undefined4 *)(param_2 + 0x100);
  iVar1 = get_thread(uVar6);
  uVar4 = *(undefined4 *)(param_2 + 0x1b0);
  iVar7 = *(int *)(iVar1 + 0x24);
  iVar1 = *(int *)(param_2 + 0x104);
  __ptr = (void *)bin2hex(param_2 + 0xa0,0x20);
  __ptr_00 = (void *)bin2hex(param_2 + 0xc0,0x20);
  __ptr_01 = (void *)bin2hex(param_2,0x80);
  sVar2 = snprintf(acStack_c28,0x400,"%lu,%s,%s,%s,%s%u,%u,%s,%s\n",uVar4,param_1,__ptr,
                   *(undefined4 *)(iVar1 + 0xa4),*(undefined4 *)(*(int *)(iVar7 + 4) + 8),
                   *(undefined4 *)(iVar7 + 8),uVar6,__ptr_00,__ptr_01,param_1,uVar4);
  free(__ptr);
  free(__ptr_00);
  free(__ptr_01);
  if ((int)sVar2 < 0x400) {
    if ((int)sVar2 < 0) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        return;
      }
      pcVar5 = "sharelog printf error";
      goto LAB_00022bea;
    }
  }
  else {
    uStack_829 = 0;
  }
  iVar1 = pthread_mutex_lock(DAT_00022cc4);
  uVar4 = DAT_00022cc8;
  if (iVar1 == 0) {
    sVar2 = fwrite(acStack_c28,sVar2,1,sharelog_file);
    fflush(sharelog_file);
    iVar1 = pthread_mutex_unlock(DAT_00022cc4);
    if (iVar1 == 0) {
      (*selective_yield)();
      if (sVar2 == 1) {
        return;
      }
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        return;
      }
      pcVar5 = "sharelog fwrite error";
LAB_00022bea:
      local_828 = *(undefined4 *)pcVar5;
      uStack_824 = *(undefined4 *)((int)pcVar5 + 4);
      uStack_820 = *(undefined4 *)((int)pcVar5 + 8);
      uStack_81c = *(undefined4 *)((int)pcVar5 + 0xc);
      uStack_818 = *(undefined4 *)((int)pcVar5 + 0x10);
      local_814 = (undefined2)*(undefined4 *)((int)pcVar5 + 0x14);
      _applog(3,&local_828,0);
      return;
    }
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    pcVar5 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar6 = 0x292;
    uVar4 = DAT_00022cc8;
  }
  else {
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    pcVar5 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar6 = 0x28f;
  }
  snprintf((char *)&local_828,0x800,pcVar5,iVar1,"cgminer.c",uVar4,uVar6);
  _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

