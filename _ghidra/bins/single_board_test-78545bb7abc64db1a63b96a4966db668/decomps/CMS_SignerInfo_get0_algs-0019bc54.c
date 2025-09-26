
void CMS_SignerInfo_get0_algs
               (CMS_SignerInfo *si,EVP_PKEY **pk,X509 **signer,X509_ALGOR **pdig,X509_ALGOR **psig)

{
  if (pk != (EVP_PKEY **)0x0) {
    *pk = *(EVP_PKEY **)(si + 0x20);
  }
  if (signer != (X509 **)0x0) {
    *signer = *(X509 **)(si + 0x1c);
  }
  if (pdig != (X509_ALGOR **)0x0) {
    *pdig = *(X509_ALGOR **)(si + 8);
  }
  if (psig != (X509_ALGOR **)0x0) {
    *psig = *(X509_ALGOR **)(si + 0x10);
  }
  return;
}

