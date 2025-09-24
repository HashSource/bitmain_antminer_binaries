
undefined4
tls13_generate_secret
          (undefined4 param_1,EVP_MD *param_2,size_t param_3,undefined1 *param_4,size_t param_5,
          uchar *param_6)

{
  EVP_PKEY_CTX *ctx;
  EVP_MD_CTX *ctx_00;
  int iVar1;
  undefined4 uVar2;
  undefined1 *p2;
  size_t local_b4;
  size_t local_ac;
  undefined1 auStack_a8 [64];
  uchar auStack_68 [68];
  
  ctx = EVP_PKEY_CTX_new_id(0x40c,(ENGINE *)0x0);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x24f,0x44,"ssl/tls13_enc.c",0xb8);
    return 0;
  }
  local_ac = EVP_MD_size(param_2);
  if ((int)local_ac < 0) {
    ossl_statem_fatal(param_1,0x50,0x24f,0x44,"ssl/tls13_enc.c",0xc0);
    EVP_PKEY_CTX_free(ctx);
    return 0;
  }
  if (param_4 == (undefined1 *)0x0) {
    param_4 = &default_zeros;
    param_5 = local_ac;
    if (param_3 == 0) goto LAB_000fd5c4;
LAB_000fd460:
    ctx_00 = (EVP_MD_CTX *)EVP_MD_CTX_new();
    if ((ctx_00 == (EVP_MD_CTX *)0x0) ||
       (iVar1 = EVP_DigestInit_ex(ctx_00,param_2,(ENGINE *)0x0), iVar1 < 1)) {
LAB_000fd588:
      ossl_statem_fatal(param_1,0x50,0x24f,0x44,"ssl/tls13_enc.c",0xd6);
      EVP_MD_CTX_free(ctx_00);
      EVP_PKEY_CTX_free(ctx);
      return 0;
    }
    iVar1 = EVP_DigestFinal_ex(ctx_00,auStack_68,(uint *)0x0);
    if (iVar1 < 1) goto LAB_000fd588;
    p2 = auStack_a8;
    EVP_MD_CTX_free(ctx_00);
    iVar1 = tls13_hkdf_expand(param_1,param_2,param_3,"derived",7,auStack_68,local_ac,p2,local_ac,1)
    ;
    if (iVar1 == 0) {
      EVP_PKEY_CTX_free(ctx);
      return 0;
    }
    local_b4 = local_ac;
  }
  else {
    if (param_3 != 0) goto LAB_000fd460;
LAB_000fd5c4:
    p2 = &default_zeros;
    local_b4 = param_3;
  }
  iVar1 = EVP_PKEY_derive_init(ctx);
  if (0 < iVar1) {
    uVar2 = 1;
    iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1007,1,(void *)0x0);
    if ((((0 < iVar1) && (iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1003,0,param_2), 0 < iVar1)) &&
        (iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1005,param_5,param_4), 0 < iVar1)) &&
       ((iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1004,local_b4,p2), 0 < iVar1 &&
        (iVar1 = EVP_PKEY_derive(ctx,param_6,&local_ac), 0 < iVar1)))) goto LAB_000fd574;
  }
  uVar2 = 0;
  ossl_statem_fatal(param_1,0x50,0x24f,0x44,"ssl/tls13_enc.c",0xf7);
LAB_000fd574:
  EVP_PKEY_CTX_free(ctx);
  if (p2 == auStack_a8) {
    OPENSSL_cleanse(p2,local_ac);
  }
  return uVar2;
}

