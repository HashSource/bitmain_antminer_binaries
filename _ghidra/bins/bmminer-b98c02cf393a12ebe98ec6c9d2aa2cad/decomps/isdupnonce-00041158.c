
uint isdupnonce(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  pthread_mutex_t *ppVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 extraout_s1;
  undefined4 local_830;
  undefined4 uStack_82c;
  char acStack_828 [2052];
  
  piVar5 = *(int **)(param_1 + 0x18);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  cgtime(&local_830);
  uVar3 = piVar5[4];
  ppVar6 = *(pthread_mutex_t **)(piVar5[1] + 8);
  piVar5[4] = uVar3 + 1;
  piVar5[5] = piVar5[5] + (uint)(0xfffffffe < uVar3);
  iVar1 = pthread_mutex_lock(ppVar6);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(acStack_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,
             "noncedup.c","isdupnonce",0x46);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar6 + 1));
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(acStack_828,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,
             "noncedup.c","isdupnonce",0x46);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  iVar1 = *(int *)(piVar5[2] + 0x10);
  uVar3 = 1;
  while( true ) {
    while( true ) {
      uVar4 = uVar3;
      if (iVar1 == 0) {
        uVar4 = 0;
      }
      if (uVar4 == 0) goto LAB_00041240;
      uVar3 = 1;
      if ((**(int **)(iVar1 + 0xc) == *(int *)(param_2 + 0x154)) &&
         ((*(int **)(iVar1 + 0xc))[1] == param_3)) break;
      iVar1 = *(int *)(iVar1 + 4);
    }
    uVar3 = 0;
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (3 < opt_log_level)))) break;
    uVar3 = 0;
  }
  snprintf(acStack_828,0x800,"%s%d: Duplicate nonce %08x",*(undefined4 *)(*(int *)(param_1 + 4) + 8)
           ,*(undefined4 *)(param_1 + 8),param_3);
  _applog(4,acStack_828,0);
LAB_00041240:
  if (uVar3 != 0) {
    iVar1 = _k_unlink_head(piVar5[1],"noncedup.c","isdupnonce",0x51);
    puVar7 = *(undefined4 **)(iVar1 + 0xc);
    *puVar7 = *(undefined4 *)(param_2 + 0x154);
    puVar7[1] = param_3;
    puVar7[3] = uStack_82c;
    puVar7[2] = local_830;
    _k_add_head(piVar5[2],iVar1,"noncedup.c","isdupnonce",0x55);
  }
  iVar1 = *(int *)(piVar5[2] + 0x10);
  while ((iVar1 != 0 &&
         (uVar8 = tdiff(*(int *)(iVar1 + 0xc) + 8,&local_830),
         (double)(longlong)*piVar5 < (double)CONCAT44(extraout_s1,uVar8)))) {
    uVar8 = _k_unlink_tail(piVar5[2],"noncedup.c","isdupnonce",0x59);
    _k_add_head(piVar5[1],uVar8,"noncedup.c","isdupnonce",0x5a);
    iVar1 = *(int *)(piVar5[2] + 0x10);
  }
  ppVar6 = *(pthread_mutex_t **)(piVar5[1] + 8);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar6 + 1));
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(acStack_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,
             "noncedup.c","isdupnonce",0x5d);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  iVar1 = pthread_mutex_unlock(ppVar6);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(acStack_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,
             "noncedup.c","isdupnonce",0x5d);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  (*selective_yield)();
  if (uVar3 == 0) {
    uVar4 = piVar5[6];
    piVar5[6] = uVar4 + 1;
    piVar5[7] = piVar5[7] + (uint)(0xfffffffe < uVar4);
  }
  return uVar3 ^ 1;
}

