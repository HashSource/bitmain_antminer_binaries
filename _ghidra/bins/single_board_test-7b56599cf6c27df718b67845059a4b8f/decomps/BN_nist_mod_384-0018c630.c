
int BN_nist_mod_384(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  uint *puVar3;
  ulong uVar4;
  uint uVar5;
  size_t __n;
  uint uVar6;
  ulong *rp;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  ulong *puVar10;
  uint uVar11;
  uint uVar12;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined1 auStack_40 [28];
  
  iVar7 = a->top;
  puVar10 = a->d;
  iVar1 = BN_is_negative(a);
  if ((iVar1 != 0) || (iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_384_sqr_9508), -1 < iVar1)) {
    iVar1 = BN_nnmod(r,a,(BIGNUM *)_bignum_nist_p_384,ctx);
    return iVar1;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_384,a);
  if (iVar1 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  if (0 < iVar1) {
    if (a == r) {
      return 1;
    }
    pBVar2 = BN_copy(r,a);
    if (pBVar2 == (BIGNUM *)0x0) {
      return 0;
    }
    return 1;
  }
  rp = puVar10;
  if (a != r) {
    iVar1 = bn_wexpand(r,6);
    if (iVar1 == 0) {
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
  if (iVar7 < 7) {
    iVar1 = 0;
    puVar3 = &local_58;
  }
  else {
    iVar1 = iVar7 + -6;
    puVar3 = (uint *)memcpy(&local_58,puVar10 + 6,(iVar7 + 0x3ffffffa) * 4);
    if (5 < iVar1) goto LAB_0018c726;
  }
  __n = iVar1 * -4 + 0x18;
  if (5 < iVar1) {
    __n = 4;
  }
  memset(puVar3 + iVar1,0,__n);
LAB_0018c726:
  uVar5 = (uint)CARRY4(local_58,*rp);
  *rp = local_58 + *rp;
  uVar6 = uVar5 + rp[1];
  uVar8 = local_54 + uVar6;
  uVar6 = ((uint)CARRY4(uVar5,rp[1]) + (uint)CARRY4(local_54,uVar6)) - (uint)(uVar8 < local_58);
  rp[1] = uVar8 - local_58;
  uVar5 = uVar6 + rp[2];
  uVar8 = local_50 + uVar5;
  uVar12 = (((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar6,rp[2]) + (uint)CARRY4(local_50,uVar5)) -
           (uint)(uVar8 < local_54);
  rp[2] = uVar8 - local_54;
  uVar5 = uVar12 + rp[3];
  uVar8 = local_4c + uVar5;
  uVar6 = uVar8 + local_58;
  uVar11 = (((int)uVar12 >> 0x1f) + (uint)CARRY4(uVar12,rp[3]) + (uint)CARRY4(local_4c,uVar5) +
           (uint)CARRY4(uVar8,local_58)) - (uint)(uVar6 < local_50);
  rp[3] = uVar6 - local_50;
  uVar12 = uVar11 + rp[4];
  uVar6 = local_48 + uVar12;
  uVar8 = local_54 + uVar6;
  uVar5 = uVar8 + local_58;
  uVar12 = (((int)uVar11 >> 0x1f) + (uint)CARRY4(uVar11,rp[4]) + (uint)CARRY4(local_48,uVar12) +
            (uint)CARRY4(local_54,uVar6) + (uint)CARRY4(uVar8,local_58)) - (uint)(uVar5 < local_4c);
  rp[4] = uVar5 - local_4c;
  uVar11 = uVar12 + rp[5];
  uVar8 = uVar11 + local_44;
  uVar5 = local_50 + uVar8;
  uVar6 = local_54 + uVar5;
  uVar8 = (((int)uVar12 >> 0x1f) + (uint)CARRY4(uVar12,rp[5]) + (uint)CARRY4(uVar11,local_44) +
           (uint)CARRY4(local_50,uVar8) + (uint)CARRY4(local_54,uVar5)) - (uint)(uVar6 < local_48);
  rp[5] = uVar6 - local_48;
  uVar5 = uVar8 + rp[6];
  uVar6 = local_4c + uVar5;
  uVar12 = local_50 + uVar6;
  uVar5 = (((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar8,rp[6]) + (uint)CARRY4(local_4c,uVar5) +
          (uint)CARRY4(local_50,uVar6)) - (uint)(uVar12 < local_44);
  rp[6] = uVar12 - local_44;
  uVar8 = uVar5 + rp[7];
  uVar6 = local_48 + uVar8;
  uVar5 = ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar5,rp[7]) + (uint)CARRY4(local_48,uVar8) +
          (uint)CARRY4(local_4c,uVar6);
  rp[7] = local_4c + uVar6;
  uVar6 = uVar5 + rp[8];
  uVar8 = uVar6 + local_44;
  uVar6 = ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar5,rp[8]) + (uint)CARRY4(uVar6,local_44) +
          (uint)CARRY4(local_48,uVar8);
  rp[8] = local_48 + uVar8;
  uVar5 = uVar6 + rp[9];
  uVar8 = ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar6,rp[9]) + (uint)CARRY4(uVar5,local_44);
  rp[9] = uVar5 + local_44;
  uVar6 = ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar8,rp[10]);
  rp[10] = uVar8 + rp[10];
  uVar5 = ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar6,rp[0xb]);
  rp[0xb] = uVar6 + rp[0xb];
  pcVar9 = (code *)(undefined *)0x1879c1;
  if ((int)uVar5 >> 0x1f < (int)(uint)(uVar5 == 0)) {
    if (uVar5 == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar4 = bn_add_words(rp,rp,(ulong *)(_nist_p_384 + ~uVar5 * 0x18),6);
      uVar5 = -uVar4;
      pcVar9 = (code *)(uVar5 & 0x19c ^ (uint)(undefined *)0x18785d);
    }
  }
  else {
    uVar4 = bn_sub_words(rp,rp,(ulong *)(_nist_p_384 + (uVar5 - 1) * 0x18),6);
    uVar5 = -uVar4;
  }
  iVar1 = (*pcVar9)(auStack_40,rp,_nist_p_384,6);
  puVar10 = (ulong *)(((uint)rp ^ (uint)auStack_40) & uVar5 & -iVar1 ^ (uint)auStack_40);
  *rp = *puVar10;
  rp[1] = puVar10[1];
  rp[2] = puVar10[2];
  rp[3] = puVar10[3];
  rp[4] = puVar10[4];
  rp[5] = puVar10[5];
  r->top = 6;
  bn_correct_top(r);
  return 1;
}

