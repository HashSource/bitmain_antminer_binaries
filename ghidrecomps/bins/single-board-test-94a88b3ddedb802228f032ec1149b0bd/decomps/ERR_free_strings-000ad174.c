
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_free_strings(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_000ad1b4;
  iVar2 = *(int *)(DAT_000ad1b4 + 0x2f4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,1,DAT_000ad1b8,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad1bc;
    }
    CRYPTO_lock(10,1,DAT_000ad1b8,0x12a);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  (**(code **)(iVar2 + 4))();
  return;
}

