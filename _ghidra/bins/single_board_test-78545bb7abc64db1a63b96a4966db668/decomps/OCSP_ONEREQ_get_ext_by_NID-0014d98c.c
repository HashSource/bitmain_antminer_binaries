
int OCSP_ONEREQ_get_ext_by_NID(OCSP_ONEREQ *x,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_NID(x->singleRequestExtensions,nid,lastpos);
  return iVar1;
}

