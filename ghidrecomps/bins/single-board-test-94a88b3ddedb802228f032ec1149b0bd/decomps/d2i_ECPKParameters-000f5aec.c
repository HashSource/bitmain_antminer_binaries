
EC_GROUP * d2i_ECPKParameters(EC_GROUP **param_1,uchar **in,long len)

{
  ASN1_VALUE *val;
  EC_GROUP *pEVar1;
  
  val = ASN1_item_d2i((ASN1_VALUE **)0x0,in,len,DAT_000f5b5c);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x10,0x91,0x75,DAT_000f5b60,0x3cf);
    ASN1_item_free((ASN1_VALUE *)0x0,DAT_000f5b5c);
    pEVar1 = (EC_GROUP *)0x0;
  }
  else {
    pEVar1 = (EC_GROUP *)ec_asn1_pkparameters2group();
    if (pEVar1 == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0x91,0x7f,DAT_000f5b60,0x3d5);
      ASN1_item_free(val,DAT_000f5b5c);
    }
    else {
      if (param_1 != (EC_GROUP **)0x0) {
        if (*param_1 != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*param_1);
        }
        *param_1 = pEVar1;
      }
      ASN1_item_free(val,DAT_000f5b5c);
    }
  }
  return pEVar1;
}

