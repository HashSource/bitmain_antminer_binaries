
int PEM_ASN1_write_bio(undefined1 *i2d,char *name,BIO *bp,void *x,EVP_CIPHER *enc,uchar *kstr,
                      int klen,undefined1 *cb,void *u)

{
  uchar uVar1;
  int iVar2;
  char *__s;
  size_t len;
  uchar *out;
  EVP_MD *md;
  size_t sVar3;
  uchar *puVar4;
  char *prompt;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  size_t sVar8;
  int local_510;
  int local_50c;
  undefined4 local_508;
  byte local_504 [16];
  uchar auStack_4f4 [64];
  EVP_CIPHER_CTX EStack_4b4;
  uchar local_428 [1028];
  
  if (enc == (EVP_CIPHER *)0x0) {
    __s = (char *)0x0;
  }
  else {
    iVar2 = EVP_CIPHER_nid(enc);
    __s = OBJ_nid2sn(iVar2);
    if (__s == (char *)0x0) {
      ERR_put_error(9,0x69,0x71,"pem_lib.c",0x160);
      goto LAB_000be33e;
    }
  }
  len = (*(code *)i2d)(x,0);
  if ((int)len < 0) {
    ERR_put_error(9,0x69,0xd,"pem_lib.c",0x166);
LAB_000be33e:
    OPENSSL_cleanse(auStack_4f4,0x40);
    OPENSSL_cleanse(local_504,0x10);
    OPENSSL_cleanse(&EStack_4b4,0x8c);
    OPENSSL_cleanse(local_428,0x400);
    return 0;
  }
  out = (uchar *)CRYPTO_malloc(len + 0x14,"pem_lib.c",0x16c);
  if (out == (uchar *)0x0) {
    ERR_put_error(9,0x69,0x41,"pem_lib.c",0x16e);
    goto LAB_000be33e;
  }
  local_508 = out;
  local_510 = (*(code *)i2d)(x,&local_508);
  if (enc == (EVP_CIPHER *)0x0) {
    local_428[0] = '\0';
LAB_000be372:
    local_510 = PEM_write_bio(bp,name,(char *)local_428,out,local_510);
    uVar6 = (uint)(0 < local_510);
  }
  else {
    if (kstr == (uchar *)0x0) {
      if (cb == (undefined1 *)0x0) {
        if (u != (void *)0x0) {
          klen = strlen((char *)u);
          if (0x3ff < klen) {
            klen = 0x400;
          }
          memcpy(local_428,u,klen);
          goto LAB_000be3aa;
        }
        prompt = EVP_get_pw_prompt();
        if (prompt == (char *)0x0) {
          prompt = "Enter PEM pass phrase:";
        }
        while (iVar2 = EVP_read_pw_string_min((char *)local_428,4,0x400,prompt,1), iVar2 == 0) {
          klen = strlen((char *)local_428);
          if (3 < klen) goto LAB_000be3aa;
          fprintf(stderr,"phrase is too short, needs to be at least %d chars\n",4);
        }
        ERR_put_error(9,100,0x6d,"pem_lib.c",0x6e);
        memset(local_428,0,0x400);
      }
      else {
        klen = (*(code *)cb)(local_428,0x400,1,u);
LAB_000be3aa:
        kstr = local_428;
        if (0 < klen) goto LAB_000be1b0;
      }
      ERR_put_error(9,0x69,0x6f,"pem_lib.c",0x17b);
      uVar6 = 0;
      goto LAB_000be2f0;
    }
LAB_000be1b0:
    RAND_add(out,local_510,0.0);
    iVar2 = enc->iv_len;
    if (0x10 < iVar2) {
      OpenSSLDie("pem_lib.c",0x185,"enc->iv_len <= (int)sizeof(iv)");
      iVar2 = enc->iv_len;
    }
    iVar2 = RAND_pseudo_bytes(local_504,iVar2);
    if (-1 < iVar2) {
      md = EVP_md5();
      iVar2 = EVP_BytesToKey(enc,md,local_504,kstr,klen,1,auStack_4f4,(uchar *)0x0);
      if (iVar2 != 0) {
        if (kstr == local_428) {
          OPENSSL_cleanse(local_428,0x400);
        }
        sVar3 = strlen(__s);
        if (0x400 < sVar3 + enc->iv_len * 2 + 0x24) {
          OpenSSLDie("pem_lib.c",0x193,"strlen(objstr) + 23 + 2 * enc->iv_len + 13 <= sizeof buf");
        }
        local_428[0] = '\0';
        BUF_strlcat((char *)local_428,"Proc-Type: 4,",0x400);
        BUF_strlcat((char *)local_428,"ENCRYPTED",0x400);
        BUF_strlcat((char *)local_428,"\n",0x400);
        iVar2 = enc->iv_len;
        BUF_strlcat((char *)local_428,"DEK-Info: ",0x400);
        BUF_strlcat((char *)local_428,__s,0x400);
        BUF_strlcat((char *)local_428,",",0x400);
        sVar3 = strlen((char *)local_428);
        sVar8 = sVar3 + iVar2 * 2;
        if ((int)sVar8 < 0x400) {
          if (0 < iVar2) {
            pbVar5 = (byte *)((int)&local_508 + 3);
            puVar4 = local_428 + sVar3;
            pbVar7 = pbVar5 + iVar2;
            do {
              pbVar5 = pbVar5 + 1;
              uVar1 = "0123456789ABCDEF"[*pbVar5 >> 4];
              puVar4[1] = "0123456789ABCDEF"[*pbVar5 & 0xf];
              *puVar4 = uVar1;
              puVar4 = puVar4 + 2;
              sVar3 = sVar8;
            } while (pbVar5 != pbVar7);
          }
          local_428[sVar3] = '\n';
          local_428[sVar3 + 1] = '\0';
        }
        EVP_CIPHER_CTX_init(&EStack_4b4);
        iVar2 = EVP_EncryptInit_ex(&EStack_4b4,enc,(ENGINE *)0x0,auStack_4f4,local_504);
        if (((iVar2 == 0) ||
            (iVar2 = EVP_EncryptUpdate(&EStack_4b4,out,&local_50c,out,local_510), iVar2 == 0)) ||
           (iVar2 = EVP_EncryptFinal_ex(&EStack_4b4,out + local_50c,&local_510), iVar2 == 0)) {
          uVar6 = 0;
          EVP_CIPHER_CTX_cleanup(&EStack_4b4);
          goto LAB_000be2f0;
        }
        EVP_CIPHER_CTX_cleanup(&EStack_4b4);
        local_510 = local_510 + local_50c;
        goto LAB_000be372;
      }
    }
    uVar6 = 0;
  }
LAB_000be2f0:
  OPENSSL_cleanse(auStack_4f4,0x40);
  OPENSSL_cleanse(local_504,0x10);
  OPENSSL_cleanse(&EStack_4b4,0x8c);
  OPENSSL_cleanse(local_428,0x400);
  OPENSSL_cleanse(out,len);
  CRYPTO_free(out);
  return uVar6;
}

