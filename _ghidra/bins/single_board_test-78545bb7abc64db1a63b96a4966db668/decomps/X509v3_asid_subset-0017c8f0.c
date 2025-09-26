
int X509v3_asid_subset(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2 || param_1 == (int *)0x0) {
    return 1;
  }
  if (param_2 == (int *)0x0) {
    return 0;
  }
  iVar1 = X509v3_asid_inherits();
  if (((iVar1 == 0) && (iVar1 = X509v3_asid_inherits(param_2), iVar1 == 0)) &&
     ((iVar1 = *param_1, iVar1 == 0 ||
      ((iVar2 = *param_2, iVar2 != 0 &&
       (iVar1 = asid_contains(*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar1 + 4),iVar2,iVar1,
                              param_4), iVar1 != 0)))))) {
    iVar1 = param_1[1];
    if (iVar1 == 0) {
      return 1;
    }
    iVar2 = param_2[1];
    if (iVar2 != 0) {
      iVar1 = asid_contains(*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar1 + 4),iVar2,iVar1,
                            param_4);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
  }
  return 0;
}

