
int EVP_PKEY_keygen_init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  undefined4 extraout_r3;
  undefined4 uVar3;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (*(int *)(iVar1 + 0x20) == 0)) {
    ERR_put_error(6,0x93,0x96,"crypto/evp/pmeth_gn.c",0x4a);
    iVar1 = -2;
  }
  else {
    pcVar2 = *(code **)(iVar1 + 0x1c);
    *(undefined4 *)(ctx + 0x10) = 4;
    if (pcVar2 == (code *)0x0) {
      return 1;
    }
    iVar1 = (*pcVar2)();
    uVar3 = extraout_r3;
    if (iVar1 < 1) {
      uVar3 = 0;
    }
    if (iVar1 < 1) {
      *(undefined4 *)(ctx + 0x10) = uVar3;
    }
  }
  return iVar1;
}

