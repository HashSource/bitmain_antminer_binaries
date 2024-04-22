
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_OBJ(X509_ATTRIBUTE **attr,ASN1_OBJECT *obj,int atrtype,void *data,int len)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *pXVar3;
  
  if (((attr == (X509_ATTRIBUTE **)0x0) || (pXVar3 = *attr, pXVar3 == (X509_ATTRIBUTE *)0x0)) &&
     (pXVar3 = X509_ATTRIBUTE_new(), pXVar3 == (X509_ATTRIBUTE *)0x0)) {
    pXVar3 = (X509_ATTRIBUTE *)X509_ATTRIBUTE_create_by_OBJ_part_0();
    return pXVar3;
  }
  if (obj != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(pXVar3->object);
    pAVar1 = OBJ_dup(obj);
    pXVar3->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(pXVar3,atrtype,data,len);
    if (iVar2 != 0) {
      if (attr == (X509_ATTRIBUTE **)0x0) {
        return pXVar3;
      }
      if (*attr == (X509_ATTRIBUTE *)0x0) {
        *attr = pXVar3;
        return pXVar3;
      }
      return pXVar3;
    }
  }
  if ((attr == (X509_ATTRIBUTE **)0x0) || (*attr != pXVar3)) {
    X509_ATTRIBUTE_free(pXVar3);
  }
  return (X509_ATTRIBUTE *)0x0;
}

