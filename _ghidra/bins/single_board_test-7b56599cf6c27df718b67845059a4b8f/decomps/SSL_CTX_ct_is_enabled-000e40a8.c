
int SSL_CTX_ct_is_enabled(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10c);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

