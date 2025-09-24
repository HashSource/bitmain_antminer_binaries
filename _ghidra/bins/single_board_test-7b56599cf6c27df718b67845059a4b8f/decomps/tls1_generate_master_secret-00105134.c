
/* WARNING: Type propagation algorithm not settling */

undefined4
tls1_generate_master_secret
          (int param_1,uchar *param_2,void *param_3,int param_4,undefined4 *param_5)

{
  size_t *ptr;
  int iVar1;
  void *p2;
  EVP_PKEY_CTX *ctx;
  int iVar2;
  size_t local_ac [34];
  
  if ((*(uint *)(*(int *)(param_1 + 0x474) + 0x1fc) & 1) == 0) {
    iVar1 = *(int *)(param_1 + 0x7c);
    local_ac[1] = 0x30;
    p2 = (void *)ssl_prf_md();
    if (p2 == (void *)0x0) {
      ossl_statem_fatal(param_1,0x50,0x11c,0x44,"ssl/t1_enc.c",0x24);
      return 0;
    }
    ctx = EVP_PKEY_CTX_new_id(0x3fd,(ENGINE *)0x0);
    if ((ctx != (EVP_PKEY_CTX *)0x0) && (iVar2 = EVP_PKEY_derive_init(ctx), 0 < iVar2)) {
      iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1000,0,p2);
      if (0 < iVar2) {
        iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1001,param_4,param_3);
        if (0 < iVar2) {
          iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0xd,"master secret");
          if (0 < iVar2) {
            iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0x20,(void *)(iVar1 + 0xac));
            if (0 < iVar2) {
              iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0,(void *)0x0);
              if (0 < iVar2) {
                iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0x20,(void *)(iVar1 + 0x8c));
                if (0 < iVar1) {
                  iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1002,0,(void *)0x0);
                  if ((0 < iVar1) && (iVar1 = EVP_PKEY_derive(ctx,param_2,local_ac + 1), 0 < iVar1))
                  {
                    EVP_PKEY_CTX_free(ctx);
                    goto LAB_0010526e;
                  }
                }
              }
            }
          }
        }
      }
    }
    ossl_statem_fatal(param_1,0x50,0x11c,0x44,"ssl/t1_enc.c",0x35);
    EVP_PKEY_CTX_free(ctx);
  }
  else {
    iVar1 = ssl3_digest_cached_records(param_1,1);
    if (iVar1 != 0) {
      ptr = local_ac + 1;
      iVar1 = ssl_handshake_hash(param_1,ptr,0x80,local_ac);
      if (iVar1 != 0) {
        iVar1 = tls1_PRF_constprop_0
                          (param_1,"extended master secret",0x16,ptr,local_ac[0],0,0,0,0,param_3,
                           param_4,param_2,0x30,1);
        if (iVar1 != 0) {
          OPENSSL_cleanse(ptr,local_ac[0]);
LAB_0010526e:
          *param_5 = 0x30;
          return 1;
        }
      }
    }
  }
  return 0;
}

