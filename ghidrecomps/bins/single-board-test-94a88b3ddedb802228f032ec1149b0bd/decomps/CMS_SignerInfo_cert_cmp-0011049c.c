
int CMS_SignerInfo_cert_cmp(CMS_SignerInfo *si,X509 *cert)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(si + 4);
  if (*piVar2 == 0) {
    iVar1 = cms_ias_cert_cmp(piVar2[1]);
    return iVar1;
  }
  if (*piVar2 == 1) {
    iVar1 = cms_keyid_cert_cmp(piVar2[1]);
    return iVar1;
  }
  return -1;
}

