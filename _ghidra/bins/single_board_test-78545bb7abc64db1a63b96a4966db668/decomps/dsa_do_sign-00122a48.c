
BIGNUM * dsa_do_sign(uchar *param_1,int param_2,int param_3)

{
  BIGNUM *pBVar1;
  BIGNUM *ctx;
  BIGNUM *ret;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *r_00;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *r_01;
  int iVar4;
  int iVar5;
  BN_MONT_CTX *pBVar6;
  BIGNUM *r_02;
  code *pcVar7;
  BIGNUM *a_00;
  BIGNUM *pBVar8;
  BIGNUM *pBVar9;
  BIGNUM *local_4c;
  
  pBVar8 = *(BIGNUM **)(param_3 + 8);
  if (((pBVar8 == (BIGNUM *)0x0) || (pBVar8 = *(BIGNUM **)(param_3 + 0xc), pBVar8 == (BIGNUM *)0x0))
     || (pBVar8 = *(BIGNUM **)(param_3 + 0x10), pBVar8 == (BIGNUM *)0x0)) {
    iVar2 = 0x65;
    pBVar9 = pBVar8;
    ctx = pBVar8;
  }
  else if (*(int *)(param_3 + 0x18) == 0) {
    iVar2 = 0x6f;
    pBVar8 = (BIGNUM *)0x0;
    pBVar9 = (BIGNUM *)0x0;
    ctx = (BIGNUM *)0x0;
  }
  else {
    pBVar1 = (BIGNUM *)DSA_SIG_new();
    pBVar9 = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) {
      iVar2 = 3;
      pBVar8 = (BIGNUM *)0x0;
      ctx = (BIGNUM *)0x0;
    }
    else {
      pBVar8 = BN_new();
      pBVar1->d = (ulong *)pBVar8;
      pBVar8 = BN_new();
      pBVar1->top = (int)pBVar8;
      if (pBVar8 == (BIGNUM *)0x0 || (BIGNUM *)pBVar1->d == (BIGNUM *)0x0) {
        pBVar8 = (BIGNUM *)0x0;
        iVar2 = 3;
        ctx = (BIGNUM *)0x0;
      }
      else {
        ctx = (BIGNUM *)BN_CTX_new();
        if (ctx == (BIGNUM *)0x0) {
          iVar2 = 3;
          pBVar8 = (BIGNUM *)0x0;
        }
        else {
          ret = BN_CTX_get((BN_CTX *)ctx);
          a = BN_CTX_get((BN_CTX *)ctx);
          r = BN_CTX_get((BN_CTX *)ctx);
          r_00 = BN_CTX_get((BN_CTX *)ctx);
          if (r_00 != (BIGNUM *)0x0) {
            local_4c = (BIGNUM *)0x0;
            do {
              if (((*(int *)(param_3 + 8) == 0) || (*(int *)(param_3 + 0xc) == 0)) ||
                 (*(int *)(param_3 + 0x10) == 0)) {
                ERR_put_error(10,0x6b,0x65,"crypto/dsa/dsa_ossl.c",0xc1);
LAB_00122b00:
                iVar2 = 3;
                pBVar8 = local_4c;
                goto LAB_00122b0c;
              }
              pBVar8 = (BIGNUM *)pBVar1->d;
              iVar2 = BN_is_zero();
              if (((iVar2 != 0) || (iVar2 = BN_is_zero(*(undefined4 *)(param_3 + 0xc)), iVar2 != 0))
                 || (iVar2 = BN_is_zero(*(undefined4 *)(param_3 + 0x10)), iVar2 != 0)) {
                ERR_put_error(10,0x6b,0x70,"crypto/dsa/dsa_ossl.c",199);
                goto LAB_00122b00;
              }
              if (*(int *)(param_3 + 0x18) == 0) {
                ERR_put_error(10,0x6b,0x6f,"crypto/dsa/dsa_ossl.c",0xcb);
                goto LAB_00122b00;
              }
              pBVar3 = BN_new();
              r_01 = BN_new();
              if (r_01 == (BIGNUM *)0x0 || pBVar3 == (BIGNUM *)0x0) {
                ERR_put_error(10,0x6b,3,"crypto/dsa/dsa_ossl.c",0x123);
                BN_CTX_free((BN_CTX *)0x0);
LAB_00122c12:
                BN_clear_free(pBVar3);
                BN_clear_free(r_01);
                iVar2 = 3;
                pBVar8 = local_4c;
                goto LAB_00122b0c;
              }
              iVar2 = BN_num_bits(*(BIGNUM **)(param_3 + 0xc));
              iVar4 = bn_get_top(*(undefined4 *)(param_3 + 0xc));
              iVar4 = iVar4 + 2;
              iVar5 = bn_wexpand(pBVar3,iVar4);
              if ((iVar5 == 0) || (iVar5 = bn_wexpand(r_01,iVar4), iVar5 == 0)) {
LAB_00122bfc:
                ERR_put_error(10,0x6b,3,"crypto/dsa/dsa_ossl.c",0x123);
                goto LAB_00122c12;
              }
              if (param_1 == (uchar *)0x0) {
                do {
                  iVar5 = BN_priv_rand_range(pBVar3,*(undefined4 *)(param_3 + 0xc));
                  if (iVar5 == 0) goto LAB_00122bfc;
                  iVar5 = BN_is_zero(pBVar3);
                } while (iVar5 != 0);
              }
              else {
                do {
                  iVar5 = BN_generate_dsa_nonce
                                    (pBVar3,*(undefined4 *)(param_3 + 0xc),
                                     *(undefined4 *)(param_3 + 0x18),param_1,param_2,ctx);
                  if (iVar5 == 0) goto LAB_00122bfc;
                  iVar5 = BN_is_zero(pBVar3);
                } while (iVar5 != 0);
              }
              BN_set_flags(pBVar3,4);
              BN_set_flags(r_01,4);
              if ((((*(int *)(param_3 + 0x1c) << 0x1f < 0) &&
                   (pBVar6 = BN_MONT_CTX_set_locked
                                       ((BN_MONT_CTX **)(param_3 + 0x20),*(int *)(param_3 + 0x34),
                                        *(BIGNUM **)(param_3 + 8),(BN_CTX *)ctx),
                   pBVar6 == (BN_MONT_CTX *)0x0)) ||
                  (iVar5 = BN_add(r_01,pBVar3,*(BIGNUM **)(param_3 + 0xc)), iVar5 == 0)) ||
                 (iVar5 = BN_add(pBVar3,r_01,*(BIGNUM **)(param_3 + 0xc)), iVar5 == 0))
              goto LAB_00122bfc;
              iVar2 = BN_is_bit_set(r_01,iVar2);
              BN_consttime_swap(iVar2,pBVar3,r_01,iVar4);
              pcVar7 = *(code **)(*(int *)(param_3 + 0x2c) + 0x14);
              if (pcVar7 == (code *)0x0) {
                iVar2 = BN_mod_exp_mont(pBVar8,*(BIGNUM **)(param_3 + 0x10),pBVar3,
                                        *(BIGNUM **)(param_3 + 8),(BN_CTX *)ctx,
                                        *(BN_MONT_CTX **)(param_3 + 0x20));
                if (iVar2 != 0) goto LAB_00122d08;
                goto LAB_00122bfc;
              }
              iVar2 = (*pcVar7)(param_3,pBVar8,*(undefined4 *)(param_3 + 0x10),pBVar3,
                                *(undefined4 *)(param_3 + 8),ctx,*(undefined4 *)(param_3 + 0x20));
              if (iVar2 == 0) goto LAB_00122bfc;
LAB_00122d08:
              iVar2 = BN_div((BIGNUM *)0x0,pBVar8,pBVar8,*(BIGNUM **)(param_3 + 0xc),(BN_CTX *)ctx);
              if (iVar2 == 0) goto LAB_00122bfc;
              a_00 = *(BIGNUM **)(param_3 + 0xc);
              pBVar8 = BN_new();
              if (pBVar8 == (BIGNUM *)0x0) goto LAB_00122bfc;
              BN_CTX_start((BN_CTX *)ctx);
              r_02 = BN_CTX_get((BN_CTX *)ctx);
              if (((r_02 == (BIGNUM *)0x0) || (iVar2 = BN_set_word(pBVar8,2), iVar2 == 0)) ||
                 ((iVar2 = BN_sub(r_02,a_00,pBVar8), iVar2 == 0 ||
                  (iVar2 = BN_mod_exp_mont(pBVar8,pBVar3,r_02,a_00,(BN_CTX *)ctx,(BN_MONT_CTX *)0x0)
                  , iVar2 == 0)))) {
                BN_free(pBVar8);
                BN_CTX_end((BN_CTX *)ctx);
                goto LAB_00122bfc;
              }
              BN_CTX_end((BN_CTX *)ctx);
              BN_clear_free(local_4c);
              BN_clear_free(pBVar3);
              BN_clear_free(r_01);
              iVar4 = BN_num_bits(*(BIGNUM **)(param_3 + 0xc));
              iVar2 = iVar4 + 7;
              if (iVar4 + 7 < 0) {
                iVar2 = iVar4 + 0xe;
              }
              if (iVar2 >> 3 < param_2) {
                iVar2 = BN_num_bits(*(BIGNUM **)(param_3 + 0xc));
                param_2 = iVar2 + 7;
                if (iVar2 + 7 < 0) {
                  param_2 = iVar2 + 0xe;
                }
                param_2 = param_2 >> 3;
              }
              pBVar3 = BN_bin2bn(param_1,param_2,ret);
              if (pBVar3 == (BIGNUM *)0x0) {
LAB_00122df6:
                iVar2 = 3;
                goto LAB_00122b0c;
              }
              do {
                iVar2 = BN_num_bits(*(BIGNUM **)(param_3 + 0xc));
                iVar2 = BN_priv_rand(a,iVar2 + -1,0xffffffff,0);
                if (iVar2 == 0) goto LAB_00122df6;
                iVar2 = BN_is_zero(a);
              } while (iVar2 != 0);
              BN_set_flags(a,4);
              BN_set_flags(r,4);
              BN_set_flags(r_00,4);
              iVar2 = BN_mod_mul(r_00,a,*(BIGNUM **)(param_3 + 0x18),*(BIGNUM **)(param_3 + 0xc),
                                 (BN_CTX *)ctx);
              if (((iVar2 == 0) ||
                  (iVar2 = BN_mod_mul(r_00,r_00,(BIGNUM *)pBVar1->d,*(BIGNUM **)(param_3 + 0xc),
                                      (BN_CTX *)ctx), iVar2 == 0)) ||
                 (((iVar2 = BN_mod_mul(r,a,ret,*(BIGNUM **)(param_3 + 0xc),(BN_CTX *)ctx),
                   iVar2 == 0 ||
                   (((iVar2 = BN_mod_add_quick((BIGNUM *)pBVar1->top,r_00,r,
                                               *(BIGNUM **)(param_3 + 0xc)), iVar2 == 0 ||
                     (iVar2 = BN_mod_mul((BIGNUM *)pBVar1->top,(BIGNUM *)pBVar1->top,pBVar8,
                                         *(BIGNUM **)(param_3 + 0xc),(BN_CTX *)ctx), iVar2 == 0)) ||
                    (pBVar3 = BN_mod_inverse(a,a,*(BIGNUM **)(param_3 + 0xc),(BN_CTX *)ctx),
                    pBVar3 == (BIGNUM *)0x0)))) ||
                  (iVar2 = BN_mod_mul((BIGNUM *)pBVar1->top,(BIGNUM *)pBVar1->top,a,
                                      *(BIGNUM **)(param_3 + 0xc),(BN_CTX *)ctx), iVar2 == 0))))
              goto LAB_00122df6;
              iVar2 = BN_is_zero((BIGNUM *)pBVar1->d);
              local_4c = pBVar8;
            } while ((iVar2 != 0) || (iVar2 = BN_is_zero((BIGNUM *)pBVar1->top), iVar2 != 0));
            goto LAB_00122b24;
          }
          iVar2 = 3;
          pBVar8 = (BIGNUM *)0x0;
        }
      }
    }
  }
LAB_00122b0c:
  ERR_put_error(10,0x70,iVar2,"crypto/dsa/dsa_ossl.c",0xa7);
  pBVar1 = (BIGNUM *)0x0;
  DSA_SIG_free((DSA_SIG *)pBVar9);
LAB_00122b24:
  BN_CTX_free((BN_CTX *)ctx);
  BN_clear_free(pBVar8);
  return pBVar1;
}

