
int ASN1_TYPE_get(ASN1_TYPE *a)

{
  uint uVar1;
  
  uVar1 = a->type;
  if (((uVar1 & 0xfffffffb) != 1) && ((a->value).ptr == (char *)0x0)) {
    uVar1 = 0;
  }
  return uVar1;
}

