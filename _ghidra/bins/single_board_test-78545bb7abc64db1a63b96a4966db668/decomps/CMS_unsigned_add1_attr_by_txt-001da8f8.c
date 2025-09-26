
int CMS_unsigned_add1_attr_by_txt(CMS_SignerInfo *si,char *attrname,int type,void *bytes,int len)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr_by_txt
                     ((stack_st_X509_ATTRIBUTE **)(si + 0x18),attrname,type,(uchar *)bytes,len);
  if (psVar1 != (stack_st_X509_ATTRIBUTE *)0x0) {
    psVar1 = (stack_st_X509_ATTRIBUTE *)0x1;
  }
  return (int)psVar1;
}

