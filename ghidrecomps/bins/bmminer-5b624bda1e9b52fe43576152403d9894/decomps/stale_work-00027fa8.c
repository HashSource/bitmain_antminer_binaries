
/* WARNING: Unknown calling convention */

_Bool stale_work(work *work,_Bool share)

{
  undefined4 uVar1;
  _Bool _Var2;
  pool *ppVar3;
  int iVar4;
  int iVar5;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  char *pcVar6;
  time_t work_expiry;
  int iVar7;
  pool *pool;
  pool *ppVar8;
  pthread_rwlock_t *__rwlock;
  timeval now;
  char tmp42 [2048];
  
  uVar1 = tmp42._32_4_;
  if ((opt_benchmark) || (opt_benchfile != (char *)0x0)) {
LAB_00027fc2:
    _Var2 = false;
  }
  else {
    if (work->work_block == work_block) {
      ppVar8 = work->pool;
      iVar7 = work->rolltime;
      if (work->rolltime <= opt_scantime) {
        iVar7 = opt_expiry;
      }
      if ((share) || (ppVar8->has_stratum == false)) {
LAB_00028084:
        iVar7 = iVar7 - (int)(longlong)
                             ((ppVar8->cgminer_pool_stats).getwork_wait_rolling * 5.0 + 1.0);
        cgtime(&now);
        if (iVar7 < 5) {
          iVar7 = 5;
        }
        if (now.tv_sec - (work->tv_staged).tv_sec < iVar7) {
          if ((((opt_fail_only == false) || (share)) || (ppVar3 = current_pool(), ppVar8 == ppVar3))
             || (((work->mandatory != false || (pool_strategy == POOL_LOADBALANCE)) ||
                 (pool_strategy == POOL_BALANCE)))) goto LAB_00027fc2;
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            pcVar6 = "Work stale due to fail only pool mismatch";
LAB_00028146:
            tmp42._0_4_ = *(undefined4 *)pcVar6;
            tmp42._4_4_ = *(undefined4 *)(pcVar6 + 4);
            tmp42._8_4_ = *(undefined4 *)(pcVar6 + 8);
            tmp42._12_4_ = *(undefined4 *)(pcVar6 + 0xc);
            tmp42._16_4_ = *(undefined4 *)(pcVar6 + 0x10);
            tmp42._20_4_ = *(undefined4 *)(pcVar6 + 0x14);
            tmp42._24_4_ = *(undefined4 *)(pcVar6 + 0x18);
            tmp42._28_4_ = *(undefined4 *)(pcVar6 + 0x1c);
            tmp42._32_4_ = *(undefined4 *)(pcVar6 + 0x20);
            tmp42._36_4_ = *(undefined4 *)(pcVar6 + 0x24);
            tmp42._40_2_ = (undefined2)*(undefined4 *)(pcVar6 + 0x28);
            _applog(7,tmp42,false);
            return true;
          }
        }
        else if ((opt_debug != false) &&
                (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Work stale due to expiry",0x18);
          tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
          _applog(7,tmp42,false);
          return true;
        }
      }
      else if ((ppVar8->stratum_active == false) || (ppVar8->stratum_notify == false)) {
        if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Work stale due to stratum inactive",0x23);
          tmp42[0x23] = SUB41(uVar1,3);
          _applog(7,tmp42,false);
          return true;
        }
      }
      else {
        iVar4 = pthread_mutex_lock((pthread_mutex_t *)&ppVar8->data_lock);
        if (iVar4 != 0) {
          _mutex_lock((pthread_mutex_t *)"stale_work",(char *)0x137d,func,line);
        }
        __rwlock = &(ppVar8->data_lock).rwlock;
        iVar4 = pthread_rwlock_rdlock((pthread_rwlock_t *)__rwlock);
        if (iVar4 != 0) {
          _rd_lock((pthread_rwlock_t *)"stale_work",(char *)0x137d,func_00,line_00);
        }
        iVar4 = pthread_mutex_unlock((pthread_mutex_t *)&ppVar8->data_lock);
        if (iVar4 != 0) {
          _mutex_unlock_noyield((pthread_mutex_t *)"stale_work",(char *)0x137d,func_01,line_01);
        }
        iVar4 = strcmp(work->job_id,(ppVar8->swork).job_id);
        iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
        if (iVar5 != 0) {
          _rw_unlock((pthread_rwlock_t *)"stale_work",(char *)0x1384,func_02,line_02);
        }
        (*selective_yield)();
        if (iVar4 == 0) goto LAB_00028084;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          pcVar6 = "Work stale due to stratum job_id mismatch";
          goto LAB_00028146;
        }
      }
    }
    else if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Work stale due to block mismatch",0x20);
      tmp42._32_4_ = tmp42._32_4_ & 0xffffff00;
      _applog(7,tmp42,false);
      return true;
    }
    _Var2 = true;
  }
  return _Var2;
}

