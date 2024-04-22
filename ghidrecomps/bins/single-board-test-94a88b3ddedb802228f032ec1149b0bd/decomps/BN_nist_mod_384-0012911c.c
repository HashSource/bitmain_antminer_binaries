
int BN_nist_mod_384(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  ulong *puVar1;
  int iVar2;
  BIGNUM *pBVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ulong *puVar11;
  uint uVar12;
  ulong *puVar13;
  ulong uVar14;
  ulong *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  ulong *rp;
  code *pcVar21;
  uint local_88 [11];
  uint local_5c;
  undefined auStack_58 [52];
  
  puVar15 = a->d;
  iVar20 = a->top;
  if ((a->neg != 0) || (iVar2 = BN_ucmp(a,DAT_00129178), -1 < iVar2)) {
    iVar20 = BN_nnmod(r,a,DAT_0012917c,ctx);
    return iVar20;
  }
  iVar2 = BN_ucmp(DAT_0012917c,a);
  if (iVar2 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  if (0 < iVar2) {
    if (r == a) {
      return 1;
    }
    pBVar3 = BN_copy(r,a);
    if (pBVar3 == (BIGNUM *)0x0) {
      return 0;
    }
    return 1;
  }
  rp = puVar15;
  if (r != a) {
    if ((r->dmax < 0xc) && (pBVar3 = bn_expand2(r,0xc), pBVar3 == (BIGNUM *)0x0)) {
      return 0;
    }
    rp = r->d;
    *rp = *puVar15;
    rp[1] = puVar15[1];
    rp[2] = puVar15[2];
    rp[3] = puVar15[3];
    rp[4] = puVar15[4];
    rp[5] = puVar15[5];
    rp[6] = puVar15[6];
    rp[7] = puVar15[7];
    rp[8] = puVar15[8];
    rp[9] = puVar15[9];
    rp[10] = puVar15[10];
    rp[0xb] = puVar15[0xb];
  }
  pcVar21 = DAT_00129768;
  iVar2 = iVar20 + -0xc;
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    if (iVar20 < 0x15) {
      iVar4 = 0;
    }
    else {
      puVar11 = puVar15 + 0x25;
      puVar13 = local_88;
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 8;
        HintPreloadData(puVar11);
        *puVar13 = puVar11[-0x19];
        puVar13[1] = puVar11[-0x18];
        puVar13[2] = puVar11[-0x17];
        puVar13[3] = puVar11[-0x16];
        puVar13[4] = puVar11[-0x15];
        puVar13[5] = puVar11[-0x14];
        puVar13[6] = puVar11[-0x13];
        puVar1 = puVar11 + -0x12;
        puVar11 = puVar11 + 8;
        puVar13[7] = *puVar1;
        puVar13 = puVar13 + 8;
      } while (iVar4 != (iVar20 - 0x15U & 0xfffffff8) + 8);
    }
    puVar13 = puVar15 + iVar4;
    do {
      iVar4 = iVar4 + 1;
      *(ulong *)((int)puVar13 + ((int)local_88 - (int)puVar15)) = puVar13[0xc];
      puVar13 = puVar13 + 1;
    } while (iVar4 < iVar2);
    if (0xb < iVar2) goto LAB_00129276;
  }
  iVar20 = iVar2 << 2;
  do {
    iVar2 = iVar2 + 1;
    *(undefined4 *)((int)local_88 + iVar20) = 0;
    iVar20 = iVar20 + 4;
  } while (iVar2 < 0xc);
LAB_00129276:
  uVar5 = local_88[0] + *rp;
  uVar6 = uVar5 + local_88[9];
  uVar7 = uVar6 + local_88[8];
  uVar5 = ((uint)CARRY4(local_88[0],*rp) + (uint)CARRY4(uVar5,local_88[9]) +
          (uint)CARRY4(uVar6,local_88[8])) - (uint)(uVar7 < local_5c);
  uVar6 = uVar5 + rp[1];
  uVar16 = uVar6 + local_88[1];
  uVar17 = uVar16 + local_88[10];
  uVar18 = uVar17 + local_5c;
  uVar19 = uVar18 - local_88[0];
  uVar17 = ((((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar5,rp[1]) + (uint)CARRY4(uVar6,local_88[1]) +
             (uint)CARRY4(uVar16,local_88[10]) + (uint)CARRY4(uVar17,local_5c)) -
           (uint)(uVar18 < local_88[0])) - (uint)(uVar19 < local_88[8]);
  *rp = uVar7 - local_5c;
  rp[1] = uVar19 - local_88[8];
  uVar5 = uVar17 + rp[2];
  uVar6 = uVar5 + local_88[2];
  uVar7 = uVar6 + local_5c;
  uVar16 = uVar7 - local_88[1];
  uVar5 = ((((int)uVar17 >> 0x1f) + (uint)CARRY4(uVar17,rp[2]) + (uint)CARRY4(uVar5,local_88[2]) +
           (uint)CARRY4(uVar6,local_5c)) - (uint)(uVar7 < local_88[1])) -
          (uint)(uVar16 < local_88[9]);
  rp[2] = uVar16 - local_88[9];
  uVar6 = uVar5 + rp[3];
  uVar7 = uVar6 + local_88[3];
  uVar16 = uVar7 + local_88[0];
  uVar17 = uVar16 + local_88[8];
  uVar18 = uVar17 + local_88[9];
  uVar19 = uVar18 - local_88[2];
  uVar8 = uVar19 - local_88[10];
  uVar12 = (((((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar5,rp[3]) + (uint)CARRY4(uVar6,local_88[3]) +
              (uint)CARRY4(uVar7,local_88[0]) + (uint)CARRY4(uVar16,local_88[8]) +
             (uint)CARRY4(uVar17,local_88[9])) - (uint)(uVar18 < local_88[2])) -
           (uint)(uVar19 < local_88[10])) - (uint)(uVar8 < local_5c);
  rp[3] = uVar8 - local_5c;
  uVar5 = uVar12 + rp[4];
  uVar6 = uVar5 + local_88[9];
  uVar7 = uVar6 + local_88[9];
  uVar16 = uVar7 + local_88[4];
  uVar17 = uVar16 + local_88[1];
  uVar18 = uVar17 + local_88[0];
  uVar19 = uVar18 + local_88[8];
  uVar8 = uVar19 + local_88[10];
  uVar9 = uVar8 - local_88[3];
  uVar10 = uVar9 - local_5c;
  uVar9 = (((((int)uVar12 >> 0x1f) + (uint)CARRY4(uVar12,rp[4]) + (uint)CARRY4(uVar5,local_88[9]) +
             (uint)CARRY4(uVar6,local_88[9]) + (uint)CARRY4(uVar7,local_88[4]) +
             (uint)CARRY4(uVar16,local_88[1]) + (uint)CARRY4(uVar17,local_88[0]) +
             (uint)CARRY4(uVar18,local_88[8]) + (uint)CARRY4(uVar19,local_88[10])) -
           (uint)(uVar8 < local_88[3])) - (uint)(uVar9 < local_5c)) - (uint)(uVar10 < local_5c);
  rp[4] = uVar10 - local_5c;
  uVar5 = uVar9 + rp[5];
  uVar6 = uVar5 + local_88[10];
  uVar7 = uVar6 + local_88[10];
  uVar16 = uVar7 + local_88[5];
  uVar17 = uVar16 + local_88[2];
  uVar18 = uVar17 + local_88[1];
  uVar19 = uVar18 + local_88[9];
  uVar8 = uVar19 + local_5c;
  uVar9 = (((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[5]) + (uint)CARRY4(uVar5,local_88[10]) +
           (uint)CARRY4(uVar6,local_88[10]) + (uint)CARRY4(uVar7,local_88[5]) +
           (uint)CARRY4(uVar16,local_88[2]) + (uint)CARRY4(uVar17,local_88[1]) +
           (uint)CARRY4(uVar18,local_88[9]) + (uint)CARRY4(uVar19,local_5c)) -
          (uint)(uVar8 < local_88[4]);
  rp[5] = uVar8 - local_88[4];
  uVar5 = uVar9 + rp[6];
  uVar6 = uVar5 + local_5c;
  uVar7 = uVar6 + local_5c;
  uVar16 = uVar7 + local_88[6];
  uVar17 = uVar16 + local_88[3];
  uVar18 = uVar17 + local_88[2];
  uVar19 = uVar18 + local_88[10];
  uVar18 = (((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[6]) + (uint)CARRY4(uVar5,local_5c) +
            (uint)CARRY4(uVar6,local_5c) + (uint)CARRY4(uVar7,local_88[6]) +
            (uint)CARRY4(uVar16,local_88[3]) + (uint)CARRY4(uVar17,local_88[2]) +
           (uint)CARRY4(uVar18,local_88[10])) - (uint)(uVar19 < local_88[5]);
  rp[6] = uVar19 - local_88[5];
  uVar5 = uVar18 + rp[7];
  uVar6 = uVar5 + local_88[7];
  uVar7 = uVar6 + local_88[4];
  uVar16 = uVar7 + local_88[3];
  uVar17 = uVar16 + local_5c;
  uVar5 = (((int)uVar18 >> 0x1f) + (uint)CARRY4(uVar18,rp[7]) + (uint)CARRY4(uVar5,local_88[7]) +
           (uint)CARRY4(uVar6,local_88[4]) + (uint)CARRY4(uVar7,local_88[3]) +
          (uint)CARRY4(uVar16,local_5c)) - (uint)(uVar17 < local_88[6]);
  rp[7] = uVar17 - local_88[6];
  uVar6 = uVar5 + rp[8];
  uVar7 = uVar6 + local_88[8];
  uVar16 = uVar7 + local_88[5];
  uVar17 = uVar16 + local_88[4];
  uVar18 = (((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar5,rp[8]) + (uint)CARRY4(uVar6,local_88[8]) +
            (uint)CARRY4(uVar7,local_88[5]) + (uint)CARRY4(uVar16,local_88[4])) -
           (uint)(uVar17 < local_88[7]);
  rp[8] = uVar17 - local_88[7];
  uVar5 = uVar18 + rp[9];
  uVar6 = uVar5 + local_88[9];
  uVar7 = uVar6 + local_88[6];
  uVar16 = uVar7 + local_88[5];
  uVar17 = (((int)uVar18 >> 0x1f) + (uint)CARRY4(uVar18,rp[9]) + (uint)CARRY4(uVar5,local_88[9]) +
            (uint)CARRY4(uVar6,local_88[6]) + (uint)CARRY4(uVar7,local_88[5])) -
           (uint)(uVar16 < local_88[8]);
  rp[9] = uVar16 - local_88[8];
  uVar16 = uVar17 + rp[10];
  uVar5 = local_88[10] + uVar16;
  uVar6 = uVar5 + local_88[7];
  uVar7 = uVar6 + local_88[6];
  uVar17 = (((int)uVar17 >> 0x1f) + (uint)CARRY4(uVar17,rp[10]) + (uint)CARRY4(local_88[10],uVar16)
            + (uint)CARRY4(uVar5,local_88[7]) + (uint)CARRY4(uVar6,local_88[6])) -
           (uint)(uVar7 < local_88[9]);
  rp[10] = uVar7 - local_88[9];
  uVar5 = uVar17 + rp[0xb];
  uVar6 = uVar5 + local_5c;
  uVar7 = uVar6 + local_88[8];
  uVar16 = uVar7 + local_88[7];
  uVar5 = (((int)uVar17 >> 0x1f) + (uint)CARRY4(uVar17,rp[0xb]) + (uint)CARRY4(uVar5,local_5c) +
           (uint)CARRY4(uVar6,local_88[8]) + (uint)CARRY4(uVar7,local_88[7])) -
          (uint)(uVar16 < local_88[10]);
  rp[0xb] = uVar16 - local_88[10];
  if ((int)uVar5 < 1) {
    if (uVar5 == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar14 = bn_add_words(rp,rp,(ulong *)(DAT_00129760 + ~uVar5 * 0x30),0xc);
      uVar5 = -uVar14;
      pcVar21 = (code *)(DAT_00129764 & ~uVar5 | uVar5 & (uint)pcVar21);
    }
  }
  else {
    uVar14 = bn_sub_words(rp,rp,(ulong *)(DAT_00129760 + (uVar5 - 1) * 0x30),0xc);
    uVar5 = -uVar14;
  }
  iVar20 = (*pcVar21)(auStack_58,rp,DAT_00129760,0xc);
  puVar15 = r->d;
  puVar13 = (ulong *)((uint)auStack_58 & ~(-iVar20 & uVar5) | (uint)rp & -iVar20 & uVar5);
  *rp = *puVar13;
  rp[1] = puVar13[1];
  rp[2] = puVar13[2];
  rp[3] = puVar13[3];
  rp[4] = puVar13[4];
  rp[5] = puVar13[5];
  rp[6] = puVar13[6];
  rp[7] = puVar13[7];
  rp[8] = puVar13[8];
  rp[9] = puVar13[9];
  rp[10] = puVar13[10];
  rp[0xb] = puVar13[0xb];
  r->top = 0xc;
  if (puVar15[0xb] == 0) {
    if (puVar15[10] == 0) {
      if (puVar15[9] == 0) {
        if (puVar15[8] == 0) {
          if (puVar15[7] == 0) {
            if (puVar15[6] == 0) {
              if (puVar15[5] == 0) {
                if (puVar15[4] == 0) {
                  if (puVar15[3] == 0) {
                    if (puVar15[2] == 0) {
                      if (puVar15[1] == 0) {
                        uVar14 = *puVar15;
                        if (uVar14 != 0) {
                          uVar14 = 1;
                        }
                      }
                      else {
                        uVar14 = 2;
                      }
                    }
                    else {
                      uVar14 = 3;
                    }
                  }
                  else {
                    uVar14 = 4;
                  }
                }
                else {
                  uVar14 = 5;
                }
              }
              else {
                uVar14 = 6;
              }
            }
            else {
              uVar14 = 7;
            }
          }
          else {
            uVar14 = 8;
          }
        }
        else {
          uVar14 = 9;
        }
      }
      else {
        uVar14 = 10;
      }
    }
    else {
      uVar14 = 0xb;
    }
  }
  else {
    uVar14 = 0xc;
  }
  r->top = uVar14;
  return 1;
}

