
undefined4 X509v3_addr_add_inherit(void)

{
  int iVar1;
  ASN1_NULL *pAVar2;
  int *piVar3;
  
  iVar1 = make_IPAddressFamily();
  if ((iVar1 != 0) && (piVar3 = *(int **)(iVar1 + 4), piVar3 != (int *)0x0)) {
    if (*piVar3 == 1) {
      if (piVar3[1] != 0) {
        return 0;
      }
    }
    else if (*piVar3 == 0) {
      if (piVar3[1] != 0) {
        return 1;
      }
    }
    else if (piVar3[1] != 0) goto LAB_0017a5be;
    pAVar2 = ASN1_NULL_new();
    piVar3[1] = (int)pAVar2;
    if (pAVar2 != (ASN1_NULL *)0x0) {
      piVar3 = *(int **)(iVar1 + 4);
LAB_0017a5be:
      *piVar3 = 0;
      return 1;
    }
  }
  return 0;
}

