
int BN_cmp(BIGNUM *a,BIGNUM *b)

{
  uint uVar1;
  uint uVar2;
  ulong *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulong *puVar8;
  bool bVar9;
  
  if (b == (BIGNUM *)0x0 || a == (BIGNUM *)0x0) {
    if (a == (BIGNUM *)0x0) {
      if (b != (BIGNUM *)0x0) {
        b = (BIGNUM *)0x1;
      }
      return (int)b;
    }
    return -1;
  }
  iVar4 = a->neg;
  if (iVar4 != b->neg) {
    if (iVar4 == 0) {
      iVar4 = 1;
    }
    else {
      iVar4 = -1;
    }
    return iVar4;
  }
  iVar6 = a->top;
  if (iVar4 == 0) {
    iVar4 = -1;
    iVar5 = 1;
  }
  else {
    iVar4 = 1;
    iVar5 = -1;
  }
  if (b->top < iVar6) {
    return iVar5;
  }
  if (b->top <= iVar6) {
    iVar7 = iVar6 + -1;
    if (iVar7 < 0) {
      return 0;
    }
    uVar1 = a->d[iVar7];
    uVar2 = b->d[iVar7];
    if (uVar2 < uVar1) {
      return iVar5;
    }
    if (uVar2 <= uVar1) {
      puVar8 = a->d + iVar6 + 0x3fffffff;
      puVar3 = b->d + iVar6 + 0x3fffffff;
      do {
        bVar9 = iVar7 == 0;
        iVar7 = iVar7 + -1;
        if (bVar9) {
          return 0;
        }
        puVar8 = puVar8 + -1;
        puVar3 = puVar3 + -1;
        if (*puVar3 < *puVar8) {
          return iVar5;
        }
      } while (*puVar3 <= *puVar8);
    }
  }
  return iVar4;
}

