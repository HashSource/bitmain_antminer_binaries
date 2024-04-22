
int pkey_dh_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  
  iVar1 = strcmp(param_2,DAT_00100598);
  if (iVar1 == 0) {
    lVar2 = strtol(param_3,(char **)0x0,10);
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x1c,2,0x1001,lVar2,(void *)0x0);
    return iVar1;
  }
  iVar1 = strcmp(param_2,DAT_0010059c);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x14);
    uVar3 = strtol(param_3,(char **)0x0,10);
    if (uVar3 < 4) {
      *(uint *)(iVar1 + 0x14) = uVar3;
      return 1;
    }
  }
  else {
    iVar1 = strcmp(param_2,DAT_001005a0);
    if (iVar1 == 0) {
      lVar2 = strtol(param_3,(char **)0x0,10);
      iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x1c,2,0x1002,lVar2,(void *)0x0);
      return iVar1;
    }
    iVar1 = strcmp(param_2,DAT_001005a4);
    if (iVar1 == 0) {
      lVar2 = strtol(param_3,(char **)0x0,10);
      iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x1c,2,0x1004,lVar2,(void *)0x0);
      return iVar1;
    }
    iVar1 = strcmp(param_2,DAT_001005a8);
    if (iVar1 == 0) {
      lVar2 = strtol(param_3,(char **)0x0,10);
      iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x1c,2,0x1005,lVar2,(void *)0x0);
      return iVar1;
    }
  }
  return -2;
}

