
EC_KEY * eckey_type2param(int param_1,ASN1_OBJECT *param_2)

{
  EC_KEY *pEVar1;
  int iVar2;
  EC_GROUP *group;
  uchar *local_14;
  
  if (param_1 == 0x10) {
    local_14 = (uchar *)param_2->nid;
    pEVar1 = d2i_ECParameters((EC_KEY **)0x0,&local_14,(long)param_2->sn);
    if (pEVar1 != (EC_KEY *)0x0) {
      return pEVar1;
    }
    ERR_put_error(0x10,0xdc,0x8e,"crypto/ec/ec_ameth.c",0x78);
    pEVar1 = (EC_KEY *)0x0;
    group = (EC_GROUP *)0x0;
  }
  else if (param_1 == 6) {
    pEVar1 = EC_KEY_new();
    if (pEVar1 == (EC_KEY *)0x0) {
      ERR_put_error(0x10,0xdc,0x41,"crypto/ec/ec_ameth.c",0x82);
      group = (EC_GROUP *)0x0;
    }
    else {
      iVar2 = OBJ_obj2nid(param_2);
      group = EC_GROUP_new_by_curve_name(iVar2);
      if (group != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(group,1);
        iVar2 = EC_KEY_set_group(pEVar1,group);
        if (iVar2 != 0) {
          EC_GROUP_free(group);
          return pEVar1;
        }
      }
    }
  }
  else {
    group = (EC_GROUP *)0x0;
    pEVar1 = (EC_KEY *)0x0;
    ERR_put_error(0x10,0xdc,0x8e,"crypto/ec/ec_ameth.c",0x8d);
  }
  EC_KEY_free(pEVar1);
  EC_GROUP_free(group);
  return (EC_KEY *)0x0;
}

