
undefined4 generate_key(int param_1)

{
  bool bVar1;
  int iVar2;
  BN_CTX *ctx;
  BIGNUM *a;
  BN_MONT_CTX *pBVar3;
  BIGNUM *a_00;
  undefined4 uVar4;
  BIGNUM *a_01;
  
  iVar2 = BN_num_bits(*(BIGNUM **)(param_1 + 8));
  if (10000 < iVar2) {
    ERR_put_error(5,0x67,0x67,"crypto/dh/dh_key.c",0x71);
    return 0;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
LAB_001135fc:
    a_00 = (BIGNUM *)0x0;
    a_01 = (BIGNUM *)0x0;
  }
  else {
    a_00 = *(BIGNUM **)(param_1 + 0x18);
    bVar1 = false;
    if (a_00 == (BIGNUM *)0x0) {
      a_00 = (BIGNUM *)BN_secure_new();
      bVar1 = true;
      if (a_00 == (BIGNUM *)0x0) goto LAB_001135fc;
    }
    a_01 = *(BIGNUM **)(param_1 + 0x14);
    if ((a_01 != (BIGNUM *)0x0) || (a_01 = BN_new(), a_01 != (BIGNUM *)0x0)) {
      if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
        pBVar3 = (BN_MONT_CTX *)0x0;
      }
      else {
        pBVar3 = BN_MONT_CTX_set_locked
                           ((BN_MONT_CTX **)(param_1 + 0x20),*(int *)(param_1 + 0x48),
                            *(BIGNUM **)(param_1 + 8),ctx);
        if (pBVar3 == (BN_MONT_CTX *)0x0) goto LAB_0011353a;
      }
      if (bVar1) {
        iVar2 = *(int *)(param_1 + 0x24);
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 0x10);
          if (iVar2 == 0) {
            iVar2 = BN_num_bits(*(BIGNUM **)(param_1 + 8));
            iVar2 = iVar2 + -1;
          }
          iVar2 = BN_priv_rand(a_00,iVar2,0);
          if ((iVar2 != 0) &&
             (((iVar2 = BN_is_word(*(undefined4 *)(param_1 + 0xc),2), iVar2 == 0 ||
               (iVar2 = BN_is_bit_set(*(BIGNUM **)(param_1 + 8),2), iVar2 != 0)) ||
              (iVar2 = BN_clear_bit(a_00,0), iVar2 != 0)))) goto LAB_0011359c;
        }
        else {
          while (iVar2 = BN_priv_rand_range(a_00,iVar2), iVar2 != 0) {
            iVar2 = BN_is_zero(a_00);
            if ((iVar2 == 0) && (iVar2 = BN_is_one(a_00), iVar2 == 0)) goto LAB_0011359c;
            iVar2 = *(int *)(param_1 + 0x24);
          }
        }
      }
      else {
LAB_0011359c:
        a = BN_new();
        if (a != (BIGNUM *)0x0) {
          BN_with_flags(a,a_00,4);
          iVar2 = (**(code **)(*(int *)(param_1 + 0x40) + 0xc))
                            (param_1,a_01,*(undefined4 *)(param_1 + 0xc),a,
                             *(undefined4 *)(param_1 + 8),ctx,pBVar3);
          if (iVar2 != 0) {
            uVar4 = 1;
            BN_clear_free(a);
            *(BIGNUM **)(param_1 + 0x14) = a_01;
            *(BIGNUM **)(param_1 + 0x18) = a_00;
            goto LAB_0011356a;
          }
          BN_clear_free(a);
        }
      }
    }
  }
LAB_0011353a:
  ERR_put_error(5,0x67,3,"crypto/dh/dh_key.c",0xbb);
  if (*(BIGNUM **)(param_1 + 0x14) != a_01) {
    BN_free(a_01);
  }
  if (*(BIGNUM **)(param_1 + 0x18) == a_00) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    BN_free(a_00);
  }
LAB_0011356a:
  BN_CTX_free(ctx);
  return uVar4;
}

