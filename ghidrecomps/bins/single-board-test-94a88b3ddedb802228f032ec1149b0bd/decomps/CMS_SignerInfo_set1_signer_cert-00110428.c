
void CMS_SignerInfo_set1_signer_cert(CMS_SignerInfo *si,X509 *signer)

{
  EVP_PKEY *pEVar1;
  
  if (signer != (X509 *)0x0) {
    CRYPTO_add_lock(&signer->references,1,3,DAT_00110464,0x1e9);
    if (*(EVP_PKEY **)(si + 0x20) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(si + 0x20));
    }
    pEVar1 = X509_get_pubkey(signer);
    *(EVP_PKEY **)(si + 0x20) = pEVar1;
  }
  if (*(X509 **)(si + 0x1c) != (X509 *)0x0) {
    X509_free(*(X509 **)(si + 0x1c));
  }
  *(X509 **)(si + 0x1c) = signer;
  return;
}

