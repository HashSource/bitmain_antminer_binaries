
int SSL_CIPHER_get_cipher_nid(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      if (*(int *)(param_1 + 0x18) == (&ssl_cipher_table_cipher)[iVar1 * 2]) {
        return (&DAT_0020e948)[iVar1 * 2];
      }
      iVar1 = iVar2;
    } while (iVar2 != 0x16);
    param_1 = 0;
  }
  return param_1;
}

