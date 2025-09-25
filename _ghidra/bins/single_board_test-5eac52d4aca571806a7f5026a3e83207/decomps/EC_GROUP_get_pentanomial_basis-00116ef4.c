
undefined4
EC_GROUP_get_pentanomial_basis
          (EC_GROUP *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  EC_METHOD *meth;
  int iVar1;
  
  if (param_1 != (EC_GROUP *)0x0) {
    meth = EC_GROUP_method_of(param_1);
    iVar1 = EC_METHOD_get_field_type(meth);
    if ((((iVar1 == 0x197) && (*(int *)(param_1 + 0x2c) != 0)) && (*(int *)(param_1 + 0x30) != 0))
       && (((*(int *)(param_1 + 0x34) != 0 && (*(int *)(param_1 + 0x38) != 0)) &&
           (*(int *)(param_1 + 0x3c) == 0)))) {
      if (param_2 != (int *)0x0) {
        *param_2 = *(int *)(param_1 + 0x38);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(param_1 + 0x34);
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(param_1 + 0x30);
        return 1;
      }
      return 1;
    }
    ERR_put_error(0x10,0xc1,0x42,"crypto/ec/ec_asn1.c",0x4a);
  }
  return 0;
}

