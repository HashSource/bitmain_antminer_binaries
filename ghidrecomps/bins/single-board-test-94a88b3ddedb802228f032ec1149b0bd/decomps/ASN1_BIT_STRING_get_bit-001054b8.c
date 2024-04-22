
int ASN1_BIT_STRING_get_bit(ASN1_BIT_STRING *a,int n)

{
  uint uVar1;
  
  uVar1 = n + 7U & n >> 0x20;
  if ((uint)n < 0xfffffff9) {
    uVar1 = n;
  }
  if (a != (ASN1_BIT_STRING *)0x0) {
    if ((int)uVar1 >> 3 < a->length) {
      a = (ASN1_BIT_STRING *)a->data;
      if (a != (ASN1_BIT_STRING *)0x0) {
        return (uint)(((uint)*(byte *)((int)&a->length + ((int)uVar1 >> 3)) & 1 << (~n & 7U)) != 0);
      }
    }
    else {
      a = (ASN1_BIT_STRING *)0x0;
    }
  }
  return (int)a;
}

