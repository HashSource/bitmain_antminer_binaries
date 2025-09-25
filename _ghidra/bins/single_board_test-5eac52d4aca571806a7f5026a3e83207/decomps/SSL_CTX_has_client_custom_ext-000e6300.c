
int SSL_CTX_has_client_custom_ext
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = custom_ext_find(*(int *)(param_1 + 0xc0) + 0xf0,0,param_2,0,param_4);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

