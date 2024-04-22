
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_get_last(void)

{
  ENGINE *pEVar1;
  
  CRYPTO_lock(9,0x1e,DAT_000a6590,0xca);
  pEVar1 = *(ENGINE **)(DAT_000a6594 + 4);
  if (pEVar1 != (ENGINE *)0x0) {
    *(int *)(pEVar1 + 0x58) = *(int *)(pEVar1 + 0x58) + 1;
  }
  CRYPTO_lock(10,0x1e,DAT_000a6590,0xd0);
  return pEVar1;
}

