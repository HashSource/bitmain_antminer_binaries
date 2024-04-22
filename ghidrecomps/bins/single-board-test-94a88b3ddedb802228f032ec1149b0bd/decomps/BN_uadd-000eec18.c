
int BN_uadd(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  ulong uVar1;
  BIGNUM *pBVar2;
  int iVar3;
  ulong *puVar4;
  int iVar5;
  ulong *puVar6;
  int num;
  BIGNUM *pBVar7;
  ulong *puVar8;
  ulong *puVar9;
  
  iVar5 = a->top;
  num = b->top;
  iVar3 = iVar5;
  pBVar7 = a;
  if (iVar5 < num) {
    iVar3 = num;
    num = iVar5;
    pBVar7 = b;
    b = a;
  }
  if ((r->dmax <= iVar3) && (pBVar2 = bn_expand2(r,iVar3 + 1), pBVar2 == (BIGNUM *)0x0)) {
    return 0;
  }
  puVar9 = pBVar7->d;
  puVar8 = r->d;
  iVar5 = iVar3 - num;
  r->top = iVar3;
  puVar6 = puVar8 + num;
  uVar1 = bn_add_words(puVar8,puVar9,b->d,num);
  puVar4 = puVar9 + num;
  if (uVar1 != 0) {
    if (iVar5 == 0) {
LAB_000eed30:
      *puVar6 = 1;
      r->top = r->top + 1;
      goto LAB_000eed16;
    }
    uVar1 = puVar9[num] + 1;
    puVar8[num] = uVar1;
    while( true ) {
      puVar6 = puVar6 + 1;
      puVar4 = puVar4 + 1;
      iVar5 = iVar5 + -1;
      if (uVar1 != 0) break;
      if (iVar5 == 0) goto LAB_000eed30;
      uVar1 = *puVar4 + 1;
      *puVar6 = uVar1;
    }
  }
  if (puVar6 != puVar4 && iVar5 != 0) {
    iVar3 = iVar5 + -1;
    puVar8 = puVar6;
    puVar9 = puVar4;
    if (8 < iVar5) {
      do {
        puVar4 = puVar9 + 8;
        puVar6 = puVar8 + 8;
        iVar3 = iVar3 + -8;
        HintPreloadData(puVar9 + 0x1d);
        *puVar8 = *puVar9;
        puVar8[1] = puVar9[1];
        puVar8[2] = puVar9[2];
        puVar8[3] = puVar9[3];
        puVar8[4] = puVar9[4];
        puVar8[5] = puVar9[5];
        puVar8[6] = puVar9[6];
        puVar8[7] = puVar9[7];
        puVar8 = puVar6;
        puVar9 = puVar4;
      } while (7 < iVar3);
    }
    puVar4 = puVar4 + -1;
    do {
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + -1;
      *puVar6 = *puVar4;
      puVar6 = puVar6 + 1;
    } while (iVar3 != -1);
  }
LAB_000eed16:
  r->neg = 0;
  return 1;
}

