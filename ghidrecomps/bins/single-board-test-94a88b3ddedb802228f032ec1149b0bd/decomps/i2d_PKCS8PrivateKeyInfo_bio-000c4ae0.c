
int i2d_PKCS8PrivateKeyInfo_bio(BIO *bp,EVP_PKEY *key)

{
  PKCS8_PRIV_KEY_INFO *a;
  int iVar1;
  
  a = EVP_PKEY2PKCS8(key);
  if (a != (PKCS8_PRIV_KEY_INFO *)0x0) {
    iVar1 = ASN1_i2d_bio((undefined1 *)0xbd80d,bp,(uchar *)a);
    PKCS8_PRIV_KEY_INFO_free(a);
    return iVar1;
  }
  return 0;
}

