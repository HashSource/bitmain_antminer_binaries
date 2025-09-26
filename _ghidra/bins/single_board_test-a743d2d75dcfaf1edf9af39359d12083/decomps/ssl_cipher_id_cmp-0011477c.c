
int ssl_cipher_id_cmp(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8) - *(int *)(param_2 + 8);
  if (iVar1 != 0) {
    if (0 < iVar1) {
      return 1;
    }
    iVar1 = -1;
  }
  return iVar1;
}

