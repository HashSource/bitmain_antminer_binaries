
void update_work_stats_isra_55(int *param_1,int param_2)

{
  double dVar1;
  char cVar2;
  int iVar3;
  time_t tVar4;
  int *piVar5;
  char *__format;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  double dVar9;
  undefined8 uVar10;
  DItype DVar11;
  char acStack_820 [2052];
  
  dVar1 = current_diff;
  uVar10 = share_diff(param_2);
  *(undefined8 *)(param_2 + 0xe8) = uVar10;
  dVar9 = (double)__floatundidf();
  cVar2 = use_syslog;
  if (dVar1 <= dVar9) {
    puVar6 = *(undefined4 **)(param_2 + 0x104);
    iVar3 = puVar6[8];
    found_blocks = found_blocks + 1;
    *(undefined1 *)(param_2 + 0x11b) = 1;
    puVar6[8] = iVar3 + 1;
    *(undefined1 *)(param_2 + 0x11a) = 1;
    if (((cVar2 != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
      snprintf(acStack_820,0x800,"Found block for pool %d!",*puVar6);
      _applog(5,acStack_820,0);
    }
  }
  iVar3 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
  if (iVar3 == 0) {
    uVar8 = __aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
    total_diff1 = __fixdfdi((DFtype)CONCAT44(extraout_s1,uVar8));
    iVar7 = *param_1;
    uVar8 = __aeabi_l2d(*(undefined4 *)(iVar7 + 0xc0),*(undefined4 *)(iVar7 + 0xc4));
    DVar11 = __fixdfdi((DFtype)CONCAT44(extraout_s1_00,uVar8));
    iVar3 = *(int *)(param_2 + 0x104);
    *(DItype *)(iVar7 + 0xc0) = DVar11;
    uVar8 = __aeabi_l2d(*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x2c));
    DVar11 = __fixdfdi((DFtype)CONCAT44(extraout_s1_01,uVar8));
    *(DItype *)(iVar3 + 0x28) = DVar11;
    tVar4 = time((time_t *)0x0);
    *(time_t *)(iVar7 + 0xe8) = tVar4;
    iVar3 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
    if (iVar3 == 0) {
      (*selective_yield)();
      return;
    }
    piVar5 = __errno_location();
    iVar3 = *piVar5;
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar8 = 0x222e;
  }
  else {
    piVar5 = __errno_location();
    iVar3 = *piVar5;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar8 = 0x2229;
  }
  snprintf(acStack_820,0x800,__format,iVar3,"cgminer.c","update_work_stats",uVar8);
  _applog(3,acStack_820,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

