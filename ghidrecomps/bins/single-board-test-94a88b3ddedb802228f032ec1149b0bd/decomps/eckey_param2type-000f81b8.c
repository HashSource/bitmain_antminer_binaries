
ASN1_OBJECT * eckey_param2type(undefined4 *param_1,ASN1_OBJECT **param_2,EC_KEY *param_3)

{
  EC_GROUP *group;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  char *pcVar3;
  
  if ((param_3 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_3), group == (EC_GROUP *)0x0))
  {
    ERR_put_error(0x10,0xdf,0x7c,DAT_000f8240,0x4e);
    pAVar2 = (ASN1_OBJECT *)0x0;
  }
  else {
    iVar1 = EC_GROUP_get_asn1_flag(group);
    if ((iVar1 == 0) || (iVar1 = EC_GROUP_get_curve_name(group), iVar1 == 0)) {
      pAVar2 = (ASN1_OBJECT *)ASN1_STRING_new();
      if (pAVar2 != (ASN1_OBJECT *)0x0) {
        pcVar3 = (char *)i2d_ECParameters(param_3,(uchar **)&pAVar2->nid);
        pAVar2->sn = pcVar3;
        if ((int)pcVar3 < 1) {
          ASN1_STRING_free((ASN1_STRING *)pAVar2);
          ERR_put_error(0x10,0xdf,0x10,DAT_000f8240,0x60);
          pAVar2 = (ASN1_OBJECT *)0x0;
        }
        else {
          *param_2 = pAVar2;
          pAVar2 = (ASN1_OBJECT *)0x1;
          *param_1 = 0x10;
        }
      }
    }
    else {
      pAVar2 = OBJ_nid2obj(iVar1);
      *param_2 = pAVar2;
      pAVar2 = (ASN1_OBJECT *)0x1;
      *param_1 = 6;
    }
  }
  return pAVar2;
}

