
/* WARNING: Unknown calling convention */

_Bool stratum_send(pool *pool,char *s,ssize_t len)

{
  int iVar1;
  int *piVar2;
  char *func;
  int line;
  send_ret sVar3;
  char cVar4;
  char tmp42 [2048];
  
  if (((opt_protocol) && (opt_debug)) && ((use_syslog || ((opt_log_output || (6 < opt_log_level)))))
     ) {
    snprintf(tmp42,0x800,"SEND: %s",s);
    _applog(7,tmp42,false);
  }
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"stratum_send",(char *)0x698,func,line);
  }
  if (pool->stratum_active == false) {
    sVar3 = SEND_INACTIVE;
    cVar4 = '\0';
  }
  else {
    sVar3 = __stratum_send(pool,s,len);
    cVar4 = '\x01' - (char)sVar3;
    if (SEND_SELECTFAIL < sVar3) {
      cVar4 = '\0';
    }
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,"util.c",
             "stratum_send",0x69e);
    _applog(3,tmp42,true);
    _quit(1);
  }
  (*selective_yield)();
  if (sVar3 == SEND_SENDFAIL) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Failed to send in stratum_send",0x1f);
      _applog(7,tmp42,false);
      suspend_stratum(pool);
      return (_Bool)cVar4;
    }
  }
  else {
    if (sVar3 == SEND_INACTIVE) {
      if (opt_debug == false) {
        return (_Bool)cVar4;
      }
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
        return (_Bool)cVar4;
      }
      builtin_strncpy(tmp42,"Stratum send failed due to no pool stratum_activ",0x30);
      tmp42[0x30] = 'e';
      tmp42[0x31] = '\0';
      _applog(7,tmp42,false);
      return (_Bool)cVar4;
    }
    if (sVar3 != SEND_SELECTFAIL) {
      return (_Bool)cVar4;
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Write select failed on pool %d sock",pool->pool_no);
      _applog(7,tmp42,false);
    }
  }
  suspend_stratum(pool);
  return (_Bool)cVar4;
}

