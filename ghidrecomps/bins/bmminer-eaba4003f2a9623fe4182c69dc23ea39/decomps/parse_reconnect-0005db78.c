
_Bool parse_reconnect(pool *pool,json_t *val)

{
  _Bool _Var1;
  json_t *pjVar2;
  int iVar3;
  char **ppcVar4;
  json_int_t jVar5;
  undefined local_a40 [8];
  char acStack_a38 [256];
  undefined auStack_938 [8];
  json_t *val_local;
  pool *pool_local;
  char tmp42 [2048];
  char address [256];
  char *stratum_port;
  char *sockaddr_url;
  char *tmp;
  int port_no;
  char *dot_reconnect;
  char *dot_pool;
  char *port;
  char *url;
  
  val_local = val;
  pool_local = pool;
  memset(address,0,0xff);
  pjVar2 = json_array_get(val_local,0);
  url = json_string_value(pjVar2);
  if (url == (char *)0x0) {
    url = pool_local->sockaddr_url;
  }
  else {
    dot_pool = strchr(pool_local->sockaddr_url,0x2e);
    if (dot_pool == (char *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Denied stratum reconnect request for pool without domain \'%s\'",
                 pool_local->sockaddr_url);
        _applog(3,tmp42,false);
      }
      return false;
    }
    dot_reconnect = strchr(url,0x2e);
    if (dot_reconnect == (char *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Denied stratum reconnect request to url without domain \'%s\'",url);
        _applog(3,tmp42,false);
      }
      return false;
    }
    iVar3 = strcmp(dot_pool,dot_reconnect);
    if (iVar3 != 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Denied stratum reconnect request to non-matching domain url \'%s\'",
                 pool_local->sockaddr_url);
        _applog(3,tmp42,false);
      }
      return false;
    }
  }
  pjVar2 = json_array_get(val_local,1);
  jVar5 = json_integer_value(pjVar2);
  port_no = (int)jVar5;
  if (port_no == 0) {
    pjVar2 = json_array_get(val_local,1);
    port = json_string_value(pjVar2);
    ppcVar4 = (char **)auStack_938;
    if (port == (char *)0x0) {
      port = pool_local->stratum_port;
      ppcVar4 = (char **)auStack_938;
    }
  }
  else {
    port = acStack_a38;
    sprintf(port,"%d",port_no);
    ppcVar4 = (char **)local_a40;
  }
  *ppcVar4 = port;
  snprintf(address,0xfe,"%s:%s",url);
  _Var1 = extract_sockaddr(address,&sockaddr_url,&stratum_port);
  if (_Var1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      iVar3 = pool_local->pool_no;
      *ppcVar4 = address;
      snprintf(tmp42,0x800,"Stratum reconnect requested from pool %d to %s",iVar3);
      _applog(4,tmp42,false);
    }
    clear_pool_work(pool_local);
    _mutex_lock(&pool_local->stratum_lock,"util.c","parse_reconnect",0x8b8);
    __suspend_stratum(pool_local);
    tmp = pool_local->sockaddr_url;
    pool_local->sockaddr_url = sockaddr_url;
    pool_local->stratum_url = pool_local->sockaddr_url;
    free(tmp);
    tmp = pool_local->stratum_port;
    pool_local->stratum_port = stratum_port;
    free(tmp);
    _mutex_unlock(&pool_local->stratum_lock,"util.c","parse_reconnect",0x8c1);
    _Var1 = restart_stratum(pool_local);
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

