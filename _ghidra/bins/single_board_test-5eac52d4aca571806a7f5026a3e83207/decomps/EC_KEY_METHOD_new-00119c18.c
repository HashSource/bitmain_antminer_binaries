
undefined4 * EC_KEY_METHOD_new(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x3c,"crypto/ec/ec_kmeth.c",0x9d);
  if (puVar1 != (undefined4 *)0x0) {
    if (param_1 != (undefined4 *)0x0) {
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      *puVar1 = *param_1;
      puVar1[1] = uVar2;
      puVar1[2] = uVar3;
      puVar1[3] = uVar4;
      uVar2 = param_1[5];
      uVar3 = param_1[6];
      uVar4 = param_1[7];
      puVar1[4] = param_1[4];
      puVar1[5] = uVar2;
      puVar1[6] = uVar3;
      puVar1[7] = uVar4;
      uVar2 = param_1[9];
      uVar3 = param_1[10];
      uVar4 = param_1[0xb];
      puVar1[8] = param_1[8];
      puVar1[9] = uVar2;
      puVar1[10] = uVar3;
      puVar1[0xb] = uVar4;
      uVar2 = param_1[0xd];
      uVar3 = param_1[0xe];
      puVar1[0xc] = param_1[0xc];
      puVar1[0xd] = uVar2;
      puVar1[0xe] = uVar3;
    }
    puVar1[1] = puVar1[1] | 1;
  }
  return puVar1;
}

