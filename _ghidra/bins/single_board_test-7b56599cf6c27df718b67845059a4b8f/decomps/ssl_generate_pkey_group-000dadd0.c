
EVP_PKEY * ssl_generate_pkey_group(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  EVP_PKEY_CTX *ctx;
  undefined4 uVar4;
  EVP_PKEY *local_1c [2];
  
  local_1c[0] = (EVP_PKEY *)0x0;
  piVar2 = (int *)tls1_group_id_lookup(param_2);
  if (piVar2 == (int *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x22f,0x44,"ssl/s3_lib.c",0x126a);
    ctx = (EVP_PKEY_CTX *)0x0;
  }
  else {
    uVar1 = *(ushort *)(piVar2 + 2);
    if ((uVar1 & 3) == 2) {
      iVar3 = *piVar2;
    }
    else {
      iVar3 = 0x198;
    }
    ctx = EVP_PKEY_CTX_new_id(iVar3,(ENGINE *)0x0);
    if (ctx == (EVP_PKEY_CTX *)0x0) {
      ossl_statem_fatal(param_1,0x50,0x22f,0x41,"ssl/s3_lib.c",0x1274);
    }
    else {
      iVar3 = EVP_PKEY_keygen_init(ctx);
      if (iVar3 < 1) {
        uVar4 = 0x1279;
      }
      else {
        if (((uVar1 & 3) == 2) ||
           (iVar3 = EVP_PKEY_CTX_ctrl(ctx,0x198,6,0x1001,*piVar2,(void *)0x0), 0 < iVar3)) {
          iVar3 = EVP_PKEY_keygen(ctx,local_1c);
          if (iVar3 < 1) {
            ossl_statem_fatal(param_1,0x50,0x22f,6,"ssl/s3_lib.c",0x1284);
            EVP_PKEY_free(local_1c[0]);
            local_1c[0] = (EVP_PKEY *)0x0;
          }
          goto LAB_000dae34;
        }
        uVar4 = 0x127f;
      }
      ossl_statem_fatal(param_1,0x50,0x22f,6,"ssl/s3_lib.c",uVar4);
    }
  }
LAB_000dae34:
  EVP_PKEY_CTX_free(ctx);
  return local_1c[0];
}

