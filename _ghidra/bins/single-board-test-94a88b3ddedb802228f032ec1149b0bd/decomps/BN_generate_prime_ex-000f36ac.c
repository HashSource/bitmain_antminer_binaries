
int BN_generate_prime_ex(BIGNUM *ret,int bits,int safe,BIGNUM *add,BIGNUM *rem,BN_GENCB *cb)

{
  ushort uVar1;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *pBVar2;
  BIGNUM *rnd;
  BIGNUM *r_00;
  int iVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (bits < 0x514) {
    if (bits < 0x352) {
      if (bits < 0x28a) {
        if (bits < 0x226) {
          if (bits < 0x1c2) {
            if (bits < 400) {
              if (bits < 0x15e) {
                if (bits < 300) {
                  if (bits < 0xfa) {
                    if (bits < 200) {
                      if (bits < 0x96) {
                        iVar8 = 0x1b;
                      }
                      else {
                        iVar8 = 0x12;
                      }
                    }
                    else {
                      iVar8 = 0xf;
                    }
                  }
                  else {
                    iVar8 = 0xc;
                  }
                }
                else {
                  iVar8 = 9;
                }
              }
              else {
                iVar8 = 8;
              }
            }
            else {
              iVar8 = 7;
            }
          }
          else {
            iVar8 = 6;
          }
        }
        else {
          iVar8 = 5;
        }
      }
      else {
        iVar8 = 4;
      }
    }
    else {
      iVar8 = 3;
    }
  }
  else {
    iVar8 = 2;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    iVar8 = 0;
  }
  else {
    BN_CTX_start(ctx);
    r = BN_CTX_get(ctx);
    if (r == (BIGNUM *)0x0) {
LAB_000f37bc:
      iVar8 = 0;
    }
    else {
      iVar3 = 0;
LAB_000f3704:
      do {
        iVar7 = iVar3;
        if (add != (BIGNUM *)0x0) {
          if (safe == 0) {
            BN_CTX_start(ctx);
            pBVar2 = BN_CTX_get(ctx);
            if ((((pBVar2 != (BIGNUM *)0x0) && (iVar3 = BN_rand(ret,bits,0,1), iVar3 != 0)) &&
                (iVar3 = BN_div((BIGNUM *)0x0,pBVar2,ret,add,ctx), iVar3 != 0)) &&
               (iVar3 = BN_sub(ret,ret,pBVar2), iVar3 != 0)) {
              if (rem == (BIGNUM *)0x0) {
                iVar3 = BN_add_word(ret,1);
              }
              else {
                iVar3 = BN_add(ret,ret,rem);
              }
              if (iVar3 != 0) {
                iVar3 = 1;
                do {
                  while( true ) {
                    iVar6 = iVar3 * 2;
                    iVar3 = iVar3 + 1;
                    uVar5 = BN_mod_word(ret,(uint)*(ushort *)(&primes + iVar6));
                    if (1 < uVar5) break;
                    iVar3 = 1;
                    iVar6 = BN_add(ret,ret,add);
                    if (iVar6 == 0) goto LAB_000f373e;
                  }
                } while (iVar3 < 0x800);
                BN_CTX_end(ctx);
                goto LAB_000f39a2;
              }
            }
          }
          else {
            BN_CTX_start(ctx);
            pBVar2 = BN_CTX_get(ctx);
            rnd = BN_CTX_get(ctx);
            r_00 = BN_CTX_get(ctx);
            if (((r_00 != (BIGNUM *)0x0) && (iVar3 = BN_rshift1(r_00,add), iVar3 != 0)) &&
               ((iVar3 = BN_rand(rnd,bits + -1,0,1), iVar3 != 0 &&
                ((iVar3 = BN_div((BIGNUM *)0x0,pBVar2,rnd,r_00,ctx), iVar3 != 0 &&
                 (iVar3 = BN_sub(rnd,rnd,pBVar2), iVar3 != 0)))))) {
              if (rem == (BIGNUM *)0x0) {
                iVar3 = BN_add_word(rnd,1);
              }
              else {
                iVar3 = BN_rshift1(pBVar2,rem);
                if (iVar3 == 0) goto LAB_000f373e;
                iVar3 = BN_add(rnd,rnd,pBVar2);
              }
              if (((iVar3 != 0) && (iVar3 = BN_lshift1(ret,rnd), iVar3 != 0)) &&
                 (iVar3 = BN_add_word(ret,1), iVar3 != 0)) {
                iVar3 = 1;
                do {
                  while( true ) {
                    uVar1 = *(ushort *)(&primes + iVar3 * 2);
                    uVar5 = BN_mod_word(ret,(uint)uVar1);
                    if ((uVar5 != 0) && (uVar5 = BN_mod_word(rnd,(uint)uVar1), uVar5 != 0)) break;
                    iVar3 = 1;
                    iVar6 = BN_add(ret,ret,add);
                    if ((iVar6 == 0) || (iVar6 = BN_add(rnd,rnd,r_00), iVar6 == 0))
                    goto LAB_000f373e;
                  }
                  iVar3 = iVar3 + 1;
                } while (iVar3 < 0x800);
                BN_CTX_end(ctx);
                goto LAB_000f39a2;
              }
            }
          }
LAB_000f373e:
          iVar8 = 0;
          BN_CTX_end(ctx);
          goto LAB_000f3746;
        }
        iVar3 = probable_prime(ret,bits);
        if (iVar3 == 0) goto LAB_000f37bc;
LAB_000f39a2:
        iVar3 = iVar7 + 1;
        if (cb != (BN_GENCB *)0x0) {
          if (cb->ver == 1) {
            if ((cb->cb).cb_1 != (_func_556 *)0x0) {
              (*(cb->cb).cb_1)(0,iVar7,cb->arg);
            }
          }
          else if ((cb->ver != 2) || (iVar6 = (*(cb->cb).cb_1)(0,iVar7,cb), iVar6 == 0))
          goto LAB_000f37bc;
        }
        if (safe != 0) {
          iVar6 = BN_rshift1(r,ret);
          if (iVar6 == 0) goto LAB_000f37bc;
          if (cb == (BN_GENCB *)0x0) {
            iVar7 = 0;
            while( true ) {
              iVar7 = iVar7 + 1;
              iVar6 = BN_is_prime_fasttest_ex_constprop_1(ret,ctx,0);
              if (iVar6 == -1) goto LAB_000f37bc;
              if (iVar6 == 0) break;
              iVar6 = BN_is_prime_fasttest_ex_constprop_1(r,ctx,0);
              if (iVar6 == -1) goto LAB_000f37bc;
              if (iVar6 == 0) break;
              if (iVar8 <= iVar7) goto LAB_000f39fa;
            }
          }
          else {
            iVar6 = 0;
            while( true ) {
              iVar6 = iVar6 + 1;
              iVar4 = BN_is_prime_fasttest_ex_constprop_1(ret,ctx,cb);
              if (iVar4 == -1) goto LAB_000f37bc;
              if (iVar4 == 0) break;
              iVar4 = BN_is_prime_fasttest_ex_constprop_1(r,ctx,cb);
              if (iVar4 == -1) goto LAB_000f37bc;
              if (iVar4 == 0) break;
              if (cb->ver == 1) {
                if ((cb->cb).cb_1 != (_func_556 *)0x0) {
                  (*(cb->cb).cb_1)(2,iVar7,cb->arg);
                }
              }
              else if ((cb->ver != 2) || (iVar4 = (*(cb->cb).cb_1)(2,iVar7,cb), iVar4 == 0))
              goto LAB_000f37bc;
              if (iVar8 <= iVar6) goto LAB_000f39fa;
            }
          }
          goto LAB_000f3704;
        }
        iVar7 = BN_is_prime_fasttest_ex_constprop_2(ret,iVar8,ctx,cb);
        if (iVar7 == -1) goto LAB_000f37bc;
      } while (iVar7 == 0);
LAB_000f39fa:
      iVar8 = 1;
    }
LAB_000f3746:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  return iVar8;
}

