
undefined4 pkey_ec_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  EC_GROUP *pEVar2;
  EC_KEY *pEVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x20,"crypto/ec/ec_pmeth.c",0x2d);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x11a,0x41,"crypto/ec/ec_pmeth.c",0x2e);
    uVar5 = 0;
  }
  else {
    *(undefined1 *)(puVar1 + 3) = 0xff;
    *(undefined1 *)((int)puVar1 + 0xd) = 1;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    puVar6 = *(undefined4 **)(param_2 + 0x14);
    if ((EC_GROUP *)*puVar6 != (EC_GROUP *)0x0) {
      pEVar2 = EC_GROUP_dup((EC_GROUP *)*puVar6);
      *puVar1 = pEVar2;
      if (pEVar2 == (EC_GROUP *)0x0) {
        return 0;
      }
    }
    pEVar3 = (EC_KEY *)puVar6[2];
    puVar1[1] = puVar6[1];
    if (pEVar3 != (EC_KEY *)0x0) {
      pEVar3 = EC_KEY_dup(pEVar3);
      puVar1[2] = pEVar3;
      if (pEVar3 == (EC_KEY *)0x0) {
        return 0;
      }
    }
    *(undefined1 *)((int)puVar1 + 0xd) = *(undefined1 *)((int)puVar6 + 0xd);
    iVar4 = puVar6[5];
    uVar5 = puVar6[7];
    puVar1[4] = puVar6[4];
    puVar1[7] = uVar5;
    if (iVar4 == 0) {
      puVar1[5] = 0;
    }
    else {
      iVar4 = CRYPTO_memdup(iVar4,puVar6[6],"crypto/ec/ec_pmeth.c",0x4f);
      puVar1[5] = iVar4;
      if (iVar4 == 0) {
        return 0;
      }
    }
    uVar5 = 1;
    puVar1[6] = puVar6[6];
  }
  return uVar5;
}

