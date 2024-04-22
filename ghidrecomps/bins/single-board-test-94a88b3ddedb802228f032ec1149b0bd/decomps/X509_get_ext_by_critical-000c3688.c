
int X509_get_ext_by_critical(X509 *x,int crit,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_critical(x->cert_info->extensions,crit,lastpos);
  return iVar1;
}

