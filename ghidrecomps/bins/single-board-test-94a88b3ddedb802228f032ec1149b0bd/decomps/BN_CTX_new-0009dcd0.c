
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BN_CTX * BN_CTX_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x2c,DAT_0009dd14,0xd8);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(3,0x6a,0x41,DAT_0009dd14,0xda);
  }
  else {
    puVar1[2] = 0;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[4] = 0;
    puVar1[3] = 0;
    puVar1[5] = 0;
    puVar1[7] = 0;
    puVar1[6] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
  }
  return (BN_CTX *)puVar1;
}

