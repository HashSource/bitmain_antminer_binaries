
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_NID(X509_ATTRIBUTE **attr,int nid,int atrtype,void *data,int len)

{
  ASN1_OBJECT *o;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *pXVar3;
  
  o = OBJ_nid2obj(nid);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x88,0x6d,DAT_0010be40,0xe4);
    return (X509_ATTRIBUTE *)0x0;
  }
  if ((attr == (X509_ATTRIBUTE **)0x0) || (pXVar3 = *attr, pXVar3 == (X509_ATTRIBUTE *)0x0)) {
    pXVar3 = X509_ATTRIBUTE_new();
    if (pXVar3 == (X509_ATTRIBUTE *)0x0) {
      pXVar3 = (X509_ATTRIBUTE *)X509_ATTRIBUTE_create_by_OBJ_part_0();
      if (pXVar3 != (X509_ATTRIBUTE *)0x0) {
        return pXVar3;
      }
      goto LAB_0010bdd8;
    }
    ASN1_OBJECT_free(pXVar3->object);
    pAVar1 = OBJ_dup(o);
    pXVar3->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(pXVar3,atrtype,data,len);
    if (iVar2 != 0) {
      if (attr == (X509_ATTRIBUTE **)0x0) {
        return pXVar3;
      }
      goto LAB_0010be10;
    }
    if (attr != (X509_ATTRIBUTE **)0x0) goto LAB_0010bdcc;
  }
  else {
    ASN1_OBJECT_free(pXVar3->object);
    pAVar1 = OBJ_dup(o);
    pXVar3->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(pXVar3,atrtype,data,len);
    if (iVar2 != 0) {
LAB_0010be10:
      if (*attr != (X509_ATTRIBUTE *)0x0) {
        return pXVar3;
      }
      *attr = pXVar3;
      return pXVar3;
    }
LAB_0010bdcc:
    if (pXVar3 == *attr) goto LAB_0010bdd8;
  }
  X509_ATTRIBUTE_free(pXVar3);
LAB_0010bdd8:
  ASN1_OBJECT_free(o);
  return (X509_ATTRIBUTE *)0x0;
}

