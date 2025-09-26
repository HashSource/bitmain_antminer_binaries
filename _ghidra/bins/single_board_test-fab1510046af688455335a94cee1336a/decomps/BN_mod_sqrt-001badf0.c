
BIGNUM * BN_mod_sqrt(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  ulong uVar1;
  BIGNUM *pBVar2;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *r_02;
  int iVar7;
  uint uVar8;
  int iVar9;
  code *pcVar10;
  
  iVar7 = n->top;
  if (iVar7 < 1) {
LAB_001bae76:
    ERR_put_error(3,0x79,0x70,"bn_sqrt.c",0x5b);
    return (BIGNUM *)0x0;
  }
  uVar8 = *n->d;
  if ((uVar8 & 1) == 0) {
    if ((iVar7 != 1) || (uVar8 != 2)) goto LAB_001bae76;
    if (ret != (BIGNUM *)0x0) {
      uVar1 = BN_is_bit_set(a,0);
      iVar7 = BN_set_word(ret,uVar1);
      if (iVar7 == 0) {
        return (BIGNUM *)0x0;
      }
      return ret;
    }
    pBVar5 = BN_new();
    if (pBVar5 != (BIGNUM *)0x0) {
      uVar1 = BN_is_bit_set(a,0);
      pBVar6 = (BIGNUM *)BN_set_word(pBVar5,uVar1);
      if (pBVar6 != (BIGNUM *)0x0) {
        return pBVar5;
      }
      goto LAB_001bae68;
    }
  }
  else {
    if ((iVar7 == 1) && (uVar8 == 1)) goto LAB_001bae76;
    iVar7 = a->top;
    if ((iVar7 == 0) || (((iVar7 == 1 && (*a->d == 1)) && (a->neg == 0)))) {
      pBVar5 = ret;
      if (ret == (BIGNUM *)0x0) {
        pBVar5 = BN_new();
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_001baeea;
        iVar7 = a->top;
      }
      if ((iVar7 == 1) && (*a->d == 1)) {
        uVar1 = 1 - a->neg;
        if (1 < (uint)a->neg) {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
      iVar7 = BN_set_word(pBVar5,uVar1);
      if (iVar7 != 0) {
        return pBVar5;
      }
      pBVar6 = (BIGNUM *)0x0;
      if (pBVar5 == ret) {
        return (BIGNUM *)0x0;
      }
LAB_001bae68:
      BN_free(pBVar5);
      return pBVar6;
    }
    BN_CTX_start(ctx);
    pBVar5 = BN_CTX_get(ctx);
    pBVar6 = BN_CTX_get(ctx);
    pBVar2 = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = BN_CTX_get(ctx);
    if ((r_01 != (BIGNUM *)0x0) &&
       ((r_02 = ret, ret != (BIGNUM *)0x0 || (r_02 = BN_new(), r_02 != (BIGNUM *)0x0)))) {
      iVar7 = BN_nnmod(pBVar5,a,n,ctx);
      if (iVar7 != 0) {
        iVar7 = 1;
        while (iVar3 = BN_is_bit_set(n,iVar7), iVar3 == 0) {
          iVar7 = iVar7 + 1;
        }
        if (iVar7 == 1) {
          iVar7 = BN_rshift(pBVar2,n,2);
          if (iVar7 != 0) {
            pBVar2->neg = 0;
            iVar7 = BN_add_word(pBVar2,1);
            if (iVar7 != 0) {
              pBVar6 = (BIGNUM *)BN_mod_exp(r_02,pBVar5,pBVar2,n,ctx);
joined_r0x001bb0ae:
              if ((pBVar6 != (BIGNUM *)0x0) && (iVar7 = BN_mod_sqr(r_00,r_02,n,ctx), iVar7 != 0)) {
                iVar7 = BN_cmp(r_00,pBVar5);
                if (iVar7 == 0) goto LAB_001baeec;
                iVar7 = 0x18a;
LAB_001bb0d6:
                ERR_put_error(3,0x79,0x6f,"bn_sqrt.c",iVar7);
              }
            }
          }
        }
        else if (iVar7 == 2) {
          iVar7 = BN_mod_lshift1_quick(r,pBVar5,n);
          if ((iVar7 != 0) && (iVar7 = BN_rshift(pBVar2,n,3), iVar7 != 0)) {
            pBVar2->neg = 0;
            iVar7 = BN_mod_exp(pBVar6,r,pBVar2,n,ctx);
            if ((iVar7 != 0) &&
               ((((iVar7 = BN_mod_sqr(r_01,pBVar6,n,ctx), iVar7 != 0 &&
                  (iVar7 = BN_mod_mul(r,r,r_01,n,ctx), iVar7 != 0)) &&
                 (iVar7 = BN_sub_word(r,1), iVar7 != 0)) &&
                ((iVar7 = BN_mod_mul(r_00,pBVar5,pBVar6,n,ctx), iVar7 != 0 &&
                 (iVar7 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar7 != 0)))))) {
LAB_001bb0a4:
              pBVar6 = BN_copy(r_02,r_00);
              goto joined_r0x001bb0ae;
            }
          }
        }
        else {
          pBVar4 = BN_copy(pBVar2,n);
          if (pBVar4 != (BIGNUM *)0x0) {
            uVar1 = 2;
            pBVar2->neg = 0;
            do {
              if ((int)uVar1 < 0x16) {
LAB_001bafa2:
                iVar3 = BN_set_word(r_01,uVar1);
                if (iVar3 == 0) goto LAB_001baee6;
              }
              else {
                iVar3 = BN_num_bits(n);
                iVar3 = BN_pseudo_rand(r_01,iVar3,0,0);
                if (iVar3 == 0) goto LAB_001baee6;
                iVar3 = BN_ucmp(r_01,n);
                if (-1 < iVar3) {
                  pcVar10 = (code *)0x18a3a5;
                  if (n->neg != 0) {
                    pcVar10 = (code *)0x18a341;
                  }
                  iVar3 = (*pcVar10)(r_01,r_01,n);
                  if (iVar3 == 0) goto LAB_001baee6;
                }
                if (r_01->top == 0) goto LAB_001bafa2;
              }
              iVar3 = BN_kronecker(r_01,pBVar2,ctx);
              if (iVar3 + 1 < 0 != SCARRY4(iVar3,1)) goto LAB_001baee6;
              if (iVar3 == 0) {
                iVar7 = 0xf9;
LAB_001bb252:
                ERR_put_error(3,0x79,0x70,"bn_sqrt.c",iVar7);
                goto LAB_001baee6;
              }
              if (iVar3 != 1) {
                if (iVar3 == -1) {
                  iVar3 = BN_rshift(pBVar2,pBVar2,iVar7);
                  if ((iVar3 == 0) || (iVar3 = BN_mod_exp(r_01,r_01,pBVar2,n,ctx), iVar3 == 0))
                  goto LAB_001baee6;
                  if ((r_01->top == 1) && ((*r_01->d == 1 && (r_01->neg == 0)))) {
                    iVar7 = 0x114;
                    goto LAB_001bb252;
                  }
                  iVar3 = BN_rshift1(r,pBVar2);
                  if (iVar3 == 0) goto LAB_001baee6;
                  if (r->top == 0) {
                    iVar3 = BN_nnmod(r,pBVar5,n,ctx);
                    if (iVar3 == 0) goto LAB_001baee6;
                    uVar1 = r->top;
                    if (uVar1 == 0) {
LAB_001bb282:
                      BN_set_word(r_02,uVar1);
                      goto LAB_001baeec;
                    }
                    iVar3 = BN_set_word(r_00,1);
                    if (iVar3 == 0) goto LAB_001baee6;
                  }
                  else {
                    iVar3 = BN_mod_exp(r_00,pBVar5,r,n,ctx);
                    if (iVar3 == 0) goto LAB_001baee6;
                    uVar1 = r_00->top;
                    if (uVar1 == 0) goto LAB_001bb282;
                  }
                  iVar3 = BN_mod_sqr(pBVar6,r_00,n,ctx);
                  if ((iVar3 == 0) || (iVar3 = BN_mod_mul(pBVar6,pBVar6,pBVar5,n,ctx), iVar3 == 0))
                  goto LAB_001baee6;
                  iVar3 = BN_mod_mul(r_00,r_00,pBVar5,n,ctx);
                  goto joined_r0x001bb1fe;
                }
                break;
              }
              uVar1 = uVar1 + 1;
            } while (uVar1 != 0x52);
            ERR_put_error(3,0x79,0x71,"bn_sqrt.c",0x105);
          }
        }
      }
LAB_001baee6:
      if (ret != r_02) {
        BN_clear_free(r_02);
        r_02 = (BIGNUM *)0x0;
        goto LAB_001baeec;
      }
    }
  }
LAB_001baeea:
  r_02 = (BIGNUM *)0x0;
LAB_001baeec:
  BN_CTX_end(ctx);
  return r_02;
joined_r0x001bb1fe:
  if (iVar3 == 0) goto LAB_001baee6;
  if (((pBVar6->top == 1) && (*pBVar6->d == 1)) && (pBVar6->neg == 0)) goto LAB_001bb0a4;
  iVar3 = BN_mod_sqr(r,pBVar6,n,ctx);
  if (iVar3 == 0) goto LAB_001baee6;
  iVar9 = 1;
  while (((r->top != 1 || (*r->d != 1)) || (r->neg != 0))) {
    iVar9 = iVar9 + 1;
    if (iVar9 == iVar7) {
      iVar7 = 0x168;
      goto LAB_001bb0d6;
    }
    iVar3 = BN_mod_mul(r,r,r,n,ctx);
    if (iVar3 == 0) goto LAB_001baee6;
  }
  pBVar2 = BN_copy(r,r_01);
  if (pBVar2 == (BIGNUM *)0x0) goto LAB_001baee6;
  iVar7 = iVar7 - iVar9;
  while (iVar7 = iVar7 + -1, 0 < iVar7) {
    iVar3 = BN_mod_sqr(r,r,n,ctx);
    if (iVar3 == 0) goto LAB_001baee6;
  }
  iVar7 = BN_mod_mul(r_01,r,r,n,ctx);
  if ((iVar7 == 0) || (iVar7 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar7 == 0)) goto LAB_001baee6;
  iVar3 = BN_mod_mul(pBVar6,pBVar6,r_01,n,ctx);
  iVar7 = iVar9;
  goto joined_r0x001bb1fe;
}

