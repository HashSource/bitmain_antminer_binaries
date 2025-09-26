
EC_KEY * d2i_ECParameters(EC_KEY **key,uchar **in,long len)

{
  ASN1_VALUE *val;
  int iVar1;
  EC_KEY *key_00;
  int line;
  
  if ((in == (uchar **)0x0) || (*in == (uchar *)0x0)) {
    ERR_put_error(0x10,0x90,0x43,"ec_asn1.c",0x4d2);
  }
  else if (((key == (EC_KEY **)0x0) || (key_00 = *key, key_00 == (EC_KEY *)0x0)) &&
          (key_00 = EC_KEY_new(), key_00 == (EC_KEY *)0x0)) {
    ERR_put_error(0x10,0x90,0x41,"ec_asn1.c",0x4d8);
  }
  else {
    val = ASN1_item_d2i((ASN1_VALUE **)0x0,in,len,(ASN1_ITEM *)ECPKPARAMETERS_it);
    if (val == (ASN1_VALUE *)0x0) {
      iVar1 = 0x75;
      line = 0x3cf;
    }
    else {
      iVar1 = ec_asn1_pkparameters2group();
      if (iVar1 != 0) {
        if (*(EC_GROUP **)(key_00 + 4) != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*(EC_GROUP **)(key_00 + 4));
        }
        *(int *)(key_00 + 4) = iVar1;
        ASN1_item_free(val,(ASN1_ITEM *)ECPKPARAMETERS_it);
        if (key != (EC_KEY **)0x0) {
          *key = key_00;
          return key_00;
        }
        return key_00;
      }
      line = 0x3d5;
      iVar1 = 0x7f;
    }
    ERR_put_error(0x10,0x91,iVar1,"ec_asn1.c",line);
    ASN1_item_free(val,(ASN1_ITEM *)ECPKPARAMETERS_it);
    ERR_put_error(0x10,0x90,0x10,"ec_asn1.c",0x4df);
    if ((key == (EC_KEY **)0x0) || (*key != key_00)) {
      EC_KEY_free(key_00);
    }
  }
  return (EC_KEY *)0x0;
}

