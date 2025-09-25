
ASN1_OBJECT * X509_ATTRIBUTE_get0_object(X509_ATTRIBUTE *attr)

{
  if (attr != (X509_ATTRIBUTE *)0x0) {
    attr = (X509_ATTRIBUTE *)attr->object;
  }
  return (ASN1_OBJECT *)attr;
}

