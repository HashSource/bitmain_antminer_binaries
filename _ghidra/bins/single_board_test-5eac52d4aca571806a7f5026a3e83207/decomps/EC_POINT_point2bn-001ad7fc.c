
BIGNUM * EC_POINT_point2bn(EC_GROUP *param_1,EC_POINT *param_2,point_conversion_form_t form,
                          BIGNUM *param_4,BN_CTX *param_5)

{
  BIGNUM *len;
  uchar *local_14 [2];
  
  len = (BIGNUM *)EC_POINT_point2buf(param_1,param_2,form,local_14,param_5);
  if (len != (BIGNUM *)0x0) {
    len = BN_bin2bn(local_14[0],(int)len,param_4);
    CRYPTO_free(local_14[0]);
  }
  return len;
}

