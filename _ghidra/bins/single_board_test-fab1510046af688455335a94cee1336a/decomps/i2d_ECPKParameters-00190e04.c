
int i2d_ECPKParameters(EC_GROUP *param_1,uchar **out)

{
  ASN1_VALUE *val;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  
  val = ASN1_item_new((ASN1_ITEM *)ECPKPARAMETERS_it);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x10,0x9c,0x41,"ec_asn1.c",0x28d);
    goto LAB_00190e5a;
  }
  iVar1 = EC_GROUP_get_asn1_flag(param_1);
  if (iVar1 == 0) {
    *(undefined4 *)val = 1;
    pAVar2 = (ASN1_OBJECT *)ec_asn1_group2parameters_constprop_0(param_1);
    *(ASN1_OBJECT **)(val + 4) = pAVar2;
joined_r0x00190e98:
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      iVar1 = ASN1_item_i2d(val,out,(ASN1_ITEM *)ECPKPARAMETERS_it);
      if (iVar1 != 0) {
        ASN1_item_free(val,(ASN1_ITEM *)ECPKPARAMETERS_it);
        return iVar1;
      }
      ERR_put_error(0x10,0xbf,0x79,"ec_asn1.c",0x3ec);
      ASN1_item_free(val,(ASN1_ITEM *)ECPKPARAMETERS_it);
      return 0;
    }
  }
  else {
    iVar1 = EC_GROUP_get_curve_name(param_1);
    if (iVar1 != 0) {
      *(undefined4 *)val = 0;
      pAVar2 = OBJ_nid2obj(iVar1);
      *(ASN1_OBJECT **)(val + 4) = pAVar2;
      goto joined_r0x00190e98;
    }
  }
  ASN1_item_free(val,(ASN1_ITEM *)ECPKPARAMETERS_it);
LAB_00190e5a:
  ERR_put_error(0x10,0xbf,0x78,"ec_asn1.c",1000);
  return 0;
}

