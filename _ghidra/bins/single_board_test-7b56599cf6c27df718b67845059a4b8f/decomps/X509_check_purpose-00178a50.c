
int X509_check_purpose(X509 *x,int id,int ca)

{
  int iVar1;
  X509_PURPOSE *pXVar2;
  
  x509v3_cache_extensions();
  if (-1 < x[1].references << 0x18) {
    if (id == -1) {
      return 1;
    }
    iVar1 = X509_PURPOSE_get_by_id(id);
    if (iVar1 != -1) {
      pXVar2 = X509_PURPOSE_get0(iVar1);
                    /* WARNING: Could not recover jumptable at 0x00178a80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*pXVar2->check_purpose)(pXVar2,x,ca);
      return iVar1;
    }
  }
  return -1;
}

