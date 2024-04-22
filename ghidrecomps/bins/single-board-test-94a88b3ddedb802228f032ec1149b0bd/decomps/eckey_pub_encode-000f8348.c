
uchar * eckey_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  int iVar1;
  uchar *penc;
  ASN1_OBJECT *aobj;
  EC_KEY *key;
  ASN1_OBJECT *local_24;
  int local_20;
  uchar *local_1c [2];
  
  key = *(EC_KEY **)(param_2 + 0x14);
  local_24 = (ASN1_OBJECT *)0x0;
  iVar1 = eckey_param2type(&local_20,&local_24,key);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0xd8,0x10,DAT_000f83e0,0x72);
    penc = (uchar *)0x0;
  }
  else {
    iVar1 = i2o_ECPublicKey(key,(uchar **)0x0);
    if ((iVar1 < 1) ||
       (penc = (uchar *)CRYPTO_malloc(iVar1,DAT_000f83e0,0x78), penc == (uchar *)0x0)) {
      penc = (uchar *)0x0;
    }
    else {
      local_1c[0] = penc;
      iVar1 = i2o_ECPublicKey(key,local_1c);
      if (0 < iVar1) {
        aobj = OBJ_nid2obj(0x198);
        iVar1 = X509_PUBKEY_set0_param(param_1,aobj,local_20,local_24,penc,iVar1);
        if (iVar1 != 0) {
          return (uchar *)0x1;
        }
      }
    }
    if (local_20 == 6) {
      ASN1_OBJECT_free(local_24);
    }
    else {
      ASN1_STRING_free((ASN1_STRING *)local_24);
    }
    if (penc != (uchar *)0x0) {
      CRYPTO_free(penc);
      penc = (uchar *)0x0;
    }
  }
  return penc;
}

