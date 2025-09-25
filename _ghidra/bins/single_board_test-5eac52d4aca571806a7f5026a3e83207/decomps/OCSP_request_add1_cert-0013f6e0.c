
int OCSP_request_add1_cert(OCSP_REQUEST *req,X509 *cert)

{
  stack_st_X509_EXTENSION *psVar1;
  int iVar2;
  OCSP_REQINFO *pOVar3;
  
  pOVar3 = req[2].tbsRequest;
  if (pOVar3 == (OCSP_REQINFO *)0x0) {
    pOVar3 = (OCSP_REQINFO *)OCSP_SIGNATURE_new();
    req[2].tbsRequest = pOVar3;
    if (pOVar3 == (OCSP_REQINFO *)0x0) {
      return 0;
    }
  }
  if (cert == (X509 *)0x0) {
    return 1;
  }
  psVar1 = pOVar3->requestExtensions;
  if (psVar1 == (stack_st_X509_EXTENSION *)0x0) {
    psVar1 = (stack_st_X509_EXTENSION *)OPENSSL_sk_new_null();
    pOVar3->requestExtensions = psVar1;
    if (psVar1 == (stack_st_X509_EXTENSION *)0x0) {
      return 0;
    }
  }
  iVar2 = OPENSSL_sk_push(psVar1,cert);
  if (iVar2 == 0) {
    return 0;
  }
  X509_up_ref(cert);
  return 1;
}

