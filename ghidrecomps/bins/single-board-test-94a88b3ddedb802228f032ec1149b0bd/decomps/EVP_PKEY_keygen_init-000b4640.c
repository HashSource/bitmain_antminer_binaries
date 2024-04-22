
int EVP_PKEY_keygen_init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (*(int *)(iVar1 + 0x20) == 0)) {
    ERR_put_error(6,0x93,0x96,DAT_000b4680,0x76);
    iVar1 = -2;
  }
  else {
    pcVar2 = *(code **)(iVar1 + 0x1c);
    *(undefined4 *)(ctx + 0x10) = 4;
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

