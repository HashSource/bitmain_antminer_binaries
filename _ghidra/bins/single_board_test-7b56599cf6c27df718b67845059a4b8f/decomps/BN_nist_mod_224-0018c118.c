
int BN_nist_mod_224(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  ulong uVar3;
  size_t __n;
  ulong *rp;
  int iVar4;
  ulong *puVar5;
  ulong local_40 [4];
  ulong local_30 [4];
  
  iVar4 = a->top;
  puVar5 = a->d;
  iVar1 = BN_is_negative(a);
  if ((iVar1 != 0) || (iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_224_sqr_9442), -1 < iVar1)) {
    iVar4 = BN_nnmod(r,a,(BIGNUM *)_bignum_nist_p_224,ctx);
    return iVar4;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_224,a);
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
  rp = puVar5;
  if (a != r) {
    iVar1 = bn_wexpand(r,4);
    if (iVar1 == 0) {
      return 0;
    }
    rp = r->d;
    *rp = *puVar5;
    rp[1] = puVar5[1];
    rp[2] = puVar5[2];
    rp[3] = puVar5[3];
  }
  iVar4 = iVar4 + -3;
  if (iVar4 < 1) {
    iVar4 = 0;
  }
  else {
    local_40[0] = puVar5[3];
    if (((iVar4 != 1) && (local_40[1] = puVar5[4], iVar4 != 2)) &&
       (local_40[2] = puVar5[5], iVar4 != 3)) {
      local_40[3] = puVar5[6];
    }
    if (3 < iVar4) goto LAB_0018c210;
  }
  __n = iVar4 * -4 + 0x10;
  if (3 < iVar4) {
    __n = 4;
  }
  memset(local_40 + iVar4,0,__n);
LAB_0018c210:
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  bn_add_words(rp,rp,local_30,4);
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  bn_add_words(rp,rp,local_30,4);
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  bn_sub_words(rp,rp,local_30,4);
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  bn_sub_words(rp,rp,local_30,4);
  uVar3 = bn_sub_words(local_40,rp,(ulong *)_nist_p_224,4);
  puVar5 = (ulong *)((uint)local_40 ^ ((uint)rp ^ (uint)local_40) & -uVar3);
  *rp = *puVar5;
  rp[1] = puVar5[1];
  rp[2] = puVar5[2];
  rp[3] = puVar5[3];
  r->top = 4;
  bn_correct_top(r);
  return 1;
}

