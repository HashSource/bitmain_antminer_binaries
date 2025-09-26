
/* WARNING: Type propagation algorithm not settling */

int ec_GFp_simple_dbl(EC_GROUP *param_1,int param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *pBVar2;
  BIGNUM *m;
  code *pcVar3;
  code *pcVar4;
  BN_CTX *c;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
  if (iVar1 != 0) {
    BN_set_word(*(BIGNUM **)(param_2 + 0x10),0);
    *(undefined4 *)(param_2 + 0x14) = 0;
    return 1;
  }
  m = *(BIGNUM **)(param_1 + 0x28);
  pcVar3 = *(code **)(*(int *)param_1 + 0x88);
  pcVar4 = *(code **)(*(int *)param_1 + 0x8c);
  c = (BN_CTX *)0x0;
  if ((param_4 == (BN_CTX *)0x0) && (param_4 = BN_CTX_new(), c = param_4, param_4 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  r = BN_CTX_get(param_4);
  r_00 = BN_CTX_get(param_4);
  r_01 = BN_CTX_get(param_4);
  if (r_01 != (BIGNUM *)0x0) {
    if (*(int *)(param_3 + 0x14) == 0) {
      if (*(int *)(param_1 + 0x4c) == 0) {
        iVar1 = (*pcVar4)(param_1,a,*(undefined4 *)(param_3 + 8),param_4);
        if ((((iVar1 != 0) && (iVar1 = BN_mod_lshift1_quick(r,a,m), iVar1 != 0)) &&
            ((iVar1 = BN_mod_add_quick(a,a,r,m), iVar1 != 0 &&
             ((iVar1 = (*pcVar4)(param_1,r,*(undefined4 *)(param_3 + 0x10),param_4), iVar1 != 0 &&
              (iVar1 = (*pcVar4)(param_1,r,r,param_4), iVar1 != 0)))))) &&
           (iVar1 = (*pcVar3)(param_1,r,r,*(undefined4 *)(param_1 + 0x44),param_4), iVar1 != 0)) {
          iVar1 = BN_mod_add_quick(r,r,a,m);
          goto joined_r0x0012ccac;
        }
      }
      else {
        iVar1 = (*pcVar4)(param_1,r,*(undefined4 *)(param_3 + 0x10),param_4);
        if ((((iVar1 != 0) &&
             (iVar1 = BN_mod_add_quick(a,*(BIGNUM **)(param_3 + 8),r,m), iVar1 != 0)) &&
            (iVar1 = BN_mod_sub_quick(r_00,*(BIGNUM **)(param_3 + 8),r,m), iVar1 != 0)) &&
           ((iVar1 = (*pcVar3)(param_1,r,a,r_00,param_4), iVar1 != 0 &&
            (iVar1 = BN_mod_lshift1_quick(a,r,m), iVar1 != 0)))) {
          iVar1 = BN_mod_add_quick(r,a,r,m);
joined_r0x0012ccac:
          if (iVar1 != 0) {
            if (*(int *)(param_3 + 0x14) == 0) {
              pBVar2 = (BIGNUM *)
                       (*pcVar3)(param_1,a,*(undefined4 *)(param_3 + 0xc),
                                 *(undefined4 *)(param_3 + 0x10),param_4);
            }
            else {
              pBVar2 = BN_copy(a,*(BIGNUM **)(param_3 + 0xc));
            }
            if ((pBVar2 != (BIGNUM *)0x0) &&
               (iVar1 = BN_mod_lshift1_quick(*(BIGNUM **)(param_2 + 0x10),a,m), iVar1 != 0)) {
              *(undefined4 *)(param_2 + 0x14) = 0;
              iVar1 = (*pcVar4)(param_1,r_01,*(undefined4 *)(param_3 + 0xc),param_4);
              if (((((iVar1 != 0) &&
                    (((iVar1 = (*pcVar3)(param_1,r_00,*(undefined4 *)(param_3 + 8),r_01,param_4),
                      iVar1 != 0 && (iVar1 = BN_mod_lshift_quick(r_00,r_00,2,m), iVar1 != 0)) &&
                     (iVar1 = BN_mod_lshift1_quick(a,r_00,m), iVar1 != 0)))) &&
                   (((iVar1 = (*pcVar4)(param_1,*(undefined4 *)(param_2 + 8),r,param_4), iVar1 != 0
                     && (iVar1 = BN_mod_sub_quick(*(BIGNUM **)(param_2 + 8),
                                                  *(BIGNUM **)(param_2 + 8),a,m), iVar1 != 0)) &&
                    (iVar1 = (*pcVar4)(param_1,a,r_01,param_4), iVar1 != 0)))) &&
                  ((iVar1 = BN_mod_lshift_quick(r_01,a,3,m), iVar1 != 0 &&
                   (iVar1 = BN_mod_sub_quick(a,r_00,*(BIGNUM **)(param_2 + 8),m), iVar1 != 0)))) &&
                 (iVar1 = (*pcVar3)(param_1,a,r,a,param_4), iVar1 != 0)) {
                iVar1 = BN_mod_sub_quick(*(BIGNUM **)(param_2 + 0xc),a,r_01,m);
                if (iVar1 != 0) {
                  iVar1 = 1;
                }
                goto LAB_0012cc2a;
              }
            }
          }
        }
      }
    }
    else {
      iVar1 = (*pcVar4)(param_1,a,*(undefined4 *)(param_3 + 8),param_4);
      if (((iVar1 != 0) && (iVar1 = BN_mod_lshift1_quick(r,a,m), iVar1 != 0)) &&
         (iVar1 = BN_mod_add_quick(a,a,r,m), iVar1 != 0)) {
        iVar1 = BN_mod_add_quick(r,a,*(BIGNUM **)(param_1 + 0x44),m);
        goto joined_r0x0012ccac;
      }
    }
  }
  iVar1 = 0;
LAB_0012cc2a:
  BN_CTX_end(param_4);
  BN_CTX_free(c);
  return iVar1;
}

