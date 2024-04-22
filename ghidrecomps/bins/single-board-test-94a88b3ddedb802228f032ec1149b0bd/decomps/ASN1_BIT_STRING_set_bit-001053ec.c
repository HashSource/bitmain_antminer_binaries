
int ASN1_BIT_STRING_set_bit(ASN1_BIT_STRING *a,int n,int value)

{
  uint uVar1;
  size_t __n;
  int iVar2;
  uchar *puVar3;
  byte bVar4;
  byte bVar5;
  int num;
  
  bVar4 = (byte)(1 << (~n & 7U));
  uVar1 = n & ~(n >> 0x20);
  if (n < 0) {
    uVar1 = n + 7;
  }
  bVar5 = bVar4;
  if (value == 0) {
    bVar5 = 0;
  }
  iVar2 = (int)uVar1 >> 3;
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  a->flags = a->flags & 0xfffffff0;
  if ((a->length <= iVar2) || (puVar3 = a->data, puVar3 == (uchar *)0x0)) {
    if (value == 0) {
      return 1;
    }
    num = iVar2 + 1;
    if (a->data == (uchar *)0x0) {
      puVar3 = (uchar *)CRYPTO_malloc(num,DAT_001054b4,0xd0);
    }
    else {
      puVar3 = (uchar *)CRYPTO_realloc_clean(a->data,a->length,num,DAT_001054b4,0xd3);
    }
    if (puVar3 == (uchar *)0x0) {
      ERR_put_error(0xd,0xb7,0x41,DAT_001054b4,0xd5);
      return 0;
    }
    __n = num - a->length;
    if (0 < (int)__n) {
      memset(puVar3 + a->length,0,__n);
    }
    a->data = puVar3;
    a->length = num;
  }
  puVar3[iVar2] = puVar3[iVar2] & ~bVar4 | bVar5;
  iVar2 = a->length;
  if (0 < iVar2) {
    do {
      if (a->data[iVar2 + -1] != '\0') {
        return 1;
      }
      iVar2 = iVar2 + -1;
      a->length = iVar2;
    } while (iVar2 != 0);
  }
  return 1;
}

