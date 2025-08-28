
_Bool stratum_send(pool *pool,char *s,ssize_t len)

{
  undefined4 uVar1;
  undefined1 uVar2;
  bool bVar3;
  ssize_t len_local;
  char *s_local;
  pool *pool_local;
  char tmp42 [2048];
  send_ret ret;
  
  ret = SEND_INACTIVE;
  if (((opt_protocol) && (opt_debug)) && ((use_syslog || ((opt_log_output || (6 < opt_log_level)))))
     ) {
    snprintf(tmp42,0x800,"SEND: %s",s);
    _applog(7,tmp42,false);
  }
  _mutex_lock(&pool->stratum_lock,"util.c","stratum_send",0x6cf);
  if (pool->stratum_active != false) {
    ret = __stratum_send(pool,s,len);
  }
  _mutex_unlock(&pool->stratum_lock,"util.c","stratum_send",0x6d6);
  uVar1 = tmp42._28_4_;
  if (ret == SEND_SENDFAIL) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Failed to send in stratum_send",0x1f);
      tmp42[0x1f] = SUB41(uVar1,3);
      _applog(7,tmp42,false);
    }
    suspend_stratum(pool);
  }
  else if (ret == SEND_INACTIVE) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Stratum send failed due to no pool stratum_activ",0x30);
      tmp42[0x30] = 'e';
      tmp42[0x31] = '\0';
      _applog(7,tmp42,false);
    }
  }
  else if (ret == SEND_SELECTFAIL) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Write select failed on pool %d sock",pool->pool_no);
      _applog(7,tmp42,false);
    }
    suspend_stratum(pool);
  }
  bVar3 = ret == SEND_OK;
  if (bVar3) {
    ret = SEND_SELECTFAIL;
  }
  uVar2 = (undefined1)ret;
  if (!bVar3) {
    uVar2 = 0;
  }
  return (_Bool)uVar2;
}

