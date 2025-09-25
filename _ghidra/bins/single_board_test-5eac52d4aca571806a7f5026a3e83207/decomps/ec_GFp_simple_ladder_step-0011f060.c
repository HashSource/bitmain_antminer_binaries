
int ec_GFp_simple_ladder_step(int *param_1,int param_2,int param_3,int param_4,BN_CTX *param_5)

{
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *a;
  BIGNUM *b;
  BIGNUM *r_02;
  BIGNUM *a_00;
  int iVar1;
  
  BN_CTX_start(param_5);
  r = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  r_01 = BN_CTX_get(param_5);
  a = BN_CTX_get(param_5);
  b = BN_CTX_get(param_5);
  r_02 = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  if (((((((((a_00 == (BIGNUM *)0x0) ||
            (iVar1 = (**(code **)(*param_1 + 0x88))
                               (param_1,a_00,*(undefined4 *)(param_2 + 8),
                                *(undefined4 *)(param_3 + 8),param_5), iVar1 == 0)) ||
           (iVar1 = (**(code **)(*param_1 + 0x88))
                              (param_1,r,*(undefined4 *)(param_2 + 0x10),
                               *(undefined4 *)(param_3 + 0x10),param_5), iVar1 == 0)) ||
          ((iVar1 = (**(code **)(*param_1 + 0x88))
                              (param_1,b,*(undefined4 *)(param_2 + 8),
                               *(undefined4 *)(param_3 + 0x10),param_5), iVar1 == 0 ||
           (iVar1 = (**(code **)(*param_1 + 0x88))
                              (param_1,a,*(undefined4 *)(param_2 + 0x10),
                               *(undefined4 *)(param_3 + 8),param_5), iVar1 == 0)))) ||
         ((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,r_02,param_1[0x11],r,param_5), iVar1 == 0
          || ((iVar1 = BN_mod_add_quick(r_02,a_00,r_02,(BIGNUM *)param_1[10]), iVar1 == 0 ||
              (iVar1 = BN_mod_add_quick(a_00,a,b,(BIGNUM *)param_1[10]), iVar1 == 0)))))) ||
        (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,r_02,a_00,r_02,param_5), iVar1 == 0)) ||
       (((((iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,r,r,param_5), iVar1 == 0 ||
           (iVar1 = BN_mod_lshift_quick(r_01,(BIGNUM *)param_1[0x12],2,(BIGNUM *)param_1[10]),
           iVar1 == 0)) ||
          (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,r,r_01,r,param_5), iVar1 == 0)) ||
         (((iVar1 = BN_mod_lshift1_quick(r_02,r_02,(BIGNUM *)param_1[10]), iVar1 == 0 ||
           (iVar1 = BN_mod_sub_quick(a,b,a,(BIGNUM *)param_1[10]), iVar1 == 0)) ||
          ((iVar1 = (**(code **)(*param_1 + 0x8c))
                              (param_1,*(undefined4 *)(param_3 + 0x10),a,param_5), iVar1 == 0 ||
           ((iVar1 = (**(code **)(*param_1 + 0x88))
                               (param_1,b,*(undefined4 *)(param_3 + 0x10),
                                *(undefined4 *)(param_4 + 8),param_5), iVar1 == 0 ||
            (iVar1 = BN_mod_add_quick(r,r,r_02,(BIGNUM *)param_1[10]), iVar1 == 0)))))))) ||
        ((iVar1 = BN_mod_sub_quick(*(BIGNUM **)(param_3 + 8),r,b,(BIGNUM *)param_1[10]), iVar1 == 0
         || (((iVar1 = (**(code **)(*param_1 + 0x8c))
                                 (param_1,b,*(undefined4 *)(param_2 + 8),param_5), iVar1 == 0 ||
              (iVar1 = (**(code **)(*param_1 + 0x8c))
                                 (param_1,r_02,*(undefined4 *)(param_2 + 0x10),param_5), iVar1 == 0)
              ) || (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,a_00,r_02,param_1[0x11],param_5),
                   iVar1 == 0)))))))) ||
      ((((iVar1 = BN_mod_add_quick(r_00,*(BIGNUM **)(param_2 + 8),*(BIGNUM **)(param_2 + 0x10),
                                   (BIGNUM *)param_1[10]), iVar1 == 0 ||
         (iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,r_00,r_00,param_5), iVar1 == 0)) ||
        (((iVar1 = BN_mod_sub_quick(r_00,r_00,b,(BIGNUM *)param_1[10]), iVar1 == 0 ||
          ((iVar1 = BN_mod_sub_quick(r_00,r_00,r_02,(BIGNUM *)param_1[10]), iVar1 == 0 ||
           (iVar1 = BN_mod_sub_quick(a,b,a_00,(BIGNUM *)param_1[10]), iVar1 == 0)))) ||
         (iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,a,a,param_5), iVar1 == 0)))) ||
       ((((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,r,r_02,r_00,param_5), iVar1 == 0 ||
          (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,r,r_01,r,param_5), iVar1 == 0)) ||
         (iVar1 = BN_mod_sub_quick(*(BIGNUM **)(param_2 + 8),a,r,(BIGNUM *)param_1[10]), iVar1 == 0)
         ) || ((iVar1 = BN_mod_add_quick(a,b,a_00,(BIGNUM *)param_1[10]), iVar1 == 0 ||
               (iVar1 = (**(code **)(*param_1 + 0x8c))(param_1,b,r_02,param_5), iVar1 == 0))))))))
     || ((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,b,b,r_01,param_5), iVar1 == 0 ||
         ((iVar1 = (**(code **)(*param_1 + 0x88))(param_1,r_00,r_00,a,param_5), iVar1 == 0 ||
          (iVar1 = BN_mod_lshift1_quick(r_00,r_00,(BIGNUM *)param_1[10]), iVar1 == 0)))))) {
    iVar1 = 0;
  }
  else {
    iVar1 = BN_mod_add_quick(*(BIGNUM **)(param_2 + 0x10),b,r_00,(BIGNUM *)param_1[10]);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  BN_CTX_end(param_5);
  return iVar1;
}

