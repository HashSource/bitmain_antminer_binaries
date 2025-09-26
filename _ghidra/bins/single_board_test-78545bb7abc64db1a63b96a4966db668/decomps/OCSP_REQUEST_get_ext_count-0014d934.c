
int OCSP_REQUEST_get_ext_count(OCSP_REQUEST *x)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_count((stack_st_X509_EXTENSION *)x[1].optionalSignature);
  return iVar1;
}

