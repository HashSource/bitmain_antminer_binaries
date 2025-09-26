
OCSP_ONEREQ * OCSP_request_add0_id(OCSP_REQUEST *req,OCSP_CERTID *cid)

{
  OCSP_ONEREQ *a;
  int iVar1;
  
  a = OCSP_ONEREQ_new();
  if (a != (OCSP_ONEREQ *)0x0) {
    OCSP_CERTID_free(a->reqCert);
    a->reqCert = cid;
    if ((req != (OCSP_REQUEST *)0x0) && (iVar1 = OPENSSL_sk_push(req[1].tbsRequest,a), iVar1 == 0))
    {
      a->reqCert = (OCSP_CERTID *)0x0;
      OCSP_ONEREQ_free(a);
      return (OCSP_ONEREQ *)0x0;
    }
  }
  return a;
}

