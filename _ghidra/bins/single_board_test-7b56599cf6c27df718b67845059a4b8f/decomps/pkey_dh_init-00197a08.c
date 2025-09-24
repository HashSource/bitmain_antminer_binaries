
bool pkey_dh_init(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x40,"crypto/dh/dh_pmeth.c",0x35);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(5,0x7d,0x41,"crypto/dh/dh_pmeth.c",0x36);
  }
  else {
    *(undefined1 *)(puVar1 + 10) = 1;
    *puVar1 = 0x800;
    puVar1[3] = 0xffffffff;
    puVar1[1] = 2;
    *(undefined4 *)(param_1 + 0x24) = 2;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    *(undefined4 **)(param_1 + 0x20) = puVar1 + 8;
  }
  return puVar1 != (undefined4 *)0x0;
}

