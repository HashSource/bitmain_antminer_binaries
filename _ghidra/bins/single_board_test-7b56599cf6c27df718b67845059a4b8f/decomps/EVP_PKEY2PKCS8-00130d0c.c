
PKCS8_PRIV_KEY_INFO * EVP_PKEY2PKCS8(EVP_PKEY *pkey)

{
  PKCS8_PRIV_KEY_INFO *a;
  int iVar1;
  code *pcVar2;
  
  a = PKCS8_PRIV_KEY_INFO_new();
  if (a == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(6,0x71,0x41,"crypto/evp/evp_pkey.c",0x41);
  }
  else {
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      ERR_put_error(6,0x71,0x76,"crypto/evp/evp_pkey.c",0x50);
    }
    else {
      pcVar2 = *(code **)(pkey->ameth + 0x28);
      if (pcVar2 == (code *)0x0) {
        ERR_put_error(6,0x71,0x90,"crypto/evp/evp_pkey.c",0x4c);
      }
      else {
        iVar1 = (*pcVar2)(a,pkey);
        if (iVar1 != 0) {
          return a;
        }
        ERR_put_error(6,0x71,0x92,"crypto/evp/evp_pkey.c",0x48);
      }
    }
    PKCS8_PRIV_KEY_INFO_free(a);
  }
  return (PKCS8_PRIV_KEY_INFO *)0x0;
}

