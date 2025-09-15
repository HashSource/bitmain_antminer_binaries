
X509_REQ * X509_REQ_dup(X509_REQ *req)

{
  X509_REQ *pXVar1;
  
  pXVar1 = (X509_REQ *)ASN1_item_dup((ASN1_ITEM *)X509_REQ_it,req);
  return pXVar1;
}

