
int X509_get_ext_by_critical(X509 *x,int crit,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_critical((stack_st_X509_EXTENSION *)x->skid,crit,lastpos);
  return iVar1;
}

