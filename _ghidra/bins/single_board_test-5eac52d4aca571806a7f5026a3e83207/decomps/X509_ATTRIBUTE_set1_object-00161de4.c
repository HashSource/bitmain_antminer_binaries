
int X509_ATTRIBUTE_set1_object(X509_ATTRIBUTE *attr,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *pAVar1;
  
  if (obj == (ASN1_OBJECT *)0x0 || attr == (X509_ATTRIBUTE *)0x0) {
    return 0;
  }
  ASN1_OBJECT_free(attr->object);
  pAVar1 = OBJ_dup(obj);
  attr->object = pAVar1;
  if (pAVar1 != (ASN1_OBJECT *)0x0) {
    pAVar1 = (ASN1_OBJECT *)0x1;
  }
  return (int)pAVar1;
}

