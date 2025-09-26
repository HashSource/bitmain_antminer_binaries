
undefined4
SSL_set_srp_server_param
          (int param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5,char *param_6
          )

{
  BIGNUM *pBVar1;
  char *pcVar2;
  
  if (param_2 != (BIGNUM *)0x0) {
    if (*(BIGNUM **)(param_1 + 0x620) == (BIGNUM *)0x0) {
      pBVar1 = BN_dup(param_2);
      *(BIGNUM **)(param_1 + 0x620) = pBVar1;
    }
    else {
      pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x620),param_2);
      if (pBVar1 == (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x620));
        *(undefined4 *)(param_1 + 0x620) = 0;
      }
    }
  }
  if (param_3 != (BIGNUM *)0x0) {
    if (*(BIGNUM **)(param_1 + 0x624) == (BIGNUM *)0x0) {
      pBVar1 = BN_dup(param_3);
      *(BIGNUM **)(param_1 + 0x624) = pBVar1;
    }
    else {
      pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x624),param_3);
      if (pBVar1 == (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x624));
        *(undefined4 *)(param_1 + 0x624) = 0;
      }
    }
  }
  if (param_4 != (BIGNUM *)0x0) {
    if (*(BIGNUM **)(param_1 + 0x628) == (BIGNUM *)0x0) {
      pBVar1 = BN_dup(param_4);
      *(BIGNUM **)(param_1 + 0x628) = pBVar1;
    }
    else {
      pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x628),param_4);
      if (pBVar1 == (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x628));
        *(undefined4 *)(param_1 + 0x628) = 0;
      }
    }
  }
  if (param_5 != (BIGNUM *)0x0) {
    if (*(BIGNUM **)(param_1 + 0x63c) == (BIGNUM *)0x0) {
      pBVar1 = BN_dup(param_5);
      *(BIGNUM **)(param_1 + 0x63c) = pBVar1;
    }
    else {
      pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x63c),param_5);
      if (pBVar1 == (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x63c));
        *(undefined4 *)(param_1 + 0x63c) = 0;
      }
    }
  }
  if (param_6 != (char *)0x0) {
    if (*(void **)(param_1 + 0x640) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x640));
    }
    pcVar2 = CRYPTO_strdup(param_6,"ssl/tls_srp.c",0xee);
    *(char **)(param_1 + 0x640) = pcVar2;
    if (pcVar2 == (char *)0x0) {
      return 0xffffffff;
    }
  }
  if ((((*(int *)(param_1 + 0x620) != 0) && (*(int *)(param_1 + 0x624) != 0)) &&
      (*(int *)(param_1 + 0x628) != 0)) && (*(int *)(param_1 + 0x63c) != 0)) {
    return 1;
  }
  return 0xffffffff;
}

