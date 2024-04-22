
void ERR_remove_thread_state(CRYPTO_THREADID *tid)

{
  int iVar1;
  int iVar2;
  CRYPTO_THREADID aCStack_1a0 [50];
  
  iVar1 = DAT_000ad6fc;
  if (tid == (CRYPTO_THREADID *)0x0) {
    CRYPTO_THREADID_current(aCStack_1a0);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  else {
    CRYPTO_THREADID_cpy(aCStack_1a0,tid);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  if (iVar2 == 0) {
    CRYPTO_lock(9,1,DAT_000ad700,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad704;
    }
    CRYPTO_lock(10,1,DAT_000ad700,0x12a);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  (**(code **)(iVar2 + 0x24))(aCStack_1a0);
  return;
}

