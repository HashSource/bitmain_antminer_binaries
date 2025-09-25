
int i2o_ECPublicKey(EC_KEY *key,uchar **out)

{
  size_t len;
  size_t sVar1;
  uchar *buf;
  
  if (key == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0x97,0x43,"crypto/ec/ec_asn1.c",0x4c7);
    return 0;
  }
  len = EC_POINT_point2oct(*(EC_GROUP **)(key + 0xc),*(EC_POINT **)(key + 0x10),
                           *(point_conversion_form_t *)(key + 0x1c),(uchar *)0x0,0,(BN_CTX *)0x0);
  if (len != 0 && out != (uchar **)0x0) {
    if (*out == (uchar *)0x0) {
      buf = (uchar *)CRYPTO_malloc(len,"crypto/ec/ec_asn1.c",0x4d3);
      *out = buf;
      if (buf == (uchar *)0x0) {
        ERR_put_error(0x10,0x97,0x41,"crypto/ec/ec_asn1.c",0x4d4);
        len = 0;
      }
      else {
        sVar1 = EC_POINT_point2oct(*(EC_GROUP **)(key + 0xc),*(EC_POINT **)(key + 0x10),
                                   *(point_conversion_form_t *)(key + 0x1c),buf,len,(BN_CTX *)0x0);
        if (sVar1 == 0) {
          ERR_put_error(0x10,0x97,0x10,"crypto/ec/ec_asn1.c",0x4db);
          CRYPTO_free(*out);
          *out = (uchar *)0x0;
          len = 0;
        }
      }
    }
    else {
      sVar1 = EC_POINT_point2oct(*(EC_GROUP **)(key + 0xc),*(EC_POINT **)(key + 0x10),
                                 *(point_conversion_form_t *)(key + 0x1c),*out,len,(BN_CTX *)0x0);
      if (sVar1 == 0) {
        ERR_put_error(0x10,0x97,0x10,"crypto/ec/ec_asn1.c",0x4db);
        return 0;
      }
      *out = *out + len;
    }
  }
  return len;
}

