
int CMS_add1_crl(CMS_ContentInfo *cms,X509_CRL *crl)

{
  int iVar1;
  
  iVar1 = CMS_add0_crl(cms,crl);
  if (0 < iVar1) {
    X509_CRL_up_ref(crl);
  }
  return iVar1;
}

