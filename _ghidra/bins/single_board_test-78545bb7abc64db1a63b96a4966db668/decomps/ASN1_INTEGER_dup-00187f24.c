
ASN1_STRING * ASN1_INTEGER_dup(ASN1_STRING *a)

{
  ASN1_STRING *dst;
  int iVar1;
  
  if (a == (ASN1_STRING *)0x0) {
    return (ASN1_STRING *)0x0;
  }
  dst = ASN1_STRING_new();
  if (dst != (ASN1_STRING *)0x0) {
    iVar1 = ASN1_STRING_copy(dst,a);
    if (iVar1 != 0) {
      return dst;
    }
    ASN1_STRING_free(dst);
    return (ASN1_STRING *)0x0;
  }
  return (ASN1_STRING *)0x0;
}

