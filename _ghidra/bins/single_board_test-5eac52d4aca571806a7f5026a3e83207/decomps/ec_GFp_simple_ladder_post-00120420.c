
int ec_GFp_simple_ladder_post
              (EC_GROUP *param_1,EC_POINT *param_2,int param_3,EC_POINT *param_4,BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *b;
  BIGNUM *r;
  BIGNUM *b_00;
  BIGNUM *pBVar2;
  BIGNUM *r_00;
  BIGNUM *pBVar3;
  BIGNUM *b_01;
  
  iVar1 = BN_is_zero(*(undefined4 *)(param_2 + 0x10));
  if (iVar1 != 0) {
    iVar1 = EC_POINT_set_to_infinity(param_1,param_2);
    return iVar1;
  }
  iVar1 = BN_is_zero(*(undefined4 *)(param_3 + 0x10));
  if (iVar1 != 0) {
    iVar1 = EC_POINT_copy(param_2,param_4);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = EC_POINT_invert(param_1,param_2,param_5);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  BN_CTX_start(param_5);
  b = BN_CTX_get(param_5);
  r = BN_CTX_get(param_5);
  b_00 = BN_CTX_get(param_5);
  pBVar2 = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  pBVar3 = BN_CTX_get(param_5);
  b_01 = BN_CTX_get(param_5);
  if (((((((((b_01 != (BIGNUM *)0x0) &&
            (iVar1 = BN_mod_lshift1_quick
                               (r_00,*(BIGNUM **)(param_4 + 0xc),*(BIGNUM **)(param_1 + 0x28)),
            iVar1 != 0)) &&
           (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                              (param_1,b_01,*(undefined4 *)(param_2 + 8),r_00,param_5), iVar1 != 0))
          && ((iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                 (param_1,b_01,*(undefined4 *)(param_3 + 0x10),b_01,param_5),
              iVar1 != 0 &&
              (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                 (param_1,pBVar3,*(undefined4 *)(param_2 + 0x10),b_01,param_5),
              iVar1 != 0)))) &&
         (iVar1 = BN_mod_lshift1_quick(r,*(BIGNUM **)(param_1 + 0x48),*(BIGNUM **)(param_1 + 0x28)),
         iVar1 != 0)) &&
        (((iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                             (param_1,r,*(undefined4 *)(param_3 + 0x10),r,param_5), iVar1 != 0 &&
          (iVar1 = (**(code **)(*(int *)param_1 + 0x8c))
                             (param_1,pBVar2,*(undefined4 *)(param_2 + 0x10),param_5), iVar1 != 0))
         && ((iVar1 = (**(code **)(*(int *)param_1 + 0x88))(param_1,b_00,pBVar2,r,param_5),
             iVar1 != 0 &&
             (((iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                  (param_1,b_01,*(undefined4 *)(param_2 + 0x10),
                                   *(undefined4 *)(param_1 + 0x44),param_5), iVar1 != 0 &&
               (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                  (param_1,r,*(undefined4 *)(param_4 + 8),
                                   *(undefined4 *)(param_2 + 8),param_5), iVar1 != 0)) &&
              (iVar1 = BN_mod_add_quick(r,r,b_01,*(BIGNUM **)(param_1 + 0x28)), iVar1 != 0))))))))
       && ((iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                              (param_1,r,*(undefined4 *)(param_3 + 0x10),r,param_5), iVar1 != 0 &&
           (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                              (param_1,b,*(undefined4 *)(param_4 + 8),
                               *(undefined4 *)(param_2 + 0x10),param_5), iVar1 != 0)))) &&
      ((iVar1 = BN_mod_add_quick(b_01,*(BIGNUM **)(param_2 + 8),b,*(BIGNUM **)(param_1 + 0x28)),
       iVar1 != 0 &&
       (((iVar1 = (**(code **)(*(int *)param_1 + 0x88))(param_1,b_01,b_01,r,param_5), iVar1 != 0 &&
         (iVar1 = BN_mod_add_quick(b_01,b_01,b_00,*(BIGNUM **)(param_1 + 0x28)), iVar1 != 0)) &&
        ((iVar1 = BN_mod_sub_quick(b,b,*(BIGNUM **)(param_2 + 8),*(BIGNUM **)(param_1 + 0x28)),
         iVar1 != 0 &&
         (((iVar1 = (**(code **)(*(int *)param_1 + 0x8c))(param_1,b,b,param_5), iVar1 != 0 &&
           (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                              (param_1,b,b,*(undefined4 *)(param_3 + 8),param_5), iVar1 != 0)) &&
          (iVar1 = BN_mod_sub_quick(b,b_01,b,*(BIGNUM **)(param_1 + 0x28)), iVar1 != 0)))))))))) &&
     ((iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                         (param_1,r,*(undefined4 *)(param_3 + 0x10),r_00,param_5), iVar1 != 0 &&
      (iVar1 = (**(code **)(*(int *)param_1 + 0x88))(param_1,r,pBVar2,r,param_5), iVar1 != 0)))) {
    iVar1 = *(int *)param_1;
    if (*(code **)(iVar1 + 0x9c) != (code *)0x0) {
      iVar1 = (**(code **)(iVar1 + 0x9c))(param_1,r,r,param_5);
      if (iVar1 == 0) goto LAB_00120492;
      iVar1 = *(int *)param_1;
    }
    iVar1 = (**(code **)(iVar1 + 0x94))(param_1,r,r,param_5);
    if (iVar1 != 0) {
      iVar1 = *(int *)param_1;
      if (*(code **)(iVar1 + 0x98) != (code *)0x0) {
        iVar1 = (**(code **)(iVar1 + 0x98))(param_1,r,r,param_5);
        if (iVar1 == 0) goto LAB_00120492;
        iVar1 = *(int *)param_1;
      }
      iVar1 = (**(code **)(iVar1 + 0x88))(param_1,*(undefined4 *)(param_2 + 8),pBVar3,r,param_5);
      if ((iVar1 != 0) &&
         (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                            (param_1,*(undefined4 *)(param_2 + 0xc),b,r,param_5), iVar1 != 0)) {
        if (*(code **)(*(int *)param_1 + 0xa0) == (code *)0x0) {
          iVar1 = BN_set_word(*(BIGNUM **)(param_2 + 0x10),1);
        }
        else {
          iVar1 = (**(code **)(*(int *)param_1 + 0xa0))
                            (param_1,*(undefined4 *)(param_2 + 0x10),param_5);
        }
        if (iVar1 != 0) {
          iVar1 = 1;
          *(undefined4 *)(param_2 + 0x14) = 1;
          goto LAB_00120494;
        }
      }
    }
  }
LAB_00120492:
  iVar1 = 0;
LAB_00120494:
  BN_CTX_end(param_5);
  return iVar1;
}

