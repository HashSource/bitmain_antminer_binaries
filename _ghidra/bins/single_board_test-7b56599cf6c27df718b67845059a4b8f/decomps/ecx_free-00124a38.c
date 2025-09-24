
void ecx_free(int param_1)

{
  void *ptr;
  int iVar1;
  undefined4 uVar2;
  
  ptr = *(void **)(param_1 + 0x18);
  if (ptr != (void *)0x0) {
    iVar1 = **(int **)(param_1 + 0xc);
    if (iVar1 == 0x40a || iVar1 == 0x43f) {
      uVar2 = 0x20;
    }
    else if (iVar1 == 0x40b) {
      uVar2 = 0x38;
    }
    else {
      uVar2 = 0x39;
    }
    CRYPTO_secure_clear_free(*(undefined4 *)((int)ptr + 0x3c),uVar2,"crypto/ec/ecx_meth.c",0x102);
    ptr = *(void **)(param_1 + 0x18);
  }
  CRYPTO_free(ptr);
  return;
}

