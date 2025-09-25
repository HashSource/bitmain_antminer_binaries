
undefined4 DH_get_nid(int param_1)

{
  ulong uVar1;
  int iVar2;
  BIGNUM *r;
  undefined4 uVar3;
  
  uVar1 = BN_get_word(*(BIGNUM **)(param_1 + 0xc));
  if (uVar1 != 2) {
    return 0;
  }
  iVar2 = BN_cmp(*(BIGNUM **)(param_1 + 8),(BIGNUM *)_bignum_ffdhe2048_p);
  if (iVar2 == 0) {
    uVar3 = 0x466;
  }
  else {
    iVar2 = BN_cmp(*(BIGNUM **)(param_1 + 8),(BIGNUM *)_bignum_ffdhe3072_p);
    if (iVar2 == 0) {
      uVar3 = 0x467;
    }
    else {
      iVar2 = BN_cmp(*(BIGNUM **)(param_1 + 8),(BIGNUM *)_bignum_ffdhe4096_p);
      if (iVar2 == 0) {
        uVar3 = 0x468;
      }
      else {
        iVar2 = BN_cmp(*(BIGNUM **)(param_1 + 8),(BIGNUM *)_bignum_ffdhe6144_p);
        if (iVar2 == 0) {
          uVar3 = 0x469;
        }
        else {
          uVar3 = 0x46a;
          iVar2 = BN_cmp(*(BIGNUM **)(param_1 + 8),(BIGNUM *)&_bignum_ffdhe8192_p);
          if (iVar2 != 0) {
            return 0;
          }
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    return uVar3;
  }
  r = BN_dup(*(BIGNUM **)(param_1 + 8));
  if (((r == (BIGNUM *)0x0) || (iVar2 = BN_rshift1(r,r), iVar2 == 0)) ||
     (iVar2 = BN_cmp(*(BIGNUM **)(param_1 + 0x24),r), iVar2 == 0)) {
    uVar3 = 0;
  }
  BN_free(r);
  return uVar3;
}

