
int BN_nist_mod_256(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  ulong *puVar1;
  int iVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ulong *puVar14;
  uint uVar15;
  ulong *puVar16;
  ulong uVar17;
  ulong *puVar18;
  ulong *rp;
  int iVar19;
  code *pcVar20;
  undefined4 uVar21;
  uint local_68 [8];
  undefined auStack_48 [36];
  
  puVar18 = a->d;
  iVar19 = a->top;
  if ((a->neg != 0) || (iVar2 = BN_ucmp(a,DAT_00128c98), -1 < iVar2)) {
    iVar19 = BN_nnmod(r,a,DAT_00128c9c,ctx);
    return iVar19;
  }
  iVar2 = BN_ucmp(DAT_00128c9c,a);
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
  rp = puVar18;
  if (r != a) {
    if ((r->dmax < 8) && (pBVar3 = bn_expand2(r,8), pBVar3 == (BIGNUM *)0x0)) {
      return 0;
    }
    rp = r->d;
    *rp = *puVar18;
    rp[1] = puVar18[1];
    rp[2] = puVar18[2];
    rp[3] = puVar18[3];
    rp[4] = puVar18[4];
    rp[5] = puVar18[5];
    rp[6] = puVar18[6];
    rp[7] = puVar18[7];
  }
  pcVar20 = DAT_00129118;
  iVar2 = iVar19 + -8;
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    if (iVar19 < 0x11) {
      iVar6 = 0;
    }
    else {
      puVar14 = puVar18 + 0x21;
      puVar16 = local_68;
      iVar6 = 0;
      do {
        iVar6 = iVar6 + 8;
        HintPreloadData(puVar14);
        *puVar16 = puVar14[-0x19];
        puVar16[1] = puVar14[-0x18];
        puVar16[2] = puVar14[-0x17];
        puVar16[3] = puVar14[-0x16];
        puVar16[4] = puVar14[-0x15];
        puVar16[5] = puVar14[-0x14];
        puVar16[6] = puVar14[-0x13];
        puVar1 = puVar14 + -0x12;
        puVar14 = puVar14 + 8;
        puVar16[7] = *puVar1;
        puVar16 = puVar16 + 8;
      } while (iVar6 != (iVar19 - 0x11U & 0xfffffff8) + 8);
    }
    puVar16 = puVar18 + iVar6;
    do {
      iVar6 = iVar6 + 1;
      *(ulong *)((int)puVar16 + ((int)local_68 - (int)puVar18)) = puVar16[8];
      puVar16 = puVar16 + 1;
    } while (iVar6 < iVar2);
    if (7 < iVar2) goto LAB_00128d70;
  }
  iVar19 = iVar2 << 2;
  do {
    iVar2 = iVar2 + 1;
    *(undefined4 *)((int)local_68 + iVar19) = 0;
    iVar19 = iVar19 + 4;
  } while (iVar2 < 8);
LAB_00128d70:
  uVar7 = local_68[0] + *rp;
  uVar8 = uVar7 + local_68[1];
  uVar9 = uVar8 - local_68[3];
  uVar21 = 0;
  uVar10 = uVar9 - local_68[4];
  uVar11 = uVar10 - local_68[5];
  uVar9 = (((((uint)CARRY4(local_68[0],*rp) + (uint)CARRY4(uVar7,local_68[1])) -
            (uint)(uVar8 < local_68[3])) - (uint)(uVar9 < local_68[4])) -
          (uint)(uVar10 < local_68[5])) - (uint)(uVar11 < local_68[6]);
  *rp = uVar11 - local_68[6];
  uVar7 = uVar9 + rp[1];
  uVar8 = uVar7 + local_68[1];
  iVar19 = ((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[1]) + (uint)CARRY4(uVar7,local_68[1]);
  uVar7 = (uVar8 + local_68[2]) - local_68[4];
  uVar9 = uVar7 - local_68[5];
  uVar10 = uVar9 - local_68[6];
  uVar7 = ((((iVar19 + (uint)CARRY4(uVar8,local_68[2])) - (uint)(uVar8 + local_68[2] < local_68[4]))
           - (uint)(uVar7 < local_68[5])) - (uint)(uVar9 < local_68[6])) -
          (uint)(uVar10 < local_68[7]);
  rp[1] = uVar10 - local_68[7];
  uVar9 = uVar7 + rp[2];
  uVar10 = uVar9 + local_68[2];
  uVar11 = uVar10 + local_68[3];
  uVar12 = uVar11 - local_68[5];
  uVar13 = uVar12 - local_68[6];
  uVar15 = (((((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,rp[2]) + (uint)CARRY4(uVar9,local_68[2]) +
             (uint)CARRY4(uVar10,local_68[3])) - (uint)(uVar11 < local_68[5])) -
           (uint)(uVar12 < local_68[6])) - (uint)(uVar13 < local_68[7]);
  uVar7 = uVar15 + rp[3];
  rp[2] = uVar13 - local_68[7];
  uVar9 = uVar7 + local_68[3];
  uVar10 = uVar9 + local_68[3];
  uVar11 = uVar10 + local_68[4];
  uVar12 = uVar11 + local_68[4];
  uVar13 = uVar12 + local_68[5];
  uVar4 = uVar13 - local_68[7];
  uVar5 = uVar4 - local_68[0];
  uVar7 = (((((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar15,rp[3]) + (uint)CARRY4(uVar7,local_68[3]) +
             (uint)CARRY4(uVar9,local_68[3]) + (uint)CARRY4(uVar10,local_68[4]) +
             (uint)CARRY4(uVar11,local_68[4]) + (uint)CARRY4(uVar12,local_68[5])) -
           (uint)(uVar13 < local_68[7])) - (uint)(uVar4 < local_68[0])) -
          (uint)(uVar5 < local_68[1]);
  uVar9 = uVar7 + rp[4];
  rp[3] = uVar5 - local_68[1];
  uVar10 = uVar9 + local_68[4];
  uVar11 = uVar10 + local_68[4];
  uVar12 = uVar11 + local_68[5];
  uVar13 = uVar12 + local_68[5];
  uVar4 = uVar13 + local_68[6];
  uVar5 = uVar4 - local_68[1];
  uVar15 = ((((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,rp[4]) + (uint)CARRY4(uVar9,local_68[4]) +
             (uint)CARRY4(uVar10,local_68[4]) + (uint)CARRY4(uVar11,local_68[5]) +
             (uint)CARRY4(uVar12,local_68[5]) + (uint)CARRY4(uVar13,local_68[6])) -
           (uint)(uVar4 < local_68[1])) - (uint)(uVar5 < local_68[2]);
  uVar7 = uVar15 + rp[5];
  rp[4] = uVar5 - local_68[2];
  uVar9 = uVar7 + local_68[5];
  uVar10 = uVar9 + local_68[5];
  uVar11 = uVar10 + local_68[6];
  uVar12 = uVar11 + local_68[6];
  uVar13 = uVar12 + local_68[7];
  uVar4 = uVar13 - local_68[2];
  uVar7 = ((((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar15,rp[5]) + (uint)CARRY4(uVar7,local_68[5]) +
            (uint)CARRY4(uVar9,local_68[5]) + (uint)CARRY4(uVar10,local_68[6]) +
            (uint)CARRY4(uVar11,local_68[6]) + (uint)CARRY4(uVar12,local_68[7])) -
          (uint)(uVar13 < local_68[2])) - (uint)(uVar4 < local_68[3]);
  uVar9 = uVar7 + rp[6];
  rp[5] = uVar4 - local_68[3];
  uVar10 = uVar9 + local_68[6];
  uVar11 = uVar10 + local_68[6];
  uVar12 = uVar11 + local_68[7];
  uVar13 = uVar12 + local_68[7];
  uVar4 = uVar13 + local_68[6];
  uVar5 = uVar4 + local_68[5];
  uVar15 = uVar5 - local_68[0];
  uVar7 = ((((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,rp[6]) + (uint)CARRY4(uVar9,local_68[6]) +
            (uint)CARRY4(uVar10,local_68[6]) + (uint)CARRY4(uVar11,local_68[7]) +
            (uint)CARRY4(uVar12,local_68[7]) + (uint)CARRY4(uVar13,local_68[6]) +
           (uint)CARRY4(uVar4,local_68[5])) - (uint)(uVar5 < local_68[0])) -
          (uint)(uVar15 < local_68[1]);
  uVar9 = uVar7 + rp[7];
  uVar10 = uVar9 + local_68[7];
  uVar11 = uVar10 + local_68[7];
  rp[6] = uVar15 - local_68[1];
  uVar12 = uVar11 + local_68[7];
  uVar13 = uVar12 + local_68[0];
  uVar4 = uVar13 - local_68[2];
  uVar5 = uVar4 - local_68[3];
  uVar15 = uVar5 - local_68[4];
  uVar7 = ((((((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,rp[7]) + (uint)CARRY4(uVar9,local_68[7]) +
              (uint)CARRY4(uVar10,local_68[7]) + (uint)CARRY4(uVar11,local_68[7]) +
             (uint)CARRY4(uVar12,local_68[0])) - (uint)(uVar13 < local_68[2])) -
           (uint)(uVar4 < local_68[3])) - (uint)(uVar5 < local_68[4])) -
          (uint)(uVar15 < local_68[5]);
  rp[7] = uVar15 - local_68[5];
  if ((int)uVar7 < 1) {
    if (uVar7 == 0) {
      uVar7 = 0xffffffff;
    }
    else {
      uVar17 = bn_add_words(rp,rp,(ulong *)(DAT_00129110 + ~uVar7 * 0x20),8);
      uVar7 = -uVar17;
      pcVar20 = (code *)(DAT_00129114 & ~uVar7 | uVar7 & (uint)pcVar20);
    }
  }
  else {
    uVar17 = bn_sub_words(rp,rp,(ulong *)(DAT_00129110 + (uVar7 - 1) * 0x20),8);
    uVar7 = -uVar17;
  }
  iVar19 = (*pcVar20)(auStack_48,rp,DAT_00129110,8,local_68[6],uVar21,uVar8,iVar19);
  puVar18 = r->d;
  puVar16 = (ulong *)((uint)auStack_48 & ~(-iVar19 & uVar7) | -iVar19 & uVar7 & (uint)rp);
  *rp = *puVar16;
  rp[1] = puVar16[1];
  rp[2] = puVar16[2];
  rp[3] = puVar16[3];
  rp[4] = puVar16[4];
  rp[5] = puVar16[5];
  rp[6] = puVar16[6];
  rp[7] = puVar16[7];
  r->top = 8;
  if (puVar18[7] == 0) {
    if (puVar18[6] == 0) {
      if (puVar18[5] == 0) {
        if (puVar18[4] == 0) {
          if (puVar18[3] == 0) {
            if (puVar18[2] == 0) {
              if (puVar18[1] == 0) {
                uVar17 = *puVar18;
                if (uVar17 != 0) {
                  uVar17 = 1;
                }
              }
              else {
                uVar17 = 2;
              }
            }
            else {
              uVar17 = 3;
            }
          }
          else {
            uVar17 = 4;
          }
        }
        else {
          uVar17 = 5;
        }
      }
      else {
        uVar17 = 6;
      }
    }
    else {
      uVar17 = 7;
    }
  }
  else {
    uVar17 = 8;
  }
  r->top = uVar17;
  return 1;
}

