
void * watchpool_thread(void *userdata)

{
  double dVar1;
  _Bool _Var2;
  pool *ppVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *userdata_local;
  char tmp42 [2048];
  timeval now;
  cgtimer_t cgt;
  double shares;
  pool *pool;
  int i;
  int intervals;
  
  intervals = 0;
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("Watchpool");
  set_lowprio();
  cgtimer_time(&cgt);
  do {
    intervals = intervals + 1;
    if (0x78 < intervals) {
      intervals = 0;
    }
    cgtime(&now);
    for (i = 0; i < total_pools; i = i + 1) {
      ppVar3 = pools[i];
      if ((opt_benchmark != true) && (opt_benchfile == (char *)0x0)) {
        reap_curl(ppVar3);
        prune_stratum_shares(ppVar3);
      }
      if (0x77 < intervals) {
        uVar5 = ppVar3->last_shares;
        dVar1 = (double)__aeabi_l2d(*(uint *)&ppVar3->diff1 - uVar5,
                                    (*(int *)((int)&ppVar3->diff1 + 4) - ((int)uVar5 >> 0x1f)) -
                                    (uint)(*(uint *)&ppVar3->diff1 < uVar5));
        ppVar3->last_shares = *(int *)&ppVar3->diff1;
        ppVar3->utility = (ppVar3->utility + dVar1 * DAT_00059ea0) / DAT_00059ea8;
        ppVar3->shares = (int)(longlong)ppVar3->utility;
      }
      if ((ppVar3->enabled != POOL_DISABLED) && (ppVar3->testing == false)) {
        _Var2 = pool_active(ppVar3,true);
        if (_Var2) {
          _Var2 = pool_tclear(ppVar3,&ppVar3->idle);
          if (_Var2) {
            pool_resus(ppVar3);
          }
        }
        else {
          cgtime(&ppVar3->tv_idle);
        }
        if ((((ppVar3->idle != true) && (pool_strategy == POOL_FAILOVER)) &&
            (iVar6 = ppVar3->prio, iVar4 = cp_prio(), iVar6 < iVar4)) &&
           (opt_pool_fallback < now.tv_sec - (ppVar3->tv_idle).tv_sec)) {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool %d %s stable for >%d seconds",ppVar3->pool_no,ppVar3->rpc_url
                     ,opt_pool_fallback);
            _applog(4,tmp42,false);
          }
          switch_pools((pool *)0x0);
        }
      }
    }
    ppVar3 = current_pool();
    if (ppVar3->idle != false) {
      switch_pools((pool *)0x0);
    }
    if ((pool_strategy == POOL_ROTATE) &&
       (iVar4 = now.tv_sec - rotate_tv.tv_sec,
       iVar4 != opt_rotate_period * 0x3c &&
       iVar4 + opt_rotate_period * -0x3c < 0 == SBORROW4(iVar4,opt_rotate_period * 0x3c))) {
      cgtime(&rotate_tv);
      switch_pools((pool *)0x0);
    }
    cgsleep_ms_r(&cgt,5000);
    cgtimer_time(&cgt);
  } while( true );
}

