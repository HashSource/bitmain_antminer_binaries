
X509_OBJECT * X509_OBJECT_retrieve_by_subject(stack_st_X509_OBJECT *h,int type,X509_NAME *name)

{
  int iVar1;
  X509_OBJECT *pXVar2;
  
  iVar1 = X509_OBJECT_idx_by_subject(h,type,name);
  if (iVar1 != -1) {
    pXVar2 = (X509_OBJECT *)OPENSSL_sk_value(h,iVar1);
    return pXVar2;
  }
  return (X509_OBJECT *)0x0;
}

