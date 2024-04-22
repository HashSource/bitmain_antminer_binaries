
X509_ATTRIBUTE * X509_REQ_get_attr(X509_REQ *req,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
  pXVar1 = X509at_get_attr(req->req_info->attributes,loc);
  return pXVar1;
}

