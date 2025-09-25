
int BN_nist_mod_192(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  uint *puVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  size_t __n;
  uint uVar7;
  ulong *rp;
  int iVar8;
  ulong *puVar9;
  uint local_40;
  uint local_3c;
  uint local_38;
  ulong auStack_34 [4];
  
  iVar8 = a->top;
  puVar9 = a->d;
  iVar1 = BN_is_negative(a);
  if ((iVar1 != 0) || (iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_192_sqr_9403), -1 < iVar1)) {
    iVar1 = BN_nnmod(r,a,(BIGNUM *)&_bignum_nist_p_192,ctx);
    return iVar1;
  }
  iVar1 = BN_ucmp((BIGNUM *)&_bignum_nist_p_192,a);
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
  rp = puVar9;
  if (a != r) {
    iVar1 = bn_wexpand(r,3);
    if (iVar1 == 0) {
      return 0;
    }
    rp = r->d;
    *rp = *puVar9;
    rp[1] = puVar9[1];
    rp[2] = puVar9[2];
  }
  if (iVar8 < 4) {
    iVar1 = 0;
    puVar3 = &local_40;
  }
  else {
    iVar1 = iVar8 + -3;
    puVar3 = (uint *)memcpy(&local_40,puVar9 + 3,(iVar8 + 0x3ffffffd) * 4);
    if (2 < iVar1) goto LAB_00187d9a;
  }
  __n = iVar1 * -4 + 0xc;
  if (2 < iVar1) {
    __n = 4;
  }
  memset(puVar3 + iVar1,0,__n);
LAB_00187d9a:
  uVar6 = (uint)CARRY4(local_40,*rp);
  *rp = local_40 + *rp;
  uVar7 = uVar6 + rp[1];
  uVar6 = (uint)CARRY4(uVar6,rp[1]) + (uint)CARRY4(local_3c,uVar7);
  uVar4 = uVar6 + rp[2];
  rp[1] = local_3c + uVar7;
  uVar7 = uVar4 + local_40;
  uVar6 = (uint)CARRY4(uVar6,rp[2]) + (uint)CARRY4(uVar4,local_40) + (uint)CARRY4(uVar7,local_38);
  rp[2] = uVar7 + local_38;
  uVar7 = uVar6 + rp[3];
  uVar4 = (uint)CARRY4(uVar6,rp[3]) + (uint)CARRY4(local_3c,uVar7);
  rp[3] = local_3c + uVar7;
  uVar6 = uVar4 + rp[4];
  uVar4 = (uint)CARRY4(uVar4,rp[4]) + (uint)CARRY4(uVar6,local_38);
  rp[4] = uVar6 + local_38;
  uVar6 = (uint)CARRY4(uVar4,rp[5]);
  rp[5] = uVar4 + rp[5];
  if (uVar6 == 0) {
    uVar6 = 0xffffffff;
  }
  else {
    uVar5 = bn_sub_words(rp,rp,(ulong *)(&_nist_p_192 + (uVar6 - 1) * 0xc),3);
    uVar6 = -uVar5;
  }
  uVar5 = bn_sub_words(auStack_34,rp,(ulong *)&_nist_p_192,3);
  puVar9 = (ulong *)((uint)auStack_34 ^ ((uint)rp ^ (uint)auStack_34) & uVar6 & -uVar5);
  *rp = *puVar9;
  rp[1] = puVar9[1];
  rp[2] = puVar9[2];
  r->top = 3;
  bn_correct_top(r);
  return 1;
}

