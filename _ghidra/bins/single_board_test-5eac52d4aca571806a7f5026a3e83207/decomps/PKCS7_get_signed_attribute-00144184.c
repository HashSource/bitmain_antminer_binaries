
ASN1_TYPE * PKCS7_get_signed_attribute(PKCS7_SIGNER_INFO *si,int nid)

{
  int loc;
  X509_ATTRIBUTE *attr;
  ASN1_TYPE *pAVar1;
  stack_st_X509_ATTRIBUTE *x;
  
  x = si->auth_attr;
  loc = X509at_get_attr_by_NID(x,nid,-1);
  attr = X509at_get_attr(x,loc);
  pAVar1 = X509_ATTRIBUTE_get0_type(attr,0);
  return pAVar1;
}

