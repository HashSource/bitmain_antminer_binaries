
_Bool stale_work(work *work,_Bool share)

{
  undefined4 uVar1;
  int iVar2;
  pool *ppVar3;
  _Bool _Var4;
  pool *ppVar5;
  _Bool share_local;
  work *work_local;
  char tmp42 [2048];
  timeval now;
  int getwork_delay;
  pool *pool;
  _Bool same_job;
  time_t work_expiry;
  
  uVar1 = tmp42._32_4_;
  if ((opt_benchmark) || (opt_benchfile != (char *)0x0)) {
    _Var4 = false;
  }
  else if (work->work_block == work_block) {
    if (opt_scantime < work->rolltime) {
      work_expiry = work->rolltime;
    }
    else {
      work_expiry = opt_expiry;
    }
    ppVar5 = work->pool;
    if ((!share) && (ppVar5->has_stratum != false)) {
      if ((ppVar5->stratum_active != true) || (ppVar5->stratum_notify != true)) {
        if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Work stale due to stratum inactive",0x23);
          tmp42[0x23] = SUB41(uVar1,3);
          _applog(7,tmp42,false);
        }
        return true;
      }
      _cg_rlock(&ppVar5->data_lock,"cgminer.c","stale_work",0x13ce);
      iVar2 = strcmp(work->job_id,(ppVar5->swork).job_id);
      _cg_runlock(&ppVar5->data_lock,"cgminer.c","stale_work",0x13d5);
      if (iVar2 != 0) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Work stale due to stratum job_id mismatc",0x28);
          tmp42[0x28] = 'h';
          tmp42[0x29] = '\0';
          _applog(7,tmp42,false);
        }
        return true;
      }
    }
    work_expiry = work_expiry -
                  (int)(longlong)((ppVar5->cgminer_pool_stats).getwork_wait_rolling * 5.0 + 1.0);
    if (work_expiry < 5) {
      work_expiry = 5;
    }
    cgtime(&now);
    if (now.tv_sec - (work->tv_staged).tv_sec < work_expiry) {
      if (((opt_fail_only == false) || (share)) ||
         ((ppVar3 = current_pool(), ppVar5 == ppVar3 ||
          (((work->mandatory == true || (pool_strategy == POOL_LOADBALANCE)) ||
           (pool_strategy == POOL_BALANCE)))))) {
        _Var4 = false;
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Work stale due to fail only pool mismatc",0x28);
          tmp42[0x28] = 'h';
          tmp42[0x29] = '\0';
          _applog(7,tmp42,false);
        }
        _Var4 = true;
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Work stale due to expiry",0x18);
        tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
        _applog(7,tmp42,false);
      }
      _Var4 = true;
    }
  }
  else {
    if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Work stale due to block mismatch",0x20);
      tmp42._32_4_ = tmp42._32_4_ & 0xffffff00;
      _applog(7,tmp42,false);
    }
    _Var4 = true;
  }
  return _Var4;
}

