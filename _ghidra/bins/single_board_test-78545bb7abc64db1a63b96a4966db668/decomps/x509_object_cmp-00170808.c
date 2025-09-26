
void x509_object_cmp(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  param_1 = (int *)*param_1;
  piVar1 = (int *)*param_2;
  iVar2 = *param_1;
  if (iVar2 != *piVar1) {
    return;
  }
  if (iVar2 != 1) {
    if (iVar2 == 2) {
      X509_CRL_cmp((X509_CRL *)param_1[1],(X509_CRL *)piVar1[1]);
      return;
    }
    return;
  }
  X509_subject_name_cmp((X509 *)param_1[1],(X509 *)piVar1[1]);
  return;
}

