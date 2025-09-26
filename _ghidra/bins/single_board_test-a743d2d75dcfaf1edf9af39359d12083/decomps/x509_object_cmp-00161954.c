
void x509_object_cmp(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)*param_2;
  piVar3 = (int *)*param_1;
  iVar2 = *piVar3;
  if (iVar2 == *piVar1) {
    if (iVar2 == 1) {
      X509_subject_name_cmp((X509 *)piVar3[1],(X509 *)piVar1[1]);
      return;
    }
    if (iVar2 == 2) {
      X509_CRL_cmp((X509_CRL *)piVar3[1],(X509_CRL *)piVar1[1]);
      return;
    }
  }
  return;
}

