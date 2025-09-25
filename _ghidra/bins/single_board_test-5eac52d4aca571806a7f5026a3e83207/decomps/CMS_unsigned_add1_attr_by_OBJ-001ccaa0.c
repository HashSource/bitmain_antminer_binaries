
int CMS_unsigned_add1_attr_by_OBJ(CMS_SignerInfo *si,ASN1_OBJECT *obj,int type,void *bytes,int len)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr_by_OBJ
                     ((stack_st_X509_ATTRIBUTE **)(si + 0x18),obj,type,(uchar *)bytes,len);
  if (psVar1 != (stack_st_X509_ATTRIBUTE *)0x0) {
    psVar1 = (stack_st_X509_ATTRIBUTE *)0x1;
  }
  return (int)psVar1;
}

