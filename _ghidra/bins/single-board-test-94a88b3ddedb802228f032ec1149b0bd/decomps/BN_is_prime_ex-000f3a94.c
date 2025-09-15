
int BN_is_prime_ex(BIGNUM *param_1,int param_2,BN_CTX *param_3,int *param_4)

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
  BN_CTX *ctx;
  
  pBVar1 = BN_value_one();
  iVar2 = BN_cmp(param_1,pBVar1);
  if (iVar2 < 1) {
    return 0;
  }
  if (param_2 == 0) {
    iVar2 = BN_num_bits(param_1);
    if (iVar2 < 0x514) {
      iVar2 = BN_num_bits(param_1);
      if (iVar2 < 0x352) {
        iVar2 = BN_num_bits(param_1);
        if (iVar2 < 0x28a) {
          iVar2 = BN_num_bits(param_1);
          if (iVar2 < 0x226) {
            iVar2 = BN_num_bits(param_1);
            if (iVar2 < 0x1c2) {
              iVar2 = BN_num_bits(param_1);
              if (iVar2 < 400) {
                iVar2 = BN_num_bits(param_1);
                if (iVar2 < 0x15e) {
                  iVar2 = BN_num_bits(param_1);
                  if (iVar2 < 300) {
                    iVar2 = BN_num_bits(param_1);
                    if (iVar2 < 0xfa) {
                      iVar2 = BN_num_bits(param_1);
                      if (iVar2 < 200) {
                        iVar2 = BN_num_bits(param_1);
                        if (iVar2 < 0x96) {
                          param_2 = 0x1b;
                        }
                        else {
                          param_2 = 0x12;
                        }
                      }
                      else {
                        param_2 = 0xf;
                      }
                    }
                    else {
                      param_2 = 0xc;
                    }
                  }
                  else {
                    param_2 = 9;
                  }
                }
                else {
                  param_2 = 8;
                }
              }
              else {
                param_2 = 7;
              }
            }
            else {
              param_2 = 6;
            }
          }
          else {
            param_2 = 5;
          }
        }
        else {
          param_2 = 4;
        }
      }
      else {
        param_2 = 3;
      }
    }
    else {
      param_2 = 2;
    }
  }
  if (param_1->top < 1) {
    return 0;
  }
  if ((*param_1->d & 1) == 0) {
    if ((param_1->top == 1) && (*param_1->d == 2)) {
      if (1 < (uint)param_1->neg) {
        return 0;
      }
      return 1 - param_1->neg;
    }
    return 0;
  }
  ctx = param_3;
  if ((param_3 == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
    return -1;
  }
  BN_CTX_start(ctx);
  pBVar1 = param_1;
  if (param_1->neg == 0) {
LAB_000f3472:
    a = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    rnd = BN_CTX_get(ctx);
    if (((rnd != (BIGNUM *)0x0) && (pBVar3 = BN_copy(a,pBVar1), pBVar3 != (BIGNUM *)0x0)) &&
       (iVar2 = BN_sub_word(a,1), iVar2 != 0)) {
      if (a->top == 0) {
        iVar2 = 0;
        mont = (BN_MONT_CTX *)0x0;
        goto LAB_000f3566;
      }
      iVar2 = 1;
      while (iVar4 = BN_is_bit_set(a,iVar2), iVar4 == 0) {
        iVar2 = iVar2 + 1;
      }
      iVar4 = BN_rshift(r,a,iVar2);
      if ((iVar4 != 0) && (mont = BN_MONT_CTX_new(), mont != (BN_MONT_CTX *)0x0)) {
        iVar4 = BN_MONT_CTX_set(mont,pBVar1,ctx);
        if (iVar4 == 0) {
LAB_000f354a:
          iVar2 = -1;
        }
        else if (param_2 < 1) {
          iVar2 = 1;
        }
        else {
          iVar4 = 0;
          do {
            iVar5 = BN_pseudo_rand_range(rnd,a);
            if ((iVar5 == 0) || (iVar5 = BN_add_word(rnd,1), iVar5 == 0)) goto LAB_000f354a;
            iVar5 = witness(rnd,pBVar1,a,r,iVar2,ctx,mont);
            if (iVar5 == -1) {
              iVar2 = -1;
              goto LAB_000f3566;
            }
            if (iVar5 != 0) {
              iVar2 = 0;
              goto LAB_000f3566;
            }
            if (param_4 != (int *)0x0) {
              if (*param_4 == 1) {
                if ((code *)param_4[2] != (code *)0x0) {
                  (*(code *)param_4[2])(1,iVar4,param_4[1]);
                }
              }
              else if ((*param_4 != 2) ||
                      (iVar5 = (*(code *)param_4[2])(1,iVar4,param_4), iVar5 == 0))
              goto LAB_000f354a;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 != param_2);
          iVar2 = 1;
        }
        goto LAB_000f3566;
      }
    }
  }
  else {
    pBVar1 = BN_CTX_get(ctx);
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_copy(pBVar1,param_1);
      pBVar1->neg = 0;
      goto LAB_000f3472;
    }
  }
  mont = (BN_MONT_CTX *)0x0;
  iVar2 = -1;
LAB_000f3566:
  BN_CTX_end(ctx);
  if (param_3 == (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(mont);
    return iVar2;
  }
  return iVar2;
}

