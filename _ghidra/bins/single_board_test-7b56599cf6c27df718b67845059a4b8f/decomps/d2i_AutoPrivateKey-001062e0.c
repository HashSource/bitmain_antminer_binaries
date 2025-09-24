
EVP_PKEY * d2i_AutoPrivateKey(EVP_PKEY **a,uchar **pp,long length)

{
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pEVar1;
  ASN1_SEQUENCE_ANY *pAVar2;
  int iVar3;
  uchar *local_24 [2];
  
  ERR_set_mark();
  local_24[0] = *pp;
  p8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,local_24,length);
  if (p8 == (PKCS8_PRIV_KEY_INFO *)0x0) {
    local_24[0] = *pp;
    pAVar2 = d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,local_24,length);
    local_24[0] = *pp;
    iVar3 = OPENSSL_sk_num();
    if (iVar3 == 6) {
      iVar3 = 0x74;
    }
    else {
      iVar3 = OPENSSL_sk_num(pAVar2);
      if (iVar3 == 4) {
        iVar3 = 0x198;
      }
      else {
        iVar3 = 6;
      }
    }
    OPENSSL_sk_pop_free(pAVar2,0x10a245);
    pEVar1 = d2i_PrivateKey(iVar3,a,pp,length);
    if (pEVar1 != (EVP_PKEY *)0x0) {
      ERR_pop_to_mark();
      return pEVar1;
    }
    ERR_clear_last_mark();
    pEVar1 = (EVP_PKEY *)0x0;
  }
  else {
    pEVar1 = EVP_PKCS82PKEY(p8);
    if (pEVar1 == (EVP_PKEY *)0x0) {
      PKCS8_PRIV_KEY_INFO_free(p8);
      ERR_clear_last_mark();
      ERR_put_error(0xd,0xcf,0xa7,"crypto/asn1/d2i_pr.c",0x7b);
      return (EVP_PKEY *)0x0;
    }
    PKCS8_PRIV_KEY_INFO_free(p8);
    *pp = local_24[0];
    ERR_clear_last_mark();
    if (a != (EVP_PKEY **)0x0) {
      *a = pEVar1;
    }
  }
  return pEVar1;
}

