
ENGINE * ssl_derive(int param_1,EVP_PKEY *param_2,EVP_PKEY *param_3,int param_4)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  uchar *key;
  ENGINE *e;
  undefined4 uVar2;
  int iVar3;
  size_t local_24;
  
  e = (ENGINE *)(uint)(param_3 == (EVP_PKEY *)0x0 || param_2 == (EVP_PKEY *)0x0);
  local_24 = 0;
  if (param_3 == (EVP_PKEY *)0x0 || param_2 == (EVP_PKEY *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x24e,0x44,"ssl/s3_lib.c",0x12be);
    return (ENGINE *)0x0;
  }
  ctx = EVP_PKEY_CTX_new(param_2,e);
  iVar1 = EVP_PKEY_derive_init(ctx);
  if ((0 < iVar1) && (iVar1 = EVP_PKEY_derive_set_peer(ctx,param_3), 0 < iVar1)) {
    iVar1 = EVP_PKEY_derive(ctx,(uchar *)e,&local_24);
    if (0 < iVar1) {
      key = (uchar *)CRYPTO_malloc(local_24,"ssl/s3_lib.c",0x12cc);
      if (key == (uchar *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x24e,0x41,"ssl/s3_lib.c",0x12cf);
        e = (ENGINE *)0x0;
      }
      else {
        iVar1 = EVP_PKEY_derive(ctx,key,&local_24);
        if (iVar1 < 1) {
          ossl_statem_fatal(param_1,0x50,0x24e,0x44,"ssl/s3_lib.c",0x12d5);
        }
        else if (param_4 == 0) {
          iVar1 = *(int *)(param_1 + 0x7c);
          e = (ENGINE *)0x1;
          *(uchar **)(iVar1 + 0x250) = key;
          *(size_t *)(iVar1 + 0x254) = local_24;
          key = (uchar *)0x0;
        }
        else {
          if (-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) {
            iVar3 = **(int **)(param_1 + 4);
            iVar1 = iVar3 + -0x10000;
            if (iVar1 != 0) {
              iVar1 = 1;
            }
            if (iVar3 < 0x304) {
              iVar1 = 0;
            }
            if (iVar1 != 0) {
              if (*(int *)(param_1 + 0x8c) == 0) {
                uVar2 = ssl_handshake_md(param_1);
                e = (ENGINE *)tls13_generate_secret(param_1,uVar2,0,0,0,param_1 + 0xcc);
                if (e == (ENGINE *)0x0) goto LAB_000db044;
              }
              e = (ENGINE *)tls13_generate_handshake_secret(param_1,key,local_24);
              if (e != (ENGINE *)0x0) {
                e = (ENGINE *)0x1;
              }
              goto LAB_000db044;
            }
          }
          e = (ENGINE *)ssl_generate_master_secret(param_1,key,local_24,0);
        }
      }
      goto LAB_000db044;
    }
  }
  key = (uchar *)0x0;
  ossl_statem_fatal(param_1,0x50,0x24e,0x44,"ssl/s3_lib.c",0x12c8);
  e = (ENGINE *)0x0;
LAB_000db044:
  CRYPTO_clear_free(key,local_24,"ssl/s3_lib.c",0x12f4);
  EVP_PKEY_CTX_free(ctx);
  return e;
}

