
X509_ATTRIBUTE * CMS_unsigned_delete_attr(CMS_SignerInfo *si,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
  pXVar1 = X509at_delete_attr(*(stack_st_X509_ATTRIBUTE **)(si + 0x18),loc);
  return pXVar1;
}

