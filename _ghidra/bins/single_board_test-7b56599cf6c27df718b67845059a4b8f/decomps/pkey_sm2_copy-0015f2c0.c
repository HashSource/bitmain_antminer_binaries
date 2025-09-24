
EC_GROUP * pkey_sm2_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  EC_GROUP *pEVar2;
  void *__dest;
  EC_GROUP *pEVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x14,"crypto/sm2/sm2_pmeth.c",0x24);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x35,0x6f,0x41,"crypto/sm2/sm2_pmeth.c",0x25);
    return (EC_GROUP *)0x0;
  }
  *(undefined4 **)(param_1 + 0x14) = puVar1;
  puVar6 = *(undefined4 **)(param_2 + 0x14);
  if ((EC_GROUP *)*puVar6 == (EC_GROUP *)0x0) {
LAB_0015f2f2:
    if (puVar6[2] != 0) {
      __dest = CRYPTO_malloc(puVar6[3],"crypto/sm2/sm2_pmeth.c",0x49);
      puVar1[2] = __dest;
      if (__dest == (void *)0x0) {
        ERR_put_error(0x35,0x73,0x41,"crypto/sm2/sm2_pmeth.c",0x4b);
        pEVar2 = (EC_GROUP *)0x0;
        goto LAB_0015f336;
      }
      memcpy(__dest,(void *)puVar6[2],puVar6[3]);
    }
    uVar4 = puVar6[4];
    uVar5 = puVar6[1];
    puVar1[3] = puVar6[3];
    puVar1[4] = uVar4;
    puVar1[1] = uVar5;
    pEVar3 = (EC_GROUP *)0x1;
  }
  else {
    pEVar2 = EC_GROUP_dup((EC_GROUP *)*puVar6);
    *puVar1 = pEVar2;
    if (pEVar2 != (EC_GROUP *)0x0) goto LAB_0015f2f2;
LAB_0015f336:
    puVar1 = *(undefined4 **)(param_1 + 0x14);
    pEVar3 = (EC_GROUP *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      EC_GROUP_free((EC_GROUP *)*puVar1);
      CRYPTO_free((void *)puVar1[2]);
      CRYPTO_free(puVar1);
      *(EC_GROUP **)(param_1 + 0x14) = pEVar2;
      pEVar3 = pEVar2;
    }
  }
  return pEVar3;
}

