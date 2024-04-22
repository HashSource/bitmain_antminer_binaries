
/* WARNING: Type propagation algorithm not settling */

undefined4 smb_send_tree_connect(int *param_1)

{
  undefined2 uVar1;
  size_t sVar2;
  size_t sVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined local_424;
  undefined local_423;
  undefined2 local_41b;
  undefined2 local_419;
  undefined2 local_417;
  undefined4 uStack_415;
  undefined2 auStack_411 [508];
  
  pcVar6 = (char *)param_1[0x26];
  iVar5 = *(int *)(*param_1 + 0x14c);
  sVar2 = strlen(pcVar6);
  sVar3 = strlen(*(char **)(iVar5 + 4));
  if (sVar2 + sVar3 + 10 < 0x401) {
    memset(&local_424,0,0x40b);
    local_424 = 4;
    local_419 = *DAT_00056d4c;
    local_417._0_1_ = *(char *)(DAT_00056d4c + 1);
    local_423 = 0xff;
    strcpy((char *)&local_417,pcVar6);
    sVar2 = strlen(pcVar6);
    pcVar6 = (char *)((int)&local_417 + sVar2 + 1);
    *(undefined2 *)((int)&local_417 + sVar2) = *DAT_00056d50;
    strcpy(pcVar6,*(char **)(iVar5 + 4));
    sVar2 = strlen(*(char **)(iVar5 + 4));
    uVar1 = *(undefined2 *)(DAT_00056d54 + 1);
    *(undefined4 *)(pcVar6 + sVar2 + 1) = *DAT_00056d54;
    *(undefined2 *)(pcVar6 + sVar2 + 5) = uVar1;
    local_41b = SUB42(pcVar6 + ((sVar2 + 7) - (int)&local_419),0);
    uVar4 = smb_send_message(param_1,0x75,&local_424,pcVar6 + ((sVar2 + 7) - (int)&local_419) + 0xb)
    ;
  }
  else {
    uVar4 = 0x3f;
  }
  return uVar4;
}

