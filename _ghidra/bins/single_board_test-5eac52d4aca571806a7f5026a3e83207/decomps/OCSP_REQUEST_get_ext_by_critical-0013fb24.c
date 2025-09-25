
int OCSP_REQUEST_get_ext_by_critical(OCSP_REQUEST *x,int crit,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_critical((stack_st_X509_EXTENSION *)x[1].optionalSignature,crit,lastpos)
  ;
  return iVar1;
}

