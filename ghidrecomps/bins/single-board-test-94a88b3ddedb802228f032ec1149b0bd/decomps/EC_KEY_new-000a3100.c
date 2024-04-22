
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EC_KEY * EC_KEY_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x24,DAT_000a3144,0x4b);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xb6,0x41,DAT_000a3144,0x4d);
  }
  else {
    *puVar1 = 1;
    puVar1[6] = 1;
    puVar1[7] = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[8] = 0;
    puVar1[5] = 4;
  }
  return (EC_KEY *)puVar1;
}

