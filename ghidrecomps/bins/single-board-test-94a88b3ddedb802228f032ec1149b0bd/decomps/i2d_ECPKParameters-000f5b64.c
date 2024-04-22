
int i2d_ECPKParameters(EC_GROUP *param_1,uchar **out)

{
  undefined4 *val;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  
  val = (undefined4 *)ASN1_item_new(DAT_000f5c10);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x9c,0x41,DAT_000f5c14,0x28d);
    goto LAB_000f5bba;
  }
  iVar1 = EC_GROUP_get_asn1_flag(param_1);
  if (iVar1 == 0) {
    *val = 1;
    pAVar2 = (ASN1_OBJECT *)ec_asn1_group2parameters_constprop_0(param_1);
    val[1] = pAVar2;
joined_r0x000f5bf8:
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      iVar1 = ASN1_item_i2d((ASN1_VALUE *)val,out,DAT_000f5c10);
      if (iVar1 != 0) {
        ASN1_item_free((ASN1_VALUE *)val,DAT_000f5c10);
        return iVar1;
      }
      ERR_put_error(0x10,0xbf,0x79,DAT_000f5c14,0x3ec);
      ASN1_item_free((ASN1_VALUE *)val,DAT_000f5c10);
      return 0;
    }
  }
  else {
    iVar1 = EC_GROUP_get_curve_name(param_1);
    if (iVar1 != 0) {
      *val = 0;
      pAVar2 = OBJ_nid2obj(iVar1);
      val[1] = pAVar2;
      goto joined_r0x000f5bf8;
    }
  }
  ASN1_item_free((ASN1_VALUE *)val,DAT_000f5c10);
LAB_000f5bba:
  ERR_put_error(0x10,0xbf,0x78,DAT_000f5c14,1000);
  return 0;
}

