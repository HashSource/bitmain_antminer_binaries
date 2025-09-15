
char * set_userpass(char *arg)

{
  char *pcVar1;
  pool *ppVar2;
  char *arg_local;
  char *updup;
  pool *pool;
  
  if ((total_users == 0) && (total_passes == 0)) {
    total_userpasses = total_userpasses + 1;
    if (total_pools < total_userpasses) {
      add_pool();
    }
    ppVar2 = pools[total_userpasses + 0x3fffffff];
    pcVar1 = strdup(arg);
    opt_set_charp(arg,&ppVar2->rpc_userpass);
    pcVar1 = strtok(pcVar1,":");
    ppVar2->rpc_user = pcVar1;
    if (ppVar2->rpc_user == (char *)0x0) {
      pcVar1 = "Failed to find : delimited user info";
    }
    else {
      pcVar1 = strtok((char *)0x0,":");
      ppVar2->rpc_pass = pcVar1;
      if (ppVar2->rpc_pass == (char *)0x0) {
        pcVar1 = strdup("");
        ppVar2->rpc_pass = pcVar1;
      }
      pcVar1 = (char *)0x0;
    }
  }
  else {
    pcVar1 = "Use only user + pass or userpass, but not both";
  }
  return pcVar1;
}

