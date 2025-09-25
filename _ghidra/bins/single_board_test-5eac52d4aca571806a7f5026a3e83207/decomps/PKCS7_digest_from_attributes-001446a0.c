
ASN1_OCTET_STRING * PKCS7_digest_from_attributes(stack_st_X509_ATTRIBUTE *sk)

{
  int loc;
  X509_ATTRIBUTE *attr;
  ASN1_OCTET_STRING *pAVar1;
  
  loc = X509at_get_attr_by_NID(sk,0x33,-1);
  attr = X509at_get_attr(sk,loc);
  pAVar1 = (ASN1_OCTET_STRING *)X509_ATTRIBUTE_get0_type(attr,0);
  if (pAVar1 != (ASN1_OCTET_STRING *)0x0) {
    pAVar1 = (ASN1_OCTET_STRING *)((_union_263 *)&pAVar1->type)->ptr;
  }
  return pAVar1;
}

