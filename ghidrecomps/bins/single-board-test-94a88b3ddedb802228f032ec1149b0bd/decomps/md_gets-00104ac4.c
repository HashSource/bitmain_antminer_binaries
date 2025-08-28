
uint md_gets(int param_1,uchar *param_2,int param_3)

{
  int iVar1;
  uint local_c [2];
  
  if (param_3 < (*(EVP_MD_CTX **)(param_1 + 0x20))->digest->md_size) {
    local_c[0] = 0;
  }
  else {
    iVar1 = EVP_DigestFinal_ex(*(EVP_MD_CTX **)(param_1 + 0x20),param_2,local_c);
    if (iVar1 < 1) {
      local_c[0] = 0xffffffff;
    }
  }
  return local_c[0];
}

