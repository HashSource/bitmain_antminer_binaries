
int X509_check_issued(X509 *issuer,X509 *subject)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  iVar1 = x509_likely_issued();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = x509_signing_allowed(issuer,subject,extraout_r2,in_r3);
  return iVar1;
}

