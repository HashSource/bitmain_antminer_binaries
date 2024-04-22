
int CMS_signed_add1_attr_by_NID(CMS_SignerInfo *si,int nid,int type,void *bytes,int len)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr_by_NID
                     ((stack_st_X509_ATTRIBUTE **)(si + 0xc),nid,type,(uchar *)bytes,len);
  if (psVar1 != (stack_st_X509_ATTRIBUTE *)0x0) {
    psVar1 = (stack_st_X509_ATTRIBUTE *)0x1;
  }
  return (int)psVar1;
}

