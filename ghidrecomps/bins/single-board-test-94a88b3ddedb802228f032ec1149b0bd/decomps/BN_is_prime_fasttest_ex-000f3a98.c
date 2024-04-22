
int BN_is_prime_fasttest_ex(BIGNUM *p,int nchecks,BN_CTX *ctx,int do_trial_division,BN_GENCB *cb)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *rnd;
  BIGNUM *pBVar3;
  int iVar4;
  BN_MONT_CTX *mont;
  int iVar5;
  ulong uVar6;
  BN_CTX *ctx_00;
  ushort *puVar7;
  ushort *puVar8;
  
  pBVar1 = BN_value_one();
  iVar2 = BN_cmp(p,pBVar1);
  if (iVar2 < 1) {
    return 0;
  }
  if (nchecks == 0) {
    iVar2 = BN_num_bits(p);
    if (iVar2 < 0x514) {
      iVar2 = BN_num_bits(p);
      if (iVar2 < 0x352) {
        iVar2 = BN_num_bits(p);
        if (iVar2 < 0x28a) {
          iVar2 = BN_num_bits(p);
          if (iVar2 < 0x226) {
            iVar2 = BN_num_bits(p);
            if (iVar2 < 0x1c2) {
              iVar2 = BN_num_bits(p);
              if (iVar2 < 400) {
                iVar2 = BN_num_bits(p);
                if (iVar2 < 0x15e) {
                  iVar2 = BN_num_bits(p);
                  if (iVar2 < 300) {
                    iVar2 = BN_num_bits(p);
                    if (iVar2 < 0xfa) {
                      iVar2 = BN_num_bits(p);
                      if (iVar2 < 200) {
                        iVar2 = BN_num_bits(p);
                        if (iVar2 < 0x96) {
                          nchecks = 0x1b;
                        }
                        else {
                          nchecks = 0x12;
                        }
                      }
                      else {
                        nchecks = 0xf;
                      }
                    }
                    else {
                      nchecks = 0xc;
                    }
                  }
                  else {
                    nchecks = 9;
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
    else {
      nchecks = 2;
    }
  }
  if (p->top < 1) {
    return 0;
  }
  if ((*p->d & 1) == 0) {
    if (p->top != 1) {
      return 0;
    }
    if (*p->d != 2) {
      return 0;
    }
    if (1 < (uint)p->neg) {
      return 0;
    }
    return 1 - p->neg;
  }
  if (do_trial_division != 0) {
    puVar8 = DAT_000f3da8 + 0x7ff;
    puVar7 = DAT_000f3da8;
    do {
      puVar7 = puVar7 + 1;
      uVar6 = BN_mod_word(p,(uint)*puVar7);
      if (uVar6 == 0) {
        return 0;
      }
    } while (puVar7 != puVar8);
    if (cb != (BN_GENCB *)0x0) {
      if (cb->ver == 1) {
        if ((cb->cb).cb_1 != (_func_556 *)0x0) {
          (*(cb->cb).cb_1)(1,-1,cb->arg);
        }
      }
      else {
        if (cb->ver != 2) {
          return -1;
        }
        iVar2 = (*(cb->cb).cb_1)(1,-1,cb);
        if (iVar2 == 0) {
          return -1;
        }
      }
    }
  }
  ctx_00 = ctx;
  if ((ctx == (BN_CTX *)0x0) && (ctx_00 = BN_CTX_new(), ctx_00 == (BN_CTX *)0x0)) {
    return -1;
  }
  BN_CTX_start(ctx_00);
  pBVar1 = p;
  if (p->neg == 0) {
LAB_000f3b14:
    a = BN_CTX_get(ctx_00);
    r = BN_CTX_get(ctx_00);
    rnd = BN_CTX_get(ctx_00);
    if (((rnd != (BIGNUM *)0x0) && (pBVar3 = BN_copy(a,pBVar1), pBVar3 != (BIGNUM *)0x0)) &&
       (iVar2 = BN_sub_word(a,1), iVar2 != 0)) {
      if (a->top == 0) {
        iVar2 = 0;
        mont = (BN_MONT_CTX *)0x0;
        goto LAB_000f3ca4;
      }
      iVar2 = 1;
      while (iVar4 = BN_is_bit_set(a,iVar2), iVar4 == 0) {
        iVar2 = iVar2 + 1;
      }
      iVar4 = BN_rshift(r,a,iVar2);
      if ((iVar4 != 0) && (mont = BN_MONT_CTX_new(), mont != (BN_MONT_CTX *)0x0)) {
        iVar4 = BN_MONT_CTX_set(mont,pBVar1,ctx_00);
        if (iVar4 == 0) {
LAB_000f3bf4:
          iVar2 = -1;
        }
        else if (nchecks < 1) {
          iVar2 = 1;
        }
        else {
          iVar4 = 0;
          do {
            iVar5 = BN_pseudo_rand_range(rnd,a);
            if ((iVar5 == 0) || (iVar5 = BN_add_word(rnd,1), iVar5 == 0)) goto LAB_000f3bf4;
            iVar5 = witness(rnd,pBVar1,a,r,iVar2,ctx_00,mont);
            if (iVar5 == -1) {
              iVar2 = -1;
              goto LAB_000f3ca4;
            }
            if (iVar5 != 0) {
              iVar2 = 0;
              goto LAB_000f3ca4;
            }
            if (cb != (BN_GENCB *)0x0) {
              if (cb->ver == 1) {
                if ((cb->cb).cb_1 != (_func_556 *)0x0) {
                  (*(cb->cb).cb_1)(1,iVar4,cb->arg);
                }
              }
              else if ((cb->ver != 2) || (iVar5 = (*(cb->cb).cb_1)(1,iVar4,cb), iVar5 == 0))
              goto LAB_000f3bf4;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 != nchecks);
          iVar2 = 1;
        }
        goto LAB_000f3ca4;
      }
    }
  }
  else {
    pBVar1 = BN_CTX_get(ctx_00);
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_copy(pBVar1,p);
      pBVar1->neg = 0;
      goto LAB_000f3b14;
    }
  }
  mont = (BN_MONT_CTX *)0x0;
  iVar2 = -1;
LAB_000f3ca4:
  BN_CTX_end(ctx_00);
  if (ctx == (BN_CTX *)0x0) {
    BN_CTX_free(ctx_00);
  }
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(mont);
    return iVar2;
  }
  return iVar2;
}

