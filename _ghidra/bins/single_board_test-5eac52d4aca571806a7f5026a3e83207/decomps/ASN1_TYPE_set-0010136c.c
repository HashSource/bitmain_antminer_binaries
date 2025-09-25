
void ASN1_TYPE_set(ASN1_TYPE *a,int type,void *value)

{
  char *pcVar1;
  ASN1_TYPE *local_14 [2];
  
  if (((a->type & 0xfffffffbU) != 1) && ((a->value).ptr != (char *)0x0)) {
    local_14[0] = a;
    asn1_primitive_free(local_14,0);
    a = local_14[0];
  }
  a->type = type;
  if (type == 1) {
    if (value == (void *)0x0) {
      pcVar1 = (char *)0x0;
    }
    else {
      pcVar1 = (char *)0xff;
    }
    (a->value).ptr = pcVar1;
    return;
  }
  (a->value).ptr = (char *)value;
  return;
}

