
int CMS_add0_crl(CMS_ContentInfo *cms,X509_CRL *crl)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CMS_add0_RevocationInfoChoice(cms);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = crl;
    puVar1 = (undefined4 *)0x1;
  }
  return (int)puVar1;
}

