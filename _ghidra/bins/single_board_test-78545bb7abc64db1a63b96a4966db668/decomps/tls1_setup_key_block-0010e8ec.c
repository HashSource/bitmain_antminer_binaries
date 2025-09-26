
undefined4 tls1_setup_key_block(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uchar *key;
  void *p2;
  EVP_PKEY_CTX *ctx;
  int iVar4;
  size_t num;
  EVP_CIPHER *local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [4];
  undefined4 local_34;
  int local_30;
  size_t local_2c [2];
  
  local_34 = 0;
  local_30 = 0;
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0x228) == 0) {
    iVar1 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0x474),&local_40,&local_3c,&local_34,
                               &local_30,auStack_38,*(undefined4 *)(param_1 + 0x5a8));
    if (iVar1 == 0) {
      ossl_statem_fatal(param_1,0x50,0xd3,0x8a,"ssl/t1_enc.c",0x162);
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x7c);
    *(int *)(iVar1 + 0x23c) = local_30;
    *(undefined4 *)(iVar1 + 0x234) = local_3c;
    *(undefined4 *)(iVar1 + 0x238) = local_34;
    *(EVP_CIPHER **)(iVar1 + 0x230) = local_40;
    iVar2 = EVP_CIPHER_key_length(local_40);
    iVar1 = local_30;
    iVar3 = EVP_CIPHER_iv_length(local_40);
    num = (iVar1 + iVar3 + iVar2) * 2;
    ssl3_cleanup_key_block(param_1);
    key = (uchar *)CRYPTO_malloc(num,"ssl/t1_enc.c",0x16f);
    if (key == (uchar *)0x0) {
      ossl_statem_fatal(param_1,0x50,0xd3,0x41,"ssl/t1_enc.c",0x171);
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x7c);
    iVar3 = *(int *)(param_1 + 0x474);
    *(size_t *)(iVar2 + 0x228) = num;
    *(uchar **)(iVar2 + 0x22c) = key;
    iVar1 = *(int *)(iVar3 + 4);
    local_2c[0] = num;
    p2 = (void *)ssl_prf_md(param_1);
    if (p2 == (void *)0x0) {
      ossl_statem_fatal(param_1,0x50,0x11c,0x44,"ssl/t1_enc.c",0x24);
      return 0;
    }
    ctx = EVP_PKEY_CTX_new_id(0x3fd,(ENGINE *)0x0);
    if (((((((ctx == (EVP_PKEY_CTX *)0x0) || (iVar4 = EVP_PKEY_derive_init(ctx), iVar4 < 1)) ||
           (iVar4 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1000,0,p2), iVar4 < 1)) ||
          ((iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1001,iVar1,(void *)(iVar3 + 0x48)), iVar1 < 1
           || (iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0xd,"key expansion"), iVar1 < 1)))) ||
         ((iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0x20,(void *)(iVar2 + 0x8c)), iVar1 < 1 ||
          ((iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0x20,(void *)(iVar2 + 0xac)), iVar1 < 1 ||
           (iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0,(void *)0x0), iVar1 < 1)))))) ||
        (iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0,(void *)0x0), iVar1 < 1)) ||
       (iVar1 = EVP_PKEY_derive(ctx,key,local_2c), iVar1 < 1)) {
      ossl_statem_fatal(param_1,0x50,0x11c,0x44,"ssl/t1_enc.c",0x35);
      EVP_PKEY_CTX_free(ctx);
      return 0;
    }
    EVP_PKEY_CTX_free(ctx);
    if (((*(uint *)(param_1 + 0x4ec) & 0x800) == 0) && (**(int **)(param_1 + 4) < 0x302)) {
      iVar1 = *(int *)(param_1 + 0x7c);
      iVar2 = *(int *)(*(int *)(param_1 + 0x474) + 0x1b8);
      *(undefined4 *)(iVar1 + 0xcc) = 1;
      if ((iVar2 != 0) && ((iVar2 = *(int *)(iVar2 + 0x18), iVar2 == 0x20 || (iVar2 == 4)))) {
        *(undefined4 *)(iVar1 + 0xcc) = 0;
        return 1;
      }
    }
  }
  return 1;
}

