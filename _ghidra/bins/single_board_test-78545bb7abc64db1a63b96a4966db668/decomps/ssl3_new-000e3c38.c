
int ssl3_new(int param_1)

{
  int iVar1;
  
  iVar1 = CRYPTO_zalloc(0x35c,"ssl/s3_lib.c",0xce0);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x7c) = iVar1;
    iVar1 = SSL_SRP_CTX_init(param_1);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
  }
  return 0;
}

