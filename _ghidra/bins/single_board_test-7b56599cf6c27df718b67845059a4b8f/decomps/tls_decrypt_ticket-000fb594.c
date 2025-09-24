
uint tls_decrypt_ticket(int param_1,uchar *param_2,uint param_3,void *param_4,size_t param_5,
                       undefined4 *param_6)

{
  bool bVar1;
  size_t len;
  int iVar2;
  EVP_MD *md;
  EVP_CIPHER *cipher;
  uchar *out;
  int iVar3;
  uint uVar4;
  EVP_CIPHER_CTX *ctx;
  code *pcVar5;
  SSL_SESSION *ses;
  SSL_SESSION *pSVar6;
  void *key;
  HMAC_CTX *ctx_00;
  uint uVar7;
  uint local_80;
  uchar *local_74;
  int local_70;
  int local_6c;
  uchar auStack_68 [68];
  
  if (param_3 == 0) {
    uVar4 = 3;
    local_80 = 0xfffffffe;
    ctx = (EVP_CIPHER_CTX *)0x0;
    ses = (SSL_SESSION *)0x0;
    ctx_00 = (HMAC_CTX *)0x0;
    uVar7 = 0;
LAB_000fb5da:
    EVP_CIPHER_CTX_free(ctx);
    HMAC_CTX_free(ctx_00);
    pcVar5 = *(code **)(*(int *)(param_1 + 0x5e0) + 0x238);
    pSVar6 = ses;
    if (pcVar5 == (code *)0x0) goto LAB_000fb5f2;
    if (0xf < param_3) {
      param_3 = 0x10;
    }
    iVar3 = (*pcVar5)(param_1,ses,param_2,param_3,uVar4,
                      *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x23c));
    switch(iVar3) {
    case 1:
      uVar4 = 2;
      SSL_SESSION_free(ses);
      ses = (SSL_SESSION *)0x0;
      break;
    case 2:
      if (1 < uVar7) {
        uVar4 = 4;
      }
      pSVar6 = (SSL_SESSION *)0x0;
      SSL_SESSION_free(ses);
      goto LAB_000fb5f2;
    case 3:
    case 4:
      if (1 < local_80) goto switchD_000fb6de_default;
      if (iVar3 == 3) {
        uVar4 = 5;
        break;
      }
      uVar4 = 6;
      if (*(int *)(param_1 + 0x58c) != 0) goto LAB_000fb5f8;
      goto LAB_000fb624;
    default:
switchD_000fb6de_default:
      uVar4 = 1;
    }
    if (*(int *)(param_1 + 0x58c) == 0) goto LAB_000fb62a;
LAB_000fb5f8:
    if ((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
       (iVar3 = **(int **)(param_1 + 4), iVar3 == 0x10000 || iVar3 < 0x304)) goto LAB_000fb62a;
  }
  else {
    if ((((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
         (iVar3 = **(int **)(param_1 + 4), iVar3 == 0x10000 || iVar3 < 0x304)) &&
        (*(int *)(param_1 + 0x58c) != 0)) || (param_3 < 0x20)) {
      ctx = (EVP_CIPHER_CTX *)0x0;
      uVar7 = 1;
      ctx_00 = (HMAC_CTX *)0x0;
      ses = (SSL_SESSION *)0x0;
      local_80 = 0xffffffff;
      uVar4 = 4;
      goto LAB_000fb5da;
    }
    iVar3 = *(int *)(param_1 + 0x5e0);
    ctx_00 = (HMAC_CTX *)HMAC_CTX_new();
    if (ctx_00 == (HMAC_CTX *)0x0) {
      uVar4 = 0;
      ctx = (EVP_CIPHER_CTX *)0x0;
    }
    else {
      ctx = EVP_CIPHER_CTX_new();
      if (ctx == (EVP_CIPHER_CTX *)0x0) {
        uVar4 = 0;
      }
      else {
        if (*(code **)(iVar3 + 0x14c) == (code *)0x0) {
          iVar2 = memcmp(param_2,(void *)(iVar3 + 0x138),0x10);
          if (iVar2 != 0) {
            uVar7 = 1;
            local_80 = 0xffffffff;
            uVar4 = 4;
            ses = (SSL_SESSION *)0x0;
            goto LAB_000fb5da;
          }
          key = *(void **)(iVar3 + 0x148);
          md = EVP_sha256();
          iVar2 = HMAC_Init_ex(ctx_00,key,0x20,md,(ENGINE *)0x0);
          if (0 < iVar2) {
            cipher = EVP_aes_256_cbc();
            iVar3 = EVP_DecryptInit_ex(ctx,cipher,(ENGINE *)0x0,
                                       (uchar *)(*(int *)(iVar3 + 0x148) + 0x20),param_2 + 0x10);
            if (0 < iVar3) {
              bVar1 = false;
              if (-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) {
                iVar3 = **(int **)(param_1 + 4);
                bVar1 = iVar3 != 0x10000 && 0x303 < iVar3;
              }
              goto LAB_000fb69e;
            }
          }
        }
        else {
          iVar3 = (**(code **)(iVar3 + 0x14c))(param_1,param_2,param_2 + 0x10,ctx,ctx_00,0);
          if (-1 < iVar3) {
            if (iVar3 == 0) {
              uVar7 = 1;
              local_80 = 0xffffffff;
              uVar4 = 4;
              ses = (SSL_SESSION *)0x0;
              goto LAB_000fb5da;
            }
            bVar1 = iVar3 == 2;
LAB_000fb69e:
            len = HMAC_size(ctx_00);
            if (len != 0) {
              iVar3 = EVP_CIPHER_CTX_iv_length(ctx);
              if (param_3 <= iVar3 + len + 0x10) {
LAB_000fb7d6:
                uVar7 = 1;
                local_80 = 0xffffffff;
                uVar4 = 4;
                ses = (SSL_SESSION *)0x0;
                goto LAB_000fb5da;
              }
              param_3 = param_3 - len;
              iVar3 = HMAC_Update(ctx_00,param_2,param_3);
              if (0 < iVar3) {
                iVar3 = HMAC_Final(ctx_00,auStack_68,(uint *)0x0);
                if (0 < iVar3) {
                  iVar3 = CRYPTO_memcmp(auStack_68,param_2 + param_3,len);
                  if (iVar3 == 0) {
                    iVar3 = EVP_CIPHER_CTX_iv_length(ctx);
                    local_74 = param_2 + iVar3 + 0x10;
                    iVar3 = EVP_CIPHER_CTX_iv_length(ctx);
                    param_3 = param_3 - (iVar3 + 0x10);
                    out = (uchar *)CRYPTO_malloc(param_3,"ssl/t1_lib.c",0x5c1);
                    if ((out == (uchar *)0x0) ||
                       (iVar3 = EVP_DecryptUpdate(ctx,out,&local_70,local_74,param_3), iVar3 < 1)) {
                      uVar4 = 1;
                      CRYPTO_free(out);
                      goto LAB_000fb6ae;
                    }
                    iVar3 = EVP_DecryptFinal(ctx,out + local_70,&local_6c);
                    if (iVar3 < 1) {
                      uVar7 = 1;
                      CRYPTO_free(out);
                      uVar4 = 4;
                      local_80 = 0xffffffff;
                      ses = (SSL_SESSION *)0x0;
                    }
                    else {
                      local_70 = local_6c + local_70;
                      local_74 = out;
                      ses = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_74,local_70);
                      local_70 = local_70 - ((int)local_74 - (int)out);
                      CRYPTO_free(out);
                      if (ses == (SSL_SESSION *)0x0) {
                        ERR_clear_error();
                        uVar7 = 1;
                        local_80 = 0xffffffff;
                        uVar4 = 4;
                      }
                      else if (local_70 == 0) {
                        if (param_5 != 0) {
                          memcpy(ses->krb5_client_princ + 0xbc,param_4,param_5);
                          *(size_t *)(ses->krb5_client_princ + 0xb8) = param_5;
                        }
                        if (!bVar1) {
                          uVar7 = 2;
                          uVar4 = 5;
                        }
                        else {
                          uVar7 = 3;
                          uVar4 = 6;
                        }
                        local_80 = (uint)bVar1;
                      }
                      else {
                        uVar7 = 1;
                        SSL_SESSION_free(ses);
                        uVar4 = 4;
                        local_80 = 0xffffffff;
                        ses = (SSL_SESSION *)0x0;
                      }
                    }
                    goto LAB_000fb5da;
                  }
                  goto LAB_000fb7d6;
                }
              }
            }
          }
        }
        uVar4 = 1;
      }
    }
LAB_000fb6ae:
    pSVar6 = (SSL_SESSION *)0x0;
    EVP_CIPHER_CTX_free(ctx);
    HMAC_CTX_free(ctx_00);
LAB_000fb5f2:
    ses = pSVar6;
    if (*(int *)(param_1 + 0x58c) != 0) goto LAB_000fb5f8;
  }
  if ((2 < uVar4) && ((uVar4 < 5 || (uVar4 == 6)))) {
LAB_000fb624:
    *(undefined4 *)(param_1 + 0x55c) = 1;
  }
LAB_000fb62a:
  *param_6 = ses;
  return uVar4;
}

