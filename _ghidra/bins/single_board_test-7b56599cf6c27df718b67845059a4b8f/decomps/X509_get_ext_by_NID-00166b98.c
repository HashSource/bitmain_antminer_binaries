
int X509_get_ext_by_NID(X509 *x,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_NID((stack_st_X509_EXTENSION *)x->skid,nid,lastpos);
  return iVar1;
}

