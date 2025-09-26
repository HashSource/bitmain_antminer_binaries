
BIGNUM * BN_mod_sqrt(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  int iVar1;
  ulong uVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  int iVar6;
  BIGNUM *pBVar7;
  code *pcVar8;
  BIGNUM *r_02;
  int iVar9;
  
  iVar1 = BN_is_odd(n);
  if ((iVar1 == 0) || (iVar1 = BN_abs_is_word(n,1), iVar1 != 0)) {
    iVar1 = BN_abs_is_word(n,2);
    if (iVar1 == 0) {
      ERR_put_error(3,0x79,0x70,"crypto/bn/bn_sqrt.c",0x2a);
      return (BIGNUM *)0x0;
    }
    if (ret != (BIGNUM *)0x0) {
      uVar2 = BN_is_bit_set(a,0);
      iVar1 = BN_set_word(ret,uVar2);
joined_r0x00198484:
      if (iVar1 != 0) {
        return ret;
      }
      return (BIGNUM *)0x0;
    }
    pBVar3 = BN_new();
    if (pBVar3 != (BIGNUM *)0x0) {
      uVar2 = BN_is_bit_set(a,0);
      iVar1 = BN_set_word(pBVar3,uVar2);
joined_r0x00198790:
      if (iVar1 != 0) {
        return pBVar3;
      }
      BN_free(pBVar3);
      return ret;
    }
  }
  else {
    iVar1 = BN_is_zero(a);
    if ((iVar1 == 0) && (iVar1 = BN_is_one(a), iVar1 == 0)) {
      BN_CTX_start(ctx);
      pBVar3 = BN_CTX_get(ctx);
      pBVar4 = BN_CTX_get(ctx);
      pBVar5 = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      r_00 = BN_CTX_get(ctx);
      r_01 = BN_CTX_get(ctx);
      if (r_01 != (BIGNUM *)0x0) {
        if (ret == (BIGNUM *)0x0) {
          pBVar7 = BN_new();
          if (pBVar7 != (BIGNUM *)0x0) {
            iVar1 = BN_nnmod(pBVar3,a,n,ctx);
            r_02 = pBVar7;
            if (iVar1 != 0) goto LAB_00198550;
LAB_001985ce:
            r_02 = (BIGNUM *)0x0;
            BN_clear_free(pBVar7);
            goto LAB_001984e6;
          }
        }
        else {
          iVar1 = BN_nnmod(pBVar3,a,n,ctx);
          r_02 = ret;
          if (iVar1 != 0) {
LAB_00198550:
            iVar1 = 1;
            while (iVar6 = BN_is_bit_set(n,iVar1), iVar6 == 0) {
              iVar1 = iVar1 + 1;
            }
            if (iVar1 == 1) {
              iVar1 = BN_rshift(pBVar5,n,2);
              if (iVar1 != 0) {
                pBVar5->neg = 0;
                iVar1 = BN_add_word(pBVar5,1);
                if (iVar1 != 0) {
                  pBVar4 = (BIGNUM *)BN_mod_exp(r_02,pBVar3,pBVar5,n,ctx);
joined_r0x00198710:
                  if ((pBVar4 != (BIGNUM *)0x0) && (iVar1 = BN_mod_sqr(r_00,r_02,n,ctx), iVar1 != 0)
                     ) {
                    iVar1 = BN_cmp(r_00,pBVar3);
                    if (iVar1 == 0) goto LAB_001984e6;
                    iVar1 = 0x15f;
LAB_001986ae:
                    ERR_put_error(3,0x79,0x6f,"crypto/bn/bn_sqrt.c",iVar1);
                  }
                }
              }
            }
            else if (iVar1 == 2) {
              iVar1 = BN_mod_lshift1_quick(r,pBVar3,n);
              if ((iVar1 != 0) && (iVar1 = BN_rshift(pBVar5,n,3), iVar1 != 0)) {
                pBVar5->neg = 0;
                iVar1 = BN_mod_exp(pBVar4,r,pBVar5,n,ctx);
                if ((iVar1 != 0) &&
                   ((((iVar1 = BN_mod_sqr(r_01,pBVar4,n,ctx), iVar1 != 0 &&
                      (iVar1 = BN_mod_mul(r,r,r_01,n,ctx), iVar1 != 0)) &&
                     (iVar1 = BN_sub_word(r,1), iVar1 != 0)) &&
                    ((iVar1 = BN_mod_mul(r_00,pBVar3,pBVar4,n,ctx), iVar1 != 0 &&
                     (iVar1 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar1 != 0)))))) {
LAB_0019867c:
                  pBVar4 = BN_copy(r_02,r_00);
                  goto joined_r0x00198710;
                }
              }
            }
            else {
              pBVar7 = BN_copy(pBVar5,n);
              if (pBVar7 != (BIGNUM *)0x0) {
                uVar2 = 2;
                pBVar5->neg = 0;
                do {
                  if ((int)uVar2 < 0x16) {
LAB_001985be:
                    iVar6 = BN_set_word(r_01,uVar2);
                    if (iVar6 == 0) goto LAB_001985ca;
                  }
                  else {
                    iVar6 = BN_num_bits(n);
                    iVar6 = BN_priv_rand(r_01,iVar6,0);
                    if (iVar6 == 0) goto LAB_001985ca;
                    iVar6 = BN_ucmp(r_01,n);
                    if (-1 < iVar6) {
                      if (n->neg == 0) {
                        pcVar8 = (code *)0x191169;
                      }
                      else {
                        pcVar8 = (code *)0x191115;
                      }
                      iVar6 = (*pcVar8)(r_01,r_01,n);
                      if (iVar6 == 0) goto LAB_001985ca;
                    }
                    iVar6 = BN_is_zero(r_01);
                    if (iVar6 != 0) goto LAB_001985be;
                  }
                  iVar6 = BN_kronecker(r_01,pBVar5,ctx);
                  if (iVar6 + 1 < 0 != SCARRY4(iVar6,1)) goto LAB_001985ca;
                  if (iVar6 == 0) {
                    iVar1 = 0xc9;
LAB_00198768:
                    ERR_put_error(3,0x79,0x70,"crypto/bn/bn_sqrt.c",iVar1);
                    goto LAB_001985ca;
                  }
                  if (iVar6 != 1) {
                    if (iVar6 == -1) {
                      iVar6 = BN_rshift(pBVar5,pBVar5,iVar1);
                      if ((iVar6 == 0) || (iVar6 = BN_mod_exp(r_01,r_01,pBVar5,n,ctx), iVar6 == 0))
                      goto LAB_001985ca;
                      iVar6 = BN_is_one(r_01);
                      if (iVar6 != 0) {
                        iVar1 = 0xe4;
                        goto LAB_00198768;
                      }
                      iVar6 = BN_rshift1(r,pBVar5);
                      if (iVar6 == 0) goto LAB_001985ca;
                      iVar6 = BN_is_zero(r);
                      if (iVar6 == 0) {
                        iVar6 = BN_mod_exp(r_00,pBVar3,r,n,ctx);
                        if (iVar6 == 0) goto LAB_001985ca;
                        iVar6 = BN_is_zero(r_00);
                        if (iVar6 != 0) goto LAB_00198964;
                      }
                      else {
                        iVar6 = BN_nnmod(r,pBVar3,n,ctx);
                        if (iVar6 == 0) goto LAB_001985ca;
                        iVar6 = BN_is_zero(r);
                        if (iVar6 != 0) {
LAB_00198964:
                          BN_set_word(r_02,0);
                          goto LAB_001984e6;
                        }
                        iVar6 = BN_set_word(r_00,1);
                        if (iVar6 == 0) goto LAB_001985ca;
                      }
                      iVar6 = BN_mod_sqr(pBVar4,r_00,n,ctx);
                      if ((iVar6 == 0) ||
                         (iVar6 = BN_mod_mul(pBVar4,pBVar4,pBVar3,n,ctx), iVar6 == 0))
                      goto LAB_001985ca;
                      iVar6 = BN_mod_mul(r_00,r_00,pBVar3,n,ctx);
                      goto joined_r0x00198864;
                    }
                    break;
                  }
                  uVar2 = uVar2 + 1;
                } while (uVar2 != 0x52);
                ERR_put_error(3,0x79,0x71,"crypto/bn/bn_sqrt.c",0xd5);
              }
            }
LAB_001985ca:
            pBVar7 = r_02;
            if (ret != r_02) goto LAB_001985ce;
          }
        }
      }
    }
    else {
      if (ret != (BIGNUM *)0x0) {
        uVar2 = BN_is_one(a);
        iVar1 = BN_set_word(ret,uVar2);
        goto joined_r0x00198484;
      }
      pBVar3 = BN_new();
      if (pBVar3 != (BIGNUM *)0x0) {
        uVar2 = BN_is_one(a);
        iVar1 = BN_set_word(pBVar3,uVar2);
        goto joined_r0x00198790;
      }
    }
  }
  r_02 = (BIGNUM *)0x0;
LAB_001984e6:
  BN_CTX_end(ctx);
  return r_02;
joined_r0x00198864:
  if (iVar6 == 0) goto LAB_001985ca;
  iVar6 = BN_is_one(pBVar4);
  if (iVar6 != 0) goto LAB_0019867c;
  iVar9 = 1;
  while( true ) {
    if (iVar1 == iVar9) {
      iVar1 = 0x140;
      goto LAB_001986ae;
    }
    if (iVar9 == 1) {
      iVar6 = BN_mod_sqr(r,pBVar4,n,ctx);
    }
    else {
      iVar6 = BN_mod_mul(r,r,r,n,ctx);
    }
    if (iVar6 == 0) goto LAB_001985ca;
    iVar6 = BN_is_one(r);
    if (iVar6 != 0) break;
    iVar9 = iVar9 + 1;
  }
  pBVar5 = BN_copy(r,r_01);
  if (pBVar5 == (BIGNUM *)0x0) goto LAB_001985ca;
  iVar1 = iVar1 - iVar9;
  while (iVar1 = iVar1 + -1, 0 < iVar1) {
    iVar6 = BN_mod_sqr(r,r,n,ctx);
    if (iVar6 == 0) goto LAB_001985ca;
  }
  iVar1 = BN_mod_mul(r_01,r,r,n,ctx);
  if ((iVar1 == 0) || (iVar1 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar1 == 0)) goto LAB_001985ca;
  iVar6 = BN_mod_mul(pBVar4,pBVar4,r_01,n,ctx);
  iVar1 = iVar9;
  goto joined_r0x00198864;
}

