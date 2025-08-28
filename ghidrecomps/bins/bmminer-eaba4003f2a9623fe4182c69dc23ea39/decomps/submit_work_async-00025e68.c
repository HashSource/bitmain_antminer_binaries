
void submit_work_async(work *work)

{
  undefined4 uVar1;
  _Bool _Var2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  work *work_local;
  char tmp42 [2048];
  pthread_t submit_thread;
  cgpu_info *cgpu;
  pool *pool;
  
  pool = work->pool;
  work_local = work;
  cgtime(&work->tv_work_found);
  if (opt_benchmark == false) {
    _Var2 = stale_work(work_local,true);
    if (_Var2) {
      if (opt_submit_stale == false) {
        if (pool->submit_old == false) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool %d stale share detected, discarding",pool->pool_no);
            _applog(5,tmp42,false);
          }
          sharelog("discard",work_local);
          _mutex_lock(&stats_lock,"cgminer.c","submit_work_async",0x219b);
          bVar5 = 0xfffffffe < (uint)total_stale;
          total_stale._0_4_ = (uint)total_stale + 1;
          total_stale._4_4_ = total_stale._4_4_ + (uint)bVar5;
          pool->stale_shares = pool->stale_shares + 1;
          total_diff_stale = work_local->work_difficulty + total_diff_stale;
          pool->diff_stale = pool->diff_stale + work_local->work_difficulty;
          _mutex_unlock(&stats_lock,"cgminer.c","submit_work_async",0x21a2);
          _free_work(&work_local,"cgminer.c","submit_work_async",0x21a4);
          return;
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Pool %d stale share detected, submitting as pool requested",
                   pool->pool_no);
          _applog(5,tmp42,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d stale share detected, submitting as user requested",
                 pool->pool_no);
        _applog(5,tmp42,false);
      }
      work_local->stale = true;
    }
    uVar1 = tmp42._32_4_;
    if (work_local->stratum == false) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Pushing submit work to work thread",0x23);
        tmp42[0x23] = SUB41(uVar1,3);
        _applog(7,tmp42,false);
      }
      iVar4 = pthread_create(&submit_thread,(pthread_attr_t *)0x0,(__start_routine *)0x1ace9,
                             work_local);
      if (iVar4 != 0) {
        builtin_strncpy(tmp42,"Failed to create submit_work_thread",0x24);
        _applog(3,tmp42,true);
        _quit(1);
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Pushing pool %d work to stratum queue",pool->pool_no);
        _applog(7,tmp42,false);
      }
      if ((pool->stratum_q == (thread_q *)0x0) ||
         (_Var2 = tq_push(pool->stratum_q,work_local), !_Var2)) {
        uVar1 = tmp42._32_4_;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Discarding work from removed pool",0x22);
          tmp42._34_2_ = SUB42(uVar1,2);
          _applog(7,tmp42,false);
        }
        _free_work(&work_local,"cgminer.c","submit_work_async",0x21b0);
      }
    }
  }
  else {
    cgpu = get_thr_cgpu(work_local->thr_id);
    _mutex_lock(&stats_lock,"cgminer.c","submit_work_async",0x217f);
    cgpu->accepted = cgpu->accepted + 1;
    bVar5 = 0xfffffffe < (uint)total_accepted;
    total_accepted._0_4_ = (uint)total_accepted + 1;
    total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar5;
    uVar3 = (uint)pool->accepted;
    iVar4 = *(int *)((int)&pool->accepted + 4);
    *(uint *)&pool->accepted = uVar3 + 1;
    *(uint *)((int)&pool->accepted + 4) = iVar4 + (uint)(0xfffffffe < uVar3);
    cgpu->diff_accepted = cgpu->diff_accepted + work_local->work_difficulty;
    total_diff_accepted = work_local->work_difficulty + total_diff_accepted;
    pool->diff_accepted = pool->diff_accepted + work_local->work_difficulty;
    _mutex_unlock(&stats_lock,"cgminer.c","submit_work_async",0x2186);
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Accepted %s %d benchmark share nonce %08x",cgpu->drv->name,
               cgpu->device_id,*(undefined4 *)(work_local->data + 0x4c));
      _applog(5,tmp42,false);
    }
  }
  return;
}

