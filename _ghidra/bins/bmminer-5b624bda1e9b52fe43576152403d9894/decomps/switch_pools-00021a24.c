
/* WARNING: Unknown calling convention */

void switch_pools(pool *selected)

{
  pool *pool;
  _Bool _Var1;
  int iVar2;
  pool **pppVar3;
  pool *ppVar4;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  char *func_03;
  char *func_04;
  int line;
  int line_00;
  pool **pppVar5;
  uint uVar6;
  int line_01;
  int line_02;
  int line_03;
  int line_04;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char tmp42 [2048];
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&control_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"switch_pools",(char *)0x1417,func,line);
  }
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar2 != 0) {
    _wr_lock((pthread_rwlock_t *)"switch_pools",(char *)0x1417,func_00,line_00);
  }
  pool = currentpool;
  iVar9 = currentpool->pool_no;
  iVar2 = total_pools;
  pppVar5 = pools;
  if ((selected != (pool *)0x0) && (iVar8 = selected->prio, iVar8 != 0)) {
    if (0 < total_pools) {
      pppVar3 = pools + total_pools;
      while( true ) {
        iVar2 = (*pppVar5)->prio;
        if (iVar2 < iVar8) {
          (*pppVar5)->prio = iVar2 + 1;
        }
        if (pppVar5 + 1 == pppVar3) break;
        iVar8 = selected->prio;
        pppVar5 = pppVar5 + 1;
      }
    }
    selected->prio = 0;
    iVar2 = total_pools;
    pppVar5 = pools;
  }
  total_pools = iVar2;
  pools = pppVar5;
  if (pool_strategy < (POOL_BALANCE|POOL_ROUNDROBIN)) {
    uVar6 = 1 << (pool_strategy & 0xff);
    if ((uVar6 & 0x19) == 0) {
      if ((uVar6 & 6) != 0) {
        if ((selected != (pool *)0x0) && (selected->idle == false)) {
          ppVar4 = pppVar5[selected->pool_no];
          goto LAB_00021ada;
        }
        if (1 < iVar2) {
          iVar10 = 1;
          iVar8 = iVar9;
          do {
            iVar8 = iVar8 + 1;
            iVar10 = iVar10 + 1;
            iVar7 = iVar8 * 4;
            if (iVar2 <= iVar8) {
              iVar7 = 0;
              iVar8 = iVar7;
            }
            ppVar4 = *(pool **)((int)pppVar5 + iVar7);
            _Var1 = pool_unusable(ppVar4);
            if (!_Var1) goto LAB_00021ada;
          } while (iVar10 != iVar2);
          ppVar4 = pppVar5[iVar9];
          goto LAB_00021ada;
        }
      }
    }
    else if (0 < iVar2) {
      iVar2 = 0;
      do {
        iVar8 = iVar2 + 1;
        ppVar4 = priority_pool(iVar2);
        _Var1 = pool_unusable(ppVar4);
        if (!_Var1) {
          ppVar4 = pools[ppVar4->pool_no];
          goto LAB_00021ada;
        }
        iVar2 = iVar8;
      } while (iVar8 < total_pools);
    }
  }
  ppVar4 = pools[iVar9];
LAB_00021ada:
  currentpool = ppVar4;
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar2 != 0) {
    _rw_unlock((pthread_rwlock_t *)"switch_pools",(char *)0x1468,func_01,line_01);
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&control_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"switch_pools",(char *)0x1468,func_02,line_02);
  }
  (*selective_yield)();
  if (((pool != ppVar4) && (pool_strategy != POOL_LOADBALANCE)) && (pool_strategy != POOL_BALANCE))
  {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Switching to pool %d %s",ppVar4->pool_no,ppVar4->rpc_url);
      _applog(4,tmp42,false);
    }
    clear_pool_work(pool);
  }
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&lp_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"switch_pools",(char *)0x1470,func_03,line_03);
  }
  pthread_cond_broadcast((pthread_cond_t *)&lp_cond);
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&lp_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"switch_pools",(char *)0x1472,func_04,line_04);
  }
  (*selective_yield)();
  return;
}

