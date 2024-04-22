
int CMS_add1_cert(CMS_ContentInfo *cms,X509 *cert)

{
  int iVar1;
  
  iVar1 = CMS_add0_cert(cms,cert);
  if (0 < iVar1) {
    CRYPTO_add_lock(&cert->references,1,3,DAT_0010fbc8,0x1de);
  }
  return iVar1;
}

