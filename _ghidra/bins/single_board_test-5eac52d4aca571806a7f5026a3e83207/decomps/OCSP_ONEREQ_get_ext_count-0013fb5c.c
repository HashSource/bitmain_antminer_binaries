
int OCSP_ONEREQ_get_ext_count(OCSP_ONEREQ *x)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_count(x->singleRequestExtensions);
  return iVar1;
}

