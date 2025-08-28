
/* WARNING: Unknown calling convention */

char * set_url(char *arg)

{
  pool *pool;
  char *pcVar1;
  char *__haystack;
  char tmp42 [2048];
  
  pool = add_url();
  setup_url(pool,arg);
  __haystack = pool->rpc_url;
  pcVar1 = strstr(__haystack,".nicehash.com");
  if ((((pcVar1 != (char *)0x0) || (pcVar1 = strstr(__haystack,"#xnsub"), pcVar1 != (char *)0x0)) &&
      (pool->extranonce_subscribe = true, opt_debug != false)) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Pool %d extranonce subscribing enabled.",pool->pool_no);
    _applog(7,tmp42,false);
  }
  return (char *)0x0;
}

