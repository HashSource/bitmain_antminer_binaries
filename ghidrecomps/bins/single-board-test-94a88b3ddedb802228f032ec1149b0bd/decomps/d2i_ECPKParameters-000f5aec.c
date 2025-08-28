
EC_GROUP * d2i_ECPKParameters(EC_GROUP **param_1,uchar **in,long len)

{
  ASN1_VALUE *val;
  EC_GROUP *pEVar1;
  
  val = ASN1_item_d2i((ASN1_VALUE **)0x0,in,len,(ASN1_ITEM *)ECPKPARAMETERS_it);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x10,0x91,0x75,"ec_asn1.c",0x3cf);
    ASN1_item_free((ASN1_VALUE *)0x0,(ASN1_ITEM *)ECPKPARAMETERS_it);
    pEVar1 = (EC_GROUP *)0x0;
  }
  else {
    pEVar1 = (EC_GROUP *)ec_asn1_pkparameters2group();
    if (pEVar1 == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0x91,0x7f,"ec_asn1.c",0x3d5);
      ASN1_item_free(val,(ASN1_ITEM *)ECPKPARAMETERS_it);
    }
    else {
      if (param_1 != (EC_GROUP **)0x0) {
        if (*param_1 != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*param_1);
        }
        *param_1 = pEVar1;
      }
      ASN1_item_free(val,(ASN1_ITEM *)ECPKPARAMETERS_it);
    }
  }
  return pEVar1;
}

