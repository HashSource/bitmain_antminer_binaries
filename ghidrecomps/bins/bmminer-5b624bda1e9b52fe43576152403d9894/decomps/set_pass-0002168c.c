
/* WARNING: Unknown calling convention */

char * set_pass(char *arg)

{
  if (total_userpasses != 0) {
    return "Use only user + pass or userpass, but not both";
  }
  total_passes = total_passes + 1;
  if (total_pools < total_passes) {
    add_pool();
  }
  opt_set_charp(arg,&pools[total_passes + -1]->rpc_pass);
  return (char *)0x0;
}

