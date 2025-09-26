
undefined4
SSL_set_srp_server_param
          (int param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5,
          undefined4 param_6)

{
  BIGNUM *pBVar1;
  undefined4 uVar2;
  
  if (param_2 != (BIGNUM *)0x0) {
    if (*(BIGNUM **)(param_1 + 0x1a8) == (BIGNUM *)0x0) {
      pBVar1 = BN_dup(param_2);
      *(BIGNUM **)(param_1 + 0x1a8) = pBVar1;
    }
    else {
      pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x1a8),param_2);
      if (pBVar1 == (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x1a8));
        *(undefined4 *)(param_1 + 0x1a8) = 0;
      }
    }
  }
  if (param_3 != (BIGNUM *)0x0) {
    if (*(BIGNUM **)(param_1 + 0x1ac) == (BIGNUM *)0x0) {
      pBVar1 = BN_dup(param_3);
      *(BIGNUM **)(param_1 + 0x1ac) = pBVar1;
    }
    else {
      pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x1ac),param_3);
      if (pBVar1 == (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x1ac));
        *(undefined4 *)(param_1 + 0x1ac) = 0;
      }
    }
  }
  if (param_4 != (BIGNUM *)0x0) {
    if (*(BIGNUM **)(param_1 + 0x1b0) == (BIGNUM *)0x0) {
      pBVar1 = BN_dup(param_4);
      *(BIGNUM **)(param_1 + 0x1b0) = pBVar1;
    }
    else {
      pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x1b0),param_4);
      if (pBVar1 == (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x1b0));
        *(undefined4 *)(param_1 + 0x1b0) = 0;
      }
    }
  }
  if (param_5 != (BIGNUM *)0x0) {
    if (*(BIGNUM **)(param_1 + 0x1c4) == (BIGNUM *)0x0) {
      pBVar1 = BN_dup(param_5);
      *(BIGNUM **)(param_1 + 0x1c4) = pBVar1;
    }
    else {
      pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x1c4),param_5);
      if (pBVar1 == (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x1c4));
        *(undefined4 *)(param_1 + 0x1c4) = 0;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x1c8) = param_6;
  if ((((*(int *)(param_1 + 0x1a8) == 0) || (*(int *)(param_1 + 0x1ac) == 0)) ||
      (*(int *)(param_1 + 0x1b0) == 0)) || (*(int *)(param_1 + 0x1c4) == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

