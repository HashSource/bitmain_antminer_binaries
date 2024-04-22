
undefined4 EC_GROUP_get_trinomial_basis(EC_GROUP *param_1,int *param_2)

{
  EC_METHOD *meth;
  int iVar1;
  
  if (param_1 != (EC_GROUP *)0x0) {
    meth = EC_GROUP_method_of(param_1);
    iVar1 = EC_METHOD_get_field_type(meth);
    if ((((iVar1 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) && (*(int *)(param_1 + 0x60) != 0))
       && (*(int *)(param_1 + 100) == 0)) {
      if (param_2 != (int *)0x0) {
        *param_2 = *(int *)(param_1 + 0x60);
        return 1;
      }
      return 1;
    }
    ERR_put_error(0x10,0xc2,0x42,DAT_000f59d0,0x61);
  }
  return 0;
}

