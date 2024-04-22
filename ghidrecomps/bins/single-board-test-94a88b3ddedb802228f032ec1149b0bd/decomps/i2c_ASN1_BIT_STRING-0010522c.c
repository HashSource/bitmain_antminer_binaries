
int i2c_ASN1_BIT_STRING(ASN1_BIT_STRING *a,uchar **pp)

{
  byte *pbVar1;
  size_t __n;
  uchar *__dest;
  uchar *puVar2;
  uint uVar3;
  int iVar4;
  
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  __n = a->length;
  if ((int)__n < 1) {
    iVar4 = __n + 1;
    uVar3 = 0;
  }
  else if (a->flags << 0x1c < 0) {
    uVar3 = a->flags & 7;
    iVar4 = __n + 1;
  }
  else {
    pbVar1 = a->data + __n;
    do {
      pbVar1 = pbVar1 + -1;
      uVar3 = (uint)*pbVar1;
      if (uVar3 != 0) {
        iVar4 = __n + 1;
        goto LAB_00105270;
      }
      __n = __n - 1;
    } while (__n != 0);
    uVar3 = (uint)a->data[-1];
    iVar4 = 1;
LAB_00105270:
    if ((int)(uVar3 << 0x1f) < 0) {
      uVar3 = 0;
    }
    else if ((int)(uVar3 << 0x1e) < 0) {
      uVar3 = 1;
    }
    else if ((int)(uVar3 << 0x1d) < 0) {
      uVar3 = 2;
    }
    else if ((int)(uVar3 << 0x1c) < 0) {
      uVar3 = 3;
    }
    else if ((int)(uVar3 << 0x1b) < 0) {
      uVar3 = 4;
    }
    else if ((int)(uVar3 << 0x1a) < 0) {
      uVar3 = 5;
    }
    else if ((int)(uVar3 << 0x19) < 0) {
      uVar3 = 6;
    }
    else if ((uVar3 & 0x80) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 7;
    }
  }
  if (pp != (uchar **)0x0) {
    __dest = *pp + 1;
    **pp = (uchar)uVar3;
    puVar2 = __dest + __n;
    memcpy(__dest,a->data,__n);
    if (0 < (int)__n) {
      puVar2[-1] = puVar2[-1] & (byte)(0xff << uVar3);
    }
    *pp = puVar2;
  }
  return iVar4;
}

