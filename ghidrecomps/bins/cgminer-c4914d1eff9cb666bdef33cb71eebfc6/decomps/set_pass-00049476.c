
char * set_pass(char *arg)

{
  char *pcVar1;
  char *arg_local;
  pool *pool;
  
  if (total_userpasses == 0) {
    total_passes = total_passes + 1;
    if (total_pools < total_passes) {
      add_pool();
    }
    opt_set_charp(arg,&pools[total_passes + 0x3fffffff]->rpc_pass);
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = "Use only user + pass or userpass, but not both";
  }
  return pcVar1;
}

