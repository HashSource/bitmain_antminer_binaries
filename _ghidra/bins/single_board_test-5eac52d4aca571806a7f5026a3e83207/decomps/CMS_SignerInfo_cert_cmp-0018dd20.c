
int CMS_SignerInfo_cert_cmp(CMS_SignerInfo *si,X509 *cert)

{
  int iVar1;
  
  iVar1 = cms_SignerIdentifier_cert_cmp(*(undefined4 *)(si + 4));
  return iVar1;
}

