
undefined4 eckey_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  EC_GROUP *group;
  int iVar1;
  ASN1_OBJECT *a;
  char *pcVar2;
  ASN1_OBJECT *aobj;
  EC_KEY *key;
  int ptype;
  uchar *penc;
  uchar *local_1c;
  
  key = *(EC_KEY **)(param_2 + 0x18);
  if ((key == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(key), group == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0xdf,0x7c,"crypto/ec/ec_ameth.c",0x1f);
    goto LAB_0011aa18;
  }
  iVar1 = EC_GROUP_get_asn1_flag(group);
  if ((iVar1 == 0) || (iVar1 = EC_GROUP_get_curve_name(group), iVar1 == 0)) {
    a = (ASN1_OBJECT *)ASN1_STRING_new();
    if (a == (ASN1_OBJECT *)0x0) {
LAB_0011aa18:
      ERR_put_error(0x10,0xd8,0x10,"crypto/ec/ec_ameth.c",0x54);
      return 0;
    }
    pcVar2 = (char *)i2d_ECParameters(key,(uchar **)&a->nid);
    a->sn = pcVar2;
    if ((int)pcVar2 < 1) {
      ASN1_STRING_free((ASN1_STRING *)a);
      ERR_put_error(0x10,0xdf,0x10,"crypto/ec/ec_ameth.c",0x42);
      goto LAB_0011aa18;
    }
    iVar1 = i2o_ECPublicKey(key,(uchar **)0x0);
    if (iVar1 < 1) {
      penc = (uchar *)0x0;
    }
    else {
      penc = (uchar *)CRYPTO_malloc(iVar1,"crypto/ec/ec_ameth.c",0x5a);
      if ((penc != (uchar *)0x0) &&
         (local_1c = penc, iVar1 = i2o_ECPublicKey(key,&local_1c), 0 < iVar1)) {
        ptype = 0x10;
        goto LAB_0011aab8;
      }
    }
LAB_0011a9ec:
    ASN1_STRING_free((ASN1_STRING *)a);
  }
  else {
    a = OBJ_nid2obj(iVar1);
    if ((a == (ASN1_OBJECT *)0x0) || (iVar1 = OBJ_length(), iVar1 == 0)) {
      ASN1_OBJECT_free(a);
      ERR_put_error(0x10,0xdf,0xa7,"crypto/ec/ec_ameth.c",0x2a);
      goto LAB_0011aa18;
    }
    iVar1 = i2o_ECPublicKey(key,(uchar **)0x0);
    if (iVar1 < 1) {
      penc = (uchar *)0x0;
    }
    else {
      penc = (uchar *)CRYPTO_malloc(iVar1,"crypto/ec/ec_ameth.c",0x5a);
      if ((penc != (uchar *)0x0) &&
         (local_1c = penc, iVar1 = i2o_ECPublicKey(key,&local_1c), 0 < iVar1)) {
        ptype = 6;
LAB_0011aab8:
        aobj = OBJ_nid2obj(0x198);
        iVar1 = X509_PUBKEY_set0_param(param_1,aobj,ptype,a,penc,iVar1);
        if (iVar1 != 0) {
          return 1;
        }
        if (ptype != 6) goto LAB_0011a9ec;
      }
    }
    ASN1_OBJECT_free(a);
  }
  CRYPTO_free(penc);
  return 0;
}

