
int i2d_PKCS8PrivateKeyInfo_fp(FILE *fp,EVP_PKEY *key)

{
  PKCS8_PRIV_KEY_INFO *a;
  int iVar1;
  
  a = EVP_PKEY2PKCS8(key);
  if (a != (PKCS8_PRIV_KEY_INFO *)0x0) {
    iVar1 = ASN1_i2d_fp(DAT_000c4a58,fp,a);
    PKCS8_PRIV_KEY_INFO_free(a);
    return iVar1;
  }
  return 0;
}

