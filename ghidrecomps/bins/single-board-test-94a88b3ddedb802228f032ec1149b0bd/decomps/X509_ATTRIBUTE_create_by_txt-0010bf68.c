
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_txt(X509_ATTRIBUTE **attr,char *atrname,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *o;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *attr_00;
  X509_ATTRIBUTE *a;
  
  o = OBJ_txt2obj(atrname,0);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x8c,0x77,DAT_0010c02c,0x116);
    ERR_add_error_data(2,DAT_0010c030,atrname);
    return (X509_ATTRIBUTE *)0x0;
  }
  if ((attr == (X509_ATTRIBUTE **)0x0) || (attr_00 = *attr, attr_00 == (X509_ATTRIBUTE *)0x0)) {
    attr_00 = X509_ATTRIBUTE_new();
    if (attr_00 == (X509_ATTRIBUTE *)0x0) {
      attr_00 = (X509_ATTRIBUTE *)X509_ATTRIBUTE_create_by_OBJ_part_0();
      goto LAB_0010bfbc;
    }
    ASN1_OBJECT_free(attr_00->object);
    pAVar1 = OBJ_dup(o);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,type,bytes,len);
    if (iVar2 != 0) {
      if (attr == (X509_ATTRIBUTE **)0x0) goto LAB_0010bfbc;
      goto LAB_0010bff2;
    }
    a = attr_00;
    if (attr != (X509_ATTRIBUTE **)0x0) goto LAB_0010bfaa;
  }
  else {
    ASN1_OBJECT_free(attr_00->object);
    pAVar1 = OBJ_dup(o);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,type,bytes,len);
    if (iVar2 != 0) {
LAB_0010bff2:
      if (*attr == (X509_ATTRIBUTE *)0x0) {
        *attr = attr_00;
      }
      goto LAB_0010bfbc;
    }
LAB_0010bfaa:
    a = attr_00;
    if (attr_00 == *attr) {
      attr_00 = (X509_ATTRIBUTE *)0x0;
      goto LAB_0010bfbc;
    }
  }
  attr_00 = (X509_ATTRIBUTE *)0x0;
  X509_ATTRIBUTE_free(a);
LAB_0010bfbc:
  ASN1_OBJECT_free(o);
  return attr_00;
}

