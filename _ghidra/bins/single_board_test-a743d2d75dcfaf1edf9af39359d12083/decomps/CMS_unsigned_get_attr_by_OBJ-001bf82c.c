
int CMS_unsigned_get_attr_by_OBJ(CMS_SignerInfo *si,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_by_OBJ(*(stack_st_X509_ATTRIBUTE **)(si + 0x18),obj,lastpos);
  return iVar1;
}

