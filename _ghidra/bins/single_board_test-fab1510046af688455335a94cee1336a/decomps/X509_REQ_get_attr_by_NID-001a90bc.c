
int X509_REQ_get_attr_by_NID(X509_REQ *req,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_by_NID(req->req_info->attributes,nid,lastpos);
  return iVar1;
}

