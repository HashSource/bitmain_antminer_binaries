
EVP_PKEY * X509_REQ_get_pubkey(X509_REQ *req)

{
  EVP_PKEY *pEVar1;
  
  if ((req != (X509_REQ *)0x0) && (req->req_info != (X509_REQ_INFO *)0x0)) {
    pEVar1 = X509_PUBKEY_get(req->req_info->pubkey);
    return pEVar1;
  }
  return (EVP_PKEY *)0x0;
}

