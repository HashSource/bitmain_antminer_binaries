
int X509_REQ_set_pubkey(X509_REQ *x,EVP_PKEY *pkey)

{
  int iVar1;
  
  if ((x != (X509_REQ *)0x0) && (x->req_info != (X509_REQ_INFO *)0x0)) {
    iVar1 = X509_PUBKEY_set(&x->req_info->pubkey,pkey);
    return iVar1;
  }
  return 0;
}

