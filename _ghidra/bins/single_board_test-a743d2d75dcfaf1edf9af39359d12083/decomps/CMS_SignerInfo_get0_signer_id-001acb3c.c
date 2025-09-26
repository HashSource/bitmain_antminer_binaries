
int CMS_SignerInfo_get0_signer_id
              (CMS_SignerInfo *si,ASN1_OCTET_STRING **keyid,X509_NAME **issuer,ASN1_INTEGER **sno)

{
  int *piVar1;
  
  piVar1 = *(int **)(si + 4);
  if (*piVar1 == 0) {
    if (issuer != (X509_NAME **)0x0) {
      *issuer = *(X509_NAME **)piVar1[1];
    }
    if (sno != (ASN1_INTEGER **)0x0) {
      *sno = *(ASN1_INTEGER **)(piVar1[1] + 4);
      return 1;
    }
  }
  else {
    if (*piVar1 != 1) {
      return 0;
    }
    if (keyid != (ASN1_OCTET_STRING **)0x0) {
      *keyid = (ASN1_OCTET_STRING *)piVar1[1];
      return 1;
    }
  }
  return 1;
}

