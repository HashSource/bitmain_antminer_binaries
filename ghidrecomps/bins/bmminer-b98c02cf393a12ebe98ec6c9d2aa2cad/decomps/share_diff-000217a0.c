
UDItype share_diff(int param_1)

{
  UDItype *pUVar1;
  UDItype UVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  char *__format;
  bool bVar8;
  bool bVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  UDItype UVar14;
  undefined4 uVar15;
  char acStack_820 [2052];
  
  dVar12 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xd8),*(undefined4 *)(param_1 + 0xdc));
  dVar10 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xd4));
  dVar11 = (double)__floatundidf(*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc));
  dVar13 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xc0),*(undefined4 *)(param_1 + 0xc4));
  dVar13 = dVar12 * 6.277101735386681e+57 + dVar10 * 3.402823669209385e+38 +
           dVar11 * 1.8446744073709552e+19 + dVar13;
  if (dVar13 == 0.0) {
    dVar13 = 0.0;
  }
  dVar13 = round(2.695953529101131e+67 / dVar13);
  UVar14 = __fixunsdfdi(dVar13);
  uVar6 = (uint)(UVar14 >> 0x20);
  uVar3 = (uint)UVar14;
  iVar4 = pthread_mutex_lock((pthread_mutex_t *)control_lock);
  if (iVar4 == 0) {
    iVar4 = pthread_rwlock_wrlock((pthread_rwlock_t *)(control_lock + 0x18));
    if (iVar4 == 0) {
      bVar8 = uVar6 <= best_diff._4_4_;
      if (best_diff._4_4_ == uVar6) {
        bVar8 = uVar3 <= (uint)best_diff;
      }
      if (!bVar8) {
        best_diff = UVar14;
        suffix_string(uVar3,uVar6,&best_share,8,0);
      }
      pUVar1 = (UDItype *)(*(int *)(param_1 + 0x104) + 0x170);
      uVar7 = *(uint *)(*(int *)(param_1 + 0x104) + 0x174);
      bVar9 = uVar6 <= uVar7;
      if (uVar7 == uVar6) {
        bVar9 = uVar3 <= *(uint *)pUVar1;
      }
      if (!bVar9) {
        *pUVar1 = UVar14;
      }
      iVar4 = pthread_rwlock_unlock((pthread_rwlock_t *)(control_lock + 0x18));
      if (iVar4 == 0) {
        iVar4 = pthread_mutex_unlock((pthread_mutex_t *)control_lock);
        if (iVar4 == 0) {
          (*selective_yield)();
          UVar2 = best_diff;
          if ((!bVar8) &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (5 < opt_log_level)))) {
            snprintf(acStack_820,0x800,"New best share: %s",&best_share);
            _applog(6,acStack_820,0);
            UVar2 = best_diff;
          }
          best_diff._4_4_ = (uint)(UVar2 >> 0x20);
          best_diff._0_4_ = (uint)UVar2;
          return UVar14;
        }
        piVar5 = __errno_location();
        iVar4 = *piVar5;
        __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar15 = 0x13df;
      }
      else {
        piVar5 = __errno_location();
        iVar4 = *piVar5;
        __format = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar15 = 0x13df;
      }
    }
    else {
      piVar5 = __errno_location();
      iVar4 = *piVar5;
      __format = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
      uVar15 = 0x13d1;
    }
  }
  else {
    piVar5 = __errno_location();
    iVar4 = *piVar5;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar15 = 0x13d1;
  }
  snprintf(acStack_820,0x800,__format,iVar4,"cgminer.c","share_diff",uVar15);
  _applog(3,acStack_820,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

