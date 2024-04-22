
undefined4 sig_cb(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = 1;
  if (param_1 == 0) {
    puVar2 = (undefined4 *)CRYPTO_malloc(8,DAT_000a47d4,0x49);
    if (puVar2 == (undefined4 *)0x0) {
      ERR_put_error(10,0x72,0x41,DAT_000a47d4,0x4b);
      uVar1 = 0;
    }
    else {
      *puVar2 = 0;
      uVar1 = 2;
      puVar2[1] = 0;
      *param_2 = puVar2;
    }
  }
  return uVar1;
}

