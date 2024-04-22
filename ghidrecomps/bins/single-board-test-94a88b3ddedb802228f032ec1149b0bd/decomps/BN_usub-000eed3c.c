
int BN_usub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  bool bVar1;
  uint *puVar2;
  ulong *puVar3;
  ulong *puVar4;
  uint uVar5;
  ulong *puVar6;
  BIGNUM *pBVar7;
  ulong *puVar8;
  int words;
  ulong *puVar9;
  int iVar10;
  ulong *puVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  ulong uVar15;
  bool bVar16;
  int local_38;
  
  iVar10 = b->top;
  words = a->top;
  local_38 = words - iVar10;
  if (local_38 < 0) {
    ERR_put_error(3,0x73,100,DAT_000ef098,0xb7);
    return 0;
  }
  if ((r->dmax < words) && (pBVar7 = bn_expand2(r,words), pBVar7 == (BIGNUM *)0x0)) {
    return 0;
  }
  puVar4 = a->d;
  puVar11 = r->d;
  puVar14 = b->d;
  puVar9 = puVar11;
  if (iVar10 != 0) {
    iVar12 = iVar10;
    if (iVar10 < 9) {
      bVar16 = false;
      puVar6 = puVar4;
    }
    else {
      bVar16 = false;
      puVar8 = puVar11;
      puVar2 = puVar14;
      puVar3 = puVar4;
      do {
        puVar6 = puVar3 + 8;
        puVar14 = puVar2 + 8;
        puVar9 = puVar8 + 8;
        uVar13 = *puVar3;
        HintPreloadData(puVar3 + 0xc);
        uVar5 = *puVar2;
        HintPreloadData(puVar2 + 0xc);
        uVar15 = (uVar13 - 1) - uVar5;
        bVar1 = uVar5 < uVar13;
        if (!bVar16) {
          uVar15 = uVar13 - uVar5;
          bVar1 = uVar5 <= uVar13;
        }
        *puVar8 = uVar15;
        uVar13 = puVar3[1];
        uVar5 = puVar2[1];
        uVar15 = uVar13 - uVar5;
        bVar16 = uVar13 < uVar5;
        if (!bVar1) {
          uVar15 = (uVar13 - 1) - uVar5;
          bVar16 = uVar13 <= uVar5;
        }
        puVar8[1] = uVar15;
        uVar13 = puVar3[2];
        uVar5 = puVar2[2];
        uVar15 = uVar13 - uVar5;
        bVar1 = uVar13 < uVar5;
        if (bVar16) {
          uVar15 = (uVar13 - 1) - uVar5;
          bVar1 = uVar13 <= uVar5;
        }
        puVar8[2] = uVar15;
        uVar13 = puVar3[3];
        uVar5 = puVar2[3];
        uVar15 = uVar13 - uVar5;
        bVar16 = uVar13 < uVar5;
        if (bVar1) {
          uVar15 = (uVar13 - 1) - uVar5;
          bVar16 = uVar13 <= uVar5;
        }
        puVar8[3] = uVar15;
        uVar13 = puVar3[4];
        uVar5 = puVar2[4];
        uVar15 = uVar13 - uVar5;
        bVar1 = uVar13 < uVar5;
        if (bVar16) {
          uVar15 = (uVar13 - 1) - uVar5;
          bVar1 = uVar13 <= uVar5;
        }
        puVar8[4] = uVar15;
        uVar13 = puVar3[5];
        uVar5 = puVar2[5];
        uVar15 = uVar13 - uVar5;
        bVar16 = uVar13 < uVar5;
        if (bVar1) {
          uVar15 = (uVar13 - 1) - uVar5;
          bVar16 = uVar13 <= uVar5;
        }
        puVar8[5] = uVar15;
        uVar13 = puVar3[6];
        uVar5 = puVar2[6];
        uVar15 = (uVar13 - 1) - uVar5;
        bVar1 = uVar13 <= uVar5;
        if (!bVar16) {
          uVar15 = uVar13 - uVar5;
          bVar1 = uVar13 < uVar5;
        }
        puVar8[6] = uVar15;
        iVar12 = iVar12 + -8;
        uVar13 = puVar3[7];
        uVar5 = puVar2[7];
        uVar15 = (uVar13 - 1) - uVar5;
        bVar16 = uVar13 <= uVar5;
        if (!bVar1) {
          uVar15 = uVar13 - uVar5;
          bVar16 = uVar13 < uVar5;
        }
        puVar8[7] = uVar15;
        puVar8 = puVar9;
        puVar2 = puVar14;
        puVar3 = puVar6;
      } while (iVar12 != (iVar10 - (iVar10 - 9U & 0xfffffff8)) + -8);
    }
    do {
      while( true ) {
        uVar5 = *puVar6;
        uVar13 = *puVar14;
        bVar1 = uVar5 <= uVar13;
        if (bVar16) break;
        iVar12 = iVar12 + -1;
        *puVar9 = uVar5 - uVar13;
        puVar14 = puVar14 + 1;
        puVar9 = puVar9 + 1;
        puVar6 = puVar6 + 1;
        bVar16 = uVar5 < uVar13;
        bVar1 = uVar5 < uVar13;
        if (iVar12 == 0) goto LAB_000eefba;
      }
      iVar12 = iVar12 + -1;
      *puVar9 = (uVar5 - 1) - uVar13;
      puVar14 = puVar14 + 1;
      puVar9 = puVar9 + 1;
      puVar6 = puVar6 + 1;
      bVar16 = bVar1;
    } while (iVar12 != 0);
LAB_000eefba:
    puVar4 = puVar4 + iVar10;
    puVar6 = puVar11 + iVar10;
    puVar9 = puVar6;
    if (bVar1) {
      puVar8 = puVar4;
      if (local_38 == 0) {
        return 0;
      }
      do {
        puVar4 = puVar8 + 1;
        uVar15 = *puVar8;
        local_38 = local_38 + -1;
        puVar9 = puVar6 + 1;
        *puVar6 = uVar15 - 1;
        if (uVar15 != 0) goto LAB_000eefec;
        puVar8 = puVar4;
        puVar6 = puVar9;
      } while (local_38 != 0);
      goto LAB_000ef03a;
    }
  }
LAB_000eefec:
  if ((((puVar9 != puVar4) && (local_38 != 0)) && (*puVar9 = *puVar4, local_38 != 1)) &&
     (puVar9[1] = puVar4[1], local_38 != 2)) {
    iVar10 = local_38 + -4;
    puVar9[2] = puVar4[2];
    puVar6 = puVar4;
    if (local_38 != 3) {
      while( true ) {
        puVar4 = puVar6 + 4;
        puVar9[3] = puVar6[3];
        if ((iVar10 == 0) || (puVar9[4] = *puVar4, iVar10 == 1)) break;
        bVar16 = iVar10 == 2;
        iVar10 = iVar10 + -4;
        puVar9[5] = puVar6[5];
        if ((bVar16) || (puVar9[6] = puVar6[6], puVar6 = puVar4, puVar9 = puVar9 + 4, iVar10 == -1))
        break;
      }
    }
  }
LAB_000ef03a:
  r->top = words;
  if (words < 1) {
    puVar4 = (ulong *)0x1;
  }
  r->neg = 0;
  if (0 < words) {
    puVar9 = puVar11 + words + -1;
    do {
      if (*puVar9 != 0) break;
      words = words + -1;
      puVar9 = puVar9 + -1;
    } while (words != 0);
    puVar4 = (ulong *)0x1;
    r->top = words;
  }
  return (int)puVar4;
}

