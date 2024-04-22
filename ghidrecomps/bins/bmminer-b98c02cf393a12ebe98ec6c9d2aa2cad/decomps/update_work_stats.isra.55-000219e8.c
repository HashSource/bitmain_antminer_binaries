
void update_work_stats_isra_55(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  time_t tVar3;
  int *piVar4;
  char *__format;
  undefined4 *puVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  undefined8 uVar9;
  DItype DVar10;
  undefined4 in_stack_fffff7d0;
  undefined4 in_stack_fffff7d4;
  undefined4 uVar11;
  undefined4 uVar12;
  char acStack_820 [2052];
  
  dVar8 = *DAT_00021b94;
  uVar9 = share_diff(param_2);
  *(undefined8 *)(param_2 + 0xe8) = uVar9;
  dVar7 = (double)__floatundidf();
  cVar1 = use_syslog;
  if (dVar8 <= dVar7) {
    puVar5 = *(undefined4 **)(param_2 + 0x104);
    iVar2 = puVar5[8];
    found_blocks = found_blocks + 1;
    *(undefined *)(param_2 + 0x11b) = 1;
    puVar5[8] = iVar2 + 1;
    *(undefined *)(param_2 + 0x11a) = 1;
    if (((cVar1 != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
      snprintf(acStack_820,0x800,"Found block for pool %d!",*puVar5);
      _applog(5,acStack_820,0);
    }
  }
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
  if (iVar2 == 0) {
    __aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
    total_diff1 = __fixdfdi((DFtype)CONCAT44(in_stack_fffff7d4,in_stack_fffff7d0));
    iVar6 = *param_1;
    __aeabi_l2d(*(undefined4 *)(iVar6 + 0xc0),*(undefined4 *)(iVar6 + 0xc4));
    DVar10 = __fixdfdi((DFtype)CONCAT44(in_stack_fffff7d4,in_stack_fffff7d0));
    iVar2 = *(int *)(param_2 + 0x104);
    *(DItype *)(iVar6 + 0xc0) = DVar10;
    __aeabi_l2d(*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x2c));
    DVar10 = __fixdfdi((DFtype)CONCAT44(in_stack_fffff7d4,in_stack_fffff7d0));
    *(DItype *)(iVar2 + 0x28) = DVar10;
    tVar3 = time((time_t *)0x0);
    *(time_t *)(iVar6 + 0xe8) = tVar3;
    iVar2 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
    uVar11 = DAT_00021b98;
    if (iVar2 == 0) {
      (*selective_yield)();
      return;
    }
    piVar4 = __errno_location();
    iVar2 = *piVar4;
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar12 = 0x222e;
  }
  else {
    piVar4 = __errno_location();
    iVar2 = *piVar4;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar12 = 0x2229;
    uVar11 = DAT_00021b98;
  }
  snprintf(acStack_820,0x800,__format,iVar2,"cgminer.c",uVar11,uVar12);
  _applog(3,acStack_820,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

