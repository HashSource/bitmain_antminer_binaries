
int CMS_RecipientInfo_ktri_get0_algs
              (CMS_RecipientInfo *ri,EVP_PKEY **pk,X509 **recip,X509_ALGOR **palg)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)ri == 0) {
    iVar1 = *(int *)(ri + 4);
    if (pk != (EVP_PKEY **)0x0) {
      *pk = *(EVP_PKEY **)(iVar1 + 0x14);
    }
    if (recip != (X509 **)0x0) {
      *recip = *(X509 **)(iVar1 + 0x10);
    }
    if (palg == (X509_ALGOR **)0x0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 1;
      *palg = *(X509_ALGOR **)(iVar1 + 8);
    }
  }
  else {
    ERR_put_error(0x2e,0x8e,0x7c,DAT_000d58c4,0x127);
    iVar2 = 0;
  }
  return iVar2;
}

