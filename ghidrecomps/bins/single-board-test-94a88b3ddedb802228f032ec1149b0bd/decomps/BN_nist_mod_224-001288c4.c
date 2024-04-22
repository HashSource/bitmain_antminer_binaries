
int BN_nist_mod_224(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  ulong *puVar1;
  int iVar2;
  BIGNUM *pBVar3;
  int iVar4;
  uint uVar5;
  ulong *puVar6;
  ulong *puVar7;
  ulong uVar8;
  ulong *puVar9;
  ulong *rp;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  code *pcVar14;
  uint uVar15;
  uint local_60 [7];
  ulong local_44 [8];
  
  puVar9 = a->d;
  iVar10 = a->top;
  if ((a->neg != 0) || (iVar2 = BN_ucmp(a,DAT_00128920), -1 < iVar2)) {
    iVar10 = BN_nnmod(r,a,DAT_00128924,ctx);
    return iVar10;
  }
  iVar2 = BN_ucmp(DAT_00128924,a);
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
  rp = puVar9;
  if (r != a) {
    if ((r->dmax < 7) && (pBVar3 = bn_expand2(r,7), pBVar3 == (BIGNUM *)0x0)) {
      return 0;
    }
    rp = r->d;
    *rp = *puVar9;
    rp[1] = puVar9[1];
    rp[2] = puVar9[2];
    rp[3] = puVar9[3];
    rp[4] = puVar9[4];
    rp[5] = puVar9[5];
    rp[6] = puVar9[6];
  }
  iVar2 = iVar10 + -7;
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    if (iVar10 < 0x10) {
      iVar4 = 0;
    }
    else {
      puVar6 = puVar9 + 0x20;
      puVar7 = local_60;
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 8;
        HintPreloadData(puVar6);
        *puVar7 = puVar6[-0x19];
        puVar7[1] = puVar6[-0x18];
        puVar7[2] = puVar6[-0x17];
        puVar7[3] = puVar6[-0x16];
        puVar7[4] = puVar6[-0x15];
        puVar7[5] = puVar6[-0x14];
        puVar7[6] = puVar6[-0x13];
        puVar1 = puVar6 + -0x12;
        puVar6 = puVar6 + 8;
        puVar7[7] = *puVar1;
        puVar7 = puVar7 + 8;
      } while (iVar4 != (iVar10 - 0x10U & 0xfffffff8) + 8);
    }
    puVar7 = puVar9 + iVar4;
    do {
      iVar4 = iVar4 + 1;
      *(ulong *)((int)puVar7 + ((int)local_60 - (int)puVar9)) = puVar7[7];
      puVar7 = puVar7 + 1;
    } while (iVar4 < iVar2);
    if (6 < iVar2) goto LAB_001289f4;
  }
  iVar10 = iVar2 << 2;
  do {
    iVar2 = iVar2 + 1;
    *(undefined4 *)((int)local_60 + iVar10) = 0;
    iVar10 = iVar10 + 4;
  } while (iVar2 < 7);
LAB_001289f4:
  uVar13 = *rp - local_60[0];
  uVar15 = -(uint)(uVar13 < local_60[4]) - (uint)(*rp < local_60[0]);
  uVar5 = uVar15 + rp[1];
  *rp = uVar13 - local_60[4];
  pcVar14 = DAT_00128c38;
  uVar13 = uVar5 - local_60[1];
  uVar5 = ((((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar15,rp[1])) - (uint)(uVar5 < local_60[1])) -
          (uint)(uVar13 < local_60[5]);
  rp[1] = uVar13 - local_60[5];
  uVar13 = uVar5 + rp[2];
  uVar11 = uVar13 - local_60[2];
  uVar12 = ((((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar5,rp[2])) - (uint)(uVar13 < local_60[2])) -
           (uint)(uVar11 < local_60[6]);
  uVar15 = uVar12 + rp[3];
  rp[2] = uVar11 - local_60[6];
  uVar5 = local_60[0] + uVar15;
  uVar13 = uVar5 + local_60[4];
  uVar15 = (((int)uVar12 >> 0x1f) + (uint)CARRY4(uVar12,rp[3]) + (uint)CARRY4(local_60[0],uVar15) +
           (uint)CARRY4(uVar5,local_60[4])) - (uint)(uVar13 < local_60[3]);
  rp[3] = uVar13 - local_60[3];
  uVar13 = uVar15 + rp[4];
  uVar11 = uVar13 + local_60[1];
  uVar5 = local_60[5] + uVar11;
  uVar13 = (((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar15,rp[4]) + (uint)CARRY4(uVar13,local_60[1]) +
           (uint)CARRY4(local_60[5],uVar11)) - (uint)(uVar5 < local_60[4]);
  rp[4] = uVar5 - local_60[4];
  uVar5 = uVar13 + rp[5];
  uVar15 = uVar5 + local_60[2];
  uVar11 = uVar15 + local_60[6];
  uVar15 = (((int)uVar13 >> 0x1f) + (uint)CARRY4(uVar13,rp[5]) + (uint)CARRY4(uVar5,local_60[2]) +
           (uint)CARRY4(uVar15,local_60[6])) - (uint)(uVar11 < local_60[5]);
  rp[5] = uVar11 - local_60[5];
  uVar5 = uVar15 + rp[6];
  uVar13 = uVar5 + local_60[3];
  uVar5 = (((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar15,rp[6]) + (uint)CARRY4(uVar5,local_60[3])) -
          (uint)(uVar13 < local_60[6]);
  rp[6] = uVar13 - local_60[6];
  if ((int)uVar5 < 1) {
    if (uVar5 == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar8 = bn_add_words(rp,rp,(ulong *)(DAT_00128c30 + ~uVar5 * 0x1c),7);
      uVar5 = -uVar8;
      pcVar14 = (code *)(DAT_00128c34 & ~uVar5 | uVar5 & (uint)pcVar14);
    }
  }
  else {
    uVar8 = bn_sub_words(rp,rp,(ulong *)(DAT_00128c30 + (uVar5 - 1) * 0x1c),7);
    uVar5 = -uVar8;
  }
  iVar10 = (*pcVar14)(local_44,rp,DAT_00128c30,7);
  puVar9 = r->d;
  puVar7 = (ulong *)((uint)local_44 & ~(-iVar10 & uVar5) | -iVar10 & uVar5 & (uint)rp);
  *rp = *puVar7;
  rp[1] = puVar7[1];
  rp[2] = puVar7[2];
  rp[3] = puVar7[3];
  rp[4] = puVar7[4];
  rp[5] = puVar7[5];
  rp[6] = puVar7[6];
  r->top = 7;
  if (puVar9[6] == 0) {
    if (puVar9[5] == 0) {
      if (puVar9[4] == 0) {
        if (puVar9[3] == 0) {
          if (puVar9[2] == 0) {
            if (puVar9[1] == 0) {
              uVar8 = *puVar9;
              if (uVar8 != 0) {
                uVar8 = 1;
              }
            }
            else {
              uVar8 = 2;
            }
          }
          else {
            uVar8 = 3;
          }
        }
        else {
          uVar8 = 4;
        }
      }
      else {
        uVar8 = 5;
      }
    }
    else {
      uVar8 = 6;
    }
  }
  else {
    uVar8 = 7;
  }
  r->top = uVar8;
  return 1;
}

