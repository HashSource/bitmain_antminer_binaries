
int OCSP_SINGLERESP_get_ext_count(OCSP_SINGLERESP *x)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_count(x->singleExtensions);
  return iVar1;
}

