
X509_EXTENSION * X509_CRL_delete_ext(X509_CRL *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = X509v3_delete_ext(x->crl->extensions,loc);
  return pXVar1;
}

