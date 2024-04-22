
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_get_first(void)

{
  ENGINE *pEVar1;
  
  CRYPTO_lock(9,0x1e,DAT_000a655c,0xbc);
  pEVar1 = *DAT_000a6560;
  if (pEVar1 != (ENGINE *)0x0) {
    *(int *)(pEVar1 + 0x58) = *(int *)(pEVar1 + 0x58) + 1;
  }
  CRYPTO_lock(10,0x1e,DAT_000a655c,0xc2);
  return pEVar1;
}

