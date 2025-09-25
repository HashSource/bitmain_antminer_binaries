
int ASN1_TYPE_cmp(ASN1_TYPE *a,ASN1_TYPE *b)

{
  int iVar1;
  int iVar2;
  
  if (b == (ASN1_TYPE *)0x0 || a == (ASN1_TYPE *)0x0) {
    return -1;
  }
  iVar1 = 0;
  iVar2 = a->type;
  if (iVar2 == b->type) {
    if (iVar2 != 5) {
      if (iVar2 == 6) {
        iVar1 = OBJ_cmp((a->value).object,(b->value).object);
        return iVar1;
      }
      if (iVar2 == 1) {
        return (int)(a->value).ptr - (b->value).boolean;
      }
      iVar1 = ASN1_STRING_cmp((a->value).asn1_string,(b->value).asn1_string);
      return iVar1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

