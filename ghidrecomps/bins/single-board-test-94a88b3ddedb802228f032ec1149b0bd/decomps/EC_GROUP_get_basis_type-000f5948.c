
int EC_GROUP_get_basis_type(EC_GROUP *param_1)

{
  int *piVar1;
  EC_METHOD *meth;
  int iVar2;
  int iVar3;
  
  meth = EC_GROUP_method_of(param_1);
  iVar2 = EC_METHOD_get_field_type(meth);
  if (iVar2 != 0x197) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x5c);
  if (iVar2 != 0) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      piVar1 = (int *)(param_1 + 0x60);
      param_1 = param_1 + 4;
    } while (*piVar1 != 0);
    if (iVar2 != 4) {
      iVar3 = 0x2aa;
      if (iVar2 != 2) {
        iVar3 = 0;
      }
      return iVar3;
    }
    iVar2 = 0x2ab;
  }
  return iVar2;
}

