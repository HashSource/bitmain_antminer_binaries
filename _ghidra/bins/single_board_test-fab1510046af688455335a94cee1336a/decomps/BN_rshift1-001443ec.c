
int BN_rshift1(BIGNUM *r,BIGNUM *a)

{
  ulong *puVar1;
  ulong *puVar2;
  BIGNUM *pBVar3;
  ulong *puVar4;
  uint uVar5;
  ulong *puVar6;
  uint uVar7;
  ulong *puVar8;
  int words;
  int iVar9;
  int iVar10;
  
  iVar9 = a->top;
  if (iVar9 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  puVar8 = a->d;
  iVar10 = iVar9 + -1;
  words = iVar9;
  if (puVar8[iVar10] == 1) {
    words = iVar9 + -1;
  }
  if (a != r) {
    if ((r->dmax < words) && (pBVar3 = bn_expand2(r,words), pBVar3 == (BIGNUM *)0x0)) {
      return 0;
    }
    r->neg = a->neg;
  }
  puVar2 = r->d;
  if ((puVar8[iVar10] & 1) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0x80000000;
  }
  uVar5 = puVar8[iVar10] >> 1;
  if (uVar5 != 0) {
    puVar2[iVar10] = uVar5;
  }
  if (0 < iVar10) {
    if (9 < iVar9) {
      puVar4 = puVar8 + iVar9;
      puVar6 = puVar2 + iVar9;
      do {
        iVar10 = iVar10 + -8;
        HintPreloadData(puVar4 + -0x12);
        HintPreloadData(puVar6 + -0x12);
        if ((puVar4[-2] & 1) == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = 0x80000000;
        }
        puVar6[-2] = uVar7 | puVar4[-2] >> 1;
        if ((puVar4[-3] & 1) == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0x80000000;
        }
        puVar6[-3] = uVar5 | puVar4[-3] >> 1;
        if ((puVar4[-4] & 1) == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = 0x80000000;
        }
        puVar6[-4] = uVar7 | puVar4[-4] >> 1;
        if ((puVar4[-5] & 1) == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0x80000000;
        }
        puVar6[-5] = uVar5 | puVar4[-5] >> 1;
        if ((puVar4[-6] & 1) == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = 0x80000000;
        }
        puVar6[-6] = uVar7 | puVar4[-6] >> 1;
        if ((puVar4[-7] & 1) == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0x80000000;
        }
        puVar6[-7] = uVar5 | puVar4[-7] >> 1;
        if ((puVar4[-8] & 1) == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = 0x80000000;
        }
        puVar6[-8] = uVar7 | puVar4[-8] >> 1;
        puVar1 = puVar4 + -9;
        puVar4 = puVar4 + -8;
        if ((*puVar1 & 1) == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0x80000000;
        }
        puVar6[-9] = uVar5 | *puVar1 >> 1;
        puVar6 = puVar6 + -8;
      } while (iVar10 != (iVar9 - (iVar9 - 10U & 0xfffffff8)) + -9);
    }
    puVar8 = puVar8 + iVar10;
    puVar2 = puVar2 + iVar10;
    do {
      puVar8 = puVar8 + -1;
      iVar10 = iVar10 + -1;
      uVar5 = uVar7 | *puVar8 >> 1;
      if ((*puVar8 & 1) == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = 0x80000000;
      }
      puVar2 = puVar2 + -1;
      *puVar2 = uVar5;
    } while (0 < iVar10);
  }
  r->top = words;
  return 1;
}

