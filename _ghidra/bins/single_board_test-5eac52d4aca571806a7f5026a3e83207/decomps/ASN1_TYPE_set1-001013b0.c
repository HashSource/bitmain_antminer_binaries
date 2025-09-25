
int ASN1_TYPE_set1(ASN1_TYPE *a,int type,void *value)

{
  if (type != 1 && value != (void *)0x0) {
    if (type == 6) {
      value = OBJ_dup((ASN1_OBJECT *)value);
    }
    else {
      value = ASN1_STRING_dup((ASN1_STRING *)value);
    }
    if ((ASN1_OBJECT *)value == (ASN1_OBJECT *)0x0) {
      return 0;
    }
  }
  ASN1_TYPE_set(a,type,value);
  return 1;
}

