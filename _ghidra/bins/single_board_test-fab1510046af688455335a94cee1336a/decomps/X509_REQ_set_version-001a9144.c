
int X509_REQ_set_version(X509_REQ *x,long version)

{
  int iVar1;
  
  if (x != (X509_REQ *)0x0) {
    iVar1 = ASN1_INTEGER_set(x->req_info->version,version);
    return iVar1;
  }
  return 0;
}

