
ASN1_TYPE * X509_ATTRIBUTE_get0_type(X509_ATTRIBUTE *attr,int idx)

{
  ASN1_TYPE *pAVar1;
  
  if (attr != (X509_ATTRIBUTE *)0x0) {
    pAVar1 = (ASN1_TYPE *)OPENSSL_sk_value(attr->single);
    return pAVar1;
  }
  return (ASN1_TYPE *)0x0;
}

