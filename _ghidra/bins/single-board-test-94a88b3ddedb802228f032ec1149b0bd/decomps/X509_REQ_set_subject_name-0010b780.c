
int X509_REQ_set_subject_name(X509_REQ *req,X509_NAME *name)

{
  int iVar1;
  
  if ((req != (X509_REQ *)0x0) && (req->req_info != (X509_REQ_INFO *)0x0)) {
    iVar1 = X509_NAME_set(&req->req_info->subject,name);
    return iVar1;
  }
  return 0;
}

