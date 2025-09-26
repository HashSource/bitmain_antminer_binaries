
void ASIdOrRange_cmp(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)*param_1;
  piVar3 = (int *)*param_2;
  if (*piVar2 == 0) {
    if (*piVar3 != 0) {
      ASN1_INTEGER_cmp((ASN1_INTEGER *)piVar2[1],*(ASN1_INTEGER **)piVar3[1]);
      return;
    }
    ASN1_INTEGER_cmp((ASN1_INTEGER *)piVar2[1],(ASN1_INTEGER *)piVar3[1]);
    return;
  }
  if ((*piVar2 == 1) && (*piVar3 == 1)) {
    iVar1 = ASN1_INTEGER_cmp(*(ASN1_INTEGER **)piVar2[1],*(ASN1_INTEGER **)piVar3[1]);
    if (iVar1 != 0) {
      return;
    }
    ASN1_INTEGER_cmp(*(ASN1_INTEGER **)(piVar2[1] + 4),*(ASN1_INTEGER **)(piVar3[1] + 4));
    return;
  }
  ASN1_INTEGER_cmp(*(ASN1_INTEGER **)piVar2[1],(ASN1_INTEGER *)piVar3[1]);
  return;
}

