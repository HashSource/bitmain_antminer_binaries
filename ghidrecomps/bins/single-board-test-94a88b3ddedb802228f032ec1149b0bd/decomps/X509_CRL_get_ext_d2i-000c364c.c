
void * X509_CRL_get_ext_d2i(X509_CRL *x,int nid,int *crit,int *idx)

{
  void *pvVar1;
  
  pvVar1 = X509V3_get_d2i(x->crl->extensions,nid,crit,idx);
  return pvVar1;
}

