
undefined4 tls1_final_finish_mac(int param_1,void *param_2,int param_3,uchar *param_4)

{
  size_t p1;
  int iVar1;
  void *p2;
  EVP_PKEY_CTX *ctx;
  int iVar2;
  int iVar3;
  size_t local_70 [2];
  undefined1 auStack_68 [68];
  
  iVar1 = ssl3_digest_cached_records(param_1,0);
  if (iVar1 != 0) {
    iVar1 = ssl_handshake_hash(param_1,auStack_68,0x40,local_70);
    p1 = local_70[0];
    if (iVar1 != 0) {
      iVar3 = *(int *)(param_1 + 0x474);
      local_70[1] = 0xc;
      iVar1 = *(int *)(iVar3 + 4);
      p2 = (void *)ssl_prf_md(param_1);
      if (p2 == (void *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x11c,0x44,"ssl/t1_enc.c",0x24);
        return 0;
      }
      ctx = EVP_PKEY_CTX_new_id(0x3fd,(ENGINE *)0x0);
      if ((((((ctx != (EVP_PKEY_CTX *)0x0) && (iVar2 = EVP_PKEY_derive_init(ctx), 0 < iVar2)) &&
            (iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1000,0,p2), 0 < iVar2)) &&
           ((iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1001,iVar1,(void *)(iVar3 + 0x48)), 0 < iVar1
            && (iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,param_3,param_2), 0 < iVar1)))) &&
          ((iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,p1,auStack_68), 0 < iVar1 &&
           ((iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0,(void *)0x0), 0 < iVar1 &&
            (iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0,(void *)0x0), 0 < iVar1)))))) &&
         ((iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0,(void *)0x0), 0 < iVar1 &&
          (iVar1 = EVP_PKEY_derive(ctx,param_4,local_70 + 1), 0 < iVar1)))) {
        EVP_PKEY_CTX_free(ctx);
        OPENSSL_cleanse(auStack_68,local_70[0]);
        return 0xc;
      }
      ossl_statem_fatal(param_1,0x50,0x11c,0x44,"ssl/t1_enc.c",0x35);
      EVP_PKEY_CTX_free(ctx);
    }
  }
  return 0;
}

