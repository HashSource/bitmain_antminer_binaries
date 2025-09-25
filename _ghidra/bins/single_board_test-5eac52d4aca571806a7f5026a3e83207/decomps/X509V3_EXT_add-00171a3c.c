
int X509V3_EXT_add(X509V3_EXT_METHOD *ext)

{
  int iVar1;
  
  if (ext_list == 0) {
    ext_list = OPENSSL_sk_new(0x171a31,ext);
    if (ext_list == 0) {
      iVar1 = 0x1d;
      goto LAB_00171a62;
    }
  }
  iVar1 = OPENSSL_sk_push(ext_list,ext);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = 0x21;
LAB_00171a62:
  ERR_put_error(0x22,0x68,0x41,"crypto/x509v3/v3_lib.c",iVar1);
  return 0;
}

