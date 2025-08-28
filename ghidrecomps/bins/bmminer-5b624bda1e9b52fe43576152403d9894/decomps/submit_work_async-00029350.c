
/* WARNING: Unknown calling convention */

void submit_work_async(work *work)

{
  char cVar1;
  undefined4 uVar2;
  _Bool _Var3;
  thr_info *ptVar4;
  int iVar5;
  char *func;
  char *func_00;
  char *__format;
  char *func_01;
  char *func_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  uint uVar6;
  pool *pool;
  pool *ppVar7;
  cgpu_info *cgpu;
  cgpu_info *pcVar8;
  bool bVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  work *local_82c [2];
  pthread_t submit_thread;
  char tmp42 [2048];
  
  ppVar7 = work->pool;
  local_82c[0] = work;
  cgtime(&work->tv_work_found);
  if (opt_benchmark != false) {
    ptVar4 = get_thread(local_82c[0]->thr_id);
    pcVar8 = ptVar4->cgpu;
    iVar5 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
    if (iVar5 != 0) {
      _mutex_lock((pthread_mutex_t *)"submit_work_async",(char *)0x2178,func,line);
    }
    dVar10 = pcVar8->diff_accepted;
    dVar12 = local_82c[0]->work_difficulty;
    uVar6 = (uint)ppVar7->accepted;
    iVar5 = *(int *)((int)&ppVar7->accepted + 4);
    dVar11 = ppVar7->diff_accepted;
    pcVar8->accepted = pcVar8->accepted + 1;
    bVar9 = 0xfffffffe < (uint)total_accepted;
    total_accepted._0_4_ = (uint)total_accepted + 1;
    total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar9;
    *(uint *)&ppVar7->accepted = uVar6 + 1;
    *(uint *)((int)&ppVar7->accepted + 4) = iVar5 + (uint)(0xfffffffe < uVar6);
    pcVar8->diff_accepted = dVar10 + dVar12;
    ppVar7->diff_accepted = dVar11 + dVar12;
    total_diff_accepted = dVar12 + total_diff_accepted;
    iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
    if (iVar5 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"submit_work_async",(char *)0x217f,func_00,line_00);
    }
    (*selective_yield)();
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 5)) {
      return;
    }
    snprintf(tmp42,0x800,"Accepted %s %d benchmark share nonce %08x",pcVar8->drv->name,
             pcVar8->device_id,*(undefined4 *)(local_82c[0]->data + 0x4c));
    _applog(5,tmp42,false);
    return;
  }
  _Var3 = stale_work(local_82c[0],true);
  if (!_Var3) {
    cVar1 = local_82c[0]->stratum;
    uVar2 = tmp42._32_4_;
    goto joined_r0x00029506;
  }
  if (opt_submit_stale == false) {
    if (ppVar7->submit_old == false) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d stale share detected, discarding",ppVar7->pool_no);
        _applog(5,tmp42,false);
      }
      sharelog("discard",local_82c[0]);
      iVar5 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
      if (iVar5 != 0) {
        _mutex_lock((pthread_mutex_t *)"submit_work_async",(char *)0x2194,func_01,line_01);
      }
      dVar10 = local_82c[0]->work_difficulty;
      total_diff_stale = dVar10 + total_diff_stale;
      bVar9 = 0xfffffffe < (uint)total_stale;
      total_stale._0_4_ = (uint)total_stale + 1;
      ppVar7->stale_shares = ppVar7->stale_shares + 1;
      total_stale._4_4_ = total_stale._4_4_ + (uint)bVar9;
      ppVar7->diff_stale = ppVar7->diff_stale + dVar10;
      iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
      if (iVar5 != 0) {
        _mutex_unlock_noyield((pthread_mutex_t *)"submit_work_async",(char *)0x219b,func_02,line_02)
        ;
      }
      (*selective_yield)();
      _free_work(local_82c,"cgminer.c","submit_work_async",0x219d);
      return;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      __format = "Pool %d stale share detected, submitting as pool requested";
      goto LAB_000294e8;
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    __format = "Pool %d stale share detected, submitting as user requested";
LAB_000294e8:
    snprintf(tmp42,0x800,__format,ppVar7->pool_no);
    _applog(5,tmp42,false);
  }
  local_82c[0]->stale = true;
  cVar1 = local_82c[0]->stratum;
  uVar2 = tmp42._32_4_;
joined_r0x00029506:
  tmp42._32_4_ = uVar2;
  if (cVar1 == '\0') {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Pushing submit work to work thread",0x23);
      tmp42[0x23] = SUB41(uVar2,3);
      _applog(7,tmp42,false);
    }
    iVar5 = pthread_create(&submit_thread,(pthread_attr_t *)0x0,(__start_routine *)0x1dc11,
                           local_82c[0]);
    if (iVar5 != 0) {
      builtin_strncpy(tmp42,"Failed to create submit_work_thread",0x24);
      _applog(3,tmp42,true);
      _quit(1);
    }
  }
  else {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Pushing pool %d work to stratum queue",ppVar7->pool_no);
      _applog(7,tmp42,false);
    }
    if ((ppVar7->stratum_q == (thread_q *)0x0) ||
       (_Var3 = tq_push(ppVar7->stratum_q,local_82c[0]), !_Var3)) {
      uVar2 = tmp42._32_4_;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Discarding work from removed pool",0x22);
        tmp42._34_2_ = SUB42(uVar2,2);
        _applog(7,tmp42,false);
      }
      _free_work(local_82c,"cgminer.c","submit_work_async",0x21a9);
    }
  }
  return;
}

