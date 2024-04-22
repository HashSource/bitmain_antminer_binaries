
int BN_nist_mod_192(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  ulong *puVar1;
  int iVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  ulong *rp;
  uint local_78;
  undefined4 local_74;
  uint local_70;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  uint local_58 [6];
  ulong local_40 [7];
  
  puVar10 = a->d;
  iVar13 = a->top;
  if ((a->neg != 0) || (iVar2 = BN_ucmp(a,DAT_0012889c), -1 < iVar2)) {
    iVar13 = BN_nnmod(r,a,DAT_001288a0,ctx);
    return iVar13;
  }
  iVar2 = BN_ucmp(DAT_001288a0,a);
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
  rp = puVar10;
  if (r != a) {
    if ((r->dmax < 6) && (pBVar3 = bn_expand2(r,6), pBVar3 == (BIGNUM *)0x0)) {
      return 0;
    }
    rp = r->d;
    *rp = *puVar10;
    rp[1] = puVar10[1];
    rp[2] = puVar10[2];
    rp[3] = puVar10[3];
    rp[4] = puVar10[4];
    rp[5] = puVar10[5];
  }
  iVar2 = iVar13 + -6;
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    if (iVar13 < 0xf) {
      iVar6 = 0;
    }
    else {
      puVar8 = puVar10 + 0x1f;
      iVar6 = 0;
      puVar9 = &local_78;
      do {
        iVar6 = iVar6 + 8;
        HintPreloadData(puVar8);
        puVar9[8] = puVar8[-0x19];
        puVar9[9] = puVar8[-0x18];
        puVar9[10] = puVar8[-0x17];
        puVar9[0xb] = puVar8[-0x16];
        puVar9[0xc] = puVar8[-0x15];
        puVar9[0xd] = puVar8[-0x14];
        puVar9[0xe] = puVar8[-0x13];
        puVar1 = puVar8 + -0x12;
        puVar8 = puVar8 + 8;
        puVar9[0xf] = *puVar1;
        puVar9 = puVar9 + 8;
      } while (iVar6 != (iVar13 - 0xfU & 0xfffffff8) + 8);
    }
    puVar9 = puVar10 + iVar6;
    do {
      iVar6 = iVar6 + 1;
      *(ulong *)((int)puVar9 + ((int)local_58 - (int)puVar10)) = puVar9[6];
      puVar9 = puVar9 + 1;
    } while (iVar6 < iVar2);
    if (5 < iVar2) goto LAB_001286f2;
  }
  iVar13 = iVar2 << 2;
  do {
    iVar2 = iVar2 + 1;
    *(undefined4 *)((int)local_58 + iVar13) = 0;
    iVar13 = iVar13 + 4;
  } while (iVar2 < 6);
LAB_001286f2:
  local_74 = 0;
  local_5c = 0;
  local_78 = local_58[0];
  local_60 = local_58[4];
  local_64 = 0;
  uVar4 = local_58[0] + *rp;
  uVar7 = (uint)CARRY4(local_58[0],*rp) + (uint)CARRY4(uVar4,local_58[4]);
  *rp = uVar4 + local_58[4];
  local_68 = local_58[1];
  uVar4 = uVar7 + rp[1];
  uVar12 = uVar4 + local_58[1];
  uVar14 = (uint)CARRY4(uVar7,rp[1]) + (uint)CARRY4(uVar4,local_58[1]) +
           (uint)CARRY4(uVar12,local_58[5]);
  uVar11 = uVar14 + rp[2];
  local_6c = 0;
  local_70 = local_58[2];
  uVar4 = local_58[0] + uVar11;
  rp[1] = uVar12 + local_58[5];
  uVar7 = uVar4 + local_58[2];
  uVar4 = (uint)CARRY4(uVar14,rp[2]) + (uint)CARRY4(local_58[0],uVar11) +
          (uint)CARRY4(uVar4,local_58[2]) + (uint)CARRY4(uVar7,local_58[4]);
  rp[2] = uVar7 + local_58[4];
  uVar12 = uVar4 + rp[3];
  uVar7 = uVar12 + local_58[1];
  uVar11 = uVar7 + local_58[3];
  uVar7 = (uint)CARRY4(uVar4,rp[3]) + (uint)CARRY4(uVar12,local_58[1]) +
          (uint)CARRY4(uVar7,local_58[3]) + (uint)CARRY4(uVar11,local_58[5]);
  rp[3] = uVar11 + local_58[5];
  uVar4 = uVar7 + rp[4];
  uVar11 = local_58[2] + uVar4;
  uVar12 = (uint)CARRY4(uVar7,rp[4]) + (uint)CARRY4(local_58[2],uVar4) +
           (uint)CARRY4(uVar11,local_58[4]);
  rp[4] = uVar11 + local_58[4];
  uVar7 = uVar12 + rp[5];
  uVar4 = 0xffffffff;
  uVar11 = uVar7 + local_58[3];
  iVar13 = (uint)CARRY4(uVar12,rp[5]) + (uint)CARRY4(uVar7,local_58[3]) +
           (uint)CARRY4(uVar11,local_58[5]);
  rp[5] = uVar11 + local_58[5];
  if (iVar13 != 0) {
    uVar5 = bn_sub_words(rp,rp,DAT_001288a4 + (iVar13 + -1) * 6,6);
    uVar4 = -uVar5;
  }
  uVar5 = bn_sub_words(local_40,rp,DAT_001288a4,6);
  puVar10 = r->d;
  puVar9 = (ulong *)((uint)local_40 & ~(-uVar5 & uVar4) | (uint)rp & -uVar5 & uVar4);
  *rp = *puVar9;
  rp[1] = puVar9[1];
  rp[2] = puVar9[2];
  rp[3] = puVar9[3];
  rp[4] = puVar9[4];
  rp[5] = puVar9[5];
  r->top = 6;
  if (puVar10[5] == 0) {
    if (puVar10[4] == 0) {
      if (puVar10[3] == 0) {
        if (puVar10[2] == 0) {
          if (puVar10[1] == 0) {
            uVar5 = *puVar10;
            if (uVar5 != 0) {
              uVar5 = 1;
            }
          }
          else {
            uVar5 = 2;
          }
        }
        else {
          uVar5 = 3;
        }
      }
      else {
        uVar5 = 4;
      }
    }
    else {
      uVar5 = 5;
    }
  }
  else {
    uVar5 = 6;
  }
  r->top = uVar5;
  return 1;
}

