
int X509v3_asid_is_canonical(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    return 1;
  }
  piVar2 = (int *)*param_1;
  if (((piVar2 == (int *)0x0) || (*piVar2 == 0)) ||
     ((*piVar2 == 1 &&
      ((iVar1 = OPENSSL_sk_num(piVar2[1]), iVar1 != 0 &&
       (iVar1 = ASIdentifierChoice_is_canonical_part_1(piVar2), iVar1 != 0)))))) {
    piVar2 = (int *)param_1[1];
    if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) {
      return 1;
    }
    if ((*piVar2 == 1) && (iVar1 = OPENSSL_sk_num(piVar2[1]), iVar1 != 0)) {
      iVar1 = ASIdentifierChoice_is_canonical_part_1(piVar2);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
  }
  return 0;
}

