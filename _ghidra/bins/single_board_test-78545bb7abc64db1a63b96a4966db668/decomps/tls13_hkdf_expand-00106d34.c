
uint tls13_hkdf_expand(undefined4 param_1,EVP_MD *param_2,void *param_3,undefined4 param_4,
                      uint param_5,int param_6,undefined4 param_7,uchar *param_8,size_t param_9,
                      uint param_10)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  int local_188;
  undefined1 auStack_184 [24];
  undefined1 auStack_16c [328];
  
  ctx = EVP_PKEY_CTX_new_id(0x40c,(ENGINE *)0x0);
  if (ctx != (EVP_PKEY_CTX *)0x0) {
    if (param_5 < 0xfa) {
      iVar1 = EVP_MD_size(param_2);
      uVar4 = WPACKET_init_static_len(auStack_184,auStack_16c,0x143,0);
      if (((((int)uVar4 != 0) &&
           (iVar2 = WPACKET_put_bytes__(auStack_184,(int)((ulonglong)uVar4 >> 0x20),param_9,0,2),
           iVar2 != 0)) && (iVar2 = WPACKET_start_sub_packet_len__(auStack_184,1), iVar2 != 0)) &&
         (((iVar2 = WPACKET_memcpy(auStack_184,"tls13 ",6), iVar2 != 0 &&
           (iVar2 = WPACKET_memcpy(auStack_184,param_4,param_5), iVar2 != 0)) &&
          (iVar2 = WPACKET_close(auStack_184), iVar2 != 0)))) {
        if (param_6 == 0) {
          param_7 = 0;
        }
        iVar2 = WPACKET_sub_memcpy__(auStack_184,param_6,param_7,1);
        if (((iVar2 != 0) && (iVar2 = WPACKET_get_total_written(auStack_184,&local_188), iVar2 != 0)
            ) && (iVar2 = WPACKET_finish(auStack_184), iVar2 != 0)) {
          iVar2 = EVP_PKEY_derive_init(ctx);
          if (((((iVar2 < 1) ||
                (iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1007,2,(void *)0x0), iVar2 < 1)) ||
               (iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1003,0,param_2), iVar2 < 1)) ||
              ((iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1005,iVar1,param_3), iVar1 < 1 ||
               (iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x400,0x1006,local_188,auStack_16c), iVar1 < 1))))
             || (iVar1 = EVP_PKEY_derive(ctx,param_8,&param_9), iVar1 < 1)) {
            EVP_PKEY_CTX_free(ctx);
            if (param_10 == 0) {
              ERR_put_error(0x14,0x231,0x44,"ssl/tls13_enc.c",0x6a);
              uVar3 = 1;
            }
            else {
              ossl_statem_fatal(param_1,0x50,0x231,0x44,"ssl/tls13_enc.c",0x68);
              uVar3 = 1;
            }
          }
          else {
            EVP_PKEY_CTX_free(ctx);
            uVar3 = 0;
          }
          return uVar3 ^ 1;
        }
      }
      EVP_PKEY_CTX_free(ctx);
      WPACKET_cleanup(auStack_184);
      if (param_10 == 0) {
        ERR_put_error(0x14,0x231,0x44,"ssl/tls13_enc.c",0x57);
        return param_10;
      }
      ossl_statem_fatal(param_1,0x50,0x231,0x44,"ssl/tls13_enc.c",0x55);
      return 0;
    }
    if (param_10 == 0) {
      ERR_put_error(0x14,0x231,0x16f,"ssl/tls13_enc.c",0x40);
    }
    else {
      ossl_statem_fatal(param_1,0x50,0x231,0x44,"ssl/tls13_enc.c",0x3a);
    }
    EVP_PKEY_CTX_free(ctx);
  }
  return 0;
}

