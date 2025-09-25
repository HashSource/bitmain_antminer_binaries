
int ec_group_do_inverse_ord(int *param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *a;
  BN_CTX *c;
  
  if (*(code **)(*param_1 + 200) == (code *)0x0) {
    if ((param_1[0x17] == 0) ||
       ((c = (BN_CTX *)0x0, param_4 == (BN_CTX *)0x0 &&
        (c = (BN_CTX *)BN_CTX_secure_new(), param_4 = c, c == (BN_CTX *)0x0)))) {
      iVar1 = 0;
    }
    else {
      BN_CTX_start(param_4);
      a = BN_CTX_get(param_4);
      if (((a == (BIGNUM *)0x0) || (iVar1 = BN_set_word(a,2), iVar1 == 0)) ||
         (iVar1 = BN_sub(a,(BIGNUM *)param_1[2],a), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = BN_mod_exp_mont(param_2,param_3,a,(BIGNUM *)param_1[2],param_4,
                                (BN_MONT_CTX *)param_1[0x17]);
        if (iVar1 != 0) {
          iVar1 = 1;
        }
      }
      BN_CTX_end(param_4);
      BN_CTX_free(c);
    }
    return iVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x0011af96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(*param_1 + 200))();
  return iVar1;
}

