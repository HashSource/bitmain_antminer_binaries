
undefined4 pkey_rsa_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  BIGNUM *pBVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x2c,DAT_000fdac4,0x67);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0x400;
    puVar1[1] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[7] = 0xfffffffe;
    puVar1[4] = 1;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    puVar6 = *(undefined4 **)(param_2 + 0x14);
    *(undefined4 **)(param_1 + 0x20) = puVar1 + 2;
    *(undefined4 *)(param_1 + 0x24) = 2;
    pBVar2 = (BIGNUM *)puVar6[1];
    *puVar1 = *puVar6;
    if (pBVar2 != (BIGNUM *)0x0) {
      pBVar2 = BN_dup(pBVar2);
      puVar1[1] = pBVar2;
      if (pBVar2 == (BIGNUM *)0x0) {
        return 0;
      }
    }
    pvVar3 = (void *)puVar6[9];
    uVar4 = puVar6[5];
    uVar5 = puVar6[6];
    puVar1[4] = puVar6[4];
    puVar1[5] = uVar4;
    puVar1[6] = uVar5;
    if (pvVar3 == (void *)0x0) {
      return 1;
    }
    if ((void *)puVar1[9] != (void *)0x0) {
      CRYPTO_free((void *)puVar1[9]);
      pvVar3 = (void *)puVar6[9];
    }
    pvVar3 = BUF_memdup(pvVar3,puVar6[10]);
    puVar1[9] = pvVar3;
    if (pvVar3 != (void *)0x0) {
      puVar1[10] = puVar6[10];
      return 1;
    }
  }
  return 0;
}

