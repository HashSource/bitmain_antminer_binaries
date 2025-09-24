
int EC_GROUP_get_basis_type(EC_GROUP *param_1)

{
  EC_METHOD *meth;
  int iVar1;
  
  meth = EC_GROUP_method_of(param_1);
  iVar1 = EC_METHOD_get_field_type(meth);
  if (iVar1 != 0x197) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if ((iVar1 != 0) && (iVar1 = *(int *)(param_1 + 0x30), iVar1 != 0)) {
    if (*(int *)(param_1 + 0x34) == 0) {
      iVar1 = 0x2aa;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x38);
      if (iVar1 != 0) {
        iVar1 = 0x2ab;
        if (*(int *)(param_1 + 0x3c) != 0) {
          iVar1 = 0;
        }
        return iVar1;
      }
    }
  }
  return iVar1;
}

