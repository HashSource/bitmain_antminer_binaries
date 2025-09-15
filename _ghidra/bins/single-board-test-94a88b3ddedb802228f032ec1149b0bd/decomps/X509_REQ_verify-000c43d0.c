
int X509_REQ_verify(X509_REQ *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = ASN1_item_verify((ASN1_ITEM *)&X509_REQ_INFO_it,a->sig_alg,a->signature,a->req_info,r);
  return iVar1;
}

