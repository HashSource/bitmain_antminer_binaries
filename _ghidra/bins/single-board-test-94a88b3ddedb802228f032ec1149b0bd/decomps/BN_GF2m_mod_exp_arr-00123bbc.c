
BIGNUM * BN_GF2m_mod_exp_arr(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,int *param_4,
                            BN_CTX *param_5)

{
  BIGNUM *a;
  ulong *puVar1;
  BIGNUM *pBVar2;
  int iVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  
  if (param_3->top == 0) {
    pBVar2 = (BIGNUM *)BN_set_word(param_1,1);
    return pBVar2;
  }
  if ((param_3->top == 1) && (*param_3->d == 1)) {
    pBVar2 = BN_copy(param_1,param_2);
    if (pBVar2 == (BIGNUM *)0x0) {
      return (BIGNUM *)0x0;
    }
    return (BIGNUM *)0x1;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  pBVar2 = a;
  if (a != (BIGNUM *)0x0) {
    if (*param_4 == 0) {
      BN_set_word(a,0);
    }
    else {
      if (param_2 != a) {
        iVar3 = param_2->top;
        if (a->dmax < iVar3) {
          pBVar2 = bn_expand2(a,iVar3);
          if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123c24;
          iVar3 = param_2->top;
        }
        if (0 < iVar3) {
          puVar4 = a->d;
          iVar6 = 0;
          puVar1 = param_2->d;
          iVar5 = 0;
          do {
            iVar5 = iVar5 + 1;
            *(undefined4 *)((int)puVar4 + iVar6) = *(undefined4 *)((int)puVar1 + iVar6);
            iVar6 = iVar6 + 4;
            iVar3 = param_2->top;
          } while (iVar5 < iVar3);
        }
        a->top = iVar3;
      }
      pBVar2 = (BIGNUM *)BN_GF2m_mod_arr_part_0(a,param_4);
      if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123c24;
    }
    iVar5 = BN_num_bits(param_3);
    iVar3 = iVar5 + -2;
    if (-1 < iVar5 + -2) {
      do {
        iVar5 = BN_GF2m_mod_sqr_arr(a,a,param_4,param_5);
        iVar6 = iVar3 + -1;
        if (iVar5 == 0) {
          pBVar2 = (BIGNUM *)0x0;
          goto LAB_00123c24;
        }
        iVar3 = BN_is_bit_set(param_3,iVar3);
        if ((iVar3 != 0) && (iVar3 = BN_GF2m_mod_mul_arr(a,a,param_2,param_4,param_5), iVar3 == 0))
        {
          pBVar2 = (BIGNUM *)0x0;
          goto LAB_00123c24;
        }
        iVar3 = iVar6;
      } while (iVar6 != -1);
    }
    pBVar2 = BN_copy(param_1,a);
    if (pBVar2 != (BIGNUM *)0x0) {
      pBVar2 = (BIGNUM *)0x1;
    }
  }
LAB_00123c24:
  BN_CTX_end(param_5);
  return pBVar2;
}

