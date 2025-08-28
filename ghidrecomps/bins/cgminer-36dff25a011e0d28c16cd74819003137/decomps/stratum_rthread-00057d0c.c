
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
  do {
    while( true ) {
      if (*(char *)((int)userdata + 0x69) != '\0') {
        suspend_stratum((pool *)userdata);
        return (void *)0x0;
      }
      _Var1 = sock_full((pool *)userdata);
      if ((!_Var1) && (_Var1 = cnx_needed((pool *)userdata), !_Var1)) {
        suspend_stratum((pool *)userdata);
        clear_stratum_shares((pool *)userdata);
        clear_pool_work((pool *)userdata);
        wait_lpcurrent((pool *)userdata);
        while (_Var1 = restart_stratum((pool *)userdata), !_Var1) {
          pool_died((pool *)userdata);
          if (*(char *)((int)userdata + 0x69) != '\0') {
            return (void *)0x0;
          }
          cgsleep_ms(5000);
        }
      }
      for (__i = 0; __i < 0x20; __i = __i + 1) {
        rd.fds_bits[__i] = 0;
      }
      iVar4 = *(int *)((int)userdata + 0x24c);
      iVar3 = iVar4 + 0x1f;
      if (-1 < iVar4) {
        iVar3 = iVar4;
      }
      uVar5 = *(uint *)((int)userdata + 0x24c);
      uVar6 = uVar5 & 0x1f;
      if ((int)uVar5 < 1) {
        uVar6 = -(-uVar5 & 0x1f);
      }
      rd.fds_bits[iVar3 >> 5] = rd.fds_bits[iVar3 >> 5] | 1 << (uVar6 & 0xff);
      timeout.tv_sec = 0x5a;
      timeout.tv_usec = 0;
      _Var1 = sock_full((pool *)userdata);
      if ((_Var1) ||
         (iVar3 = select(*(int *)((int)userdata + 0x24c) + 1,(fd_set *)&rd,(fd_set *)0x0,
                         (fd_set *)0x0,(timeval *)&timeout), 0 < iVar3)) {
        s = recv_line((pool *)userdata);
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
          snprintf(tmp42,0x800,"Stratum select failed on pool %d with value %d",*userdata,iVar3);
          _applog(7,tmp42,false);
        }
        s = (char *)0x0;
      }
      if (s == (char *)0x0) break;
      stratum_resumed((pool *)userdata);
      _Var1 = parse_method((pool *)userdata,s);
      if (((_Var1) || (_Var1 = parse_stratum_response((pool *)userdata,s), _Var1)) ||
         (_Var1 = parse_version_rolling_mask((pool *)userdata,s), _Var1)) {
        if (*(char *)((int)userdata + 0x2a8) != '\0') {
          work = make_work();
          *(undefined1 *)((int)userdata + 0x2a8) = 0;
          gen_stratum_work((pool *)userdata,work);
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
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"Stratum connection to pool %d interrupted",*userdata);
      _applog(5,tmp42,false);
    }
    *(int *)((int)userdata + 0x80) = *(int *)((int)userdata + 0x80) + 1;
    total_go = total_go + 1;
    _Var1 = supports_resume((pool *)userdata);
    if ((!_Var1) || (opt_lowmem != false)) {
      clear_stratum_shares((pool *)userdata);
    }
    clear_pool_work((pool *)userdata);
    ppVar2 = current_pool();
    if ((pool *)userdata == ppVar2) {
      restart_threads();
    }
    while (_Var1 = restart_stratum((pool *)userdata), !_Var1) {
      pool_died((pool *)userdata);
      if (*(char *)((int)userdata + 0x69) != '\0') {
        return (void *)0x0;
      }
      cgsleep_ms(5000);
    }
  } while( true );
}

