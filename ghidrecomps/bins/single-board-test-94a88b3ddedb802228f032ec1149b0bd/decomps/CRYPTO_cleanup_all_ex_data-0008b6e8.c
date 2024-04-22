
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRYPTO_cleanup_all_ex_data(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0008b71c;
  iVar2 = *(int *)(DAT_0008b71c + 4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,2,DAT_0008b720,0xc9);
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = DAT_0008b724;
    }
    CRYPTO_lock(10,2,DAT_0008b720,0xcc);
    iVar2 = *(int *)(iVar1 + 4);
  }
  (**(code **)(iVar2 + 4))();
  return;
}

