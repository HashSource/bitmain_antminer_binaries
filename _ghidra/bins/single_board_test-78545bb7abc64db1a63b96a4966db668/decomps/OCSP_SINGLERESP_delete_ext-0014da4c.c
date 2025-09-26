
X509_EXTENSION * OCSP_SINGLERESP_delete_ext(OCSP_SINGLERESP *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = X509v3_delete_ext(x->singleExtensions,loc);
  return pXVar1;
}

