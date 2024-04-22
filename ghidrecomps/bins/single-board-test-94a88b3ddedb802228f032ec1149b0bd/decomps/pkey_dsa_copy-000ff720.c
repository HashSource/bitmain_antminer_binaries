
undefined4 pkey_dsa_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x18,DAT_000ff768,0x54);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = 0;
    *puVar1 = 0x400;
    puVar1[1] = 0xa0;
    puVar1[5] = 0;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    puVar3 = *(undefined4 **)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x24) = 2;
    *(undefined4 **)(param_1 + 0x20) = puVar1 + 3;
    uVar5 = puVar3[1];
    uVar2 = puVar3[2];
    uVar4 = puVar3[5];
    *puVar1 = *puVar3;
    puVar1[1] = uVar5;
    puVar1[2] = uVar2;
    puVar1[5] = uVar4;
    return 1;
  }
  return 0;
}

