
int X509_get_ext_count(X509 *x)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_count((stack_st_X509_EXTENSION *)x->skid);
  return iVar1;
}

