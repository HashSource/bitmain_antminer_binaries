
/* WARNING: Unknown calling convention */

char * set_userpass(char *arg)

{
  char *pcVar1;
  char *pcVar2;
  pool *ppVar3;
  
  if ((total_users == 0) && (total_passes == 0)) {
    total_userpasses = total_userpasses + 1;
    if (total_pools < total_userpasses) {
      add_pool();
    }
    ppVar3 = pools[total_userpasses + -1];
    pcVar1 = (char *)__strdup(arg);
    opt_set_charp(arg,&ppVar3->rpc_userpass);
    pcVar1 = strtok(pcVar1,":");
    ppVar3->rpc_user = pcVar1;
    if (pcVar1 == (char *)0x0) {
      pcVar1 = "Failed to find : delimited user info";
    }
    else {
      pcVar2 = strtok((char *)0x0,":");
      pcVar1 = (char *)0x0;
      ppVar3->rpc_pass = pcVar2;
      if (pcVar2 == (char *)0x0) {
        pcVar1 = (char *)calloc(1,1);
        ppVar3->rpc_pass = pcVar1;
        pcVar1 = (char *)0x0;
      }
    }
  }
  else {
    pcVar1 = "Use only user + pass or userpass, but not both";
  }
  return pcVar1;
}

