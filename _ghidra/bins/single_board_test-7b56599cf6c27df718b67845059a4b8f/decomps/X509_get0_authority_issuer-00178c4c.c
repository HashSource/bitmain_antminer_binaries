
int X509_get0_authority_issuer(X509 *param_1)

{
  int iVar1;
  
  iVar1 = X509_check_purpose(param_1,-1,-1);
  if (iVar1 == 1) {
    iVar1 = param_1[1].ex_pcpathlen;
    if (iVar1 != 0) {
      return *(int *)(iVar1 + 4);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

