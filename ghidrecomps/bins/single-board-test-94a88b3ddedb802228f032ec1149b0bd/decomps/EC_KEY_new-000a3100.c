
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EC_KEY * EC_KEY_new(void)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)CRYPTO_malloc(0x24,"ec_key.c",0x4b);
  if (pEVar1 == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0xb6,0x41,"ec_key.c",0x4d);
  }
  else {
    *(undefined4 *)pEVar1 = 1;
    *(undefined4 *)(pEVar1 + 0x18) = 1;
    *(undefined4 *)(pEVar1 + 0x1c) = 0;
    *(undefined4 *)(pEVar1 + 4) = 0;
    *(undefined4 *)(pEVar1 + 8) = 0;
    *(undefined4 *)(pEVar1 + 0xc) = 0;
    *(undefined4 *)(pEVar1 + 0x10) = 0;
    *(undefined4 *)(pEVar1 + 0x20) = 0;
    *(undefined4 *)(pEVar1 + 0x14) = 4;
  }
  return pEVar1;
}

