
int BN_is_prime_fasttest_ex(BIGNUM *p,int nchecks,BN_CTX *ctx,int do_trial_division,BN_GENCB *cb)

{
  ushort uVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *a_00;
  BIGNUM *pBVar4;
  ulong uVar5;
  BN_CTX *ctx_00;
  int iVar6;
  ushort *puVar7;
  BN_MONT_CTX *mont;
  int n;
  int local_30;
  
  iVar2 = BN_is_word(p,2);
  if ((iVar2 != 0) || (iVar2 = BN_is_word(p,3), iVar2 != 0)) {
    return 1;
  }
  iVar2 = BN_is_odd(p);
  if (iVar2 == 0) {
    return 0;
  }
  pBVar3 = BN_value_one();
  iVar2 = BN_cmp(p,pBVar3);
  if (iVar2 < 1) {
    return 0;
  }
  if (nchecks == 0) {
    iVar2 = BN_num_bits(p);
    if (iVar2 < 0xea3) {
      iVar2 = BN_num_bits(p);
      if (iVar2 < 0x541) {
        iVar2 = BN_num_bits(p);
        if (iVar2 < 0x1dc) {
          iVar2 = BN_num_bits(p);
          if (iVar2 < 400) {
            iVar2 = BN_num_bits(p);
            if (iVar2 < 0x15b) {
              iVar2 = BN_num_bits(p);
              if (iVar2 < 0x134) {
                iVar2 = BN_num_bits(p);
                if (iVar2 < 0x37) {
                  nchecks = 0x22;
                }
                else {
                  nchecks = 0x1b;
                }
              }
              else {
                nchecks = 8;
              }
            }
            else {
              nchecks = 7;
            }
          }
          else {
            nchecks = 6;
          }
        }
        else {
          nchecks = 5;
        }
      }
      else {
        nchecks = 4;
      }
    }
    else {
      nchecks = 3;
    }
  }
  if (do_trial_division == 0) {
LAB_0018cd9c:
    ctx_00 = ctx;
    if ((ctx != (BN_CTX *)0x0) || (ctx_00 = BN_CTX_new(), ctx_00 != (BN_CTX *)0x0)) {
      BN_CTX_start(ctx_00);
      pBVar3 = BN_CTX_get(ctx_00);
      a = BN_CTX_get(ctx_00);
      r = BN_CTX_get(ctx_00);
      a_00 = BN_CTX_get(ctx_00);
      if ((((a_00 == (BIGNUM *)0x0) || (pBVar4 = BN_copy(pBVar3,p), pBVar4 == (BIGNUM *)0x0)) ||
          (iVar2 = BN_sub_word(pBVar3,1), iVar2 == 0)) ||
         (pBVar4 = BN_copy(a,p), pBVar4 == (BIGNUM *)0x0)) {
LAB_0018cde0:
        mont = (BN_MONT_CTX *)0x0;
        iVar2 = -1;
      }
      else {
        iVar2 = BN_sub_word(a,3);
        n = 1;
        if (iVar2 == 0) goto LAB_0018cde0;
        while (iVar2 = BN_is_bit_set(pBVar3,n), iVar2 == 0) {
          n = n + 1;
        }
        iVar2 = BN_rshift(r,pBVar3,n);
        if ((iVar2 == 0) || (mont = BN_MONT_CTX_new(), mont == (BN_MONT_CTX *)0x0))
        goto LAB_0018cde0;
        iVar2 = BN_MONT_CTX_set(mont,p,ctx_00);
        if (iVar2 == 0) {
LAB_0018cf9c:
          iVar2 = -1;
        }
        else {
          if (0 < nchecks) {
            local_30 = 0;
            do {
              iVar2 = BN_priv_rand_range(a_00,a);
              if (((iVar2 == 0) || (iVar2 = BN_add_word(a_00,2), iVar2 == 0)) ||
                 (iVar2 = BN_mod_exp_mont(a_00,a_00,r,p,ctx_00,mont), iVar2 == 0))
              goto LAB_0018cf9c;
              iVar2 = BN_is_one(a_00);
              if (iVar2 == 0) {
                iVar6 = BN_cmp(a_00,pBVar3);
                iVar2 = n;
                while (iVar6 != 0) {
                  iVar2 = iVar2 + -1;
                  if (iVar2 == 0) {
LAB_0018cf78:
                    iVar2 = 0;
                    goto LAB_0018cde8;
                  }
                  iVar6 = BN_mod_mul(a_00,a_00,a_00,p,ctx_00);
                  if (iVar6 == 0) goto LAB_0018cf9c;
                  iVar6 = BN_is_one(a_00);
                  if (iVar6 != 0) goto LAB_0018cf78;
                  iVar6 = BN_cmp(a_00,pBVar3);
                }
              }
              iVar2 = BN_GENCB_call(cb,1,local_30);
              if (iVar2 == 0) goto LAB_0018cf9c;
              local_30 = local_30 + 1;
            } while (local_30 != nchecks);
          }
          iVar2 = 1;
        }
      }
LAB_0018cde8:
      BN_CTX_end(ctx_00);
      if (ctx == (BN_CTX *)0x0) {
        BN_CTX_free(ctx_00);
      }
      goto LAB_0018cdf4;
    }
  }
  else {
    puVar7 = (ushort *)&primes;
    do {
      puVar7 = puVar7 + 1;
      uVar1 = *puVar7;
      uVar5 = BN_mod_word(p,(uint)uVar1);
      if (uVar5 == 0xffffffff) goto LAB_0018ce66;
      if (uVar5 == 0) {
        iVar2 = BN_is_word(p,(uint)uVar1);
        return iVar2;
      }
    } while (puVar7 != (ushort *)&UNK_00226372);
    iVar2 = BN_GENCB_call(cb,1,-1);
    if (iVar2 != 0) goto LAB_0018cd9c;
  }
LAB_0018ce66:
  iVar2 = -1;
  mont = (BN_MONT_CTX *)0x0;
LAB_0018cdf4:
  BN_MONT_CTX_free(mont);
  return iVar2;
}

