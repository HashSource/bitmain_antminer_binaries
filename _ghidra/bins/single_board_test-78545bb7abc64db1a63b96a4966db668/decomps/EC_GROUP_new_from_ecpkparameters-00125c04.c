
EC_GROUP * EC_GROUP_new_from_ecpkparameters(int *param_1)

{
  EC_GROUP *pEVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    ERR_put_error(0x10,0x108,0x7c,"crypto/ec/ec_asn1.c",0x398);
    pEVar1 = (EC_GROUP *)0x0;
  }
  else {
    iVar2 = *param_1;
    if (iVar2 == 0) {
      iVar2 = OBJ_obj2nid((ASN1_OBJECT *)param_1[1]);
      pEVar1 = EC_GROUP_new_by_curve_name(iVar2);
      if (pEVar1 != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(pEVar1,1);
        return pEVar1;
      }
      ERR_put_error(0x10,0x108,0x77,"crypto/ec/ec_asn1.c",0x3a1);
      pEVar1 = (EC_GROUP *)0x0;
    }
    else if (iVar2 == 1) {
      pEVar1 = (EC_GROUP *)EC_GROUP_new_from_ecparameters(param_1[1]);
      if (pEVar1 == (EC_GROUP *)0x0) {
        ERR_put_error(0x10,0x108,0x10,"crypto/ec/ec_asn1.c",0x3a9);
      }
      else {
        EC_GROUP_set_asn1_flag(pEVar1,0);
      }
    }
    else if (iVar2 == 2) {
      pEVar1 = (EC_GROUP *)0x0;
    }
    else {
      ERR_put_error(0x10,0x108,0x73,"crypto/ec/ec_asn1.c",0x3b1);
      pEVar1 = (EC_GROUP *)0x0;
    }
  }
  return pEVar1;
}

