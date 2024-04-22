
int X509_REVOKED_get_ext_by_NID(X509_REVOKED *x,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_NID(x->extensions,nid,lastpos);
  return iVar1;
}

