
int CMS_RecipientInfo_ktri_cert_cmp(CMS_RecipientInfo *ri,X509 *cert)

{
  int iVar1;
  
  if (*(int *)ri == 0) {
    iVar1 = cms_SignerIdentifier_cert_cmp(*(undefined4 *)(*(int *)(ri + 4) + 4));
    return iVar1;
  }
  ERR_put_error(0x2e,0x8b,0x7c,DAT_000d592c,0x14a);
  return -2;
}

