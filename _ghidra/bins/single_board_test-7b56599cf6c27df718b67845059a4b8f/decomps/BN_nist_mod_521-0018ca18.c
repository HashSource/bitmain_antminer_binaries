
int BN_nist_mod_521(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  ulong uVar3;
  size_t __n;
  ulong *rp;
  int iVar4;
  ulong *puVar5;
  ulong local_44 [4];
  ulong local_34;
  ulong local_30;
  ulong local_2c;
  ulong local_28;
  ulong local_24;
  
  iVar4 = a->top;
  puVar5 = a->d;
  iVar1 = BN_is_negative(a);
  if ((iVar1 != 0) || (iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_521_sqr_9535), -1 < iVar1)) {
    iVar4 = BN_nnmod(r,a,(BIGNUM *)_bignum_nist_p_521,ctx);
    return iVar4;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_521,a);
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
    iVar1 = bn_wexpand(r,9);
    if (iVar1 == 0) {
      return 0;
    }
    rp = r->d;
    *rp = *puVar5;
    rp[1] = puVar5[1];
    rp[2] = puVar5[2];
    rp[3] = puVar5[3];
    rp[4] = puVar5[4];
    rp[5] = puVar5[5];
    rp[6] = puVar5[6];
    rp[7] = puVar5[7];
    rp[8] = puVar5[8];
  }
  iVar4 = iVar4 + -8;
  if (iVar4 < 1) {
    iVar4 = 0;
  }
  else {
    local_44[0] = puVar5[8];
    if (((((iVar4 != 1) && (local_44[1] = puVar5[9], iVar4 != 2)) &&
         (local_44[2] = puVar5[10], iVar4 != 3)) &&
        ((local_44[3] = puVar5[0xb], iVar4 != 4 && (local_34 = puVar5[0xc], iVar4 != 5)))) &&
       ((local_30 = puVar5[0xd], iVar4 != 6 &&
        ((local_2c = puVar5[0xe], iVar4 != 7 && (local_28 = puVar5[0xf], iVar4 != 8)))))) {
      local_24 = puVar5[0x10];
    }
    if (8 < iVar4) goto LAB_0018cb6e;
  }
  __n = iVar4 * -4 + 0x24;
  if (8 < iVar4) {
    __n = 4;
  }
  memset(local_44 + iVar4,0,__n);
LAB_0018cb6e:
  local_44[0] = local_44[0] >> 9;
  local_44[1] = local_44[1] >> 9;
  local_34 = local_34 >> 9;
  local_44[2] = local_44[2] >> 9;
  local_44[3] = local_44[3] >> 9;
  local_2c = local_2c >> 9;
  local_28 = local_28 >> 9;
  local_30 = local_30 >> 9;
  local_24 = local_24 >> 9;
  rp[8] = 0;
  bn_add_words(rp,rp,local_44,9);
  uVar3 = bn_sub_words(local_44,rp,(ulong *)_nist_p_521,9);
  puVar5 = (ulong *)((uint)local_44 ^ -uVar3 & ((uint)rp ^ (uint)local_44));
  *rp = *puVar5;
  rp[1] = puVar5[1];
  rp[2] = puVar5[2];
  rp[3] = puVar5[3];
  rp[4] = puVar5[4];
  rp[5] = puVar5[5];
  rp[6] = puVar5[6];
  rp[7] = puVar5[7];
  rp[8] = puVar5[8];
  r->top = 9;
  bn_correct_top(r);
  return 1;
}

