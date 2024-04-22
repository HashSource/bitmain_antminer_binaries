
UDItype share_diff(int param_1)

{
  UDItype *pUVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  char *__format;
  bool bVar7;
  bool bVar8;
  UDItype UVar9;
  undefined4 in_stack_fffff7d0;
  undefined4 in_stack_fffff7d4;
  undefined4 uVar10;
  undefined4 uVar11;
  char acStack_820 [2052];
  
  __floatundidf(*(undefined4 *)(param_1 + 0xd8),*(undefined4 *)(param_1 + 0xdc));
  __floatundidf(*(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xd4));
  __floatundidf(*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc));
  __floatundidf(*(undefined4 *)(param_1 + 0xc0),*(undefined4 *)(param_1 + 0xc4));
  round((double)CONCAT44(in_stack_fffff7d4,in_stack_fffff7d0));
  UVar9 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff7d4,in_stack_fffff7d0));
  uVar5 = (uint)(UVar9 >> 0x20);
  uVar2 = (uint)UVar9;
  iVar3 = pthread_mutex_lock((pthread_mutex_t *)control_lock);
  if (iVar3 == 0) {
    iVar3 = pthread_rwlock_wrlock(DAT_000219d8);
    uVar10 = DAT_000219e0;
    if (iVar3 == 0) {
      bVar7 = uVar5 <= *(uint *)((int)DAT_000219dc + 4);
      if (*(uint *)((int)DAT_000219dc + 4) == uVar5) {
        bVar7 = uVar2 <= *(uint *)DAT_000219dc;
      }
      if (!bVar7) {
        *DAT_000219dc = UVar9;
        suffix_string(uVar2,uVar5,DAT_000219e4,8,0);
      }
      pUVar1 = (UDItype *)(*(int *)(param_1 + 0x104) + 0x170);
      uVar6 = *(uint *)(*(int *)(param_1 + 0x104) + 0x174);
      bVar8 = uVar5 <= uVar6;
      if (uVar6 == uVar5) {
        bVar8 = uVar2 <= *(uint *)pUVar1;
      }
      if (!bVar8) {
        *pUVar1 = UVar9;
      }
      iVar3 = pthread_rwlock_unlock(DAT_000219d8);
      uVar10 = DAT_000219e0;
      if (iVar3 == 0) {
        iVar3 = pthread_mutex_unlock((pthread_mutex_t *)control_lock);
        uVar10 = DAT_000219e0;
        if (iVar3 == 0) {
          (*selective_yield)();
          if ((!bVar7) &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (5 < opt_log_level)))) {
            snprintf(acStack_820,0x800,"New best share: %s",DAT_000219e4);
            _applog(6,acStack_820,0);
          }
          return UVar9;
        }
        piVar4 = __errno_location();
        iVar3 = *piVar4;
        __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar11 = 0x13df;
      }
      else {
        piVar4 = __errno_location();
        iVar3 = *piVar4;
        __format = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar11 = 0x13df;
      }
    }
    else {
      piVar4 = __errno_location();
      iVar3 = *piVar4;
      __format = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
      uVar11 = 0x13d1;
    }
  }
  else {
    piVar4 = __errno_location();
    iVar3 = *piVar4;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar11 = 0x13d1;
    uVar10 = DAT_000219e0;
  }
  snprintf(acStack_820,0x800,__format,iVar3,"cgminer.c",uVar10,uVar11);
  _applog(3,acStack_820,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

