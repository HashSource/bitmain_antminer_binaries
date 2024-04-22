
EVP_PKEY * d2i_AutoPrivateKey(EVP_PKEY **a,uchar **pp,long length)

{
  _STACK *st;
  int iVar1;
  EVP_PKEY *pEVar2;
  PKCS8_PRIV_KEY_INFO *p8;
  uchar *local_1c;
  
  local_1c = *pp;
  st = &d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_1c,length)->stack;
  iVar1 = sk_num(st);
  if (iVar1 == 6) {
    iVar1 = 0x74;
  }
  else {
    iVar1 = sk_num(st);
    if (iVar1 == 4) {
      iVar1 = 0x198;
    }
    else {
      iVar1 = sk_num(st);
      if (iVar1 == 3) {
        p8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,pp,length);
        sk_pop_free(st,DAT_000b80c0);
        if (p8 == (PKCS8_PRIV_KEY_INFO *)0x0) {
          ERR_put_error(0xd,0xcf,0xa7,DAT_000b80c4,0x9b);
          return (EVP_PKEY *)0x0;
        }
        pEVar2 = EVP_PKCS82PKEY(p8);
        PKCS8_PRIV_KEY_INFO_free(p8);
        if (a == (EVP_PKEY **)0x0) {
          return pEVar2;
        }
        *a = pEVar2;
        return pEVar2;
      }
      iVar1 = 6;
    }
  }
  sk_pop_free(st,DAT_000b80c0);
  pEVar2 = d2i_PrivateKey(iVar1,a,pp,length);
  return pEVar2;
}

