
int OCSP_BASICRESP_get_ext_by_NID(OCSP_BASICRESP *x,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_NID((stack_st_X509_EXTENSION *)x[1].signatureAlgorithm,nid,lastpos);
  return iVar1;
}

