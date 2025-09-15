
/* WARNING: Unknown calling convention */

void suspend_stratum(pool *pool)

{
  int iVar1;
  int *piVar2;
  char *func;
  int line;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
    snprintf(tmp42,0x800,"Closing socket for stratum pool %d",pool->pool_no);
    _applog(6,tmp42,false);
  }
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"suspend_stratum",(char *)0xb9a,func,line);
  }
  clear_sockbuf(pool);
  pool->stratum_notify = false;
  pool->stratum_active = false;
  if (pool->sock != 0) {
    close(pool->sock);
  }
  pool->sock = 0;
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,"util.c",
             "suspend_stratum",0xb9c);
    _applog(3,tmp42,true);
    _quit(1);
  }
  (*selective_yield)();
  return;
}

