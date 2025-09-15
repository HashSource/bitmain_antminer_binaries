
char * set_user(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (total_userpasses != 0) {
    return "Use only user + pass or userpass, but not both";
  }
  total_users = total_users + 1;
  if (total_pools < total_users) {
    add_pool();
  }
  opt_set_charp(param_1,*(int *)(pools + (total_users + 0x3fffffff) * 4) + 0xac,pools,
                total_users + 0x3fffffff,param_4);
  return (char *)0x0;
}

