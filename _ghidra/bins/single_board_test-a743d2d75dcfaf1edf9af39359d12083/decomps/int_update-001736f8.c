
int int_update(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = CMAC_Update(*(CMAC_CTX **)(*(int *)(param_1 + 0x10) + 0x14),param_2,param_3);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

