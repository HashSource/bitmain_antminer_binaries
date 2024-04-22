
uint isdupnonce(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  pthread_mutex_t *ppVar8;
  undefined4 *puVar9;
  double dVar10;
  double dVar11;
  undefined4 local_830;
  undefined4 uStack_82c;
  char acStack_828 [2052];
  
  piVar7 = *(int **)(param_1 + 0x18);
  if (piVar7 == (int *)0x0) {
    return 0;
  }
  cgtime(&local_830);
  uVar5 = piVar7[4];
  ppVar8 = *(pthread_mutex_t **)(piVar7[1] + 8);
  piVar7[4] = uVar5 + 1;
  piVar7[5] = piVar7[5] + (uint)(0xfffffffe < uVar5);
  iVar2 = pthread_mutex_lock(ppVar8);
  if (iVar2 != 0) {
    piVar4 = __errno_location();
    snprintf(acStack_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar4,
             "noncedup.c",DAT_0004141c,0x46);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar8 + 1));
  uVar1 = DAT_0004141c;
  if (iVar2 != 0) {
    piVar4 = __errno_location();
    snprintf(acStack_828,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar4,
             "noncedup.c",uVar1,0x46);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  iVar2 = *(int *)(piVar7[2] + 0x10);
  uVar5 = 1;
  while( true ) {
    while( true ) {
      uVar6 = uVar5;
      if (iVar2 == 0) {
        uVar6 = 0;
      }
      if (uVar6 == 0) goto LAB_00041240;
      uVar5 = 1;
      if ((**(int **)(iVar2 + 0xc) == *(int *)(param_2 + 0x154)) &&
         ((*(int **)(iVar2 + 0xc))[1] == param_3)) break;
      iVar2 = *(int *)(iVar2 + 4);
    }
    uVar5 = 0;
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (3 < opt_log_level)))) break;
    uVar5 = 0;
  }
  snprintf(acStack_828,0x800,"%s%d: Duplicate nonce %08x",*(undefined4 *)(*(int *)(param_1 + 4) + 8)
           ,*(undefined4 *)(param_1 + 8),param_3);
  _applog(4,acStack_828,0);
LAB_00041240:
  if (uVar5 != 0) {
    iVar2 = _k_unlink_head(piVar7[1],"noncedup.c",DAT_0004141c,0x51);
    puVar9 = *(undefined4 **)(iVar2 + 0xc);
    *puVar9 = *(undefined4 *)(param_2 + 0x154);
    puVar9[1] = param_3;
    uVar1 = DAT_0004141c;
    puVar9[3] = uStack_82c;
    puVar9[2] = local_830;
    _k_add_head(piVar7[2],iVar2,"noncedup.c",uVar1,0x55);
  }
  uVar1 = DAT_0004141c;
  iVar2 = *(int *)(piVar7[2] + 0x10);
  while (iVar2 != 0) {
    dVar10 = (double)tdiff(*(int *)(iVar2 + 0xc) + 8,&local_830);
    dVar11 = (double)(longlong)*piVar7;
    if (dVar10 == dVar11 || dVar10 < dVar11 != (NAN(dVar10) || NAN(dVar11))) break;
    uVar3 = _k_unlink_tail(piVar7[2],"noncedup.c",uVar1,0x59);
    _k_add_head(piVar7[1],uVar3,"noncedup.c",uVar1,0x5a);
    iVar2 = *(int *)(piVar7[2] + 0x10);
  }
  ppVar8 = *(pthread_mutex_t **)(piVar7[1] + 8);
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar8 + 1));
  if (iVar2 != 0) {
    piVar4 = __errno_location();
    snprintf(acStack_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar4,
             "noncedup.c",DAT_0004141c,0x5d);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  iVar2 = pthread_mutex_unlock(ppVar8);
  uVar1 = DAT_0004141c;
  if (iVar2 != 0) {
    piVar4 = __errno_location();
    snprintf(acStack_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar4,
             "noncedup.c",uVar1,0x5d);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  (*selective_yield)();
  if (uVar5 == 0) {
    uVar6 = piVar7[6];
    piVar7[6] = uVar6 + 1;
    piVar7[7] = piVar7[7] + (uint)(0xfffffffe < uVar6);
  }
  return uVar5 ^ 1;
}

