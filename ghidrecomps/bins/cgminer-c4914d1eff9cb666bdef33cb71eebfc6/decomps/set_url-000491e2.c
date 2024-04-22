
char * set_url(char *arg)

{
  pool *pool_00;
  char *pcVar1;
  char *arg_local;
  char tmp42 [2048];
  pool *pool;
  
  pool_00 = add_url();
  setup_url(pool_00,arg);
  pcVar1 = strstr(pool_00->rpc_url,".nicehash.com");
  if ((((pcVar1 != (char *)0x0) ||
       (pcVar1 = strstr(pool_00->rpc_url,"#xnsub"), pcVar1 != (char *)0x0)) &&
      (pool_00->extranonce_subscribe = true, opt_debug != false)) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Pool %d extranonce subscribing enabled.",pool_00->pool_no);
    _applog(7,tmp42,false);
  }
  return (char *)0x0;
}

