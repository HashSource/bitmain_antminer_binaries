
int X509_ATTRIBUTE_set1_data(X509_ATTRIBUTE *attr,int attrtype,void *data,int len)

{
  ASN1_STRING *str;
  int iVar1;
  ASN1_TYPE *a;
  int iVar2;
  
  if (attr == (X509_ATTRIBUTE *)0x0) {
    return 0;
  }
  if ((attrtype & 0x1000U) == 0) {
    if (len == -1) {
      str = (ASN1_STRING *)0x0;
      iVar2 = 0;
    }
    else {
      str = ASN1_STRING_type_new(attrtype);
      if (str == (ASN1_STRING *)0x0) {
        a = (ASN1_TYPE *)0x0;
        goto LAB_0016fc96;
      }
      iVar1 = ASN1_STRING_set(str,data,len);
      iVar2 = attrtype;
      if (iVar1 == 0) {
        a = (ASN1_TYPE *)0x0;
        goto LAB_0016fc96;
      }
    }
    if (attrtype == 0) {
      ASN1_STRING_free(str);
      return 1;
    }
    a = ASN1_TYPE_new();
    if (a == (ASN1_TYPE *)0x0) goto LAB_0016fc96;
    if (len != -1) goto LAB_0016fce4;
    iVar2 = ASN1_TYPE_set1(a,attrtype,data);
    if (iVar2 == 0) goto LAB_0016fc96;
  }
  else {
    iVar2 = OBJ_obj2nid(attr->object);
    str = ASN1_STRING_set_by_NID((ASN1_STRING **)0x0,(uchar *)data,len,attrtype,iVar2);
    if (str == (ASN1_STRING *)0x0) {
      ERR_put_error(0xb,0x8a,0xd,"crypto/x509/x509_att.c",0x101);
      return 0;
    }
    iVar2 = str->type;
    a = ASN1_TYPE_new();
    if (a == (ASN1_TYPE *)0x0) goto LAB_0016fc96;
LAB_0016fce4:
    ASN1_TYPE_set(a,iVar2,str);
    str = (ASN1_STRING *)0x0;
  }
  iVar2 = OPENSSL_sk_push(attr->single,a);
  if (iVar2 != 0) {
    return 1;
  }
LAB_0016fc96:
  ERR_put_error(0xb,0x8a,0x41,"crypto/x509/x509_att.c",0x122);
  ASN1_TYPE_free(a);
  ASN1_STRING_free(str);
  return 0;
}

