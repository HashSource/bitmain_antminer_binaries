
int pkey_gost_mac_signctx(undefined4 param_1,uchar *param_2,uint *param_3,EVP_MD_CTX *param_4)

{
  int iVar1;
  uint local_c;
  
  local_c = *param_3;
  if (param_2 == (uchar *)0x0) {
    iVar1 = 1;
    *param_3 = 4;
  }
  else {
    iVar1 = EVP_DigestFinal_ex(param_4,param_2,&local_c);
    *param_3 = local_c;
  }
  return iVar1;
}

