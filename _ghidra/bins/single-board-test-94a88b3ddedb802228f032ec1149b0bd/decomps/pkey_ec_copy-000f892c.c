
undefined4 pkey_ec_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  EC_GROUP *pEVar2;
  EC_KEY *pEVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x20,"ec_pmeth.c",0x5e);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  *(undefined1 *)(puVar1 + 3) = 0xff;
  *(undefined1 *)((int)puVar1 + 0xd) = 1;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[4] = 0;
  puVar1[7] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  *(undefined4 **)(param_1 + 0x14) = puVar1;
  puVar7 = *(undefined4 **)(param_2 + 0x14);
  if ((EC_GROUP *)*puVar7 != (EC_GROUP *)0x0) {
    pEVar2 = EC_GROUP_dup((EC_GROUP *)*puVar7);
    *puVar1 = pEVar2;
    if (pEVar2 == (EC_GROUP *)0x0) {
      return 0;
    }
  }
  pEVar3 = (EC_KEY *)puVar7[2];
  puVar1[1] = puVar7[1];
  if (pEVar3 != (EC_KEY *)0x0) {
    pEVar3 = EC_KEY_dup(pEVar3);
    puVar1[2] = pEVar3;
    if (pEVar3 == (EC_KEY *)0x0) {
      return 0;
    }
  }
  uVar5 = puVar7[4];
  uVar6 = puVar7[7];
  pvVar4 = (void *)puVar7[5];
  *(undefined1 *)((int)puVar1 + 0xd) = *(undefined1 *)((int)puVar7 + 0xd);
  puVar1[4] = uVar5;
  puVar1[7] = uVar6;
  if (pvVar4 == (void *)0x0) {
    puVar1[5] = 0;
  }
  else {
    pvVar4 = BUF_memdup(pvVar4,puVar7[6]);
    puVar1[5] = pvVar4;
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
  }
  puVar1[6] = puVar7[6];
  return 1;
}

