
OCSP_ONEREQ * OCSP_request_add0_id(OCSP_REQUEST *req,OCSP_CERTID *cid)

{
  OCSP_ONEREQ *a;
  int iVar1;
  
  a = OCSP_ONEREQ_new();
  if (a != (OCSP_ONEREQ *)0x0) {
    if (a->reqCert != (OCSP_CERTID *)0x0) {
      OCSP_CERTID_free(a->reqCert);
    }
    a->reqCert = cid;
    if (req == (OCSP_REQUEST *)0x0) {
      return a;
    }
    iVar1 = sk_push(&req->tbsRequest->requestList->stack,a);
    if (iVar1 != 0) {
      return a;
    }
  }
  OCSP_ONEREQ_free(a);
  return (OCSP_ONEREQ *)0x0;
}

