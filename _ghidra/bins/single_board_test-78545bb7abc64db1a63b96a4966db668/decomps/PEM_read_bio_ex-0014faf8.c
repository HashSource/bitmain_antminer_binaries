
uint PEM_read_bio_ex(BIO *param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5,
                    uint param_6)

{
  BIO_METHOD *pBVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  EVP_ENCODE_CTX *ctx;
  long len;
  void *pvVar8;
  uint uVar9;
  char *__s;
  int iVar10;
  size_t sVar11;
  BIO *bp;
  bool bVar12;
  bool bVar13;
  uint local_68;
  BIO *local_64;
  BIO *local_5c;
  int local_34;
  int local_30;
  int *local_2c [2];
  
  __s = (char *)0x0;
  *param_5 = 0;
  *param_3 = 0;
  *param_2 = 0;
  *param_4 = 0;
  if ((param_6 & 6) == 6) {
    ctx = (EVP_ENCODE_CTX *)0x0;
    uVar9 = 0;
    ERR_put_error(9,0x91,7,"crypto/pem/pem_lib.c",0x392);
    local_64 = (BIO *)0x0;
    local_5c = (BIO *)0x0;
LAB_0014fd7a:
    local_68 = param_6 & 1;
    EVP_ENCODE_CTX_free(ctx);
    if (local_68 != 0) {
LAB_0014fd86:
      CRYPTO_secure_clear_free(__s,0,"crypto/pem/pem_lib.c",0xdd);
      goto LAB_0014fd4c;
    }
  }
  else {
    uVar9 = param_6 & 1;
    if (uVar9 == 0) {
      pBVar1 = BIO_s_mem();
      local_5c = BIO_new(pBVar1);
      local_64 = BIO_new(pBVar1);
      if (local_64 == (BIO *)0x0 || local_5c == (BIO *)0x0) goto LAB_0014fd60;
      pcVar2 = (char *)CRYPTO_malloc(0x100,"crypto/pem/pem_lib.c",0xe5);
    }
    else {
      pBVar1 = (BIO_METHOD *)BIO_s_secmem();
      local_5c = BIO_new(pBVar1);
      local_64 = BIO_new(pBVar1);
      if (local_64 == (BIO *)0x0 || local_5c == (BIO *)0x0) {
LAB_0014fd60:
        __s = (char *)0x0;
        uVar9 = 0;
        ctx = (EVP_ENCODE_CTX *)0x0;
        ERR_put_error(9,0x91,0x41,"crypto/pem/pem_lib.c",0x39a);
        goto LAB_0014fd7a;
      }
      pcVar2 = (char *)CRYPTO_secure_malloc(0x100,"crypto/pem/pem_lib.c",0xe4);
    }
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(9,0x90,0x41,"crypto/pem/pem_lib.c",0x2e1);
      uVar9 = 0;
      ctx = (EVP_ENCODE_CTX *)0x0;
      __s = (char *)0x0;
      goto LAB_0014fd7a;
    }
    do {
      iVar3 = BIO_gets(param_1,pcVar2,0xff);
      if (iVar3 < 1) {
        ERR_put_error(9,0x90,0x6c,"crypto/pem/pem_lib.c",0x2e9);
        goto LAB_0014fd1e;
      }
      iVar3 = sanitize_line(pcVar2,iVar3,param_6 & 0xfffffffb);
      uVar4 = strncmp(pcVar2,"-----BEGIN ",0xb);
      if (uVar4 != 0) {
        uVar4 = 1;
      }
      if (iVar3 < 6) {
        uVar4 = uVar4 | 1;
      }
    } while ((uVar4 != 0) || (iVar5 = strncmp(pcVar2 + iVar3 + -6,"-----\n",6), iVar5 != 0));
    sVar11 = iVar3 - 0x10;
    pcVar2[iVar3 + -6] = '\0';
    if (uVar9 == 0) {
      __s = (char *)CRYPTO_malloc(sVar11,"crypto/pem/pem_lib.c",0xe5);
    }
    else {
      __s = (char *)CRYPTO_secure_malloc(sVar11,"crypto/pem/pem_lib.c",0xe4);
    }
    if (__s == (char *)0x0) {
      ERR_put_error(9,0x90,0x41,"crypto/pem/pem_lib.c",0x2f8);
LAB_0014fd1e:
      if (uVar9 == 0) {
        CRYPTO_free(pcVar2);
        EVP_ENCODE_CTX_free(0);
        __s = (char *)0x0;
        goto LAB_0014fd3e;
      }
      __s = (char *)0x0;
      uVar9 = 0;
      CRYPTO_secure_clear_free(pcVar2,0x100,"crypto/pem/pem_lib.c",0xdd);
      EVP_ENCODE_CTX_free(0);
      goto LAB_0014fd86;
    }
    memcpy(__s,pcVar2 + 0xb,sVar11);
    if (uVar9 == 0) {
      CRYPTO_free(pcVar2);
      pcVar2 = (char *)CRYPTO_malloc(0x100,"crypto/pem/pem_lib.c",0xe5);
    }
    else {
      CRYPTO_secure_clear_free(pcVar2,0x100,"crypto/pem/pem_lib.c",0xdd);
      pcVar2 = (char *)CRYPTO_secure_malloc(0x100,"crypto/pem/pem_lib.c",0xe4);
    }
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(9,0x8f,0x41,"crypto/pem/pem_lib.c",0x324);
      uVar9 = 0;
      ctx = (EVP_ENCODE_CTX *)0x0;
      goto LAB_0014fd7a;
    }
    iVar5 = 0;
    bVar12 = false;
    iVar3 = 0;
    bp = local_5c;
    while (sVar11 = BIO_gets(param_1,pcVar2,0xff), 0 < (int)sVar11) {
      if (sVar11 == 0xfe) {
        iVar10 = (byte)pcVar2[0xfd] - 10;
        if (iVar10 != 0) {
          iVar10 = 1;
        }
        if (iVar5 != 0) goto LAB_0014fdaa;
LAB_0014fc7c:
        pvVar6 = memchr(pcVar2,0x3a,sVar11);
        if (pvVar6 == (void *)0x0) {
          iVar7 = strncmp(pcVar2,"-----END ",9);
          if (iVar7 == 0) goto LAB_0014fdfc;
          goto LAB_0014fdbe;
        }
        iVar5 = 1;
        uVar4 = 0xfffffffb;
      }
      else {
        iVar10 = 0;
        if (iVar5 == 0) goto LAB_0014fc7c;
LAB_0014fdaa:
        iVar7 = strncmp(pcVar2,"-----END ",9);
        if (iVar7 == 0 || iVar5 == 1) {
LAB_0014fdfc:
          uVar4 = 0xfffffffb;
        }
        else {
          iVar5 = 2;
LAB_0014fdbe:
          uVar4 = 0xffffffff;
        }
      }
      iVar7 = sanitize_line(pcVar2,sVar11,param_6 & uVar4);
      if (*pcVar2 == '\n') {
        bVar13 = iVar3 == 0;
        iVar3 = iVar10;
        if (bVar13) {
          if (iVar5 == 2) {
            iVar3 = 0x349;
            goto LAB_0014fe50;
          }
          iVar5 = 2;
          bp = local_64;
        }
      }
      else {
        iVar3 = strncmp(pcVar2,"-----END ",9);
        if (iVar3 == 0) {
          sVar11 = strlen(__s);
          iVar3 = strncmp(pcVar2 + 9,__s,sVar11);
          if ((iVar3 != 0) || (iVar3 = strncmp(pcVar2 + 9 + sVar11,"-----\n",6), iVar3 != 0)) {
            iVar3 = 0x358;
            goto LAB_0014fe50;
          }
          if (iVar5 == 0) {
            local_5c = local_64;
            local_64 = bp;
          }
          if (uVar9 == 0) {
            CRYPTO_free(pcVar2);
            BIO_ctrl(local_64,0x73,0,local_2c);
            local_34 = *local_2c[0];
            if (local_34 == 0) {
              EVP_ENCODE_CTX_free();
              goto LAB_0014fd3e;
            }
          }
          else {
            CRYPTO_secure_clear_free(pcVar2,0x100,"crypto/pem/pem_lib.c",0xdd);
            BIO_ctrl(local_64,0x73,0,local_2c);
            local_34 = *local_2c[0];
            if (local_34 == 0) {
              EVP_ENCODE_CTX_free();
              uVar9 = 0;
              goto LAB_0014fd86;
            }
          }
          ctx = (EVP_ENCODE_CTX *)EVP_ENCODE_CTX_new();
          if (ctx == (EVP_ENCODE_CTX *)0x0) {
            ERR_put_error(9,0x91,0x41,"crypto/pem/pem_lib.c",0x3ac);
            uVar9 = 0;
            goto LAB_0014fd7a;
          }
          EVP_DecodeInit(ctx);
          iVar3 = EVP_DecodeUpdate(ctx,(uchar *)local_2c[0][1],&local_34,(uchar *)local_2c[0][1],
                                   local_34);
          if ((iVar3 < 0) ||
             (iVar3 = EVP_DecodeFinal(ctx,(uchar *)(local_2c[0][1] + local_34),&local_30), iVar3 < 0
             )) {
            uVar9 = 0;
            ERR_put_error(9,0x91,100,"crypto/pem/pem_lib.c",0x3b5);
            goto LAB_0014fd7a;
          }
          local_34 = local_34 + local_30;
          *local_2c[0] = local_34;
          len = BIO_ctrl(local_5c,3,0,(void *)0x0);
          if (uVar9 == 0) {
            pvVar6 = CRYPTO_malloc(len + 1,"crypto/pem/pem_lib.c",0xe5);
            *param_3 = (int)pvVar6;
            pvVar8 = CRYPTO_malloc(local_34,"crypto/pem/pem_lib.c",0xe5);
            *param_4 = (int)pvVar8;
            pvVar6 = (void *)*param_3;
            if (pvVar8 == (void *)0x0 || pvVar6 == (void *)0x0) {
              CRYPTO_free(pvVar6);
              CRYPTO_free((void *)*param_4);
              EVP_ENCODE_CTX_free(ctx);
              goto LAB_0014fd3e;
            }
          }
          else {
            iVar3 = CRYPTO_secure_malloc(len + 1,"crypto/pem/pem_lib.c",0xe4);
            *param_3 = iVar3;
            iVar3 = CRYPTO_secure_malloc(local_34,"crypto/pem/pem_lib.c",0xe4);
            *param_4 = iVar3;
            pvVar6 = (void *)*param_3;
            if (iVar3 == 0 || pvVar6 == (void *)0x0) {
              CRYPTO_secure_clear_free(pvVar6,0,"crypto/pem/pem_lib.c",0xdd);
              uVar9 = 0;
              CRYPTO_secure_clear_free(*param_4,0,"crypto/pem/pem_lib.c",0xdd);
              EVP_ENCODE_CTX_free(ctx);
              goto LAB_0014fd86;
            }
          }
          BIO_read(local_5c,pvVar6,len);
          uVar9 = 1;
          *(undefined1 *)(*param_3 + len) = 0;
          BIO_read(local_64,(void *)*param_4,local_34);
          *param_5 = local_34;
          *param_2 = __s;
          __s = (char *)0x0;
          goto LAB_0014fd7a;
        }
        if (bVar12) {
          iVar3 = 0x362;
          goto LAB_0014fe50;
        }
        iVar3 = BIO_puts(bp,pcVar2);
        if ((iVar3 < 0) || ((iVar3 = iVar10, iVar5 == 2 && (bVar12 = iVar7 != 0x41, 0x41 < iVar7))))
        goto LAB_0014fe5c;
      }
    }
    iVar3 = 0x32c;
LAB_0014fe50:
    ERR_put_error(9,0x8f,0x66,"crypto/pem/pem_lib.c",iVar3);
LAB_0014fe5c:
    if (uVar9 != 0) {
      CRYPTO_secure_clear_free(pcVar2,0x100,"crypto/pem/pem_lib.c",0xdd);
      uVar9 = 0;
      EVP_ENCODE_CTX_free();
      goto LAB_0014fd86;
    }
    CRYPTO_free(pcVar2);
    EVP_ENCODE_CTX_free(0);
  }
LAB_0014fd3e:
  CRYPTO_free(__s);
LAB_0014fd4c:
  BIO_free(local_5c);
  BIO_free(local_64);
  return uVar9;
}

