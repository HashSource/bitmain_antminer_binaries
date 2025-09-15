
BIGNUM * BN_copy(BIGNUM *a,BIGNUM *b)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong *puVar11;
  
  if (a == b) {
    return a;
  }
  uVar6 = b->top;
  if (a->dmax < (int)uVar6) {
    puVar11 = (ulong *)bn_expand_internal(a,uVar6);
    if (puVar11 == (ulong *)0x0) {
      return (BIGNUM *)0x0;
    }
    if (a->d != (ulong *)0x0) {
      CRYPTO_free(a->d);
    }
    a->dmax = uVar6;
    a->d = puVar11;
    uVar6 = b->top;
  }
  else {
    puVar11 = a->d;
  }
  iVar5 = (int)uVar6 >> 2;
  puVar1 = b->d;
  puVar2 = puVar1;
  puVar3 = puVar11;
  iVar7 = iVar5;
  if (0 < iVar5) {
    do {
      uVar10 = puVar2[1];
      iVar7 = iVar7 + -1;
      uVar9 = puVar2[2];
      uVar8 = puVar2[3];
      *puVar3 = *puVar2;
      puVar3[1] = uVar10;
      puVar3[2] = uVar9;
      puVar3[3] = uVar8;
      puVar2 = puVar2 + 4;
      puVar3 = puVar3 + 4;
    } while (iVar7 != 0);
    uVar6 = b->top;
    puVar11 = puVar11 + iVar5 * 4;
    puVar1 = puVar1 + iVar5 * 4;
  }
  uVar4 = uVar6 & 3;
  if (uVar4 == 2) {
LAB_0009d194:
    puVar11[1] = puVar1[1];
  }
  else {
    if (uVar4 == 3) {
      puVar11[2] = puVar1[2];
      goto LAB_0009d194;
    }
    if (uVar4 != 1) goto LAB_0009d17c;
  }
  *puVar11 = *puVar1;
  uVar6 = b->top;
LAB_0009d17c:
  iVar5 = b->neg;
  a->top = uVar6;
  a->neg = iVar5;
  return a;
}

