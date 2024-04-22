
char * set_user(char *arg)

{
  char *pcVar1;
  char *arg_local;
  pool *pool;
  
  if (total_userpasses == 0) {
    total_users = total_users + 1;
    if (total_pools < total_users) {
      add_pool();
    }
    opt_set_charp(arg,&pools[total_users + -1]->rpc_user);
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = "Use only user + pass or userpass, but not both";
  }
  return pcVar1;
}

