
int OCSP_request_set1_name(OCSP_REQUEST *req,X509_NAME *nm)

{
  OCSP_SIGNATURE *a;
  int iVar1;
  OCSP_SIGNATURE *a_00;
  
  a = (OCSP_SIGNATURE *)GENERAL_NAME_new();
  if (a == (OCSP_SIGNATURE *)0x0) {
    return 0;
  }
  iVar1 = X509_NAME_set((X509_NAME **)&a->signature,nm);
  if (iVar1 != 0) {
    a_00 = req->optionalSignature;
    a->signatureAlgorithm = (X509_ALGOR *)0x4;
    GENERAL_NAME_free((GENERAL_NAME *)a_00);
    req->optionalSignature = a;
    return 1;
  }
  GENERAL_NAME_free((GENERAL_NAME *)a);
  return 0;
}

