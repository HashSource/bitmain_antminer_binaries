
undefined4
tls1_PRF_constprop_0
          (undefined4 param_1,void *param_2,int param_3,void *param_4,int param_5,void *param_6,
          int param_7,void *param_8,int param_9,void *param_10,int param_11,uchar *param_12,
          undefined4 param_13,int param_14)

{
  int iVar1;
  void *p2;
  EVP_PKEY_CTX *ctx;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = param_14;
  p2 = (void *)ssl_prf_md();
  if (p2 != (void *)0x0) {
    ctx = EVP_PKEY_CTX_new_id(0x3fd,(ENGINE *)0x0);
    if ((((((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = EVP_PKEY_derive_init(ctx), iVar2 < 1)) ||
          (iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1000,0,p2), iVar2 < 1)) ||
         ((iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1001,param_11,param_10), iVar2 < 1 ||
          (iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,param_3,param_2), iVar2 < 1)))) ||
        ((iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,param_5,param_4), iVar2 < 1 ||
         ((iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,param_7,param_6), iVar2 < 1 ||
          (iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,param_9,param_8), iVar2 < 1)))))) ||
       ((iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0,(void *)0x0), iVar2 < 1 ||
        (iVar2 = EVP_PKEY_derive(ctx,param_12,&param_13), iVar2 < 1)))) {
      if (iVar1 == 0) {
        ERR_put_error(0x14,0x11c,0x44,"ssl/t1_enc.c",0x37);
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
        ossl_statem_fatal(param_1,0x50,0x11c,0x44,"ssl/t1_enc.c",0x35);
      }
    }
    else {
      uVar3 = 1;
    }
    EVP_PKEY_CTX_free(ctx);
    return uVar3;
  }
  if (iVar1 == 0) {
    ERR_put_error(0x14,0x11c,0x44,"ssl/t1_enc.c",0x26);
    return 0;
  }
  ossl_statem_fatal(param_1,0x50,0x11c,0x44,"ssl/t1_enc.c",0x24);
  return 0;
}

