
int EC_GROUP_copy(EC_GROUP *dst,EC_GROUP *src)

{
  undefined4 *ptr;
  int iVar1;
  BIGNUM *pBVar2;
  BN_MONT_CTX *to;
  undefined4 uVar3;
  BN_MONT_CTX *pBVar4;
  undefined4 uVar5;
  int *piVar6;
  code *pcVar7;
  int iVar8;
  void *pvVar9;
  int *piVar10;
  int iVar11;
  EC_GROUP *pEVar12;
  int iVar13;
  
  if (*(int *)(*(int *)dst + 0x14) == 0) {
    ERR_put_error(0x10,0x6a,0x42,"ec_lib.c",0xb0);
    return 0;
  }
  if (*(int *)dst != *(int *)src) {
    ERR_put_error(0x10,0x6a,0x65,"ec_lib.c",0xb4);
    return 0;
  }
  if (dst == src) {
    return 1;
  }
  pEVar12 = dst + 0x44;
  if (pEVar12 != (EC_GROUP *)0x0) {
    ptr = (undefined4 *)*(void **)(dst + 0x44);
    while (ptr != (undefined4 *)0x0) {
      pvVar9 = (void *)*ptr;
      (*(code *)ptr[3])(ptr[1]);
      CRYPTO_free(ptr);
      ptr = (undefined4 *)pvVar9;
    }
    *(undefined4 *)(dst + 0x44) = 0;
  }
  for (piVar10 = *(int **)(src + 0x44); piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {
    iVar1 = (*(code *)piVar10[2])(piVar10[1]);
    if (iVar1 == 0) {
      return 0;
    }
    iVar8 = piVar10[2];
    iVar11 = piVar10[3];
    iVar13 = piVar10[4];
    if (pEVar12 == (EC_GROUP *)0x0) {
      return 0;
    }
    for (piVar6 = *(int **)pEVar12; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      if (((iVar8 == piVar6[2]) && (iVar11 == piVar6[3])) && (iVar13 == piVar6[4])) {
        ERR_put_error(0x10,0xd3,0x6c,"ec_lib.c",0x239);
        return 0;
      }
    }
    piVar6 = (int *)CRYPTO_malloc(0x14,"ec_lib.c",0x242);
    if (piVar6 == (int *)0x0) {
      return 0;
    }
    piVar6[1] = iVar1;
    piVar6[2] = iVar8;
    piVar6[3] = iVar11;
    piVar6[4] = iVar13;
    *piVar6 = *(int *)pEVar12;
    *(int **)pEVar12 = piVar6;
  }
  if ((*(int *)(src + 0x34) < 0) &&
     (pBVar4 = *(BN_MONT_CTX **)(src + 0xac), pBVar4 != (BN_MONT_CTX *)0x0)) {
    to = *(BN_MONT_CTX **)(dst + 0xac);
    if (to == (BN_MONT_CTX *)0x0) {
      to = BN_MONT_CTX_new();
      *(BN_MONT_CTX **)(dst + 0xac) = to;
      if (to == (BN_MONT_CTX *)0x0) {
        return 0;
      }
      pBVar4 = *(BN_MONT_CTX **)(src + 0xac);
    }
    pBVar4 = BN_MONT_CTX_copy(to,pBVar4);
    if (pBVar4 == (BN_MONT_CTX *)0x0) {
      return 0;
    }
  }
  else if ((*(int *)(dst + 0x34) < 0) && (*(BN_MONT_CTX **)(dst + 0xac) != (BN_MONT_CTX *)0x0)) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(dst + 0xac));
    *(undefined4 *)(dst + 0xac) = 0;
  }
  piVar6 = *(int **)(src + 4);
  piVar10 = *(int **)(dst + 4);
  if (piVar6 == (int *)0x0) {
    if (piVar10 != (int *)0x0) {
      pcVar7 = *(code **)(*piVar10 + 0x30);
      if ((pcVar7 != (code *)0x0) || (pcVar7 = *(code **)(*piVar10 + 0x2c), pcVar7 != (code *)0x0))
      {
        (*pcVar7)(piVar10);
      }
      OPENSSL_cleanse(piVar10,0x44);
      CRYPTO_free(piVar10);
      *(undefined4 *)(dst + 4) = 0;
    }
  }
  else {
    if (piVar10 == (int *)0x0) {
      if (*(int *)(*(int *)dst + 0x28) == 0) {
        ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2c7);
LAB_000a0ed0:
        *(undefined4 *)(dst + 4) = 0;
        return 0;
      }
      piVar10 = (int *)CRYPTO_malloc(0x44,"ec_lib.c",0x2cb);
      if (piVar10 == (int *)0x0) {
        ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2cd);
        goto LAB_000a0ed0;
      }
      iVar1 = *(int *)dst;
      *piVar10 = iVar1;
      iVar1 = (**(code **)(iVar1 + 0x28))();
      if (iVar1 == 0) {
        CRYPTO_free(piVar10);
        goto LAB_000a0ed0;
      }
      *(int **)(dst + 4) = piVar10;
      piVar6 = *(int **)(src + 4);
    }
    pcVar7 = *(code **)(*piVar10 + 0x34);
    if (pcVar7 == (code *)0x0) {
      ERR_put_error(0x10,0x72,0x42,"ec_lib.c",0x2f5);
      return 0;
    }
    if (*piVar10 != *piVar6) {
      ERR_put_error(0x10,0x72,0x65,"ec_lib.c",0x2f9);
      return 0;
    }
    if ((piVar6 != piVar10) && (iVar1 = (*pcVar7)(piVar10), iVar1 == 0)) {
      return 0;
    }
  }
  pBVar2 = BN_copy((BIGNUM *)(dst + 8),(BIGNUM *)(src + 8));
  if ((pBVar2 == (BIGNUM *)0x0) ||
     (pBVar2 = BN_copy((BIGNUM *)(dst + 0x1c),(BIGNUM *)(src + 0x1c)), pBVar2 == (BIGNUM *)0x0)) {
    return 0;
  }
  uVar3 = *(undefined4 *)(src + 0x34);
  uVar5 = *(undefined4 *)(src + 0x38);
  iVar1 = *(int *)(src + 0x3c);
  *(undefined4 *)(dst + 0x30) = *(undefined4 *)(src + 0x30);
  *(undefined4 *)(dst + 0x34) = uVar3;
  *(undefined4 *)(dst + 0x38) = uVar5;
  pvVar9 = *(void **)(dst + 0x3c);
  if (iVar1 == 0) {
    if (pvVar9 != (void *)0x0) {
      CRYPTO_free(pvVar9);
    }
    *(undefined4 *)(dst + 0x3c) = 0;
    *(undefined4 *)(dst + 0x40) = 0;
  }
  else {
    if (pvVar9 != (void *)0x0) {
      CRYPTO_free(pvVar9);
    }
    pvVar9 = CRYPTO_malloc(*(int *)(src + 0x40),"ec_lib.c",0xf3);
    *(void **)(dst + 0x3c) = pvVar9;
    if (pvVar9 == (void *)0x0) {
      return 0;
    }
    pvVar9 = memcpy(pvVar9,*(void **)(src + 0x3c),*(size_t *)(src + 0x40));
    if (pvVar9 == (void *)0x0) {
      return 0;
    }
    *(undefined4 *)(dst + 0x40) = *(undefined4 *)(src + 0x40);
  }
  iVar1 = (**(code **)(*(int *)dst + 0x14))(dst,src);
  return iVar1;
}

