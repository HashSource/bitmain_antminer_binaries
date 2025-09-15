
void * watchpool_thread(void *userdata)

{
  double dVar1;
  _Bool _Var2;
  uint uVar3;
  pool *ppVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
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
      ppVar4 = pools[i];
      if ((opt_benchmark != true) && (opt_benchfile == (char *)0x0)) {
        reap_curl(ppVar4);
        prune_stratum_shares(ppVar4);
      }
      if (0x77 < intervals) {
        uVar3 = (uint)ppVar4->diff1;
        uVar6 = ppVar4->last_shares;
        dVar1 = (double)__aeabi_l2d(uVar3 - uVar6,
                                    *(int *)((int)&ppVar4->diff1 + 4) -
                                    (((int)uVar6 >> 0x1f) + (uint)(uVar3 < uVar6)));
        ppVar4->last_shares = (int)ppVar4->diff1;
        ppVar4->utility = (ppVar4->utility + dVar1 * 0.63) / 1.63;
        ppVar4->shares = (int)(longlong)ppVar4->utility;
      }
      if ((ppVar4->enabled != POOL_DISABLED) && (ppVar4->testing == false)) {
        _Var2 = pool_active(ppVar4,true);
        if (_Var2) {
          _Var2 = pool_tclear(ppVar4,&ppVar4->idle);
          if (_Var2) {
            pool_resus(ppVar4);
          }
        }
        else {
          cgtime(&ppVar4->tv_idle);
        }
        if ((((ppVar4->idle != true) && (pool_strategy == POOL_FAILOVER)) &&
            (iVar7 = ppVar4->prio, iVar5 = cp_prio(), iVar7 < iVar5)) &&
           (opt_pool_fallback < now.tv_sec - (ppVar4->tv_idle).tv_sec)) {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool %d %s stable for >%d seconds",ppVar4->pool_no,ppVar4->rpc_url
                     ,opt_pool_fallback);
            _applog(4,tmp42,false);
          }
          switch_pools((pool *)0x0);
        }
      }
    }
    ppVar4 = current_pool();
    if (ppVar4->idle != false) {
      switch_pools((pool *)0x0);
    }
    if ((pool_strategy == POOL_ROTATE) &&
       (iVar5 = now.tv_sec - rotate_tv.tv_sec,
       iVar5 != opt_rotate_period * 0x3c &&
       iVar5 + opt_rotate_period * -0x3c < 0 == SBORROW4(iVar5,opt_rotate_period * 0x3c))) {
      cgtime(&rotate_tv);
      switch_pools((pool *)0x0);
    }
    cgsleep_ms_r(&cgt,5000);
    cgtimer_time(&cgt);
  } while( true );
}

