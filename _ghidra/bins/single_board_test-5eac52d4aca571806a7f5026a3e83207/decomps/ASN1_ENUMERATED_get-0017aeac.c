
long ASN1_ENUMERATED_get(ASN1_ENUMERATED *a)

{
  int iVar1;
  uint local_10;
  int iStack_c;
  
  if (a != (ASN1_ENUMERATED *)0x0) {
    if (((a->type & 0xfffffeffU) == 10) && (a->length < 5)) {
      iVar1 = ASN1_ENUMERATED_get_int64(&local_10,a);
      if ((iVar1 == 0) || (iStack_c + (uint)(0x7fffffff < local_10) != 0)) {
        local_10 = 0xffffffff;
      }
      return local_10;
    }
    a = (ASN1_ENUMERATED *)0xffffffff;
  }
  return (long)a;
}

