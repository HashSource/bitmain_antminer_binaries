
int CMS_add1_crl(CMS_ContentInfo *cms,X509_CRL *crl)

{
  CMS_RevocationInfoChoice *pCVar1;
  
  pCVar1 = CMS_add0_RevocationInfoChoice(cms);
  if (pCVar1 != (CMS_RevocationInfoChoice *)0x0) {
    *(undefined4 *)pCVar1 = 0;
    *(X509_CRL **)(pCVar1 + 4) = crl;
    CRYPTO_add_lock(&crl->references,1,6,"cms_lib.c",0x21a);
    pCVar1 = (CMS_RevocationInfoChoice *)0x1;
  }
  return (int)pCVar1;
}

