
ASN1_TYPE * PKCS12_get_attr_gen(stack_st_X509_ATTRIBUTE *attrs,int attr_nid)

{
  int loc;
  X509_ATTRIBUTE *attr;
  ASN1_TYPE *pAVar1;
  
  loc = X509at_get_attr_by_NID(attrs,attr_nid,-1);
  attr = X509at_get_attr(attrs,loc);
  pAVar1 = X509_ATTRIBUTE_get0_type(attr,0);
  return pAVar1;
}

