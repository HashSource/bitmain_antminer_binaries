
/* WARNING: Unknown calling convention */

char * set_user(char *arg)

{
  if (total_userpasses != 0) {
    return "Use only user + pass or userpass, but not both";
  }
  total_users = total_users + 1;
  if (total_pools < total_users) {
    add_pool();
  }
  opt_set_charp(arg,&pools[total_users + -1]->rpc_user);
  return (char *)0x0;
}

