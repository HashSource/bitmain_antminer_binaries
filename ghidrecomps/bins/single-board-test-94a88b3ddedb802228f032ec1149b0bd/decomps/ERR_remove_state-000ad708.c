
void ERR_remove_state(void)

{
  int iVar1;
  int iVar2;
  CRYPTO_THREADID aCStack_198 [50];
  
  iVar1 = DAT_000ac8cc;
  CRYPTO_THREADID_current(aCStack_198);
  iVar2 = *(int *)(iVar1 + 0x2f4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,1,DAT_000ac8d0,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ac8d4;
    }
    CRYPTO_lock(10,1,DAT_000ac8d0,0x12a);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  (**(code **)(iVar2 + 0x24))(aCStack_198);
  return;
}

