
int X509_CRL_get_ext_by_NID(X509_CRL *x,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_NID(x->crl->extensions,nid,lastpos);
  return iVar1;
}

