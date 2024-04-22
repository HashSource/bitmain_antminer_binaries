
undefined4 smb_send_open(int *param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined local_44c;
  undefined local_44b;
  short local_446;
  undefined4 local_43c;
  undefined4 local_42c;
  undefined4 local_428;
  short local_41b;
  char acStack_419 [1029];
  
  iVar4 = *param_1;
  iVar3 = *(int *)(iVar4 + 0x14c);
  sVar1 = strlen(*(char **)(iVar3 + 8));
  if (sVar1 + 1 < 0x401) {
    memset(&local_44c,0,0x433);
    local_44c = 0x18;
    local_44b = 0xff;
    sVar1 = strlen(*(char **)(iVar3 + 8));
    local_446 = (short)sVar1;
    local_42c = 7;
    if (*(char *)(iVar4 + 0x309) == '\0') {
      local_43c = 0x80000000;
      local_428 = 1;
    }
    else {
      local_43c = 0xc0000000;
      local_428 = 5;
    }
    local_41b = local_446 + 1;
    strcpy(acStack_419,*(char **)(iVar3 + 8));
    uVar2 = smb_send_message(param_1,0xa2,&local_44c,sVar1 + 0x34);
  }
  else {
    uVar2 = 0x3f;
  }
  return uVar2;
}

