
char * set_userpass(undefined4 param_1)

{
  char *pcVar1;
  void *pvVar2;
  int iVar3;
  
  if ((total_users == 0) && (total_passes == 0)) {
    total_userpasses = total_userpasses + 1;
    if (total_pools < total_userpasses) {
      add_pool();
    }
    iVar3 = *(int *)(pools + (total_userpasses + 0x3fffffff) * 4);
    pcVar1 = (char *)__strdup(param_1);
    opt_set_charp(param_1,iVar3 + 0xa8);
    pcVar1 = strtok(pcVar1,":");
    *(char **)(iVar3 + 0xac) = pcVar1;
    if (pcVar1 == (char *)0x0) {
      pcVar1 = "Failed to find : delimited user info";
    }
    else {
      pcVar1 = strtok((char *)0x0,":");
      *(char **)(iVar3 + 0xb0) = pcVar1;
      if (pcVar1 != (char *)0x0) {
        return (char *)0x0;
      }
      pvVar2 = calloc(1,1);
      *(void **)(iVar3 + 0xb0) = pvVar2;
      pcVar1 = (char *)0x0;
    }
  }
  else {
    pcVar1 = "Use only user + pass or userpass, but not both";
  }
  return pcVar1;
}

