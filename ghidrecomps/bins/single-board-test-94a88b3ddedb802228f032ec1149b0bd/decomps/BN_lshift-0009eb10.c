
int BN_lshift(BIGNUM *r,BIGNUM *a,int n)

{
  ulong *puVar1;
  ulong *__s;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ulong *puVar6;
  int iVar7;
  ulong *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  ulong *puVar13;
  uint uVar14;
  uint uVar15;
  
  if (n < 0) {
    ERR_put_error(3,0x91,0x77,DAT_0009ed70,0x8d);
    iVar12 = 0;
  }
  else {
    iVar12 = n >> 5;
    iVar3 = a->top + iVar12;
    r->neg = a->neg;
    if (r->dmax <= iVar3) {
      pBVar2 = bn_expand2(r,iVar3 + 1);
      if (pBVar2 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar3 = a->top + iVar12;
    }
    __s = r->d;
    uVar5 = n & 0x1f;
    puVar13 = a->d;
    __s[iVar3] = 0;
    if (uVar5 == 0) {
      iVar3 = a->top;
      iVar9 = iVar3 + -1;
      if (-1 < iVar9) {
        if (8 < iVar3) {
          puVar8 = puVar13 + iVar3 + -0x15;
          puVar6 = __s + iVar12 + iVar9;
          do {
            iVar9 = iVar9 + -8;
            HintPreloadData(puVar8);
            *puVar6 = puVar8[0x14];
            puVar6[-1] = puVar8[0x13];
            puVar6[-2] = puVar8[0x12];
            puVar6[-3] = puVar8[0x11];
            puVar6[-4] = puVar8[0x10];
            puVar6[-5] = puVar8[0xf];
            puVar6[-6] = puVar8[0xe];
            puVar1 = puVar8 + 0xd;
            puVar8 = puVar8 + -8;
            puVar6[-7] = *puVar1;
            puVar6 = puVar6 + -8;
          } while (iVar9 != (iVar3 - (iVar3 - 9U & 0xfffffff8)) + -9);
        }
        iVar4 = iVar9 + iVar12;
        iVar3 = iVar9 * 4;
        iVar7 = 0;
        do {
          iVar9 = iVar9 + -1;
          *(undefined4 *)((int)__s + iVar7 + iVar4 * 4) =
               *(undefined4 *)((int)puVar13 + iVar7 + iVar3);
          iVar7 = iVar7 + -4;
        } while (-1 < iVar9);
      }
    }
    else {
      iVar3 = a->top;
      iVar9 = iVar3 + -1;
      if (-1 < iVar9) {
        if (iVar3 < 9) {
          uVar10 = 0x20 - uVar5;
        }
        else {
          puVar8 = __s + iVar12 + iVar3;
          puVar6 = puVar13 + iVar3;
          uVar10 = 0x20 - uVar5;
          do {
            HintPreloadData(puVar6 + -0xc);
            iVar9 = iVar9 + -8;
            HintPreloadData(puVar8 + -0xb);
            uVar11 = puVar6[-1] << uVar5;
            *puVar8 = *puVar8 | puVar6[-1] >> (uVar10 & 0xff);
            HintPreloadData(puVar8 + -0xc);
            puVar8[-1] = uVar11;
            uVar14 = puVar6[-2];
            uVar15 = uVar14 << uVar5;
            puVar8[-2] = uVar15;
            puVar8[-1] = uVar11 | uVar14 >> (uVar10 & 0xff);
            uVar11 = puVar6[-3];
            uVar14 = uVar11 << uVar5;
            puVar8[-3] = uVar14;
            puVar8[-2] = uVar15 | uVar11 >> (uVar10 & 0xff);
            uVar11 = puVar6[-4];
            uVar15 = uVar11 << uVar5;
            puVar8[-4] = uVar15;
            puVar8[-3] = uVar14 | uVar11 >> (uVar10 & 0xff);
            uVar11 = puVar6[-5];
            uVar14 = uVar11 << uVar5;
            puVar8[-5] = uVar14;
            puVar8[-4] = uVar15 | uVar11 >> (uVar10 & 0xff);
            uVar11 = puVar6[-6];
            uVar15 = uVar11 << uVar5;
            puVar8[-6] = uVar15;
            puVar8[-5] = uVar14 | uVar11 >> (uVar10 & 0xff);
            uVar11 = puVar6[-7];
            uVar14 = uVar11 << uVar5;
            puVar8[-7] = uVar14;
            puVar8[-6] = uVar15 | uVar11 >> (uVar10 & 0xff);
            puVar6 = puVar6 + -8;
            uVar11 = *puVar6;
            puVar8[-7] = uVar14 | uVar11 >> (uVar10 & 0xff);
            puVar8 = puVar8 + -8;
            *puVar8 = uVar11 << uVar5;
          } while (iVar9 != (iVar3 - (iVar3 - 9U & 0xfffffff8)) + -9);
        }
        puVar13 = puVar13 + iVar9 + 1;
        puVar6 = __s + iVar12 + iVar9 + 1;
        do {
          puVar13 = puVar13 + -1;
          uVar11 = *puVar13;
          iVar9 = iVar9 + -1;
          puVar6[-1] = uVar11 << uVar5;
          *puVar6 = *puVar6 | uVar11 >> (uVar10 & 0xff);
          puVar6 = puVar6 + -1;
        } while (-1 < iVar9);
      }
    }
    memset(__s,0,iVar12 << 2);
    iVar12 = iVar12 + a->top;
    iVar3 = iVar12 + 1;
    r->top = iVar3;
    if (0 < iVar3) {
      puVar13 = r->d + iVar12;
      do {
        if (*puVar13 != 0) break;
        iVar3 = iVar3 + -1;
        puVar13 = puVar13 + -1;
      } while (iVar3 != 0);
      r->top = iVar3;
    }
    iVar12 = 1;
  }
  return iVar12;
}

