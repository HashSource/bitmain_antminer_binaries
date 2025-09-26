
X509_ATTRIBUTE * CMS_unsigned_get_attr(CMS_SignerInfo *si,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
  pXVar1 = X509at_get_attr(*(stack_st_X509_ATTRIBUTE **)(si + 0x18),loc);
  return pXVar1;
}

