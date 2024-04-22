
int ec_GFp_simple_dbl(int *param_1,int param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *pBVar2;
  code *pcVar3;
  BIGNUM *m;
  code *pcVar4;
  BN_CTX *c;
  EC_POINT *local_38;
  
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_3);
  if (iVar1 != 0) {
    BN_set_word((BIGNUM *)(param_2 + 0x2c),0);
    *(undefined4 *)(param_2 + 0x40) = 0;
    return 1;
  }
  m = (BIGNUM *)(param_1 + 0x12);
  pcVar4 = *(code **)(*param_1 + 0x84);
  pcVar3 = *(code **)(*param_1 + 0x88);
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
    if (*(int *)(param_3 + 0x40) == 0) {
      if (param_1[0x27] == 0) {
        iVar1 = (*pcVar3)(param_1,a,param_3 + 4,param_4);
        if ((((iVar1 != 0) && (iVar1 = BN_mod_lshift1_quick(r,a,m), iVar1 != 0)) &&
            (iVar1 = BN_mod_add_quick(a,a,r,m), iVar1 != 0)) &&
           (((iVar1 = (*pcVar3)(param_1,r,param_3 + 0x2c,param_4), iVar1 != 0 &&
             (iVar1 = (*pcVar3)(param_1,r,r,param_4), iVar1 != 0)) &&
            (iVar1 = (*pcVar4)(param_1,r,r,param_1 + 0x1d,param_4), iVar1 != 0)))) {
          iVar1 = BN_mod_add_quick(r,r,a,m);
          goto joined_r0x0012a05e;
        }
      }
      else {
        iVar1 = (*pcVar3)(param_1,r,param_3 + 0x2c,param_4);
        if (iVar1 != 0) {
          iVar1 = BN_mod_add_quick(a,(BIGNUM *)(param_3 + 4),r,m);
          if (((iVar1 != 0) &&
              (iVar1 = BN_mod_sub_quick(r_00,(BIGNUM *)(param_3 + 4),r,m), iVar1 != 0)) &&
             ((iVar1 = (*pcVar4)(param_1,r,a,r_00,param_4), iVar1 != 0 &&
              (iVar1 = BN_mod_lshift1_quick(a,r,m), iVar1 != 0)))) {
            iVar1 = BN_mod_add_quick(r,a,r,m);
            goto joined_r0x0012a05e;
          }
        }
      }
    }
    else {
      iVar1 = (*pcVar3)(param_1,a,param_3 + 4,param_4);
      if (((iVar1 != 0) && (iVar1 = BN_mod_lshift1_quick(r,a,m), iVar1 != 0)) &&
         (iVar1 = BN_mod_add_quick(a,a,r,m), iVar1 != 0)) {
        iVar1 = BN_mod_add_quick(r,a,(BIGNUM *)(param_1 + 0x1d),m);
joined_r0x0012a05e:
        if (iVar1 != 0) {
          local_38 = param_3 + 4;
          if (*(int *)(param_3 + 0x40) == 0) {
            pBVar2 = (BIGNUM *)(*pcVar4)(param_1,a,param_3 + 0x18,param_3 + 0x2c,param_4);
          }
          else {
            pBVar2 = BN_copy(a,(BIGNUM *)(param_3 + 0x18));
          }
          if (pBVar2 != (BIGNUM *)0x0) {
            iVar1 = BN_mod_lshift1_quick((BIGNUM *)(param_2 + 0x2c),a,m);
            if (iVar1 != 0) {
              *(undefined4 *)(param_2 + 0x40) = 0;
              iVar1 = (*pcVar3)(param_1,r_01,param_3 + 0x18,param_4);
              if (((iVar1 != 0) &&
                  (iVar1 = (*pcVar4)(param_1,r_00,local_38,r_01,param_4), iVar1 != 0)) &&
                 ((iVar1 = BN_mod_lshift_quick(r_00,r_00,2,m), iVar1 != 0 &&
                  (iVar1 = BN_mod_lshift1_quick(a,r_00,m), iVar1 != 0)))) {
                pBVar2 = (BIGNUM *)(param_2 + 4);
                iVar1 = (*pcVar3)(param_1,pBVar2,r,param_4);
                if ((((iVar1 != 0) && (iVar1 = BN_mod_sub_quick(pBVar2,pBVar2,a,m), iVar1 != 0)) &&
                    (iVar1 = (*pcVar3)(param_1,a,r_01,param_4), iVar1 != 0)) &&
                   (((iVar1 = BN_mod_lshift_quick(r_01,a,3,m), iVar1 != 0 &&
                     (iVar1 = BN_mod_sub_quick(a,r_00,pBVar2,m), iVar1 != 0)) &&
                    (iVar1 = (*pcVar4)(param_1,a,r,a,param_4), iVar1 != 0)))) {
                  iVar1 = BN_mod_sub_quick((BIGNUM *)(param_2 + 0x18),a,r_01,m);
                  if (iVar1 != 0) {
                    iVar1 = 1;
                  }
                  goto LAB_00129fd2;
                }
              }
            }
          }
        }
      }
    }
  }
  iVar1 = 0;
LAB_00129fd2:
  BN_CTX_end(param_4);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return iVar1;
}

