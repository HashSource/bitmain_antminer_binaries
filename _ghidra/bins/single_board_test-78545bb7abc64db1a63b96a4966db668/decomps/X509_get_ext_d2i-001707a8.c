
void * X509_get_ext_d2i(X509 *x,int nid,int *crit,int *idx)

{
  void *pvVar1;
  
  pvVar1 = X509V3_get_d2i((stack_st_X509_EXTENSION *)x->skid,nid,crit,idx);
  return pvVar1;
}

