
int EC_GROUP_copy(EC_GROUP *dst,EC_GROUP *src)

{
  void **ptr;
  int *piVar1;
  int **ppiVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BN_MONT_CTX *to;
  undefined4 uVar5;
  BN_MONT_CTX *pBVar6;
  undefined4 uVar7;
  int *piVar8;
  code *pcVar9;
  int *piVar10;
  void *pvVar11;
  int *piVar12;
  int *piVar13;
  int **ppiVar14;
  int *piVar15;
  
  if (*(int *)(*(int *)dst + 0x14) == 0) {
    ERR_put_error(0x10,0x6a,0x42,DAT_000a0f00,0xb0);
    return 0;
  }
  if (*(int *)dst != *(int *)src) {
    ERR_put_error(0x10,0x6a,0x65,DAT_000a0f00,0xb4);
    return 0;
  }
  if (dst == src) {
    return 1;
  }
  ppiVar14 = (int **)(dst + 0x44);
  if (ppiVar14 != (int **)0x0) {
    ptr = (void **)*(void **)(dst + 0x44);
    while (ptr != (void **)0x0) {
      pvVar11 = *ptr;
      (*(code *)ptr[3])(ptr[1]);
      CRYPTO_free(ptr);
      ptr = (void **)pvVar11;
    }
    *(undefined4 *)(dst + 0x44) = 0;
  }
  for (piVar12 = *(int **)(src + 0x44); piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {
    piVar1 = (int *)(*(code *)piVar12[2])(piVar12[1]);
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    piVar10 = (int *)piVar12[2];
    piVar13 = (int *)piVar12[3];
    piVar15 = (int *)piVar12[4];
    if (ppiVar14 == (int **)0x0) {
      return 0;
    }
    for (piVar8 = *ppiVar14; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      if (((piVar10 == (int *)piVar8[2]) && (piVar13 == (int *)piVar8[3])) &&
         (piVar15 == (int *)piVar8[4])) {
        ERR_put_error(0x10,0xd3,0x6c,DAT_000a0f00,0x239);
        return 0;
      }
    }
    ppiVar2 = (int **)CRYPTO_malloc(0x14,DAT_000a0f00,0x242);
    if (ppiVar2 == (int **)0x0) {
      return 0;
    }
    ppiVar2[1] = piVar1;
    ppiVar2[2] = piVar10;
    ppiVar2[3] = piVar13;
    ppiVar2[4] = piVar15;
    *ppiVar2 = *ppiVar14;
    *ppiVar14 = (int *)ppiVar2;
  }
  if ((*(int *)(src + 0x34) < 0) &&
     (pBVar6 = *(BN_MONT_CTX **)(src + 0xac), pBVar6 != (BN_MONT_CTX *)0x0)) {
    to = *(BN_MONT_CTX **)(dst + 0xac);
    if (to == (BN_MONT_CTX *)0x0) {
      to = BN_MONT_CTX_new();
      *(BN_MONT_CTX **)(dst + 0xac) = to;
      if (to == (BN_MONT_CTX *)0x0) {
        return 0;
      }
      pBVar6 = *(BN_MONT_CTX **)(src + 0xac);
    }
    pBVar6 = BN_MONT_CTX_copy(to,pBVar6);
    if (pBVar6 == (BN_MONT_CTX *)0x0) {
      return 0;
    }
  }
  else if ((*(int *)(dst + 0x34) < 0) && (*(BN_MONT_CTX **)(dst + 0xac) != (BN_MONT_CTX *)0x0)) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(dst + 0xac));
    *(undefined4 *)(dst + 0xac) = 0;
  }
  piVar1 = *(int **)(src + 4);
  piVar12 = *(int **)(dst + 4);
  if (piVar1 == (int *)0x0) {
    if (piVar12 != (int *)0x0) {
      pcVar9 = *(code **)(*piVar12 + 0x30);
      if ((pcVar9 != (code *)0x0) || (pcVar9 = *(code **)(*piVar12 + 0x2c), pcVar9 != (code *)0x0))
      {
        (*pcVar9)(piVar12);
      }
      OPENSSL_cleanse(piVar12,0x44);
      CRYPTO_free(piVar12);
      *(undefined4 *)(dst + 4) = 0;
    }
  }
  else {
    if (piVar12 == (int *)0x0) {
      if (*(int *)(*(int *)dst + 0x28) == 0) {
        ERR_put_error(0x10,0x79,0x42,DAT_000a0f00,0x2c7);
LAB_000a0ed0:
        *(undefined4 *)(dst + 4) = 0;
        return 0;
      }
      piVar12 = (int *)CRYPTO_malloc(0x44,DAT_000a0f00,0x2cb);
      if (piVar12 == (int *)0x0) {
        ERR_put_error(0x10,0x79,0x41,DAT_000a0f00,0x2cd);
        goto LAB_000a0ed0;
      }
      iVar3 = *(int *)dst;
      *piVar12 = iVar3;
      iVar3 = (**(code **)(iVar3 + 0x28))();
      if (iVar3 == 0) {
        CRYPTO_free(piVar12);
        goto LAB_000a0ed0;
      }
      *(int **)(dst + 4) = piVar12;
      piVar1 = *(int **)(src + 4);
    }
    pcVar9 = *(code **)(*piVar12 + 0x34);
    if (pcVar9 == (code *)0x0) {
      ERR_put_error(0x10,0x72,0x42,DAT_000a0f00,0x2f5);
      return 0;
    }
    if (*piVar12 != *piVar1) {
      ERR_put_error(0x10,0x72,0x65,DAT_000a0f00,0x2f9);
      return 0;
    }
    if ((piVar1 != piVar12) && (iVar3 = (*pcVar9)(piVar12), iVar3 == 0)) {
      return 0;
    }
  }
  pBVar4 = BN_copy((BIGNUM *)(dst + 8),(BIGNUM *)(src + 8));
  if ((pBVar4 == (BIGNUM *)0x0) ||
     (pBVar4 = BN_copy((BIGNUM *)(dst + 0x1c),(BIGNUM *)(src + 0x1c)), pBVar4 == (BIGNUM *)0x0)) {
    return 0;
  }
  uVar5 = *(undefined4 *)(src + 0x34);
  uVar7 = *(undefined4 *)(src + 0x38);
  iVar3 = *(int *)(src + 0x3c);
  *(undefined4 *)(dst + 0x30) = *(undefined4 *)(src + 0x30);
  *(undefined4 *)(dst + 0x34) = uVar5;
  *(undefined4 *)(dst + 0x38) = uVar7;
  pvVar11 = *(void **)(dst + 0x3c);
  if (iVar3 == 0) {
    if (pvVar11 != (void *)0x0) {
      CRYPTO_free(pvVar11);
    }
    *(undefined4 *)(dst + 0x3c) = 0;
    *(undefined4 *)(dst + 0x40) = 0;
  }
  else {
    if (pvVar11 != (void *)0x0) {
      CRYPTO_free(pvVar11);
    }
    pvVar11 = CRYPTO_malloc(*(int *)(src + 0x40),DAT_000a0f00,0xf3);
    *(void **)(dst + 0x3c) = pvVar11;
    if (pvVar11 == (void *)0x0) {
      return 0;
    }
    pvVar11 = memcpy(pvVar11,*(void **)(src + 0x3c),*(size_t *)(src + 0x40));
    if (pvVar11 == (void *)0x0) {
      return 0;
    }
    *(undefined4 *)(dst + 0x40) = *(undefined4 *)(src + 0x40);
  }
  iVar3 = (**(code **)(*(int *)dst + 0x14))(dst,src);
  return iVar3;
}

