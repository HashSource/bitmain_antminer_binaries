
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_get_next_error_library(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_000ae3fc;
  iVar2 = *(int *)(DAT_000ae3fc + 0x2f4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,1,DAT_000ae400,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ae404;
    }
    CRYPTO_lock(10,1,DAT_000ae400,0x12a);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  iVar1 = (**(code **)(iVar2 + 0x28))();
  return iVar1;
}

