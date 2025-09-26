
X509_EXTENSION * X509_get_ext(X509 *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = X509v3_get_ext(x->cert_info->extensions,loc);
  return pXVar1;
}

