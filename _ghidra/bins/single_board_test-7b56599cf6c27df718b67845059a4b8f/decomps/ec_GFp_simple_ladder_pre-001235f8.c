
undefined4
ec_GFp_simple_ladder_pre(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *a;
  BIGNUM *r_01;
  BIGNUM *r_02;
  
  if (*(int *)(param_4 + 0x14) != 0) {
    r = *(BIGNUM **)(param_3 + 0x10);
    a = *(BIGNUM **)(param_3 + 8);
    r_00 = *(BIGNUM **)(param_2 + 0x10);
    r_01 = *(BIGNUM **)(param_2 + 8);
    r_02 = *(BIGNUM **)(param_3 + 0xc);
    iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,a,*(undefined4 *)(param_4 + 8),param_5);
    if (((((iVar1 != 0) &&
          (iVar1 = BN_mod_sub_quick(r_01,a,(BIGNUM *)param_1[0x11],(BIGNUM *)param_1[10]),
          iVar1 != 0)) &&
         (iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,r_01,r_01,param_5), iVar1 != 0)) &&
        ((((iVar1 = (**(code **)(*param_1 + 0x88))
                              (param_1,r_02,*(undefined4 *)(param_4 + 8),param_1[0x12],param_5),
           iVar1 != 0 &&
           (iVar1 = BN_mod_lshift_quick(r_02,r_02,3,(BIGNUM *)param_1[10]), iVar1 != 0)) &&
          ((iVar1 = BN_mod_sub_quick(*(BIGNUM **)(param_2 + 8),r_01,r_02,(BIGNUM *)param_1[10]),
           iVar1 != 0 &&
           ((iVar1 = BN_mod_add_quick(r,a,(BIGNUM *)param_1[0x11],(BIGNUM *)param_1[10]), iVar1 != 0
            && (iVar1 = (**(code **)(*param_1 + 0x88))
                                  (param_1,r_00,*(undefined4 *)(param_4 + 8),r,param_5), iVar1 != 0)
            ))))) &&
         (iVar1 = BN_mod_add_quick(r_00,(BIGNUM *)param_1[0x12],r_00,(BIGNUM *)param_1[10]),
         iVar1 != 0)))) &&
       (iVar1 = BN_mod_lshift_quick(*(BIGNUM **)(param_2 + 0x10),r_00,2,(BIGNUM *)param_1[10]),
       iVar1 != 0)) {
      do {
        iVar1 = BN_priv_rand_range(*(undefined4 *)(param_2 + 0xc),param_1[10]);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = BN_is_zero(*(undefined4 *)(param_2 + 0xc));
      } while (iVar1 != 0);
      do {
        iVar1 = BN_priv_rand_range(*(undefined4 *)(param_3 + 0x10),param_1[10]);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = BN_is_zero(*(undefined4 *)(param_3 + 0x10));
      } while (iVar1 != 0);
      iVar1 = *param_1;
      if (*(code **)(iVar1 + 0x98) != (code *)0x0) {
        iVar1 = (**(code **)(iVar1 + 0x98))
                          (param_1,*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0xc),
                           param_5);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = (**(code **)(*param_1 + 0x98))
                          (param_1,*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x10),
                           param_5);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = *param_1;
      }
      iVar1 = (**(code **)(iVar1 + 0x88))
                        (param_1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x10),
                         *(undefined4 *)(param_2 + 0xc),param_5);
      if (((iVar1 != 0) &&
          (iVar1 = (**(code **)(*param_1 + 0x88))
                             (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 8),
                              *(undefined4 *)(param_2 + 0xc),param_5), iVar1 != 0)) &&
         (iVar1 = (**(code **)(*param_1 + 0x88))
                            (param_1,*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_4 + 8),
                             *(undefined4 *)(param_3 + 0x10),param_5), iVar1 != 0)) {
        *(undefined4 *)(param_2 + 0x14) = 0;
        *(undefined4 *)(param_3 + 0x14) = 0;
        return 1;
      }
    }
  }
  return 0;
}

