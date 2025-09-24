
int RSA_pkey_ctx_ctrl(EVP_PKEY_CTX *param_1,int param_2,int param_3,int param_4,void *param_5)

{
  int iVar1;
  
  if (((param_1 == (EVP_PKEY_CTX *)0x0) || (*(int **)param_1 == (int *)0x0)) ||
     (iVar1 = **(int **)param_1, iVar1 == 6 || iVar1 == 0x390)) {
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,-1,param_2,param_3,param_4,param_5);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

