
int rsa_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  int iVar1;
  RSA *key;
  uchar *puStack_18;
  long local_14 [2];
  
  iVar1 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&puStack_18,local_14,(X509_ALGOR **)0x0,param_2);
  if (iVar1 != 0) {
    key = d2i_RSAPrivateKey((RSA **)0x0,&puStack_18,local_14[0]);
    if (key == (RSA *)0x0) {
      ERR_put_error(4,0x93,4,DAT_000fcea4,0x77);
      iVar1 = 0;
    }
    else {
      EVP_PKEY_assign(param_1,6,key);
      iVar1 = 1;
    }
  }
  return iVar1;
}

