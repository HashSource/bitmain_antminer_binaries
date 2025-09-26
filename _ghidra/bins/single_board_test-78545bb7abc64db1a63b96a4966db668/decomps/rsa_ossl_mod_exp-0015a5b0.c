
BIGNUM * rsa_ossl_mod_exp(BIGNUM *param_1,BIGNUM *param_2,int param_3,BN_CTX *param_4)

{
  BIGNUM *rr;
  BIGNUM *r;
  BIGNUM *pBVar1;
  BIGNUM *r_00;
  BN_MONT_CTX *pBVar2;
  BIGNUM *mod;
  BIGNUM *a;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  BIGNUM *pBVar7;
  int iVar8;
  int iVar9;
  undefined4 local_34 [4];
  
  BN_CTX_start(param_4);
  rr = BN_CTX_get(param_4);
  r = BN_CTX_get(param_4);
  pBVar1 = BN_CTX_get(param_4);
  r_00 = BN_CTX_get(param_4);
  if (r_00 != (BIGNUM *)0x0) {
    if (*(int *)(param_3 + 4) == 1) {
      iVar9 = OPENSSL_sk_num(*(undefined4 *)(param_3 + 0x30));
      if (2 < iVar9 - 1U) goto LAB_0015a61a;
    }
    else {
      iVar9 = 0;
    }
    iVar6 = *(int *)(param_3 + 0x40);
    if (iVar6 << 0x1d < 0) {
      mod = BN_new();
      if (mod == (BIGNUM *)0x0) goto LAB_0015a61a;
      BN_with_flags(mod,*(undefined4 *)(param_3 + 0x1c),4);
      pBVar2 = BN_MONT_CTX_set_locked
                         ((BN_MONT_CTX **)(param_3 + 0x48),*(int *)(param_3 + 0x5c),mod,param_4);
      if (pBVar2 != (BN_MONT_CTX *)0x0) {
        BN_with_flags(mod,*(undefined4 *)(param_3 + 0x20),4);
        pBVar2 = BN_MONT_CTX_set_locked
                           ((BN_MONT_CTX **)(param_3 + 0x4c),*(int *)(param_3 + 0x5c),mod,param_4);
        if (pBVar2 != (BN_MONT_CTX *)0x0) {
          iVar6 = 0;
          if (iVar9 != 0) {
            do {
              puVar3 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_3 + 0x30),iVar6);
              BN_with_flags(mod,*puVar3,4);
              iVar6 = iVar6 + 1;
              pBVar2 = BN_MONT_CTX_set_locked
                                 ((BN_MONT_CTX **)(puVar3 + 4),*(int *)(param_3 + 0x5c),mod,param_4)
              ;
              if (pBVar2 == (BN_MONT_CTX *)0x0) {
                BN_free(mod);
                pBVar7 = (BIGNUM *)0x0;
                goto LAB_0015a61c;
              }
            } while (iVar9 != iVar6);
            BN_free(mod);
LAB_0015a838:
            iVar6 = *(int *)(param_3 + 0x40);
            goto LAB_0015a606;
          }
          BN_free(mod);
          if (*(undefined **)(*(int *)(param_3 + 8) + 0x18) != (undefined *)0x193739)
          goto LAB_0015a838;
          iVar8 = BN_num_bits(*(BIGNUM **)(param_3 + 0x20));
          iVar4 = BN_num_bits(*(BIGNUM **)(param_3 + 0x1c));
          iVar6 = *(int *)(param_3 + 0x40);
          if (iVar8 != iVar4) goto LAB_0015a606;
          if ((((((iVar6 << 0x1e < 0) &&
                 (pBVar2 = BN_MONT_CTX_set_locked
                                     ((BN_MONT_CTX **)(param_3 + 0x44),*(int *)(param_3 + 0x5c),
                                      *(BIGNUM **)(param_3 + 0x10),param_4),
                 pBVar2 == (BN_MONT_CTX *)0x0)) ||
                (iVar9 = bn_from_mont_fixed_top
                                   (pBVar1,param_2,*(undefined4 *)(param_3 + 0x4c),param_4),
                iVar9 == 0)) ||
               ((iVar9 = bn_to_mont_fixed_top(pBVar1,pBVar1,*(undefined4 *)(param_3 + 0x4c),param_4)
                , iVar9 == 0 ||
                (iVar9 = BN_mod_exp_mont_consttime
                                   (pBVar1,pBVar1,*(BIGNUM **)(param_3 + 0x28),
                                    *(BIGNUM **)(param_3 + 0x20),param_4,
                                    *(BN_MONT_CTX **)(param_3 + 0x4c)), iVar9 == 0)))) ||
              (iVar9 = bn_from_mont_fixed_top(rr,param_2,*(undefined4 *)(param_3 + 0x48),param_4),
              iVar9 == 0)) ||
             ((((iVar9 = bn_to_mont_fixed_top(rr,rr,*(undefined4 *)(param_3 + 0x48),param_4),
                iVar9 == 0 ||
                (iVar9 = BN_mod_exp_mont_consttime
                                   (rr,rr,*(BIGNUM **)(param_3 + 0x24),*(BIGNUM **)(param_3 + 0x1c),
                                    param_4,*(BN_MONT_CTX **)(param_3 + 0x48)), iVar9 == 0)) ||
               ((iVar9 = bn_mod_sub_fixed_top(rr,rr,pBVar1,*(undefined4 *)(param_3 + 0x1c)),
                iVar9 == 0 ||
                (((iVar9 = bn_to_mont_fixed_top(rr,rr,*(undefined4 *)(param_3 + 0x48),param_4),
                  iVar9 == 0 ||
                  (iVar9 = bn_mul_mont_fixed_top
                                     (rr,rr,*(undefined4 *)(param_3 + 0x2c),
                                      *(undefined4 *)(param_3 + 0x48),param_4), iVar9 == 0)) ||
                 (iVar9 = bn_mul_fixed_top(param_1,rr,*(undefined4 *)(param_3 + 0x20),param_4),
                 iVar9 == 0)))))) ||
              (iVar9 = bn_mod_add_fixed_top(param_1,param_1,pBVar1,*(undefined4 *)(param_3 + 0x10)),
              iVar9 == 0)))) goto LAB_0015a61a;
          goto LAB_0015a95a;
        }
      }
LAB_0015a83e:
      pBVar7 = (BIGNUM *)0x0;
LAB_0015a840:
      BN_free(mod);
      goto LAB_0015a61c;
    }
LAB_0015a606:
    if (((-1 < iVar6 << 0x1e) ||
        (pBVar2 = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(param_3 + 0x44),*(int *)(param_3 + 0x5c),
                             *(BIGNUM **)(param_3 + 0x10),param_4), pBVar2 != (BN_MONT_CTX *)0x0))
       && (mod = BN_new(), mod != (BIGNUM *)0x0)) {
      BN_with_flags(mod,param_2,4);
      iVar6 = BN_div((BIGNUM *)0x0,rr,mod,*(BIGNUM **)(param_3 + 0x20),param_4);
      if (iVar6 == 0) {
        BN_free(mod);
        pBVar7 = (BIGNUM *)0x0;
        goto LAB_0015a61c;
      }
      pBVar7 = BN_new();
      if (pBVar7 == (BIGNUM *)0x0) {
        BN_free(mod);
        pBVar7 = (BIGNUM *)0x0;
        goto LAB_0015a61c;
      }
      BN_with_flags(pBVar7,*(undefined4 *)(param_3 + 0x28),4);
      iVar6 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                        (pBVar1,rr,pBVar7,*(undefined4 *)(param_3 + 0x20),param_4,
                         *(undefined4 *)(param_3 + 0x4c));
      if (iVar6 == 0) {
        BN_free(mod);
        BN_free(pBVar7);
        pBVar7 = (BIGNUM *)0x0;
        goto LAB_0015a61c;
      }
      BN_free(pBVar7);
      iVar6 = BN_div((BIGNUM *)0x0,rr,mod,*(BIGNUM **)(param_3 + 0x1c),param_4);
      if (iVar6 == 0) goto LAB_0015a83e;
      BN_free(mod);
      mod = BN_new();
      if (mod != (BIGNUM *)0x0) {
        BN_with_flags(mod,*(undefined4 *)(param_3 + 0x24),4);
        pBVar7 = (BIGNUM *)
                 (**(code **)(*(int *)(param_3 + 8) + 0x18))
                           (param_1,rr,mod,*(undefined4 *)(param_3 + 0x1c),param_4,
                            *(undefined4 *)(param_3 + 0x48));
        if (pBVar7 == (BIGNUM *)0x0) goto LAB_0015a840;
        BN_free(mod);
        if (iVar9 != 0) {
          mod = BN_new();
          a = BN_new();
          if (mod == (BIGNUM *)0x0 || a == (BIGNUM *)0x0) {
            BN_free(a);
            BN_free(mod);
            goto LAB_0015a61a;
          }
          iVar6 = 0;
          do {
            pBVar7 = BN_CTX_get(param_4);
            local_34[iVar6] = pBVar7;
            iVar8 = iVar6 + 1;
            if (pBVar7 == (BIGNUM *)0x0) {
LAB_0015a78a:
              BN_free(a);
              goto LAB_0015a840;
            }
            puVar3 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_3 + 0x30),iVar6);
            BN_with_flags(a,param_2,4);
            BN_with_flags(mod,puVar3[1],4);
            iVar6 = BN_div((BIGNUM *)0x0,rr,a,(BIGNUM *)*puVar3,param_4);
            if (iVar6 == 0) {
              BN_free(a);
              BN_free(mod);
              pBVar7 = (BIGNUM *)0x0;
              goto LAB_0015a61c;
            }
            iVar6 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                              (pBVar7,rr,mod,*puVar3,param_4,puVar3[4]);
            if (iVar6 == 0) {
              pBVar7 = (BIGNUM *)0x0;
              goto LAB_0015a78a;
            }
            iVar6 = iVar8;
          } while (iVar9 != iVar8);
          BN_free(a);
          BN_free(mod);
        }
        iVar6 = BN_sub(param_1,param_1,pBVar1);
        if (((iVar6 != 0) &&
            ((iVar6 = BN_is_negative(param_1), iVar6 == 0 ||
             (iVar6 = BN_add(param_1,param_1,*(BIGNUM **)(param_3 + 0x1c)), iVar6 != 0)))) &&
           ((iVar6 = BN_mul(rr,param_1,*(BIGNUM **)(param_3 + 0x2c),param_4), iVar6 != 0 &&
            (mod = BN_new(), mod != (BIGNUM *)0x0)))) {
          BN_with_flags(mod,rr,4);
          iVar6 = BN_div((BIGNUM *)0x0,param_1,mod,*(BIGNUM **)(param_3 + 0x1c),param_4);
          if (iVar6 == 0) goto LAB_0015a83e;
          BN_free(mod);
          iVar6 = BN_is_negative(param_1);
          if ((((iVar6 == 0) ||
               (iVar6 = BN_add(param_1,param_1,*(BIGNUM **)(param_3 + 0x1c)), iVar6 != 0)) &&
              (iVar6 = BN_mul(rr,param_1,*(BIGNUM **)(param_3 + 0x20),param_4), iVar6 != 0)) &&
             (iVar6 = BN_add(param_1,rr,pBVar1), iVar6 != 0)) {
            if (iVar9 != 0) {
              pBVar1 = BN_new();
              if (pBVar1 == (BIGNUM *)0x0) goto LAB_0015a61a;
              iVar6 = 0;
              do {
                puVar5 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_3 + 0x30),iVar6);
                puVar3 = local_34 + iVar6;
                iVar6 = iVar6 + 1;
                pBVar7 = (BIGNUM *)BN_sub(rr,(BIGNUM *)*puVar3,param_1);
                if ((pBVar7 == (BIGNUM *)0x0) ||
                   (pBVar7 = (BIGNUM *)BN_mul(r,rr,(BIGNUM *)puVar5[2],param_4),
                   pBVar7 == (BIGNUM *)0x0)) {
LAB_0015ab40:
                  BN_free(pBVar1);
                  goto LAB_0015a61c;
                }
                BN_with_flags(pBVar1,r,4);
                pBVar7 = (BIGNUM *)BN_div((BIGNUM *)0x0,rr,pBVar1,(BIGNUM *)*puVar5,param_4);
                if ((pBVar7 == (BIGNUM *)0x0) ||
                   ((iVar8 = BN_is_negative(rr), iVar8 != 0 &&
                    (pBVar7 = (BIGNUM *)BN_add(rr,rr,(BIGNUM *)*puVar5), pBVar7 == (BIGNUM *)0x0))))
                goto LAB_0015ab40;
                pBVar7 = (BIGNUM *)BN_mul(rr,rr,(BIGNUM *)puVar5[3],param_4);
                if ((pBVar7 == (BIGNUM *)0x0) ||
                   (pBVar7 = (BIGNUM *)BN_add(param_1,param_1,rr), pBVar7 == (BIGNUM *)0x0)) {
                  BN_free(pBVar1);
                  goto LAB_0015a61c;
                }
              } while (iVar9 != iVar6);
              BN_free(pBVar1);
            }
LAB_0015a95a:
            if ((*(BIGNUM **)(param_3 + 0x14) != (BIGNUM *)0x0) &&
               (*(BIGNUM **)(param_3 + 0x10) != (BIGNUM *)0x0)) {
              if (*(undefined **)(*(int *)(param_3 + 8) + 0x18) == (undefined *)0x193739) {
                iVar9 = BN_mod_exp_mont(r_00,param_1,*(BIGNUM **)(param_3 + 0x14),
                                        *(BIGNUM **)(param_3 + 0x10),param_4,
                                        *(BN_MONT_CTX **)(param_3 + 0x44));
              }
              else {
                bn_correct_top(param_1);
                iVar9 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                                  (r_00,param_1,*(undefined4 *)(param_3 + 0x14),
                                   *(undefined4 *)(param_3 + 0x10),param_4,
                                   *(undefined4 *)(param_3 + 0x44));
              }
              if ((iVar9 == 0) || (iVar9 = BN_sub(r_00,r_00,param_2), iVar9 == 0))
              goto LAB_0015a61a;
              iVar9 = BN_is_zero(r_00);
              if (iVar9 == 0) {
                iVar9 = BN_div((BIGNUM *)0x0,r_00,r_00,*(BIGNUM **)(param_3 + 0x10),param_4);
                if ((iVar9 == 0) ||
                   ((iVar9 = BN_is_negative(r_00), iVar9 != 0 &&
                    (iVar9 = BN_add(r_00,r_00,*(BIGNUM **)(param_3 + 0x10)), iVar9 == 0))))
                goto LAB_0015a61a;
                iVar9 = BN_is_zero(r_00);
                if (iVar9 == 0) {
                  mod = BN_new();
                  if (mod == (BIGNUM *)0x0) goto LAB_0015a61a;
                  BN_with_flags(mod,*(undefined4 *)(param_3 + 0x18),4);
                  pBVar7 = (BIGNUM *)
                           (**(code **)(*(int *)(param_3 + 8) + 0x18))
                                     (param_1,param_2,mod,*(undefined4 *)(param_3 + 0x10),param_4,
                                      *(undefined4 *)(param_3 + 0x44));
                  if (pBVar7 == (BIGNUM *)0x0) goto LAB_0015a840;
                  BN_free(mod);
                }
              }
            }
            pBVar7 = (BIGNUM *)0x1;
            bn_correct_top(param_1);
            goto LAB_0015a61c;
          }
        }
      }
    }
  }
LAB_0015a61a:
  pBVar7 = (BIGNUM *)0x0;
LAB_0015a61c:
  BN_CTX_end(param_4);
  return pBVar7;
}

