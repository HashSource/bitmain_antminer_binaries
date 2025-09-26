
X509_EXTENSION * OCSP_ONEREQ_get_ext(OCSP_ONEREQ *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = X509v3_get_ext(x->singleRequestExtensions,loc);
  return pXVar1;
}

