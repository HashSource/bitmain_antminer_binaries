
int X509_ATTRIBUTE_set1_object(X509_ATTRIBUTE *attr,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *pAVar1;
  
  if (attr != (X509_ATTRIBUTE *)0x0 && obj != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(attr->object);
    pAVar1 = OBJ_dup(obj);
    attr->object = pAVar1;
  }
  return (uint)(attr != (X509_ATTRIBUTE *)0x0 && obj != (ASN1_OBJECT *)0x0);
}

