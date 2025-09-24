
void SSL3_RECORD_release(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      CRYPTO_free(*(void **)(param_1 + 0x1c));
      *(undefined4 *)(param_1 + 0x1c) = 0;
      param_1 = param_1 + 0x30;
    } while (param_2 != iVar1);
    return;
  }
  return;
}

