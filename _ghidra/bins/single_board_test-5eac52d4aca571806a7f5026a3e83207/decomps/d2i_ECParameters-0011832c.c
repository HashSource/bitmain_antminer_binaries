
EC_KEY * d2i_ECParameters(EC_KEY **key,uchar **in,long len)

{
  EC_GROUP *pEVar1;
  EC_KEY *key_00;
  
  if ((in == (uchar **)0x0) || (*in == (uchar *)0x0)) {
    ERR_put_error(0x10,0x90,0x43,"crypto/ec/ec_asn1.c",0x494);
    return (EC_KEY *)0x0;
  }
  if ((key == (EC_KEY **)0x0) || (key_00 = *key, key_00 == (EC_KEY *)0x0)) {
    key_00 = EC_KEY_new();
    if (key_00 == (EC_KEY *)0x0) {
      ERR_put_error(0x10,0x90,0x41,"crypto/ec/ec_asn1.c",0x49a);
      return (EC_KEY *)0x0;
    }
    pEVar1 = d2i_ECPKParameters((EC_GROUP **)(key_00 + 0xc),in,len);
    if (pEVar1 != (EC_GROUP *)0x0) {
      if (key == (EC_KEY **)0x0) {
        return key_00;
      }
      goto LAB_00118350;
    }
    ERR_put_error(0x10,0x90,0x10,"crypto/ec/ec_asn1.c",0x4a1);
    if (key == (EC_KEY **)0x0) goto LAB_00118392;
  }
  else {
    pEVar1 = d2i_ECPKParameters((EC_GROUP **)(key_00 + 0xc),in,len);
    if (pEVar1 != (EC_GROUP *)0x0) {
LAB_00118350:
      *key = key_00;
      return key_00;
    }
    ERR_put_error(0x10,0x90,0x10,"crypto/ec/ec_asn1.c",0x4a1);
  }
  if (*key == key_00) {
    return (EC_KEY *)0x0;
  }
LAB_00118392:
  EC_KEY_free(key_00);
  return (EC_KEY *)0x0;
}

