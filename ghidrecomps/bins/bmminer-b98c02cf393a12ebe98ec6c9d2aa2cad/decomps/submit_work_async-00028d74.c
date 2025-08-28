
void submit_work_async(void *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  void *local_824 [2];
  pthread_t pStack_81c;
  char local_818 [32];
  undefined4 local_7f8;
  
  puVar5 = *(undefined4 **)((int)param_1 + 0x104);
  local_824[0] = param_1;
  cgtime((int)param_1 + 0x1b0);
  if (opt_benchmark != '\0') {
    iVar1 = get_thread(*(undefined4 *)((int)local_824[0] + 0x100));
    iVar7 = *(int *)(iVar1 + 0x24);
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
    if (iVar1 != 0) {
      piVar2 = __errno_location();
      iVar1 = *piVar2;
      uVar6 = 0x2194;
LAB_000290da:
      pcVar4 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
      goto LAB_000290ea;
    }
    dVar10 = *(double *)(iVar7 + 200);
    dVar11 = *(double *)(puVar5 + 0x12);
    dVar9 = *(double *)((int)local_824[0] + 0x178);
    uVar3 = puVar5[2];
    iVar1 = puVar5[3];
    *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) + 1;
    puVar5[2] = uVar3 + 1;
    puVar5[3] = iVar1 + (uint)(0xfffffffe < uVar3);
    total_diff_accepted = total_diff_accepted + dVar9;
    *(double *)(iVar7 + 200) = dVar10 + dVar9;
    bVar8 = 0xfffffffe < (uint)total_accepted;
    total_accepted._0_4_ = (uint)total_accepted + 1;
    *(double *)(puVar5 + 0x12) = dVar11 + dVar9;
    total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar8;
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
    if (iVar1 == 0) {
      (*selective_yield)();
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 5)) {
        return;
      }
      snprintf(local_818,0x800,"Accepted %s %d benchmark share nonce %08x",
               *(undefined4 *)(*(int *)(iVar7 + 4) + 8),*(undefined4 *)(iVar7 + 8),
               *(undefined4 *)((int)local_824[0] + 0x4c));
      _applog(5,local_818,0);
      return;
    }
    piVar2 = __errno_location();
    iVar1 = *piVar2;
    uVar6 = 0x219b;
LAB_00029282:
    pcVar4 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
LAB_000290ea:
    snprintf(local_818,0x800,pcVar4,iVar1,"cgminer.c","submit_work_async",uVar6);
    _applog(3,local_818,1);
                    /* WARNING: Subroutine does not return */
    __quit(1);
  }
  iVar1 = stale_work(local_824[0],1);
  if (iVar1 != 0) {
    if (opt_submit_stale == '\0') {
      if (*(char *)(puVar5 + 0x1a) == '\0') {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
          snprintf(local_818,0x800,"Pool %d stale share detected, discarding",*puVar5);
          _applog(5,local_818,0);
        }
        sharelog("discard",local_824[0]);
        iVar1 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
        if (iVar1 != 0) {
          piVar2 = __errno_location();
          iVar1 = *piVar2;
          uVar6 = 0x21b0;
          goto LAB_000290da;
        }
        dVar9 = *(double *)((int)local_824[0] + 0x178);
        bVar8 = 0xfffffffe < (uint)total_stale;
        total_stale._0_4_ = (uint)total_stale + 1;
        total_diff_stale = total_diff_stale + dVar9;
        total_stale._4_4_ = total_stale._4_4_ + (uint)bVar8;
        puVar5[0x1e] = puVar5[0x1e] + 1;
        *(double *)(puVar5 + 0x16) = *(double *)(puVar5 + 0x16) + dVar9;
        iVar1 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
        if (iVar1 == 0) {
          (*selective_yield)();
          _free_work(local_824,"cgminer.c","submit_work_async",0x21b9);
          return;
        }
        piVar2 = __errno_location();
        iVar1 = *piVar2;
        uVar6 = 0x21b7;
        goto LAB_00029282;
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
        pcVar4 = "Pool %d stale share detected, submitting as pool requested";
        goto LAB_00028eca;
      }
    }
    else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
      pcVar4 = "Pool %d stale share detected, submitting as user requested";
LAB_00028eca:
      snprintf(local_818,0x800,pcVar4,*puVar5);
      _applog(5,local_818,0);
    }
    *(undefined1 *)((int)local_824[0] + 0x119) = 1;
  }
  iVar1 = is_network_error();
  if (iVar1 != 0) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      builtin_strncpy(local_818,"Work stale due to network error",0x20);
      _applog(7,local_818,0);
    }
    _free_work(local_824,"cgminer.c","submit_work_async",0x21c2);
    return;
  }
  if (*(char *)((int)local_824[0] + 0x11c) == '\0') {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      builtin_strncpy(local_818,"Pushing submit work to work thre",0x20);
      local_7f8 = CONCAT13(local_7f8._3_1_,0x6461);
      _applog(7,local_818,0);
    }
    iVar1 = pthread_create(&pStack_81c,(pthread_attr_t *)0x0,(__start_routine *)0x1bc91,local_824[0]
                          );
    if (iVar1 == 0) {
      return;
    }
    builtin_strncpy(local_818,"Failed to create submit_work_thr",0x20);
    local_7f8._0_1_ = 'e';
    local_7f8._1_1_ = 'a';
    local_7f8._2_1_ = 'd';
    local_7f8._3_1_ = '\0';
    _applog(3,local_818,1);
                    /* WARNING: Subroutine does not return */
    __quit(1);
  }
  if (opt_debug == '\0') {
    iVar1 = puVar5[0xb6];
    if (iVar1 == 0) goto LAB_00028fd4;
LAB_000291dc:
    iVar1 = tq_push(iVar1,local_824[0]);
    if (iVar1 != 0) {
      return;
    }
LAB_0002924c:
    if (opt_debug == '\0') goto LAB_00028fd4;
    if (use_syslog == '\0') goto LAB_00028fa2;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (6 < opt_log_level)) {
      snprintf(local_818,0x800,"Pushing pool %d work to stratum queue",*puVar5);
      _applog(7,local_818,0);
      iVar1 = puVar5[0xb6];
      if (iVar1 != 0) goto LAB_000291dc;
      goto LAB_0002924c;
    }
    iVar1 = puVar5[0xb6];
    if (iVar1 != 0) goto LAB_000291dc;
LAB_00028fa2:
    if ((opt_log_output == '\0') && (opt_log_level < 7)) goto LAB_00028fd4;
  }
  builtin_strncpy(local_818,"Discarding work from removed poo",0x20);
  local_7f8 = CONCAT22(local_7f8._2_2_,0x6c);
  _applog(7,local_818,0);
LAB_00028fd4:
  _free_work(local_824,"cgminer.c","submit_work_async",0x21ca);
  return;
}

