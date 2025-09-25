
undefined4 SSL_CTX_set_alpn_protos(int param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 0 || param_3 == 0) {
    CRYPTO_free(*(void **)(param_1 + 0x178));
    *(undefined4 *)(param_1 + 0x178) = 0;
    *(undefined4 *)(param_1 + 0x17c) = 0;
    return 0;
  }
  uVar3 = 0;
  if (1 < param_3) {
    do {
      pbVar1 = (byte *)(param_2 + uVar3);
      uVar3 = uVar3 + *pbVar1 + 1;
      if (*pbVar1 == 0) {
        return 1;
      }
    } while (uVar3 < param_3);
    if (param_3 == uVar3) {
      iVar2 = CRYPTO_memdup(param_2,param_3,"ssl/ssl_lib.c",0xb47);
      if (iVar2 != 0) {
        CRYPTO_free(*(void **)(param_1 + 0x178));
        *(int *)(param_1 + 0x178) = iVar2;
        *(uint *)(param_1 + 0x17c) = param_3;
        return 0;
      }
      ERR_put_error(0x14,0x157,0x41,"ssl/ssl_lib.c",0xb49);
    }
  }
  return 1;
}

