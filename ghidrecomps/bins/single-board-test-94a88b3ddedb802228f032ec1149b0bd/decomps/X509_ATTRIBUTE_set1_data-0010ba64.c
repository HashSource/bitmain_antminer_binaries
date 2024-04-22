
int X509_ATTRIBUTE_set1_data(X509_ATTRIBUTE *attr,int attrtype,void *data,int len)

{
  ASN1_STRING *str;
  int iVar1;
  _STACK *p_Var2;
  ASN1_TYPE *a;
  int iVar3;
  
  if (attr == (X509_ATTRIBUTE *)0x0) {
    return 0;
  }
  if ((attrtype & 0x1000U) == 0) {
    if (len == -1) {
      str = (ASN1_STRING *)0x0;
      iVar3 = 0;
    }
    else {
      str = ASN1_STRING_type_new(attrtype);
      if ((str == (ASN1_STRING *)0x0) ||
         (iVar1 = ASN1_STRING_set(str,data,len), iVar3 = attrtype, iVar1 == 0)) goto LAB_0010ba94;
    }
  }
  else {
    iVar3 = OBJ_obj2nid(attr->object);
    str = ASN1_STRING_set_by_NID((ASN1_STRING **)0x0,(uchar *)data,len,attrtype,iVar3);
    if (str == (ASN1_STRING *)0x0) {
      ERR_put_error(0xb,0x8a,0xd,DAT_0010bb34,0x134);
      return 0;
    }
    iVar3 = str->type;
  }
  p_Var2 = sk_new_null();
  (attr->value).set = (stack_st_ASN1_TYPE *)p_Var2;
  if (p_Var2 != (_STACK *)0x0) {
    attr->single = 0;
    if (attrtype == 0) {
      return 1;
    }
    a = ASN1_TYPE_new();
    if (a != (ASN1_TYPE *)0x0) {
      if ((len == -1) && ((attrtype & 0x1000U) == 0)) {
        iVar3 = ASN1_TYPE_set1(a,attrtype,data);
        if (iVar3 == 0) goto LAB_0010ba94;
      }
      else {
        ASN1_TYPE_set(a,iVar3,str);
      }
      iVar3 = sk_push(&((attr->value).set)->stack,a);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
LAB_0010ba94:
  ERR_put_error(0xb,0x8a,0x41,DAT_0010bb34,0x154);
  return 0;
}

