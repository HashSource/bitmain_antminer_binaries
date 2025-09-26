
void ASN1_TYPE_set(ASN1_TYPE *a,int type,void *value)

{
  ASN1_BOOLEAN AVar1;
  ASN1_TYPE *local_14 [2];
  
  if ((a->value).ptr != (char *)0x0) {
    local_14[0] = a;
    ASN1_primitive_free((ASN1_VALUE **)local_14,(ASN1_ITEM *)0x0);
    a = local_14[0];
  }
  a->type = type;
  if (type == 1) {
    if (value == (void *)0x0) {
      AVar1 = 0;
    }
    else {
      AVar1 = 0xff;
    }
    (a->value).boolean = AVar1;
  }
  else {
    (a->value).ptr = (char *)value;
  }
  return;
}

