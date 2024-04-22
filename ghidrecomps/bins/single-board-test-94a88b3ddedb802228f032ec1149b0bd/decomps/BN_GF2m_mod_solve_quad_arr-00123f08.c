
BIGNUM * BN_GF2m_mod_solve_quad_arr(BIGNUM *param_1,BIGNUM *param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  ulong *puVar1;
  BIGNUM *pBVar2;
  BIGNUM *rnd;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulong *puVar8;
  int local_2c;
  
  if (*param_3 == 0) {
    BN_set_word(param_1,0);
    return (BIGNUM *)0x1;
  }
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  a_00 = BN_CTX_get(param_4);
  a_01 = BN_CTX_get(param_4);
  pBVar2 = a_01;
  if (a_01 != (BIGNUM *)0x0) {
    if (*param_3 == 0) {
      BN_set_word(a,0);
    }
    else {
      if (a != param_2) {
        iVar5 = param_2->top;
        if (a->dmax < iVar5) {
          pBVar2 = bn_expand2(a,iVar5);
          if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123f80;
          iVar5 = param_2->top;
        }
        if (0 < iVar5) {
          puVar8 = a->d;
          iVar7 = 0;
          puVar1 = param_2->d;
          iVar6 = 0;
          do {
            iVar6 = iVar6 + 1;
            *(undefined4 *)((int)puVar8 + iVar7) = *(undefined4 *)((int)puVar1 + iVar7);
            iVar7 = iVar7 + 4;
            iVar5 = param_2->top;
          } while (iVar6 < iVar5);
        }
        a->top = iVar5;
      }
      pBVar2 = (BIGNUM *)BN_GF2m_mod_arr_part_0(a,param_3);
      if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123f80;
    }
    if (a->top == 0) {
      pBVar2 = (BIGNUM *)0x1;
      BN_set_word(param_1,0);
    }
    else {
      if (*param_3 << 0x1f < 0) {
        pBVar2 = BN_copy(a_00,a);
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123f80;
        if (2 < *param_3) {
          iVar5 = 1;
          do {
            iVar6 = BN_GF2m_mod_sqr_arr(a_00,a_00,param_3,param_4);
            iVar5 = iVar5 + 1;
            if (iVar6 == 0) {
              pBVar2 = (BIGNUM *)0x0;
              goto LAB_00123f80;
            }
            iVar6 = BN_GF2m_mod_sqr_arr(a_00,a_00,param_3,param_4);
            if (iVar6 == 0) goto LAB_0012406c;
            pBVar2 = (BIGNUM *)BN_GF2m_add(a_00,a_00,a);
            if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123f80;
          } while (iVar5 <= (*param_3 + -1) / 2);
        }
LAB_0012402e:
        pBVar2 = (BIGNUM *)BN_GF2m_mod_sqr_arr(a_01,a_00,param_3,param_4);
        if ((pBVar2 == (BIGNUM *)0x0) ||
           (pBVar2 = (BIGNUM *)BN_GF2m_add(a_01,a_00,a_01), pBVar2 == (BIGNUM *)0x0))
        goto LAB_00123f80;
        iVar5 = BN_ucmp(a_01,a);
        if (iVar5 == 0) {
          pBVar2 = BN_copy(param_1,a_00);
          if (pBVar2 != (BIGNUM *)0x0) {
            pBVar2 = (BIGNUM *)0x1;
          }
          goto LAB_00123f80;
        }
        ERR_put_error(3,0x87,0x74,DAT_00124190,0x4ac);
      }
      else {
        rnd = BN_CTX_get(param_4);
        pBVar3 = BN_CTX_get(param_4);
        pBVar4 = BN_CTX_get(param_4);
        if (pBVar4 != (BIGNUM *)0x0) {
          iVar5 = *param_3;
          local_2c = 0x32;
          do {
            pBVar2 = (BIGNUM *)BN_rand(rnd,iVar5,0,0);
            if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123f80;
            if (*param_3 == 0) {
              BN_set_word(rnd,0);
            }
            else {
              pBVar2 = (BIGNUM *)BN_GF2m_mod_arr_part_0(rnd,param_3);
              if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123f80;
            }
            BN_set_word(a_00,0);
            pBVar2 = BN_copy(a_01,rnd);
            if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123f80;
            iVar5 = *param_3;
            if (1 < iVar5) {
              iVar6 = 1;
              do {
                iVar5 = BN_GF2m_mod_sqr_arr(a_00,a_00,param_3,param_4);
                iVar6 = iVar6 + 1;
                if ((((iVar5 == 0) ||
                     (iVar5 = BN_GF2m_mod_sqr_arr(pBVar3,a_01,param_3,param_4), iVar5 == 0)) ||
                    (iVar5 = BN_GF2m_mod_mul_arr(pBVar4,pBVar3,a,param_3,param_4), iVar5 == 0)) ||
                   (iVar5 = BN_GF2m_add(a_00,a_00,pBVar4), iVar5 == 0)) goto LAB_0012406c;
                pBVar2 = (BIGNUM *)BN_GF2m_add(a_01,pBVar3,rnd);
                if (pBVar2 == (BIGNUM *)0x0) goto LAB_00123f80;
                iVar5 = *param_3;
              } while (iVar6 < iVar5);
            }
            if (a_01->top != 0) goto LAB_0012402e;
            local_2c = local_2c + -1;
          } while (local_2c != 0);
          ERR_put_error(3,0x87,0x71,DAT_00124190,0x4a2);
          pBVar2 = (BIGNUM *)0x0;
          goto LAB_00123f80;
        }
      }
LAB_0012406c:
      pBVar2 = (BIGNUM *)0x0;
    }
  }
LAB_00123f80:
  BN_CTX_end(param_4);
  return pBVar2;
}

