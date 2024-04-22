
undefined4 dsa_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  int iVar1;
  DSA *r;
  ASN1_INTEGER *ai;
  BIGNUM *pBVar2;
  uchar *puStack_28;
  uchar *local_24;
  long local_20;
  int local_1c;
  long *local_18;
  X509_ALGOR *local_14;
  
  iVar1 = X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&puStack_28,&local_20,&local_14,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_1c,&local_18,local_14);
  if (local_1c == 0x10) {
    local_24 = (uchar *)local_18[2];
    r = d2i_DSAparams((DSA **)0x0,&local_24,*local_18);
    if (r == (DSA *)0x0) {
      ERR_put_error(10,0x75,0x68,DAT_000ff084,0x5c);
      return 0;
    }
  }
  else {
    if (local_1c != 5 && local_1c != -1) {
      ERR_put_error(10,0x75,0x69,DAT_000ff084,0x66);
      return 0;
    }
    r = DSA_new();
    if (r == (DSA *)0x0) {
      ERR_put_error(10,0x75,0x41,DAT_000ff084,0x62);
      return 0;
    }
  }
  ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&puStack_28,local_20);
  if (ai == (ASN1_INTEGER *)0x0) {
    ERR_put_error(10,0x75,0x68,DAT_000ff084,0x6b);
    if (r == (DSA *)0x0) {
      return 0;
    }
  }
  else {
    pBVar2 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
    *(BIGNUM **)&r->field_0x18 = pBVar2;
    if (pBVar2 != (BIGNUM *)0x0) {
      ASN1_INTEGER_free(ai);
      EVP_PKEY_assign(param_1,0x74,r);
      return 1;
    }
    ERR_put_error(10,0x75,0x6c,DAT_000ff084,0x70);
    ASN1_INTEGER_free(ai);
  }
  DSA_free(r);
  return 0;
}

