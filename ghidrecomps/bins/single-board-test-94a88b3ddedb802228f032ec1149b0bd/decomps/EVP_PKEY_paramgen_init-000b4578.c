
int EVP_PKEY_paramgen_init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (*(int *)(iVar1 + 0x18) == 0)) {
    ERR_put_error(6,0x95,0x96,DAT_000b45b8,0x49);
    iVar1 = -2;
  }
  else {
    pcVar2 = *(code **)(iVar1 + 0x14);
    *(undefined4 *)(ctx + 0x10) = 2;
    if (pcVar2 == (code *)0x0) {
      iVar1 = 1;
    }
    else {
      iVar1 = (*pcVar2)();
      if (iVar1 < 1) {
        pcVar2 = (code *)0x0;
      }
      if (iVar1 < 1) {
        *(code **)(ctx + 0x10) = pcVar2;
      }
    }
  }
  return iVar1;
}

