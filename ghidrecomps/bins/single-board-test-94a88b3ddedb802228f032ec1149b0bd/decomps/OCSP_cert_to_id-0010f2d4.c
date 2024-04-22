
OCSP_CERTID * OCSP_cert_to_id(EVP_MD *dgst,X509 *subject,X509 *issuer)

{
  X509_NAME *issuerName;
  ASN1_INTEGER *serialNumber;
  ASN1_BIT_STRING *issuerKey;
  OCSP_CERTID *pOVar1;
  
  if (dgst == (EVP_MD *)0x0) {
    dgst = EVP_sha1();
  }
  if (subject == (X509 *)0x0) {
    issuerName = X509_get_subject_name(issuer);
    serialNumber = (ASN1_INTEGER *)0x0;
  }
  else {
    issuerName = X509_get_issuer_name(subject);
    serialNumber = X509_get_serialNumber(subject);
  }
  issuerKey = X509_get0_pubkey_bitstr(issuer);
  pOVar1 = OCSP_cert_id_new(dgst,issuerName,issuerKey,serialNumber);
  return pOVar1;
}

