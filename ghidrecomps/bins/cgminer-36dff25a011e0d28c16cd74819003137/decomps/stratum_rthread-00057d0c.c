
void * stratum_rthread(void *userdata)

{
  _Bool _Var1;
  pthread_t __th;
  pool *ppVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  void *userdata_local;
  fd_set rd;
  char tmp42 [2048];
  work *work;
  timeval timeout;
  char threadname [16];
  int sel_ret;
  fd_set *__arr;
  pool *pool;
  uint __i;
  char *s;
  
  __th = pthread_self();
  pthread_detach(__th);
                    /* WARNING: Load size is inaccurate */
  snprintf(threadname,0x10,"%d/RStratum",*userdata);
  RenameThread(threadname);
  pool = (pool *)userdata;
  do {
    while( true ) {
      if (pool->removed != false) {
        suspend_stratum(pool);
        return (void *)0x0;
      }
      _Var1 = sock_full(pool);
      if ((!_Var1) && (_Var1 = cnx_needed(pool), !_Var1)) {
        suspend_stratum(pool);
        clear_stratum_shares(pool);
        clear_pool_work(pool);
        wait_lpcurrent(pool);
        while (_Var1 = restart_stratum(pool), !_Var1) {
          pool_died(pool);
          if (pool->removed != false) {
            return (void *)0x0;
          }
          cgsleep_ms(5000);
        }
      }
      for (__i = 0; __i < 0x20; __i = __i + 1) {
        rd.fds_bits[__i] = 0;
      }
      iVar4 = pool->sock;
      iVar3 = iVar4 + 0x1f;
      if (-1 < iVar4) {
        iVar3 = iVar4;
      }
      uVar5 = pool->sock;
      uVar6 = uVar5 & 0x1f;
      if ((int)uVar5 < 1) {
        uVar6 = -(-uVar5 & 0x1f);
      }
      rd.fds_bits[iVar3 >> 5] = rd.fds_bits[iVar3 >> 5] | 1 << (uVar6 & 0xff);
      timeout.tv_sec = 0x5a;
      timeout.tv_usec = 0;
      _Var1 = sock_full(pool);
      if ((_Var1) ||
         (iVar3 = select(pool->sock + 1,(fd_set *)&rd,(fd_set *)0x0,(fd_set *)0x0,
                         (timeval *)&timeout), 0 < iVar3)) {
        s = recv_line(pool);
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"Stratum select failed on pool %d with value %d",pool->pool_no,iVar3)
          ;
          _applog(7,tmp42,false);
        }
        s = (char *)0x0;
      }
      if (s == (char *)0x0) break;
      stratum_resumed(pool);
      _Var1 = parse_method(pool,s);
      if (((_Var1) || (_Var1 = parse_stratum_response(pool,s), _Var1)) ||
         (_Var1 = parse_version_rolling_mask(pool,s), _Var1)) {
        if ((pool->swork).clean != false) {
          work = make_work();
          (pool->swork).clean = false;
          gen_stratum_work(pool,work);
          work->longpoll = true;
          test_work_current(work);
          _free_work(&work,"cgminer.c","stratum_rthread",0x1d8e);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"Unknown stratum msg: %s",s);
        _applog(6,tmp42,false);
      }
      free(s);
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Stratum connection to pool %d interrupted",pool->pool_no);
      _applog(5,tmp42,false);
    }
    pool->getfail_occasions = pool->getfail_occasions + 1;
    total_go = total_go + 1;
    _Var1 = supports_resume(pool);
    if ((!_Var1) || (opt_lowmem != false)) {
      clear_stratum_shares(pool);
    }
    clear_pool_work(pool);
    ppVar2 = current_pool();
    if (pool == ppVar2) {
      restart_threads();
    }
    while (_Var1 = restart_stratum(pool), !_Var1) {
      pool_died(pool);
      if (pool->removed != false) {
        return (void *)0x0;
      }
      cgsleep_ms(5000);
    }
  } while( true );
}

