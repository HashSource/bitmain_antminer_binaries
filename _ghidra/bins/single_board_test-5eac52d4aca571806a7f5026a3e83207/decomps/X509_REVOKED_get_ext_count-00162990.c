
int X509_REVOKED_get_ext_count(X509_REVOKED *x)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_count((stack_st_X509_EXTENSION *)x->sequence);
  return iVar1;
}

