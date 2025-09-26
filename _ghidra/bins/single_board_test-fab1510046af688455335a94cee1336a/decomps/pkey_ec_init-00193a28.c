
undefined4 pkey_ec_init(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x20,"ec_pmeth.c",0x5e);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[4] = 0;
    puVar1[7] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 3) = 0xff;
    *(undefined1 *)((int)puVar1 + 0xd) = 1;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    return 1;
  }
  return 0;
}

