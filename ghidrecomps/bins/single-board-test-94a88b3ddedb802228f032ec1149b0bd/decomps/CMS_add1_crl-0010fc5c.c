
int CMS_add1_crl(CMS_ContentInfo *cms,X509_CRL *crl)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CMS_add0_RevocationInfoChoice(cms);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = crl;
    CRYPTO_add_lock(&crl->references,1,6,DAT_0010fc8c,0x21a);
    puVar1 = (undefined4 *)0x1;
  }
  return (int)puVar1;
}

