
void * CMS_signed_get0_data_by_OBJ(CMS_SignerInfo *si,ASN1_OBJECT *oid,int lastpos,int type)

{
  void *pvVar1;
  
  pvVar1 = X509at_get0_data_by_OBJ(*(stack_st_X509_ATTRIBUTE **)(si + 0xc),oid,lastpos,type);
  return pvVar1;
}

