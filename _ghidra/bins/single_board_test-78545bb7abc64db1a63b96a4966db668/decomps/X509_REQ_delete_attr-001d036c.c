
X509_ATTRIBUTE * X509_REQ_delete_attr(X509_REQ *req,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
  pXVar1 = X509at_delete_attr((stack_st_X509_ATTRIBUTE *)req[1].signature,loc);
  if (pXVar1 != (X509_ATTRIBUTE *)0x0) {
    req->signature = (ASN1_BIT_STRING *)0x1;
  }
  return pXVar1;
}

