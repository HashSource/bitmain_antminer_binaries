
int OCSP_request_set1_name(OCSP_REQUEST *req,X509_NAME *nm)

{
  GENERAL_NAME *a;
  int iVar1;
  OCSP_REQINFO *pOVar2;
  
  a = GENERAL_NAME_new();
  if (a == (GENERAL_NAME *)0x0) {
    return 0;
  }
  iVar1 = X509_NAME_set(&(a->d).directoryName,nm);
  if (iVar1 != 0) {
    pOVar2 = req->tbsRequest;
    a->type = 4;
    if (pOVar2->requestorName != (GENERAL_NAME *)0x0) {
      GENERAL_NAME_free(pOVar2->requestorName);
      pOVar2 = req->tbsRequest;
    }
    pOVar2->requestorName = a;
    return 1;
  }
  GENERAL_NAME_free(a);
  return 0;
}

