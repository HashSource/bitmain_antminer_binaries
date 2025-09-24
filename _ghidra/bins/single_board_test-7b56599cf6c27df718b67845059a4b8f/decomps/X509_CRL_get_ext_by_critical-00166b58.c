
int X509_CRL_get_ext_by_critical(X509_CRL *x,int crit,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_critical((stack_st_X509_EXTENSION *)x->idp_flags,crit,lastpos);
  return iVar1;
}

