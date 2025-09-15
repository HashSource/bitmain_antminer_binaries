
_Bool stratum_works(pool *pool)

{
  _Bool _Var1;
  pool *pool_local;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
    snprintf(tmp42,0x800,"Testing pool %d stratum %s",pool->pool_no,pool->stratum_url);
    _applog(6,tmp42,false);
  }
  _Var1 = extract_sockaddr(pool->stratum_url,&pool->sockaddr_url,&pool->stratum_port);
  if (_Var1) {
    _Var1 = initiate_stratum(pool);
    if (_Var1) {
      _Var1 = true;
    }
    else {
      _Var1 = false;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

