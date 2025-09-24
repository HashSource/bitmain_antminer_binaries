
undefined4 get_issuer_sk(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = find_issuer(param_2,*(undefined4 *)(param_2 + 0x14));
  *param_1 = iVar1;
  if ((iVar1 != 0) && (iVar1 = X509_up_ref(), iVar1 != 0)) {
    return 1;
  }
  *param_1 = 0;
  return 0;
}

