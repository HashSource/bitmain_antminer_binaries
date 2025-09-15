
int i2c_ASN1_INTEGER(ASN1_INTEGER *a,uchar **pp)

{
  uchar *puVar1;
  uchar *__dest;
  byte bVar2;
  uint uVar3;
  size_t __n;
  size_t sVar4;
  byte *pbVar5;
  int iVar6;
  uchar uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  __n = a->length;
  uVar3 = a->type & 0x100;
  if (__n == 0) {
    iVar11 = 1;
    iVar6 = 0;
    uVar7 = '\0';
  }
  else {
    pbVar5 = a->data;
    bVar2 = *pbVar5;
    if (bVar2 == 0 && __n == 1) {
      iVar6 = 0;
      uVar10 = 0;
      uVar3 = 0;
    }
    else {
      uVar10 = 0;
      if (uVar3 == 0 && 0x7f < bVar2) {
        iVar6 = 1;
        uVar3 = uVar10;
      }
      else {
        uVar10 = uVar3;
        if (uVar3 == 0) {
          iVar6 = 0;
          uVar3 = 0;
        }
        else {
          if (bVar2 < 0x81) {
            if ((bVar2 != 0x80) || ((int)__n < 2)) {
              iVar6 = 0;
              uVar3 = 0;
              goto LAB_000b54fe;
            }
            if (pbVar5[1] == 0) {
              pbVar8 = pbVar5 + 2;
              do {
                if (pbVar8 == pbVar5 + __n) {
                  iVar6 = 0;
                  uVar3 = 0;
                  goto LAB_000b54fe;
                }
                bVar2 = *pbVar8;
                pbVar8 = pbVar8 + 1;
              } while (bVar2 == 0);
            }
          }
          iVar6 = 1;
          uVar3 = 0xff;
        }
      }
    }
LAB_000b54fe:
    uVar7 = (uchar)uVar3;
    iVar11 = iVar6 + __n;
    uVar3 = uVar10;
  }
  if (pp == (uchar **)0x0) {
    return iVar11;
  }
  puVar1 = *pp;
  __dest = puVar1;
  if (iVar6 != 0) {
    __dest = puVar1 + 1;
    *puVar1 = uVar7;
    __n = a->length;
  }
  if (__n == 0) {
    *__dest = '\0';
  }
  else if (uVar3 == 0) {
    memcpy(__dest,a->data,__n);
  }
  else {
    sVar4 = __n - 1;
    pbVar8 = __dest + sVar4;
    uVar7 = a->data[sVar4];
    pbVar5 = a->data + sVar4;
    if (uVar7 == '\0') {
      bVar2 = 0;
      if (1 < (int)__n) {
        do {
          __n = sVar4;
          pbVar5 = pbVar5 + -1;
          pbVar9 = pbVar8 + -1;
          *pbVar8 = 0;
          pbVar8 = pbVar9;
          if (*pbVar5 != 0) {
            bVar2 = -*pbVar5;
            goto LAB_000b5582;
          }
          sVar4 = __n - 1;
        } while (__n != 1);
        *pbVar9 = 0;
        goto LAB_000b5518;
      }
    }
    else {
      bVar2 = -uVar7;
    }
LAB_000b5582:
    *pbVar8 = bVar2;
    if (1 < (int)__n) {
      pbVar9 = pbVar5 + (1 - __n);
      do {
        pbVar5 = pbVar5 + -1;
        pbVar8 = pbVar8 + -1;
        *pbVar8 = ~*pbVar5;
      } while (pbVar5 != pbVar9);
    }
  }
LAB_000b5518:
  *pp = *pp + iVar11;
  return iVar11;
}

