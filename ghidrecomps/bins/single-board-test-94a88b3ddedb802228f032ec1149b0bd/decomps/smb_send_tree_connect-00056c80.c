
undefined4 smb_send_tree_connect(int *param_1)

{
  size_t sVar1;
  size_t sVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *__dest;
  undefined1 local_424;
  undefined1 local_423;
  undefined2 local_41b;
  undefined2 local_419;
  char local_417 [6];
  char acStack_411 [13];
  char acStack_404 [1004];
  
  pcVar5 = (char *)param_1[0x26];
  iVar4 = *(int *)(*param_1 + 0x14c);
  sVar1 = strlen(pcVar5);
  sVar2 = strlen(*(char **)(iVar4 + 4));
  if (sVar1 + sVar2 + 10 < 0x401) {
    memset(&local_424,0,0x40b);
    local_424 = 4;
    local_423 = 0xff;
    local_419 = 0x5c5c;
    local_417[0] = '\0';
    strcpy(local_417,pcVar5);
    sVar1 = strlen(pcVar5);
    __dest = local_417 + sVar1 + 1;
    pcVar5 = local_417 + sVar1;
    pcVar5[0] = '\\';
    pcVar5[1] = '\0';
    strcpy(__dest,*(char **)(iVar4 + 4));
    sVar2 = strlen(*(char **)(iVar4 + 4));
    builtin_strncpy(local_417 + sVar2 + sVar1 + 2,"?????",6);
    local_41b = SUB42(__dest + ((sVar2 + 7) - (int)&local_419),0);
    uVar3 = smb_send_message(param_1,0x75,&local_424,__dest + ((sVar2 + 7) - (int)&local_419) + 0xb)
    ;
  }
  else {
    uVar3 = 0x3f;
  }
  return uVar3;
}

