
int X509_CRL_get_ext_by_NID(X509_CRL *x,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_NID((stack_st_X509_EXTENSION *)x->idp_flags,nid,lastpos);
  return iVar1;
}

