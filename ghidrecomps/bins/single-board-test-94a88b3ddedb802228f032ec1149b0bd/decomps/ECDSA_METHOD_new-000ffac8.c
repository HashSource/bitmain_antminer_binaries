
undefined4 * ECDSA_METHOD_new(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x18,DAT_000ffb1c,0x11b);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x2a,0x69,0x41,DAT_000ffb1c,0x11d);
  }
  else {
    if (param_1 == (undefined4 *)0x0) {
      uVar5 = 2;
      puVar1[2] = 0;
      puVar1[1] = 0;
      puVar1[3] = 0;
      *puVar1 = 0;
    }
    else {
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      *puVar1 = *param_1;
      puVar1[1] = uVar2;
      puVar1[2] = uVar3;
      puVar1[3] = uVar4;
      uVar2 = param_1[5];
      uVar5 = param_1[4] | 2;
      puVar1[4] = param_1[4];
      puVar1[5] = uVar2;
    }
    puVar1[4] = uVar5;
  }
  return puVar1;
}

