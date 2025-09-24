
int BN_nist_mod_256(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  uint *puVar3;
  uint uVar4;
  ulong uVar5;
  size_t __n;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulong *rp;
  code *pcVar9;
  int iVar10;
  ulong *puVar11;
  uint uVar12;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined1 auStack_38 [20];
  
  iVar10 = a->top;
  puVar11 = a->d;
  iVar1 = BN_is_negative(a);
  if ((iVar1 != 0) || (iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_256_sqr_9474), -1 < iVar1)) {
    iVar1 = BN_nnmod(r,a,(BIGNUM *)_bignum_nist_p_256,ctx);
    return iVar1;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_256,a);
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
  rp = puVar11;
  if (a != r) {
    iVar1 = bn_wexpand(r,4);
    if (iVar1 == 0) {
      return 0;
    }
    rp = r->d;
    *rp = *puVar11;
    rp[1] = puVar11[1];
    rp[2] = puVar11[2];
    rp[3] = puVar11[3];
  }
  if (iVar10 < 5) {
    iVar1 = 0;
    puVar3 = &local_48;
  }
  else {
    iVar1 = iVar10 + -4;
    puVar3 = (uint *)memcpy(&local_48,puVar11 + 4,(iVar10 + 0x3ffffffc) * 4);
    if (3 < iVar1) goto LAB_0018c3b0;
  }
  __n = iVar1 * -4 + 0x10;
  if (3 < iVar1) {
    __n = 4;
  }
  memset(puVar3 + iVar1,0,__n);
LAB_0018c3b0:
  uVar4 = local_48 + *rp;
  uVar6 = local_44 + uVar4;
  uVar4 = ((uint)CARRY4(local_48,*rp) + (uint)CARRY4(local_44,uVar4)) - (uint)(uVar6 < local_3c);
  *rp = uVar6 - local_3c;
  uVar12 = uVar4 + rp[1];
  uVar6 = local_44 + uVar12;
  uVar4 = ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar4,rp[1]) + (uint)CARRY4(local_44,uVar12) +
          (uint)CARRY4(uVar6,local_40);
  rp[1] = uVar6 + local_40;
  uVar6 = uVar4 + rp[2];
  uVar12 = uVar6 + local_40;
  uVar6 = ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar4,rp[2]) + (uint)CARRY4(uVar6,local_40) +
          (uint)CARRY4(local_3c,uVar12);
  rp[2] = local_3c + uVar12;
  uVar12 = uVar6 + rp[3];
  uVar7 = local_3c + uVar12;
  uVar4 = local_3c + uVar7;
  uVar8 = uVar4 - local_48;
  uVar6 = ((((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar6,rp[3]) + (uint)CARRY4(local_3c,uVar12) +
           (uint)CARRY4(local_3c,uVar7)) - (uint)(uVar4 < local_48)) - (uint)(uVar8 < local_44);
  rp[3] = uVar8 - local_44;
  uVar4 = uVar6 + rp[4];
  uVar12 = uVar4 - local_44;
  uVar7 = ((((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar6,rp[4])) - (uint)(uVar4 < local_44)) -
          (uint)(uVar12 < local_40);
  rp[4] = uVar12 - local_40;
  uVar6 = uVar7 + rp[5];
  uVar4 = uVar6 - local_40;
  uVar6 = ((((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,rp[5])) - (uint)(uVar6 < local_40)) -
          (uint)(uVar4 < local_3c);
  rp[5] = uVar4 - local_3c;
  uVar4 = uVar6 + rp[6];
  uVar12 = uVar4 - local_48;
  uVar7 = ((((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar6,rp[6])) - (uint)(uVar4 < local_48)) -
          (uint)(uVar12 < local_44);
  rp[6] = uVar12 - local_44;
  uVar4 = uVar7 + rp[7];
  uVar12 = local_48 + uVar4;
  uVar6 = uVar12 - local_40;
  uVar4 = ((((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,rp[7]) + (uint)CARRY4(local_48,uVar4)) -
          (uint)(uVar12 < local_40)) - (uint)(uVar6 < local_3c);
  rp[7] = uVar6 - local_3c;
  pcVar9 = (code *)(undefined *)0x1879c1;
  if ((int)uVar4 >> 0x1f < (int)(uint)(uVar4 == 0)) {
    if (uVar4 == 0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar5 = bn_add_words(rp,rp,(ulong *)(_nist_p_256 + ~uVar4 * 0x10),4);
      uVar4 = -uVar5;
      pcVar9 = (code *)(uVar4 & 0x19c ^ (uint)(undefined *)0x18785d);
    }
  }
  else {
    uVar5 = bn_sub_words(rp,rp,(ulong *)(_nist_p_224 + uVar4 * 0x10 + 0x10),4);
    uVar4 = -uVar5;
  }
  iVar1 = (*pcVar9)(auStack_38,rp,_nist_p_256,4);
  puVar11 = (ulong *)(((uint)rp ^ (uint)auStack_38) & uVar4 & -iVar1 ^ (uint)auStack_38);
  *rp = *puVar11;
  rp[1] = puVar11[1];
  rp[2] = puVar11[2];
  rp[3] = puVar11[3];
  r->top = 4;
  bn_correct_top(r);
  return 1;
}

