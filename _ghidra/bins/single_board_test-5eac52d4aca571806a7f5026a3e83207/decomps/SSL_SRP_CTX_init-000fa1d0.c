
undefined4 SSL_SRP_CTX_init(int param_1)

{
  BIGNUM *pBVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int line;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar6 = *(int *)(param_1 + 0x4d0);
  if (iVar6 == 0) {
    return 0;
  }
  memset((void *)(param_1 + 0x60c),0,0x40);
  uVar5 = *(undefined4 *)(iVar6 + 0x1f8);
  pBVar1 = *(BIGNUM **)(iVar6 + 0x1d4);
  uVar7 = *(undefined4 *)(iVar6 + 0x1c4);
  uVar3 = *(undefined4 *)(iVar6 + 0x1c8);
  uVar4 = *(undefined4 *)(iVar6 + 0x1cc);
  *(undefined4 *)(param_1 + 0x60c) = *(undefined4 *)(iVar6 + 0x1c0);
  *(undefined4 *)(param_1 + 0x610) = uVar7;
  *(undefined4 *)(param_1 + 0x614) = uVar3;
  *(undefined4 *)(param_1 + 0x618) = uVar4;
  *(undefined4 *)(param_1 + 0x644) = uVar5;
  if (pBVar1 != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(pBVar1);
    *(BIGNUM **)(param_1 + 0x620) = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) goto LAB_000fa232;
LAB_000fa2ee:
    ERR_put_error(0x14,0x139,3,"ssl/tls_srp.c",0x62);
    goto LAB_000fa302;
  }
LAB_000fa232:
  if (*(BIGNUM **)(iVar6 + 0x1d8) != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(*(BIGNUM **)(iVar6 + 0x1d8));
    *(BIGNUM **)(param_1 + 0x624) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_000fa2ee;
  }
  if (*(BIGNUM **)(iVar6 + 0x1dc) != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(*(BIGNUM **)(iVar6 + 0x1dc));
    *(BIGNUM **)(param_1 + 0x628) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_000fa2ee;
  }
  if (*(BIGNUM **)(iVar6 + 0x1e0) != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(*(BIGNUM **)(iVar6 + 0x1e0));
    *(BIGNUM **)(param_1 + 0x62c) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_000fa2ee;
  }
  if (*(BIGNUM **)(iVar6 + 0x1e4) != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(*(BIGNUM **)(iVar6 + 0x1e4));
    *(BIGNUM **)(param_1 + 0x630) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_000fa2ee;
  }
  if (*(BIGNUM **)(iVar6 + 0x1e8) != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(*(BIGNUM **)(iVar6 + 0x1e8));
    *(BIGNUM **)(param_1 + 0x634) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_000fa2ee;
  }
  if (*(BIGNUM **)(iVar6 + 0x1f0) != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(*(BIGNUM **)(iVar6 + 0x1f0));
    *(BIGNUM **)(param_1 + 0x63c) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_000fa2ee;
  }
  if (*(BIGNUM **)(iVar6 + 0x1ec) != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(*(BIGNUM **)(iVar6 + 0x1ec));
    *(BIGNUM **)(param_1 + 0x638) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_000fa2ee;
  }
  if (*(char **)(iVar6 + 0x1d0) == (char *)0x0) {
LAB_000fa2c6:
    if (*(char **)(iVar6 + 500) == (char *)0x0) {
LAB_000fa2e0:
      *(undefined4 *)(param_1 + 0x648) = *(undefined4 *)(iVar6 + 0x1fc);
      return 1;
    }
    pcVar2 = CRYPTO_strdup(*(char **)(iVar6 + 500),"ssl/tls_srp.c",0x6b);
    *(char **)(param_1 + 0x640) = pcVar2;
    if (pcVar2 != (char *)0x0) goto LAB_000fa2e0;
    line = 0x6c;
  }
  else {
    pcVar2 = CRYPTO_strdup(*(char **)(iVar6 + 0x1d0),"ssl/tls_srp.c",0x66);
    line = 0x67;
    *(char **)(param_1 + 0x61c) = pcVar2;
    if (pcVar2 != (char *)0x0) goto LAB_000fa2c6;
  }
  ERR_put_error(0x14,0x139,0x44,"ssl/tls_srp.c",line);
LAB_000fa302:
  CRYPTO_free(*(void **)(param_1 + 0x61c));
  CRYPTO_free(*(void **)(param_1 + 0x640));
  BN_free(*(BIGNUM **)(param_1 + 0x620));
  BN_free(*(BIGNUM **)(param_1 + 0x624));
  BN_free(*(BIGNUM **)(param_1 + 0x628));
  BN_free(*(BIGNUM **)(param_1 + 0x62c));
  BN_free(*(BIGNUM **)(param_1 + 0x630));
  BN_free(*(BIGNUM **)(param_1 + 0x634));
  BN_free(*(BIGNUM **)(param_1 + 0x638));
  BN_free(*(BIGNUM **)(param_1 + 0x63c));
  memset((void *)(param_1 + 0x60c),0,0x40);
  return 0;
}

