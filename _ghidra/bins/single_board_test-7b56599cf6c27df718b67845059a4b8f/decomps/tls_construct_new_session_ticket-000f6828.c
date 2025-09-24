
int tls_construct_new_session_ticket(int param_1,undefined4 param_2)

{
  EVP_MD *pEVar1;
  int iVar2;
  SSL_SESSION *in;
  time_t tVar3;
  EVP_CIPHER *cipher;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  SSL_SESSION **a;
  undefined4 uVar8;
  void *key;
  uchar *in_00;
  EVP_CIPHER_CTX *ctx;
  HMAC_CTX *ctx_00;
  uchar *local_94;
  int local_90;
  int local_8c;
  undefined4 local_80;
  uchar *local_7c;
  uchar *local_78;
  uchar *local_74;
  uchar *local_70;
  uchar *local_6c;
  uchar *local_68;
  int local_64;
  int local_60;
  uint local_5c;
  int local_58;
  int local_54;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  uchar auStack_48 [16];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  local_80 = 0;
  local_90 = *(int *)(param_1 + 0x5e0);
  if ((*(uint *)((*(int **)(param_1 + 4))[0x19] + 0x30) & 8) == 0) {
    iVar5 = **(int **)(param_1 + 4);
    if (iVar5 == 0x10000 || iVar5 < 0x304) {
      pcVar7 = *(code **)(local_90 + 0x234);
      goto joined_r0x000f68b6;
    }
    pEVar1 = (EVP_MD *)ssl_handshake_md();
    iVar5 = EVP_MD_size(pEVar1);
    if (iVar5 < 0) {
      uVar6 = 0xff1;
      iVar5 = 0;
      goto LAB_000f6ac0;
    }
    if ((*(int *)(param_1 + 0xf70) == 0) && (*(int *)(param_1 + 0x8c) == 0)) {
      iVar2 = *(int *)(param_1 + 0x474);
    }
    else {
      iVar2 = ssl_session_dup(*(undefined4 *)(param_1 + 0x474),0);
      if (iVar2 == 0) {
        return 0;
      }
      SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0x474));
      *(int *)(param_1 + 0x474) = iVar2;
    }
    iVar2 = ssl_generate_session_id(param_1,iVar2);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = RAND_bytes((uchar *)&local_80,4);
    if (iVar2 < 1) {
      ossl_statem_fatal(param_1,0x50,0x1ac,0x44,"ssl/statem/statem_srvr.c",0x100e);
      return 0;
    }
    uVar6 = *(undefined4 *)(param_1 + 0xf78);
    uVar8 = *(undefined4 *)(param_1 + 0xf7c);
    iVar2 = *(int *)(param_1 + 0x474);
    local_49 = (undefined1)uVar6;
    local_4a = (undefined1)((uint)uVar6 >> 8);
    *(undefined4 *)(iVar2 + 0x1dc) = local_80;
    local_4b = (undefined1)((uint)uVar6 >> 0x10);
    local_4f = (undefined1)((uint)uVar8 >> 0x10);
    local_4c = (undefined1)((uint)uVar6 >> 0x18);
    local_50 = (undefined1)((uint)uVar8 >> 0x18);
    local_4d = (undefined1)uVar8;
    local_4e = (undefined1)((uint)uVar8 >> 8);
    iVar2 = tls13_hkdf_expand(param_1,pEVar1,param_1 + 0x18c,"resumption",10,&local_50,8,
                              iVar2 + 0x48,iVar5,1);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x474);
    *(int *)(iVar2 + 4) = iVar5;
    tVar3 = time((time_t *)0x0);
    iVar5 = *(int *)(param_1 + 0x7c);
    *(time_t *)(iVar2 + 0x1b0) = tVar3;
    if (*(int *)(iVar5 + 0x340) == 0) {
      iVar5 = *(int *)(param_1 + 0x474);
    }
    else {
      CRYPTO_free(*(void **)(*(int *)(param_1 + 0x474) + 0x1e4));
      iVar2 = *(int *)(param_1 + 0x474);
      uVar6 = CRYPTO_memdup(*(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x340),
                            *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x344),
                            "ssl/statem/statem_srvr.c",0x1029);
      iVar5 = *(int *)(param_1 + 0x474);
      *(undefined4 *)(iVar2 + 0x1e4) = uVar6;
      if (*(int *)(iVar5 + 0x1e4) == 0) {
        *(undefined4 *)(iVar5 + 0x1e8) = 0;
        ossl_statem_fatal(param_1,0x50,0x1ac,0x41,"ssl/statem/statem_srvr.c",0x102e);
        return 0;
      }
      *(undefined4 *)(iVar5 + 0x1e8) = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x344);
    }
    pcVar7 = *(code **)(local_90 + 0x234);
    *(undefined4 *)(iVar5 + 0x1e0) = *(undefined4 *)(param_1 + 0xf50);
    if ((pcVar7 != (code *)0x0) &&
       (iVar5 = (*pcVar7)(param_1,*(undefined4 *)(local_90 + 0x23c)), iVar5 == 0)) {
      iVar5 = 0;
      goto LAB_000f6ab6;
    }
LAB_000f68c8:
    if (*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) {
      local_90 = *(int *)(param_1 + 0x5e0);
    }
    else {
      iVar5 = **(int **)(param_1 + 4);
      if (iVar5 == 0x10000 || iVar5 < 0x304) {
        local_90 = *(int *)(param_1 + 0x5e0);
      }
      else {
        if ((*(int *)(param_1 + 0x4ec) << 0x11 < 0) ||
           ((*(int *)(param_1 + 0xf50) != 0 && (-1 < *(int *)(param_1 + 0x4ec) << 7)))) {
          iVar5 = create_ticket_prequel(param_1,param_2,local_80,&local_50);
          if (iVar5 == 0) {
            return 0;
          }
          iVar5 = WPACKET_memcpy(param_2,*(int *)(param_1 + 0x474) + 0x14c,
                                 *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x148));
          if ((iVar5 == 0) || (iVar5 = WPACKET_close(param_2), iVar5 == 0)) {
            ossl_statem_fatal(param_1,0x50,0x27c,0x44,"ssl/statem/statem_srvr.c",0xfd4);
            return 0;
          }
          goto LAB_000f69cc;
        }
        local_90 = *(int *)(param_1 + 0x5e0);
      }
    }
  }
  else {
    pcVar7 = *(code **)(local_90 + 0x234);
joined_r0x000f68b6:
    if (pcVar7 != (code *)0x0) {
      iVar5 = (*pcVar7)(param_1,*(undefined4 *)(local_90 + 0x23c));
      if (iVar5 == 0) {
LAB_000f6ab6:
        uVar6 = 0x103a;
LAB_000f6ac0:
        ossl_statem_fatal(param_1,0x50,0x1ac,0x44,"ssl/statem/statem_srvr.c",uVar6);
        return iVar5;
      }
      goto LAB_000f68c8;
    }
  }
  uVar6 = local_80;
  iVar5 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0x474),(uchar **)0x0);
  if (iVar5 == 0 || 0xff00 < iVar5) {
    a = (SSL_SESSION **)0x0;
    ctx_00 = (HMAC_CTX *)0x0;
    ctx = (EVP_CIPHER_CTX *)0x0;
    in_00 = (uchar *)0x0;
    ossl_statem_fatal(param_1,0x50,0x27d,0x44,"ssl/statem/statem_srvr.c",0xf32);
  }
  else {
    in_00 = (uchar *)CRYPTO_malloc(iVar5,"ssl/statem/statem_srvr.c",0xf35);
    if (in_00 == (uchar *)0x0) {
      ossl_statem_fatal(param_1,0x50,0x27d,0x41,"ssl/statem/statem_srvr.c",0xf38);
      a = (SSL_SESSION **)0x0;
      ctx = (EVP_CIPHER_CTX *)0x0;
      ctx_00 = (HMAC_CTX *)0x0;
    }
    else {
      ctx = EVP_CIPHER_CTX_new();
      ctx_00 = (HMAC_CTX *)HMAC_CTX_new();
      a = (SSL_SESSION **)(uint)(ctx_00 == (HMAC_CTX *)0x0 || ctx == (EVP_CIPHER_CTX *)0x0);
      if (ctx_00 == (HMAC_CTX *)0x0 || ctx == (EVP_CIPHER_CTX *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x27d,0x41,"ssl/statem/statem_srvr.c",0xf40);
        a = (SSL_SESSION **)0x0;
      }
      else {
        local_7c = in_00;
        iVar2 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0x474),&local_7c);
        if (iVar2 == 0) {
          ossl_statem_fatal(param_1,0x50,0x27d,0x44,"ssl/statem/statem_srvr.c",0xf47);
          a = (SSL_SESSION **)0x0;
        }
        else {
          local_68 = in_00;
          in = d2i_SSL_SESSION(a,&local_68,iVar5);
          if (in == (SSL_SESSION *)0x0) {
            ossl_statem_fatal(param_1,0x50,0x27d,0x44,"ssl/statem/statem_srvr.c",0xf52);
            a = (SSL_SESSION **)0x0;
          }
          else {
            iVar2 = i2d_SSL_SESSION(in,(uchar **)a);
            if (iVar2 == 0 || iVar5 < iVar2) {
              ossl_statem_fatal(param_1,0x50,0x27d,0x44,"ssl/statem/statem_srvr.c",0xf5a);
              SSL_SESSION_free(in);
            }
            else {
              local_7c = in_00;
              iVar5 = i2d_SSL_SESSION(in,&local_7c);
              if (iVar5 == 0) {
                ossl_statem_fatal(param_1,0x50,0x27d,0x44,"ssl/statem/statem_srvr.c",0xf61);
                SSL_SESSION_free(in);
                a = (SSL_SESSION **)0x0;
              }
              else {
                SSL_SESSION_free(in);
                if (*(code **)(local_90 + 0x14c) == (code *)0x0) {
                  cipher = EVP_aes_256_cbc();
                  local_8c = EVP_CIPHER_iv_length(cipher);
                  iVar5 = RAND_bytes(auStack_48,local_8c);
                  if ((0 < iVar5) &&
                     (iVar5 = EVP_EncryptInit_ex(ctx,cipher,(ENGINE *)0x0,
                                                 (uchar *)(*(int *)(local_90 + 0x148) + 0x20),
                                                 auStack_48), iVar5 != 0)) {
                    key = *(void **)(local_90 + 0x148);
                    pEVar1 = EVP_sha256();
                    iVar5 = HMAC_Init_ex(ctx_00,key,0x20,pEVar1,(ENGINE *)0x0);
                    if (iVar5 != 0) {
                      local_38 = *(undefined4 *)(local_90 + 0x138);
                      uStack_34 = *(undefined4 *)(local_90 + 0x13c);
                      uStack_30 = *(undefined4 *)(local_90 + 0x140);
                      uStack_2c = *(undefined4 *)(local_90 + 0x144);
                      goto LAB_000f6d04;
                    }
                  }
                  uVar6 = 0xf90;
LAB_000f6d78:
                  uVar8 = 0x44;
LAB_000f6d7c:
                  ossl_statem_fatal(param_1,0x50,0x27d,uVar8,"ssl/statem/statem_srvr.c",uVar6);
                }
                else {
                  iVar5 = (**(code **)(local_90 + 0x14c))(param_1,&local_38,auStack_48,ctx,ctx_00,1)
                  ;
                  if (iVar5 == 0) {
                    iVar5 = WPACKET_put_bytes__(param_2,4,0,0,4);
                    if ((iVar5 != 0) && (iVar5 = WPACKET_put_bytes__(param_2,2,0,0,2), iVar5 != 0))
                    {
                      CRYPTO_free(in_00);
                      EVP_CIPHER_CTX_free(ctx);
                      HMAC_CTX_free(ctx_00);
                      goto LAB_000f69cc;
                    }
                    uVar6 = 0xf77;
                    goto LAB_000f6d78;
                  }
                  if (iVar5 < 0) {
                    uVar6 = 0xf81;
                    uVar8 = 0xea;
                    goto LAB_000f6d7c;
                  }
                  local_8c = EVP_CIPHER_CTX_iv_length(ctx);
LAB_000f6d04:
                  local_94 = auStack_48;
                  iVar5 = create_ticket_prequel(param_1,param_2,uVar6,&local_50);
                  if (iVar5 != 0) {
                    iVar5 = WPACKET_get_total_written(param_2,&local_58);
                    if (((iVar5 != 0) &&
                        (iVar5 = WPACKET_memcpy(param_2,&local_38,0x10), iVar5 != 0)) &&
                       (iVar5 = WPACKET_memcpy(param_2,local_94,local_8c), iVar5 != 0)) {
                      iVar5 = WPACKET_reserve_bytes(param_2,iVar2 + 0x20,&local_78);
                      if ((iVar5 != 0) &&
                         (iVar5 = EVP_EncryptUpdate(ctx,local_78,&local_64,in_00,iVar2), iVar5 != 0)
                         ) {
                        iVar5 = WPACKET_allocate_bytes(param_2,local_64,&local_74);
                        if ((((iVar5 != 0) &&
                             ((local_78 == local_74 &&
                              (iVar5 = EVP_EncryptFinal(ctx,local_78 + local_64,&local_60),
                              iVar5 != 0)))) &&
                            (iVar5 = WPACKET_allocate_bytes(param_2,local_60,&local_74), iVar5 != 0)
                            ) && ((((((local_74 == local_78 + local_64 &&
                                      (local_60 + local_64 <= iVar2 + 0x20)) &&
                                     (iVar5 = WPACKET_get_total_written(param_2,&local_54),
                                     iVar5 != 0)) &&
                                    ((iVar5 = HMAC_Update(ctx_00,(uchar *)(*(int *)(*(int *)(param_1
                                                                                            + 0x6c)
                                                                                   + 4) + local_58),
                                                          local_54 - local_58), iVar5 != 0 &&
                                     (iVar5 = WPACKET_reserve_bytes(param_2,0x40,&local_70),
                                     iVar5 != 0)))) &&
                                   ((iVar5 = HMAC_Final(ctx_00,local_70,&local_5c), iVar5 != 0 &&
                                    ((local_5c < 0x41 &&
                                     (iVar5 = WPACKET_allocate_bytes(param_2,local_5c,&local_6c),
                                     iVar5 != 0)))))) && (local_70 == local_6c)))) {
                          iVar5 = WPACKET_close(param_2);
                          if (iVar5 != 0) {
                            a = (SSL_SESSION **)0x1;
                            goto LAB_000f69aa;
                          }
                          uVar6 = 0xfbc;
                          goto LAB_000f6d78;
                        }
                      }
                    }
                    uVar6 = 0xfb5;
                    goto LAB_000f6d78;
                  }
                }
                a = (SSL_SESSION **)0x0;
              }
            }
          }
        }
      }
    }
  }
LAB_000f69aa:
  CRYPTO_free(in_00);
  EVP_CIPHER_CTX_free(ctx);
  HMAC_CTX_free(ctx_00);
  if (a == (SSL_SESSION **)0x0) {
    return 0;
  }
LAB_000f69cc:
  if ((*(uint *)((*(int **)(param_1 + 4))[0x19] + 0x30) & 8) == 0) {
    iVar2 = **(int **)(param_1 + 4);
    iVar5 = iVar2 + -0x10000;
    if (iVar5 != 0) {
      iVar5 = 1;
    }
    if (iVar2 < 0x304) {
      iVar5 = 0;
    }
    if (iVar5 != 0) {
      iVar5 = tls_construct_extensions(param_1,param_2,0x2000,0,0);
      if (iVar5 != 0) {
        uVar4 = *(uint *)(param_1 + 0xf78);
        *(int *)(param_1 + 0xf70) = *(int *)(param_1 + 0xf70) + 1;
        *(uint *)(param_1 + 0xf78) = uVar4 + 1;
        *(uint *)(param_1 + 0xf7c) = *(int *)(param_1 + 0xf7c) + (uint)(0xfffffffe < uVar4);
        ssl_update_cache(param_1,2);
        return 1;
      }
      return 0;
    }
  }
  return 1;
}

