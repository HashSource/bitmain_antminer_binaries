
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_PCTX * ASN1_PCTX_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x14,DAT_0010810c,0x57);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0xd,0xcd,0x41,DAT_0010810c,0x59);
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
  }
  return (ASN1_PCTX *)puVar1;
}

