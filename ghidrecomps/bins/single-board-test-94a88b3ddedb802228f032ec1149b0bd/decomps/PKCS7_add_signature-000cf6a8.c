
PKCS7_SIGNER_INFO * PKCS7_add_signature(PKCS7 *p7,X509 *x509,EVP_PKEY *pkey,EVP_MD *dgst)

{
  PKCS7_SIGNER_INFO *p7i;
  int iVar1;
  char *name;
  int local_1c;
  
  if (dgst == (EVP_MD *)0x0) {
    iVar1 = EVP_PKEY_get_default_digest_nid(pkey,&local_1c);
    if (iVar1 < 1) {
      return (PKCS7_SIGNER_INFO *)0x0;
    }
    name = OBJ_nid2sn(local_1c);
    dgst = EVP_get_digestbyname(name);
    if (dgst == (EVP_MD *)0x0) {
      ERR_put_error(0x21,0x83,0x97,DAT_000cf720,0x19c);
      return (PKCS7_SIGNER_INFO *)0x0;
    }
  }
  p7i = PKCS7_SIGNER_INFO_new();
  if (p7i == (PKCS7_SIGNER_INFO *)0x0) {
    return (PKCS7_SIGNER_INFO *)0x0;
  }
  iVar1 = PKCS7_SIGNER_INFO_set(p7i,x509,pkey,dgst);
  if ((iVar1 != 0) && (iVar1 = PKCS7_add_signer(p7,p7i), iVar1 != 0)) {
    return p7i;
  }
  PKCS7_SIGNER_INFO_free(p7i);
  return (PKCS7_SIGNER_INFO *)0x0;
}

