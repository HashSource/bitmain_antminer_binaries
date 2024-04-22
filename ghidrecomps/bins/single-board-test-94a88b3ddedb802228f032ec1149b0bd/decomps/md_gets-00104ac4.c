
uint md_gets(int param_1,uchar *param_2,int param_3)

{
  int iVar1;
  uint auStack_c [3];
  
  if (param_3 < (*(EVP_MD_CTX **)(param_1 + 0x20))->digest->md_size) {
    auStack_c[0] = 0;
  }
  else {
    iVar1 = EVP_DigestFinal_ex(*(EVP_MD_CTX **)(param_1 + 0x20),param_2,auStack_c);
    if (iVar1 < 1) {
      auStack_c[0] = 0xffffffff;
    }
  }
  return auStack_c[0];
}

