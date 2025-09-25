
EVP_PKEY * d2i_PrivateKey(int type,EVP_PKEY **a,uchar **pp,long length)

{
  int iVar1;
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pkey;
  int iVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  EVP_PKEY *pkey_00;
  uchar *local_24 [2];
  
  local_24[0] = *pp;
  if ((a == (EVP_PKEY **)0x0) || (pkey_00 = *a, pkey_00 == (EVP_PKEY *)0x0)) {
    pkey_00 = EVP_PKEY_new();
    if (pkey_00 == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0x9a,6,"crypto/asn1/d2i_pr.c",0x1d);
      return (EVP_PKEY *)0x0;
    }
  }
  else {
    ENGINE_finish(pkey_00->engine);
    pkey_00->engine = (ENGINE *)0x0;
  }
  iVar1 = EVP_PKEY_set_type(pkey_00,type);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0x9a,0xa3,"crypto/asn1/d2i_pr.c",0x29);
  }
  else {
    pEVar3 = pkey_00->ameth;
    if (*(code **)(pEVar3 + 0x60) != (code *)0x0) {
      iVar1 = (**(code **)(pEVar3 + 0x60))(pkey_00,local_24,length);
      pkey = pkey_00;
      if (iVar1 != 0) goto LAB_00102046;
      pEVar3 = pkey_00->ameth;
    }
    if (*(int *)(pEVar3 + 0x24) == 0) {
      ERR_put_error(0xd,0x9a,0xd,"crypto/asn1/d2i_pr.c",0x3e);
    }
    else {
      p8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,local_24,length);
      if (p8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        pkey = EVP_PKCS82PKEY(p8);
        PKCS8_PRIV_KEY_INFO_free(p8);
        if (pkey != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(pkey_00);
          iVar1 = EVP_PKEY_type(type);
          iVar2 = EVP_PKEY_base_id(pkey);
          pkey_00 = pkey;
          if (iVar1 == iVar2) {
LAB_00102046:
            *pp = local_24[0];
            if (a != (EVP_PKEY **)0x0) {
              *a = pkey;
              return pkey;
            }
            return pkey;
          }
        }
      }
    }
  }
  if ((a == (EVP_PKEY **)0x0) || (pkey_00 != *a)) {
    EVP_PKEY_free(pkey_00);
  }
  return (EVP_PKEY *)0x0;
}

