
long ASN1_INTEGER_get(ASN1_INTEGER *a)

{
  int iVar1;
  uint local_10;
  int iStack_c;
  
  if (a != (ASN1_INTEGER *)0x0) {
    iVar1 = ASN1_INTEGER_get_int64(&local_10,a);
    if (iVar1 == 0) {
      local_10 = 0xffffffff;
    }
    else if (iStack_c + (uint)(0x7fffffff < local_10) != 0) {
      local_10 = 0xffffffff;
    }
    return local_10;
  }
  return 0;
}

