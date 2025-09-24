
X509_EXTENSION * X509_CRL_get_ext(X509_CRL *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = X509v3_get_ext((stack_st_X509_EXTENSION *)x->idp_flags,loc);
  return pXVar1;
}

