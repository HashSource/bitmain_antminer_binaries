
/* WARNING: Type propagation algorithm not settling */

BIGNUM * BN_mod_sqrt(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  code *pcVar1;
  ulong uVar2;
  BIGNUM *pBVar3;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  int iVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  BIGNUM *r_02;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar8 = n->top;
  if (iVar8 < 1) {
LAB_00121ff6:
    ERR_put_error(3,0x79,0x70,DAT_00122274,0x5b);
    return (BIGNUM *)0x0;
  }
  uVar9 = *n->d;
  if ((uVar9 & 1) == 0) {
    if ((iVar8 != 1) || (uVar9 != 2)) goto LAB_00121ff6;
    if (ret != (BIGNUM *)0x0) {
      uVar2 = BN_is_bit_set(a,0);
      iVar8 = BN_set_word(ret,uVar2);
      if (iVar8 == 0) {
        return (BIGNUM *)0x0;
      }
      return ret;
    }
    pBVar6 = BN_new();
    if (pBVar6 != (BIGNUM *)0x0) {
      uVar2 = BN_is_bit_set(a,0);
      pBVar7 = (BIGNUM *)BN_set_word(pBVar6,uVar2);
      if (pBVar7 != (BIGNUM *)0x0) {
        return pBVar6;
      }
      goto LAB_00121fe8;
    }
  }
  else {
    if ((iVar8 == 1) && (uVar9 == 1)) goto LAB_00121ff6;
    iVar8 = a->top;
    if ((iVar8 == 0) || (((iVar8 == 1 && (*a->d == 1)) && (a->neg == 0)))) {
      pBVar6 = ret;
      if (ret == (BIGNUM *)0x0) {
        pBVar6 = BN_new();
        if (pBVar6 == (BIGNUM *)0x0) goto LAB_0012206a;
        iVar8 = a->top;
      }
      if ((iVar8 == 1) && (*a->d == 1)) {
        uVar2 = 1 - a->neg;
        if (1 < (uint)a->neg) {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
      iVar8 = BN_set_word(pBVar6,uVar2);
      if (iVar8 != 0) {
        return pBVar6;
      }
      pBVar7 = (BIGNUM *)0x0;
      if (pBVar6 == ret) {
        return (BIGNUM *)0x0;
      }
LAB_00121fe8:
      BN_free(pBVar6);
      return pBVar7;
    }
    BN_CTX_start(ctx);
    pBVar6 = BN_CTX_get(ctx);
    pBVar7 = BN_CTX_get(ctx);
    pBVar3 = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = BN_CTX_get(ctx);
    if ((r_01 != (BIGNUM *)0x0) &&
       ((r_02 = ret, ret != (BIGNUM *)0x0 || (r_02 = BN_new(), r_02 != (BIGNUM *)0x0)))) {
      iVar8 = BN_nnmod(pBVar6,a,n,ctx);
      if (iVar8 != 0) {
        iVar8 = 1;
        while (iVar4 = BN_is_bit_set(n,iVar8), iVar4 == 0) {
          iVar8 = iVar8 + 1;
        }
        if (iVar8 == 1) {
          iVar8 = BN_rshift(pBVar3,n,2);
          if (iVar8 != 0) {
            pBVar3->neg = 0;
            iVar8 = BN_add_word(pBVar3,1);
            if (iVar8 != 0) {
              pBVar7 = (BIGNUM *)BN_mod_exp(r_02,pBVar6,pBVar3,n,ctx);
joined_r0x0012222e:
              if ((pBVar7 != (BIGNUM *)0x0) && (iVar8 = BN_mod_sqr(r_00,r_02,n,ctx), iVar8 != 0)) {
                iVar8 = BN_cmp(r_00,pBVar6);
                if (iVar8 == 0) goto LAB_0012206c;
                iVar8 = 0x18a;
LAB_00122256:
                ERR_put_error(3,0x79,0x6f,DAT_00122274,iVar8);
              }
            }
          }
        }
        else if (iVar8 == 2) {
          iVar8 = BN_mod_lshift1_quick(r,pBVar6,n);
          if ((iVar8 != 0) && (iVar8 = BN_rshift(pBVar3,n,3), iVar8 != 0)) {
            pBVar3->neg = 0;
            iVar8 = BN_mod_exp(pBVar7,r,pBVar3,n,ctx);
            if ((iVar8 != 0) &&
               ((((iVar8 = BN_mod_sqr(r_01,pBVar7,n,ctx), iVar8 != 0 &&
                  (iVar8 = BN_mod_mul(r,r,r_01,n,ctx), iVar8 != 0)) &&
                 (iVar8 = BN_sub_word(r,1), iVar8 != 0)) &&
                ((iVar8 = BN_mod_mul(r_00,pBVar6,pBVar7,n,ctx), iVar8 != 0 &&
                 (iVar8 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar8 != 0)))))) {
LAB_00122224:
              pBVar7 = BN_copy(r_02,r_00);
              goto joined_r0x0012222e;
            }
          }
        }
        else {
          pBVar5 = BN_copy(pBVar3,n);
          if (pBVar5 != (BIGNUM *)0x0) {
            uVar2 = 2;
            pBVar3->neg = 0;
            do {
              if ((int)uVar2 < 0x16) {
LAB_00122122:
                iVar4 = BN_set_word(r_01,uVar2);
                if (iVar4 == 0) goto LAB_00122066;
              }
              else {
                iVar4 = BN_num_bits(n);
                iVar4 = BN_pseudo_rand(r_01,iVar4,0,0);
                if (iVar4 == 0) goto LAB_00122066;
                iVar4 = BN_ucmp(r_01,n);
                if (-1 < iVar4) {
                  pcVar1 = BN_sub;
                  if (n->neg != 0) {
                    pcVar1 = BN_add;
                  }
                  iVar4 = (*(pcVar1 + 1))(r_01,r_01,n);
                  if (iVar4 == 0) goto LAB_00122066;
                }
                if (r_01->top == 0) goto LAB_00122122;
              }
              iVar4 = BN_kronecker(r_01,pBVar3,ctx);
              if (iVar4 + 1 < 0 != SCARRY4(iVar4,1)) goto LAB_00122066;
              if (iVar4 == 0) {
                iVar8 = 0xf9;
LAB_001223d2:
                ERR_put_error(3,0x79,0x70,DAT_001224a8,iVar8);
                goto LAB_00122066;
              }
              if (iVar4 != 1) {
                if (iVar4 == -1) {
                  iVar4 = BN_rshift(pBVar3,pBVar3,iVar8);
                  if ((iVar4 == 0) || (iVar4 = BN_mod_exp(r_01,r_01,pBVar3,n,ctx), iVar4 == 0))
                  goto LAB_00122066;
                  if ((r_01->top == 1) && ((*r_01->d == 1 && (r_01->neg == 0)))) {
                    iVar8 = 0x114;
                    goto LAB_001223d2;
                  }
                  iVar4 = BN_rshift1(r,pBVar3);
                  if (iVar4 == 0) goto LAB_00122066;
                  if (r->top == 0) {
                    iVar4 = BN_nnmod(r,pBVar6,n,ctx);
                    if (iVar4 == 0) goto LAB_00122066;
                    uVar2 = r->top;
                    if (uVar2 == 0) {
LAB_00122402:
                      BN_set_word(r_02,uVar2);
                      goto LAB_0012206c;
                    }
                    iVar4 = BN_set_word(r_00,1);
                    if (iVar4 == 0) goto LAB_00122066;
                  }
                  else {
                    iVar4 = BN_mod_exp(r_00,pBVar6,r,n,ctx);
                    if (iVar4 == 0) goto LAB_00122066;
                    uVar2 = r_00->top;
                    if (uVar2 == 0) goto LAB_00122402;
                  }
                  iVar4 = BN_mod_sqr(pBVar7,r_00,n,ctx);
                  if ((iVar4 == 0) || (iVar4 = BN_mod_mul(pBVar7,pBVar7,pBVar6,n,ctx), iVar4 == 0))
                  goto LAB_00122066;
                  iVar4 = BN_mod_mul(r_00,r_00,pBVar6,n,ctx);
                  goto joined_r0x0012237e;
                }
                break;
              }
              uVar2 = uVar2 + 1;
            } while (uVar2 != 0x52);
            ERR_put_error(3,0x79,0x71,DAT_001224a8,0x105);
          }
        }
      }
LAB_00122066:
      if (ret != r_02) {
        BN_clear_free(r_02);
        r_02 = (BIGNUM *)0x0;
        goto LAB_0012206c;
      }
    }
  }
LAB_0012206a:
  r_02 = (BIGNUM *)0x0;
LAB_0012206c:
  BN_CTX_end(ctx);
  return r_02;
joined_r0x0012237e:
  if (iVar4 == 0) goto LAB_00122066;
  if (((pBVar7->top == 1) && (*pBVar7->d == 1)) && (pBVar7->neg == 0)) goto LAB_00122224;
  iVar4 = BN_mod_sqr(r,pBVar7,n,ctx);
  if (iVar4 == 0) goto LAB_00122066;
  iVar10 = 1;
  while (((r->top != 1 || (*r->d != 1)) || (r->neg != 0))) {
    iVar10 = iVar10 + 1;
    if (iVar10 == iVar8) {
      iVar8 = 0x168;
      goto LAB_00122256;
    }
    iVar4 = BN_mod_mul(r,r,r,n,ctx);
    if (iVar4 == 0) goto LAB_00122066;
  }
  pBVar3 = BN_copy(r,r_01);
  if (pBVar3 == (BIGNUM *)0x0) goto LAB_00122066;
  iVar8 = iVar8 - iVar10;
  while (iVar8 = iVar8 + -1, 0 < iVar8) {
    iVar4 = BN_mod_sqr(r,r,n,ctx);
    if (iVar4 == 0) goto LAB_00122066;
  }
  iVar8 = BN_mod_mul(r_01,r,r,n,ctx);
  if ((iVar8 == 0) || (iVar8 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar8 == 0)) goto LAB_00122066;
  iVar4 = BN_mod_mul(pBVar7,pBVar7,r_01,n,ctx);
  iVar8 = iVar10;
  goto joined_r0x0012237e;
}

