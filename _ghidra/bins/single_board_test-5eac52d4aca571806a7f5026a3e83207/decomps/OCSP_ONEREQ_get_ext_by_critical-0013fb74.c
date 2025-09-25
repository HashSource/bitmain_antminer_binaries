
int OCSP_ONEREQ_get_ext_by_critical(OCSP_ONEREQ *x,int crit,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_critical(x->singleRequestExtensions,crit,lastpos);
  return iVar1;
}

