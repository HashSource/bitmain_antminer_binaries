
int try_decode_X509Certificate
              (char *param_1,undefined4 param_2,uchar *param_3,long param_4,undefined4 param_5,
              undefined4 *param_6)

{
  int iVar1;
  X509 *a;
  uchar *local_1c [2];
  
  local_1c[0] = param_3;
  if (param_1 == (char *)0x0) {
    a = d2i_X509_AUX((X509 **)0x0,local_1c,param_4);
joined_r0x001be7e4:
    if (a == (X509 *)0x0) {
      a = d2i_X509((X509 **)0x0,local_1c,param_4);
      goto joined_r0x001be7c8;
    }
  }
  else {
    iVar1 = strcmp(param_1,"TRUSTED CERTIFICATE");
    if (iVar1 != 0) {
      iVar1 = strcmp(param_1,"X509 CERTIFICATE");
      if ((iVar1 != 0) && (iVar1 = strcmp(param_1,"CERTIFICATE"), iVar1 != 0)) {
        return 0;
      }
      *param_6 = 1;
      a = d2i_X509_AUX((X509 **)0x0,local_1c,param_4);
      goto joined_r0x001be7e4;
    }
    *param_6 = 1;
    a = d2i_X509_AUX((X509 **)0x0,local_1c,param_4);
joined_r0x001be7c8:
    if (a == (X509 *)0x0) {
      a = (X509 *)0x0;
      goto LAB_001be7cc;
    }
  }
  *param_6 = 1;
  iVar1 = OSSL_STORE_INFO_new_CERT(a);
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_001be7cc:
  X509_free(a);
  return 0;
}

