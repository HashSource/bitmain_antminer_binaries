
X509_OBJECT * X509_OBJECT_retrieve_by_subject(stack_st_X509_OBJECT *h,int type,X509_NAME *name)

{
  int iVar1;
  X509_OBJECT *pXVar2;
  
  iVar1 = x509_object_idx_cnt();
  if (iVar1 != -1) {
    pXVar2 = (X509_OBJECT *)sk_value(&h->stack,iVar1);
    return pXVar2;
  }
  return (X509_OBJECT *)0x0;
}

