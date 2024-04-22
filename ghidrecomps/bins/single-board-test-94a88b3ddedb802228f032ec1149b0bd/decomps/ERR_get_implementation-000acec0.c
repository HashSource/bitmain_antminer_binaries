
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ERR_FNS * ERR_get_implementation(void)

{
  int iVar1;
  
  iVar1 = DAT_000acefc;
  if (*(ERR_FNS **)(DAT_000acefc + 0x2f4) != (ERR_FNS *)0x0) {
    return *(ERR_FNS **)(DAT_000acefc + 0x2f4);
  }
  CRYPTO_lock(9,1,DAT_000acf00,0x127);
  if (*(int *)(iVar1 + 0x2f4) == 0) {
    *(undefined4 *)(iVar1 + 0x2f4) = DAT_000acf04;
  }
  CRYPTO_lock(10,1,DAT_000acf00,0x12a);
  return *(ERR_FNS **)(iVar1 + 0x2f4);
}

