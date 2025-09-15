
int X509_get_ext_by_NID(X509 *x,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_NID(x->cert_info->extensions,nid,lastpos);
  return iVar1;
}

