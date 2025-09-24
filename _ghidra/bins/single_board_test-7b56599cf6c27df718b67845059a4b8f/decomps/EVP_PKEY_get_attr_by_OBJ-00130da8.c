
int EVP_PKEY_get_attr_by_OBJ(EVP_PKEY *key,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_by_OBJ((stack_st_X509_ATTRIBUTE *)key[1].type,obj,lastpos);
  return iVar1;
}

