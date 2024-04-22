
/* WARNING: Type propagation algorithm not settling */

BIGNUM * BN_mod_inverse(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  int *piVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  int iVar9;
  BIGNUM *pBVar10;
  int iVar11;
  int iVar12;
  ulong uVar13;
  BIGNUM *b;
  BIGNUM *local_60;
  BIGNUM *local_54;
  BIGNUM local_50;
  BIGNUM local_3c;
  
  if ((a->flags << 0x1d < 0) || (n->flags << 0x1d < 0)) {
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    pBVar3 = BN_CTX_get(ctx);
    pBVar4 = BN_CTX_get(ctx);
    pBVar5 = BN_CTX_get(ctx);
    pBVar6 = BN_CTX_get(ctx);
    pBVar7 = BN_CTX_get(ctx);
    pBVar8 = BN_CTX_get(ctx);
    if (pBVar8 == (BIGNUM *)0x0) {
      local_54 = (BIGNUM *)0x0;
joined_r0x000f2c5c:
      if (ret != (BIGNUM *)0x0) goto LAB_000f2b7a;
    }
    else {
      local_54 = ret;
      if ((ret != (BIGNUM *)0x0) || (local_54 = BN_new(), local_54 != (BIGNUM *)0x0)) {
        BN_set_word(pBVar4,1);
        BN_set_word(pBVar7,0);
        pBVar8 = BN_copy(pBVar3,a);
        if ((pBVar8 == (BIGNUM *)0x0) || (pBVar8 = BN_copy(pBVar2,n), pBVar8 == (BIGNUM *)0x0))
        goto joined_r0x000f2c5c;
        pBVar2->neg = 0;
        iVar12 = pBVar3->neg;
        if (iVar12 == 0) {
          iVar12 = BN_ucmp(pBVar3,pBVar2);
          if (-1 < iVar12) {
            iVar12 = pBVar3->neg;
            goto LAB_000f2ab8;
          }
        }
        else {
LAB_000f2ab8:
          local_3c.d = pBVar3->d;
          local_3c.top = pBVar3->top;
          local_3c.flags = local_3c.flags & 1U | pBVar3->flags & 0xfffffffeU | 6;
          local_3c.dmax = pBVar3->dmax;
          local_3c.neg = iVar12;
          iVar12 = BN_nnmod(pBVar3,&local_3c,pBVar2,ctx);
          if (iVar12 == 0) goto joined_r0x000f2c5c;
        }
        if (pBVar3->top == 0) {
LAB_000f2ee2:
          iVar12 = BN_sub(pBVar7,n,pBVar7);
          if (iVar12 == 0) goto joined_r0x000f2c5c;
        }
        else {
          iVar12 = -1;
          pBVar8 = pBVar2;
          pBVar10 = pBVar7;
          do {
            pBVar7 = pBVar4;
            pBVar2 = pBVar3;
            pBVar3 = pBVar6;
            pBVar4 = pBVar8;
            local_50.top = pBVar4->top;
            iVar12 = -iVar12;
            local_50.dmax = pBVar4->dmax;
            local_50.d = pBVar4->d;
            local_50.flags = pBVar4->flags & 0xfffffffeU | local_50.flags & 1U | 6;
            local_50.neg = pBVar4->neg;
            iVar9 = BN_div(pBVar5,pBVar3,&local_50,pBVar2,ctx);
            if (((iVar9 == 0) || (iVar9 = BN_mul(pBVar4,pBVar5,pBVar7,ctx), iVar9 == 0)) ||
               (iVar9 = BN_add(pBVar4,pBVar4,pBVar10), iVar9 == 0)) goto joined_r0x000f2c5c;
            pBVar8 = pBVar2;
            pBVar6 = pBVar10;
            pBVar10 = pBVar7;
          } while (pBVar3->top != 0);
          if (iVar12 == -1) goto LAB_000f2ee2;
        }
        if (((pBVar2->top == 1) && (*pBVar2->d == 1)) && (pBVar2->neg == 0)) {
          if ((pBVar7->neg == 0) && (iVar12 = BN_ucmp(pBVar7,n), iVar12 < 0)) {
            pBVar6 = BN_copy(local_54,pBVar7);
          }
          else {
            pBVar6 = (BIGNUM *)BN_nnmod(local_54,pBVar7,n,ctx);
          }
          if (pBVar6 != (BIGNUM *)0x0) goto LAB_000f2b7c;
        }
        else {
          ERR_put_error(3,0x8b,0x6c,DAT_000f3038,0x2b2);
        }
        goto joined_r0x000f2c5c;
      }
    }
    BN_free(local_54);
    local_54 = (BIGNUM *)0x0;
  }
  else {
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    pBVar6 = BN_CTX_get(ctx);
    pBVar4 = BN_CTX_get(ctx);
    pBVar5 = BN_CTX_get(ctx);
    pBVar3 = BN_CTX_get(ctx);
    pBVar7 = BN_CTX_get(ctx);
    pBVar8 = BN_CTX_get(ctx);
    if (pBVar8 == (BIGNUM *)0x0) {
      local_60 = (BIGNUM *)0x0;
      goto LAB_000f2c1c;
    }
    local_60 = ret;
    if ((ret == (BIGNUM *)0x0) && (local_60 = BN_new(), local_60 == (BIGNUM *)0x0)) {
LAB_000f2c22:
      local_54 = (BIGNUM *)0x0;
      BN_free(local_60);
      goto LAB_000f2b7c;
    }
    BN_set_word(pBVar4,1);
    BN_set_word(pBVar7,0);
    pBVar10 = BN_copy(pBVar6,a);
    if (((pBVar10 != (BIGNUM *)0x0) && (pBVar10 = BN_copy(pBVar2,n), pBVar10 != (BIGNUM *)0x0)) &&
       (((pBVar2->neg = 0, pBVar6->neg == 0 && (iVar12 = BN_ucmp(pBVar6,pBVar2), iVar12 < 0)) ||
        (iVar12 = BN_nnmod(pBVar6,pBVar6,pBVar2,ctx), iVar12 != 0)))) {
      if (((n->top < 1) || (-1 < (int)(*n->d << 0x1f))) || (iVar12 = BN_num_bits(n), 0x800 < iVar12)
         ) {
        if (pBVar6->top == 0) {
LAB_000f2f62:
          iVar12 = BN_sub(pBVar7,n,pBVar7);
          if (iVar12 == 0) goto LAB_000f2c1c;
        }
        else {
          iVar12 = -1;
          pBVar10 = pBVar2;
          b = pBVar7;
          do {
            pBVar7 = pBVar4;
            pBVar2 = pBVar6;
            pBVar4 = pBVar10;
            iVar9 = BN_num_bits(pBVar4);
            iVar11 = BN_num_bits(pBVar2);
            if (iVar9 == iVar11) {
LAB_000f2d5e:
              iVar9 = BN_set_word(pBVar5,1);
              if ((iVar9 == 0) || (iVar9 = BN_sub(pBVar3,pBVar4,pBVar2), iVar9 == 0))
              goto LAB_000f2c1c;
              iVar9 = pBVar5->top;
            }
            else {
              iVar9 = BN_num_bits(pBVar4);
              iVar11 = BN_num_bits(pBVar2);
              if (iVar9 == iVar11 + 1) {
                iVar9 = BN_lshift1(pBVar8,pBVar2);
                if (iVar9 == 0) goto LAB_000f2c1c;
                iVar9 = BN_ucmp(pBVar4,pBVar8);
                if (iVar9 < 0) goto LAB_000f2d5e;
                iVar9 = BN_sub(pBVar3,pBVar4,pBVar8);
                if ((iVar9 == 0) || (iVar9 = BN_add(pBVar5,pBVar8,pBVar2), iVar9 == 0))
                goto LAB_000f2c1c;
                iVar9 = BN_ucmp(pBVar4,pBVar5);
                if (iVar9 < 0) {
                  iVar9 = BN_set_word(pBVar5,2);
                }
                else {
                  iVar9 = BN_set_word(pBVar5,3);
                  if (iVar9 == 0) goto LAB_000f2c1c;
                  iVar9 = BN_sub(pBVar3,pBVar3,pBVar2);
                }
              }
              else {
                iVar9 = BN_div(pBVar5,pBVar3,pBVar4,pBVar2,ctx);
              }
              if (iVar9 == 0) goto LAB_000f2c1c;
              iVar9 = pBVar5->top;
            }
            if (iVar9 == 1) {
              uVar13 = *pBVar5->d;
              if (uVar13 != 1) {
                if (uVar13 == 2) {
                  if (pBVar5->neg != 0) goto LAB_000f2d9a;
                  iVar9 = BN_lshift1(pBVar4,pBVar7);
                }
                else if ((uVar13 == 4) && (pBVar5->neg == 0)) {
                  iVar9 = BN_lshift(pBVar4,pBVar7,2);
                }
                else {
LAB_000f2d9a:
                  pBVar6 = BN_copy(pBVar4,pBVar7);
                  if (pBVar6 == (BIGNUM *)0x0) goto LAB_000f2c1c;
                  iVar9 = BN_mul_word(pBVar4,*pBVar5->d);
                }
                if (iVar9 != 0) goto LAB_000f2d22;
                goto LAB_000f2c1c;
              }
              if (pBVar5->neg != 0) goto LAB_000f2d9a;
              iVar9 = BN_add(pBVar4,pBVar7,b);
            }
            else {
              iVar9 = BN_mul(pBVar4,pBVar5,pBVar7,ctx);
              if (iVar9 == 0) goto LAB_000f2c1c;
LAB_000f2d22:
              iVar9 = BN_add(pBVar4,pBVar4,b);
            }
            if (iVar9 == 0) goto LAB_000f2c1c;
            piVar1 = &pBVar3->top;
            iVar12 = -iVar12;
            pBVar10 = pBVar2;
            pBVar6 = pBVar3;
            pBVar3 = b;
            b = pBVar7;
          } while (*piVar1 != 0);
          if (iVar12 == -1) goto LAB_000f2f62;
        }
        if (((pBVar2->top == 1) && (*pBVar2->d == 1)) && (pBVar2->neg == 0)) {
          if ((pBVar7->neg == 0) && (iVar12 = BN_ucmp(pBVar7,n), iVar12 < 0)) {
            pBVar6 = BN_copy(local_60,pBVar7);
          }
          else {
            pBVar6 = (BIGNUM *)BN_nnmod(local_60,pBVar7,n,ctx);
          }
          local_54 = local_60;
          if (pBVar6 != (BIGNUM *)0x0) goto LAB_000f2b7c;
        }
        else {
          ERR_put_error(3,0x6e,0x6c,DAT_000f3038,0x20d);
        }
      }
      else {
        while( true ) {
          if (pBVar6->top == 0) goto LAB_000f2f62;
          iVar12 = 0;
          while (iVar9 = BN_is_bit_set(pBVar6,iVar12), iVar9 == 0) {
            iVar12 = iVar12 + 1;
            if ((((0 < pBVar4->top) && ((int)(*pBVar4->d << 0x1f) < 0)) &&
                (iVar9 = BN_uadd(pBVar4,pBVar4,n), iVar9 == 0)) ||
               (iVar9 = BN_rshift1(pBVar4,pBVar4), iVar9 == 0)) goto LAB_000f2c1c;
          }
          if ((iVar12 != 0) && (iVar12 = BN_rshift(pBVar6,pBVar6,iVar12), iVar12 == 0)) break;
          iVar12 = 0;
          while (iVar9 = BN_is_bit_set(pBVar2,iVar12), iVar9 == 0) {
            iVar12 = iVar12 + 1;
            if ((((0 < pBVar7->top) && ((int)(*pBVar7->d << 0x1f) < 0)) &&
                (iVar9 = BN_uadd(pBVar7,pBVar7,n), iVar9 == 0)) ||
               (iVar9 = BN_rshift1(pBVar7,pBVar7), iVar9 == 0)) goto LAB_000f2c1c;
          }
          if ((iVar12 != 0) && (iVar12 = BN_rshift(pBVar2,pBVar2,iVar12), iVar12 == 0)) break;
          iVar12 = BN_ucmp(pBVar6,pBVar2);
          if (iVar12 < 0) {
            iVar12 = BN_uadd(pBVar7,pBVar7,pBVar4);
            if (iVar12 == 0) break;
            iVar12 = BN_usub(pBVar2,pBVar2,pBVar6);
          }
          else {
            iVar12 = BN_uadd(pBVar4,pBVar4,pBVar7);
            if (iVar12 == 0) break;
            iVar12 = BN_usub(pBVar6,pBVar6,pBVar2);
          }
          if (iVar12 == 0) break;
        }
      }
    }
LAB_000f2c1c:
    if (ret == (BIGNUM *)0x0) goto LAB_000f2c22;
LAB_000f2b7a:
    local_54 = (BIGNUM *)0x0;
  }
LAB_000f2b7c:
  BN_CTX_end(ctx);
  return local_54;
}

