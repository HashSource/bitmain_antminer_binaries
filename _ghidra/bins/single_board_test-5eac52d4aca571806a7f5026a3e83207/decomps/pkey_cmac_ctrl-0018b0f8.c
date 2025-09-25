
int pkey_cmac_ctrl(int param_1,int param_2,uint param_3,EVP_CIPHER *param_4)

{
  int iVar1;
  uint uVar2;
  CMAC_CTX *ctx;
  
  ctx = *(CMAC_CTX **)(param_1 + 0x14);
  if (param_2 == 6) {
    uVar2 = param_3 >> 0x1f;
    if (param_4 == (EVP_CIPHER *)0x0) {
      uVar2 = 1;
    }
    if (uVar2 == 0) {
      iVar1 = CMAC_Init(ctx,param_4,param_3,(EVP_CIPHER *)0x0,(ENGINE *)0x0);
      if (iVar1 == 0) {
        return 0;
      }
      return 1;
    }
  }
  else {
    if (param_2 == 0xc) {
      iVar1 = CMAC_Init(ctx,(void *)0x0,0,param_4,*(ENGINE **)(param_1 + 4));
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
    if (param_2 != 1) {
      return -2;
    }
    if ((*(int *)(param_1 + 8) == 0) ||
       (iVar1 = CMAC_CTX_copy(ctx,*(CMAC_CTX **)(*(int *)(param_1 + 8) + 0x18)), iVar1 != 0)) {
      iVar1 = CMAC_Init(ctx,(void *)0x0,0,(EVP_CIPHER *)0x0,(ENGINE *)0x0);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
  }
  return 0;
}

