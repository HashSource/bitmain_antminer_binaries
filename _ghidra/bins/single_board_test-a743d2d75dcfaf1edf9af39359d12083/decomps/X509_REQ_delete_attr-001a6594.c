
X509_ATTRIBUTE * X509_REQ_delete_attr(X509_REQ *req,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
  pXVar1 = X509at_delete_attr(req->req_info->attributes,loc);
  return pXVar1;
}

