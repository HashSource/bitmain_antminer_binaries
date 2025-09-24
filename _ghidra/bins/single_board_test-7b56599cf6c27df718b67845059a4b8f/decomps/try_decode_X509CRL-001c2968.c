
int try_decode_X509CRL(char *param_1,undefined4 param_2,uchar *param_3,long param_4,
                      undefined4 param_5,undefined4 *param_6)

{
  int iVar1;
  X509_CRL *a;
  uchar *local_14 [2];
  
  local_14[0] = param_3;
  if (param_1 != (char *)0x0) {
    iVar1 = strcmp(param_1,"X509 CRL");
    if (iVar1 != 0) {
      return 0;
    }
    *param_6 = 1;
  }
  a = d2i_X509_CRL((X509_CRL **)0x0,local_14,param_4);
  if (a != (X509_CRL *)0x0) {
    *param_6 = 1;
    iVar1 = OSSL_STORE_INFO_new_CRL();
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  X509_CRL_free(a);
  return 0;
}

