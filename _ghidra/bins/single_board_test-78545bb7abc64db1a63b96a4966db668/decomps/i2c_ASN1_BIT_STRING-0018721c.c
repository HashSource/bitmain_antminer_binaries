
int i2c_ASN1_BIT_STRING(ASN1_BIT_STRING *a,uchar **pp)

{
  uchar *__src;
  size_t __n;
  uchar uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uchar *puVar5;
  uchar *__dest;
  byte bVar6;
  int iVar7;
  bool bVar8;
  
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  __n = a->length;
  if ((int)__n < 1) {
    if (pp == (uchar **)0x0) {
      return __n + 1;
    }
    puVar5 = *pp;
    *puVar5 = '\0';
    *pp = puVar5 + 1;
    return __n + 1;
  }
  if (a->flags << 0x1c < 0) {
    uVar2 = a->flags & 7;
    iVar3 = __n + 1;
    if (pp == (uchar **)0x0) {
      return iVar3;
    }
    puVar5 = *pp;
    *puVar5 = (uchar)uVar2;
    bVar6 = (byte)(0xff << uVar2);
    __src = a->data;
    __dest = puVar5 + 1;
  }
  else {
    pbVar4 = a->data + __n;
    do {
      pbVar4 = pbVar4 + -1;
      uVar2 = (uint)*pbVar4;
      if (uVar2 != 0) {
        iVar3 = __n + 1;
        goto LAB_00187276;
      }
      __n = __n - 1;
    } while (__n != 0);
    uVar2 = (uint)a->data[-1];
    iVar3 = 1;
LAB_00187276:
    if ((int)(uVar2 << 0x1f) < 0) {
      bVar6 = 0xff;
      uVar1 = '\0';
    }
    else {
      iVar7 = uVar2 << 0x1e;
      bVar8 = iVar7 < 0;
      if (bVar8) {
        iVar7 = -2;
      }
      bVar6 = (byte)iVar7;
      if (bVar8) {
        uVar1 = '\x01';
      }
      else if ((int)(uVar2 << 0x1d) < 0) {
        bVar6 = 0xfc;
        uVar1 = '\x02';
      }
      else if ((int)(uVar2 << 0x1c) < 0) {
        bVar6 = 0xf8;
        uVar1 = '\x03';
      }
      else {
        iVar7 = uVar2 << 0x1b;
        bVar8 = iVar7 < 0;
        if (bVar8) {
          iVar7 = -0x10;
        }
        bVar6 = (byte)iVar7;
        if (bVar8) {
          uVar1 = '\x04';
        }
        else if ((int)(uVar2 << 0x1a) < 0) {
          bVar6 = 0xe0;
          uVar1 = '\x05';
        }
        else if ((int)(uVar2 << 0x19) < 0) {
          bVar6 = 0xc0;
          uVar1 = '\x06';
        }
        else {
          uVar1 = (uchar)(uVar2 & 0x80);
          if ((uVar2 & 0x80) == 0) {
            bVar6 = 0xff;
          }
          else {
            bVar6 = 0x80;
            uVar1 = '\a';
          }
        }
      }
    }
    if (pp == (uchar **)0x0) {
      return iVar3;
    }
    puVar5 = *pp;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 1;
    if (__n == 0) goto LAB_0018725a;
    __src = a->data;
    __dest = puVar5;
  }
  puVar5 = __dest + __n;
  memcpy(__dest,__src,__n);
  puVar5[-1] = puVar5[-1] & bVar6;
LAB_0018725a:
  *pp = puVar5;
  return iVar3;
}

