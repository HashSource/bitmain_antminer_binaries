
int CMS_add1_cert(CMS_ContentInfo *cms,X509 *cert)

{
  int iVar1;
  
  iVar1 = CMS_add0_cert(cms,cert);
  if (0 < iVar1) {
    X509_up_ref(cert);
  }
  return iVar1;
}

