
undefined4
witness(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,int param_5,BN_CTX *param_6,
       BN_MONT_CTX *param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = BN_mod_exp_mont(param_1,param_1,param_4,param_2,param_6,param_7);
  if (iVar1 == 0) {
LAB_000f30c0:
    uVar2 = 0xffffffff;
  }
  else {
    if (((param_1->top != 1) || (*param_1->d != 1)) || (param_1->neg != 0)) {
      iVar1 = BN_cmp(param_1,param_3);
      while (iVar1 != 0) {
        param_5 = param_5 + -1;
        if (param_5 == 0) {
          return 1;
        }
        iVar1 = BN_mod_mul(param_1,param_1,param_1,param_2,param_6);
        if (iVar1 == 0) goto LAB_000f30c0;
        if (((param_1->top == 1) && (*param_1->d == 1)) && (param_1->neg == 0)) {
          return 1;
        }
        iVar1 = BN_cmp(param_1,param_3);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

