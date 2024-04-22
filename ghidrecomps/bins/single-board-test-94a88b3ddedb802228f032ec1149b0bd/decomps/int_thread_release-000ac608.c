
void int_thread_release(int *param_1)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) &&
     (iVar1 = CRYPTO_add_lock(DAT_000ac634,-1,1,DAT_000ac638,0x1d9), iVar1 < 1)) {
    *param_1 = 0;
  }
  return;
}

