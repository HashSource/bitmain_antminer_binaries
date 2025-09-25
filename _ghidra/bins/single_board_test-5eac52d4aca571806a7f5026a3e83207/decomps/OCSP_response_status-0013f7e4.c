
int OCSP_response_status(OCSP_RESPONSE *resp)

{
  long lVar1;
  
  lVar1 = ASN1_ENUMERATED_get(resp->responseStatus);
  return lVar1;
}

