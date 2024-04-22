
EVP_PKEY * d2i_PrivateKey(int type,EVP_PKEY **a,uchar **pp,long length)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pkey;
  
  if ((a == (EVP_PKEY **)0x0) || (pkey = *a, pkey == (EVP_PKEY *)0x0)) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0x9a,6,DAT_000b8014,0x4e);
      return (EVP_PKEY *)0x0;
    }
  }
  else if (pkey->engine != (ENGINE *)0x0) {
    ENGINE_finish(pkey->engine);
    pkey->engine = (ENGINE *)0x0;
  }
  iVar1 = EVP_PKEY_set_type(pkey,type);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0x9a,0xa3,DAT_000b8014,0x5c);
  }
  else {
    pEVar2 = pkey->ameth;
    if (*(code **)(pEVar2 + 0x5c) != (code *)0x0) {
      iVar1 = (**(code **)(pEVar2 + 0x5c))(pkey,pp,length);
      if (iVar1 != 0) goto LAB_000b7fb2;
      pEVar2 = pkey->ameth;
    }
    if (*(int *)(pEVar2 + 0x24) == 0) {
      ERR_put_error(0xd,0x9a,0xd,DAT_000b8014,0x6c);
    }
    else {
      p8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,pp,length);
      if (p8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        EVP_PKEY_free(pkey);
        pkey = EVP_PKCS82PKEY(p8);
        PKCS8_PRIV_KEY_INFO_free(p8);
LAB_000b7fb2:
        if (a != (EVP_PKEY **)0x0) {
          *a = pkey;
          return pkey;
        }
        return pkey;
      }
    }
  }
  if ((a == (EVP_PKEY **)0x0) || (*a != pkey)) {
    EVP_PKEY_free(pkey);
  }
  return (EVP_PKEY *)0x0;
}

