
int * EC_GROUP_get_ecpkparameters(EC_GROUP *param_1,int *param_2)

{
  int iVar1;
  ASN1_OBJECT *a;
  
  if (param_2 == (int *)0x0) {
    param_2 = (int *)ECPKPARAMETERS_new();
    if (param_2 == (int *)0x0) {
      ERR_put_error(0x10,0x106,0x41,"crypto/ec/ec_asn1.c",0x21c);
      return (int *)0x0;
    }
  }
  else if (*param_2 == 0) {
    ASN1_OBJECT_free((ASN1_OBJECT *)param_2[1]);
  }
  else if ((*param_2 == 1) && (param_2[1] != 0)) {
    ECPARAMETERS_free();
  }
  iVar1 = EC_GROUP_get_asn1_flag(param_1);
  if (iVar1 == 1) {
    iVar1 = EC_GROUP_get_curve_name(param_1);
    if (iVar1 != 0) {
      a = OBJ_nid2obj(iVar1);
      if ((a != (ASN1_OBJECT *)0x0) && (iVar1 = OBJ_length(), iVar1 != 0)) {
        *param_2 = 0;
        param_2[1] = (int)a;
        return param_2;
      }
      ASN1_OBJECT_free(a);
      ERR_put_error(0x10,0x106,0xa7,"crypto/ec/ec_asn1.c",0x231);
    }
  }
  else {
    *param_2 = 1;
    iVar1 = EC_GROUP_get_ecparameters(param_1,0);
    param_2[1] = iVar1;
    if (iVar1 != 0) {
      return param_2;
    }
  }
  ECPKPARAMETERS_free(param_2);
  return (int *)0x0;
}

