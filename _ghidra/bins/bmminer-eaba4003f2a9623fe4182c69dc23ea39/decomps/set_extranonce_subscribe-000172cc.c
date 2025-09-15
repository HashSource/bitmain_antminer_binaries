
char * set_extranonce_subscribe(char *arg)

{
  pool *ppVar1;
  char *arg_local;
  char tmp42 [2048];
  pool *pool;
  
  total_extranonce = total_extranonce + 1;
  if (total_pools < total_extranonce) {
    add_pool();
  }
  ppVar1 = pools[total_extranonce + -1];
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Enable extranonce subscribe on %d",ppVar1->pool_no);
    _applog(7,tmp42,false);
  }
  opt_set_bool(&ppVar1->extranonce_subscribe);
  return (char *)0x0;
}

