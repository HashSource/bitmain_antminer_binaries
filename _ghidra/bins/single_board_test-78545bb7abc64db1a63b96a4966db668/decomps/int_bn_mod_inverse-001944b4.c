
BIGNUM * int_bn_mod_inverse(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4,
                           undefined4 *param_5)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  BIGNUM *pBVar9;
  int iVar10;
  int iVar11;
  BIGNUM *pBVar12;
  BIGNUM *pBVar13;
  int local_54;
  BIGNUM *local_48;
  BIGNUM BStack_3c;
  
  iVar1 = BN_abs_is_word(param_3,1);
  if ((iVar1 != 0) || (iVar1 = BN_is_zero(param_3), iVar1 != 0)) {
    *param_5 = 1;
    return (BIGNUM *)0x0;
  }
  *param_5 = 0;
  iVar1 = BN_get_flags(param_2,4);
  if ((iVar1 == 0) && (iVar1 = BN_get_flags(param_3,4), iVar1 == 0)) {
    BN_CTX_start(param_4);
    pBVar4 = BN_CTX_get(param_4);
    pBVar2 = BN_CTX_get(param_4);
    pBVar3 = BN_CTX_get(param_4);
    pBVar6 = BN_CTX_get(param_4);
    pBVar7 = BN_CTX_get(param_4);
    pBVar5 = BN_CTX_get(param_4);
    pBVar8 = BN_CTX_get(param_4);
    if (pBVar8 == (BIGNUM *)0x0) {
      pBVar13 = (BIGNUM *)0x0;
      goto LAB_001947f4;
    }
    if (param_1 == (BIGNUM *)0x0) {
      pBVar9 = BN_new();
      if ((pBVar9 != (BIGNUM *)0x0) && (iVar1 = BN_set_word(pBVar3,1), iVar1 != 0)) {
        BN_set_word(pBVar5,0);
        pBVar12 = BN_copy(pBVar2,param_2);
        pBVar13 = pBVar9;
        if (pBVar12 != (BIGNUM *)0x0) goto LAB_0019470c;
      }
LAB_001947fc:
      pBVar13 = (BIGNUM *)0x0;
      BN_free(pBVar9);
    }
    else {
      iVar1 = BN_set_word(pBVar3,1);
      if (iVar1 != 0) {
        BN_set_word(pBVar5,0);
        pBVar9 = BN_copy(pBVar2,param_2);
        pBVar13 = param_1;
        if (pBVar9 != (BIGNUM *)0x0) {
LAB_0019470c:
          pBVar9 = BN_copy(pBVar4,param_3);
          if ((pBVar9 != (BIGNUM *)0x0) &&
             (((pBVar4->neg = 0, pBVar2->neg == 0 && (iVar1 = BN_ucmp(pBVar2,pBVar4), iVar1 < 0)) ||
              (iVar1 = BN_nnmod(pBVar2,pBVar2,pBVar4,param_4), iVar1 != 0)))) {
            iVar1 = BN_is_odd(param_3);
            if ((iVar1 == 0) || (iVar1 = BN_num_bits(param_3), 0x800 < iVar1)) {
              iVar1 = -1;
              pBVar9 = pBVar4;
              pBVar12 = pBVar5;
              while (pBVar5 = pBVar12, pBVar12 = pBVar3, pBVar4 = pBVar9,
                    iVar10 = BN_is_zero(pBVar2), iVar10 == 0) {
                iVar10 = BN_num_bits(pBVar4);
                iVar11 = BN_num_bits(pBVar2);
                if (iVar10 == iVar11) {
LAB_0019483a:
                  iVar10 = BN_set_word(pBVar6,1);
                  if (iVar10 == 0) goto LAB_001947f4;
                  iVar10 = BN_sub(pBVar7,pBVar4,pBVar2);
                }
                else {
                  iVar10 = BN_num_bits(pBVar4);
                  iVar11 = BN_num_bits(pBVar2);
                  if (iVar10 == iVar11 + 1) {
                    iVar10 = BN_lshift1(pBVar8,pBVar2);
                    if (iVar10 == 0) goto LAB_001947f4;
                    iVar10 = BN_ucmp(pBVar4,pBVar8);
                    if (iVar10 < 0) goto LAB_0019483a;
                    iVar10 = BN_sub(pBVar7,pBVar4,pBVar8);
                    if ((iVar10 == 0) || (iVar10 = BN_add(pBVar6,pBVar8,pBVar2), iVar10 == 0))
                    goto LAB_001947f4;
                    iVar10 = BN_ucmp(pBVar4,pBVar6);
                    if (iVar10 < 0) {
                      iVar10 = BN_set_word(pBVar6,2);
                    }
                    else {
                      iVar10 = BN_set_word(pBVar6,3);
                      if (iVar10 == 0) goto LAB_001947f4;
                      iVar10 = BN_sub(pBVar7,pBVar7,pBVar2);
                    }
                  }
                  else {
                    iVar10 = BN_div(pBVar6,pBVar7,pBVar4,pBVar2,param_4);
                  }
                }
                if (iVar10 == 0) goto LAB_001947f4;
                iVar10 = BN_is_one(pBVar6);
                if (iVar10 == 0) {
                  iVar10 = BN_is_word(pBVar6,2);
                  if (iVar10 == 0) {
                    iVar10 = BN_is_word(pBVar6,4);
                    if (iVar10 == 0) {
                      if (pBVar6->top == 1) {
                        pBVar3 = BN_copy(pBVar4,pBVar12);
                        if (pBVar3 == (BIGNUM *)0x0) goto LAB_001947f4;
                        iVar10 = BN_mul_word(pBVar4,*pBVar6->d);
                      }
                      else {
                        iVar10 = BN_mul(pBVar4,pBVar6,pBVar12,param_4);
                      }
                    }
                    else {
                      iVar10 = BN_lshift(pBVar4,pBVar12,2);
                    }
                  }
                  else {
                    iVar10 = BN_lshift1(pBVar4,pBVar12);
                  }
                  if (iVar10 == 0) goto LAB_001947f4;
                  iVar10 = BN_add(pBVar4,pBVar4,pBVar5);
                }
                else {
                  iVar10 = BN_add(pBVar4,pBVar12,pBVar5);
                }
                if (iVar10 == 0) goto LAB_001947f4;
                iVar1 = -iVar1;
                pBVar9 = pBVar2;
                pBVar2 = pBVar7;
                pBVar3 = pBVar4;
                pBVar7 = pBVar5;
              }
              if (iVar1 == -1) {
LAB_00194aa8:
                iVar1 = BN_sub(pBVar5,param_3,pBVar5);
                if (iVar1 == 0) goto LAB_001947f4;
              }
              iVar1 = BN_is_one(pBVar4);
              if (iVar1 == 0) {
                *param_5 = 1;
              }
              else {
                if ((pBVar5->neg == 0) && (iVar1 = BN_ucmp(pBVar5,param_3), iVar1 < 0)) {
                  pBVar2 = BN_copy(pBVar13,pBVar5);
                }
                else {
                  pBVar2 = (BIGNUM *)BN_nnmod(pBVar13,pBVar5,param_3,param_4);
                }
                if (pBVar2 != (BIGNUM *)0x0) goto LAB_001946e6;
              }
            }
            else {
              while( true ) {
                iVar1 = BN_is_zero(pBVar2);
                if (iVar1 != 0) goto LAB_00194aa8;
                iVar1 = 0;
                while (iVar10 = BN_is_bit_set(pBVar2,iVar1), iVar10 == 0) {
                  iVar1 = iVar1 + 1;
                  iVar10 = BN_is_odd(pBVar3);
                  if (((iVar10 != 0) && (iVar10 = BN_uadd(pBVar3,pBVar3,param_3), iVar10 == 0)) ||
                     (iVar10 = BN_rshift1(pBVar3,pBVar3), iVar10 == 0)) goto LAB_001947f4;
                }
                if ((iVar1 != 0) && (iVar1 = BN_rshift(pBVar2,pBVar2,iVar1), iVar1 == 0)) break;
                iVar1 = 0;
                while (iVar10 = BN_is_bit_set(pBVar4,iVar1), iVar10 == 0) {
                  iVar1 = iVar1 + 1;
                  iVar10 = BN_is_odd(pBVar5);
                  if (((iVar10 != 0) && (iVar10 = BN_uadd(pBVar5,pBVar5,param_3), iVar10 == 0)) ||
                     (iVar10 = BN_rshift1(pBVar5,pBVar5), iVar10 == 0)) goto LAB_001947f4;
                }
                if ((iVar1 != 0) && (iVar1 = BN_rshift(pBVar4,pBVar4,iVar1), iVar1 == 0)) break;
                iVar1 = BN_ucmp(pBVar2,pBVar4);
                if (iVar1 < 0) {
                  iVar1 = BN_uadd(pBVar5,pBVar5,pBVar3);
                  if (iVar1 == 0) break;
                  iVar1 = BN_usub(pBVar4,pBVar4,pBVar2);
                }
                else {
                  iVar1 = BN_uadd(pBVar3,pBVar3,pBVar5);
                  if (iVar1 == 0) break;
                  iVar1 = BN_usub(pBVar2,pBVar2,pBVar4);
                }
                if (iVar1 == 0) break;
              }
            }
          }
LAB_001947f4:
          pBVar9 = pBVar13;
          if (param_1 == (BIGNUM *)0x0) goto LAB_001947fc;
        }
      }
      pBVar13 = (BIGNUM *)0x0;
    }
LAB_001946e6:
    BN_CTX_end(param_4);
    return pBVar13;
  }
  BN_CTX_start(param_4);
  pBVar2 = BN_CTX_get(param_4);
  pBVar3 = BN_CTX_get(param_4);
  pBVar4 = BN_CTX_get(param_4);
  pBVar5 = BN_CTX_get(param_4);
  pBVar6 = BN_CTX_get(param_4);
  pBVar7 = BN_CTX_get(param_4);
  pBVar8 = BN_CTX_get(param_4);
  if (pBVar8 == (BIGNUM *)0x0) {
    local_48 = (BIGNUM *)0x0;
    goto LAB_00194636;
  }
  if (param_1 == (BIGNUM *)0x0) {
    local_48 = BN_new();
    if ((local_48 != (BIGNUM *)0x0) && (iVar1 = BN_set_word(pBVar4,1), iVar1 != 0)) {
      BN_set_word(pBVar7,0);
      pBVar8 = BN_copy(pBVar3,param_2);
      if (pBVar8 != (BIGNUM *)0x0) goto LAB_0019456a;
    }
LAB_0019463a:
    pBVar2 = local_48;
    local_48 = (BIGNUM *)0x0;
    BN_free(pBVar2);
  }
  else {
    iVar1 = BN_set_word(pBVar4,1);
    if (iVar1 != 0) {
      BN_set_word(pBVar7,0);
      pBVar8 = BN_copy(pBVar3,param_2);
      local_48 = param_1;
      if (pBVar8 != (BIGNUM *)0x0) {
LAB_0019456a:
        pBVar8 = BN_copy(pBVar2,param_3);
        if (pBVar8 != (BIGNUM *)0x0) {
          pBVar2->neg = 0;
          if ((pBVar3->neg != 0) || (iVar1 = BN_ucmp(pBVar3,pBVar2), -1 < iVar1)) {
            bn_init(&BStack_3c);
            BN_with_flags(&BStack_3c,pBVar3,4);
            iVar1 = BN_nnmod(pBVar3,&BStack_3c,pBVar2,param_4);
            if (iVar1 == 0) goto LAB_00194636;
          }
          local_54 = -1;
          while (pBVar13 = pBVar7, pBVar8 = pBVar2, iVar1 = BN_is_zero(pBVar3), iVar1 == 0) {
            local_54 = -local_54;
            bn_init(&BStack_3c);
            BN_with_flags(&BStack_3c,pBVar8,4);
            iVar1 = BN_div(pBVar5,pBVar6,&BStack_3c,pBVar3,param_4);
            if (((iVar1 == 0) || (iVar1 = BN_mul(pBVar8,pBVar5,pBVar4,param_4), iVar1 == 0)) ||
               (iVar1 = BN_add(pBVar8,pBVar8,pBVar13), pBVar2 = pBVar3, pBVar3 = pBVar6,
               pBVar7 = pBVar4, pBVar4 = pBVar8, pBVar6 = pBVar13, iVar1 == 0)) goto LAB_00194636;
          }
          if ((local_54 != -1) || (iVar1 = BN_sub(pBVar13,param_3,pBVar13), iVar1 != 0)) {
            iVar1 = BN_is_one(pBVar8);
            if (iVar1 == 0) {
              *param_5 = 1;
            }
            else {
              if ((pBVar13->neg == 0) && (iVar1 = BN_ucmp(pBVar13,param_3), iVar1 < 0)) {
                pBVar2 = BN_copy(local_48,pBVar13);
              }
              else {
                pBVar2 = (BIGNUM *)BN_nnmod(local_48,pBVar13,param_3,param_4);
              }
              if (pBVar2 != (BIGNUM *)0x0) {
                *param_5 = 0;
                goto LAB_00194658;
              }
            }
          }
        }
LAB_00194636:
        if (param_1 == (BIGNUM *)0x0) goto LAB_0019463a;
      }
    }
    local_48 = (BIGNUM *)0x0;
  }
LAB_00194658:
  BN_CTX_end(param_4);
  return local_48;
}

