
ASN1_STRING * eckey_param2type(undefined4 *param_1,undefined4 *param_2,EC_KEY *param_3)

{
  EC_GROUP *group;
  int iVar1;
  ASN1_STRING *a;
  ASN1_OBJECT *pAVar2;
  
  if ((param_3 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_3), group == (EC_GROUP *)0x0))
  {
    ERR_put_error(0x10,0xdf,0x7c,"ec_ameth.c",0x4e);
    a = (ASN1_STRING *)0x0;
  }
  else {
    iVar1 = EC_GROUP_get_asn1_flag(group);
    if ((iVar1 == 0) || (iVar1 = EC_GROUP_get_curve_name(group), iVar1 == 0)) {
      a = ASN1_STRING_new();
      if (a != (ASN1_STRING *)0x0) {
        iVar1 = i2d_ECParameters(param_3,&a->data);
        a->length = iVar1;
        if (iVar1 < 1) {
          ASN1_STRING_free(a);
          ERR_put_error(0x10,0xdf,0x10,"ec_ameth.c",0x60);
          a = (ASN1_STRING *)0x0;
        }
        else {
          *param_2 = a;
          a = (ASN1_STRING *)0x1;
          *param_1 = 0x10;
        }
      }
    }
    else {
      pAVar2 = OBJ_nid2obj(iVar1);
      *param_2 = pAVar2;
      a = (ASN1_STRING *)0x1;
      *param_1 = 6;
    }
  }
  return a;
}

