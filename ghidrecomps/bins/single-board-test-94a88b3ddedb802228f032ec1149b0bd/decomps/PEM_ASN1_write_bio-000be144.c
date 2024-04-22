
int PEM_ASN1_write_bio(undefined1 *i2d,char *name,BIO *bp,void *x,EVP_CIPHER *enc,uchar *kstr,
                      int klen,undefined1 *cb,void *u)

{
  uchar uVar1;
  FILE **ppFVar2;
  int iVar3;
  char *__s;
  size_t len;
  uchar *out;
  EVP_MD *md;
  size_t sVar4;
  uchar *puVar5;
  char *prompt;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  size_t sVar9;
  undefined4 in_stack_fffffad8;
  undefined4 in_stack_fffffadc;
  long local_510;
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
    iVar3 = EVP_CIPHER_nid(enc);
    __s = OBJ_nid2sn(iVar3);
    if (__s == (char *)0x0) {
      ERR_put_error(9,0x69,0x71,DAT_000be448,0x160);
      goto LAB_000be33e;
    }
  }
  len = (*(code *)i2d)(x,0);
  if ((int)len < 0) {
    ERR_put_error(9,0x69,0xd,DAT_000be448,0x166);
LAB_000be33e:
    OPENSSL_cleanse(auStack_4f4,0x40);
    OPENSSL_cleanse(local_504,0x10);
    OPENSSL_cleanse(&EStack_4b4,0x8c);
    OPENSSL_cleanse(local_428,0x400);
    return 0;
  }
  out = (uchar *)CRYPTO_malloc(len + 0x14,DAT_000be448,0x16c);
  if (out == (uchar *)0x0) {
    ERR_put_error(9,0x69,0x41,DAT_000be448,0x16e);
    goto LAB_000be33e;
  }
  local_508 = out;
  local_510 = (*(code *)i2d)(x,&local_508);
  if (enc == (EVP_CIPHER *)0x0) {
    local_428[0] = '\0';
LAB_000be372:
    local_510 = PEM_write_bio(bp,name,(char *)local_428,out,local_510);
    uVar7 = (uint)(0 < local_510);
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
        ppFVar2 = DAT_000be53c;
        if (prompt == (char *)0x0) {
          prompt = DAT_000be538;
        }
        while( true ) {
          in_stack_fffffad8 = 1;
          iVar3 = EVP_read_pw_string_min((char *)local_428,4,0x400,prompt,1);
          if (iVar3 != 0) break;
          klen = strlen((char *)local_428);
          if (3 < klen) goto LAB_000be3aa;
          fprintf(*ppFVar2,DAT_000be530,4);
        }
        ERR_put_error(9,100,0x6d,DAT_000be534,0x6e);
        memset(local_428,0,0x400);
      }
      else {
        klen = (*(code *)cb)(local_428,0x400,1,u);
LAB_000be3aa:
        kstr = local_428;
        if (0 < klen) goto LAB_000be1b0;
      }
      ERR_put_error(9,0x69,0x6f,DAT_000be534,0x17b);
      uVar7 = 0;
      goto LAB_000be2f0;
    }
LAB_000be1b0:
    RAND_add(out,local_510,(double)CONCAT44(in_stack_fffffadc,in_stack_fffffad8));
    iVar3 = enc->iv_len;
    if (0x10 < iVar3) {
      OpenSSLDie(DAT_000be448,0x185,DAT_000be464);
      iVar3 = enc->iv_len;
    }
    iVar3 = RAND_pseudo_bytes(local_504,iVar3);
    if (-1 < iVar3) {
      md = EVP_md5();
      iVar3 = EVP_BytesToKey(enc,md,local_504,kstr,klen,1,auStack_4f4,(uchar *)0x0);
      if (iVar3 != 0) {
        if (kstr == local_428) {
          OPENSSL_cleanse(local_428,0x400);
        }
        sVar4 = strlen(__s);
        if (0x400 < sVar4 + enc->iv_len * 2 + 0x24) {
          OpenSSLDie(DAT_000be448,0x193,DAT_000be468);
        }
        local_428[0] = '\0';
        BUF_strlcat((char *)local_428,DAT_000be44c,0x400);
        BUF_strlcat((char *)local_428,DAT_000be450,0x400);
        BUF_strlcat((char *)local_428,DAT_000be454,0x400);
        iVar3 = enc->iv_len;
        BUF_strlcat((char *)local_428,DAT_000be458,0x400);
        BUF_strlcat((char *)local_428,__s,0x400);
        BUF_strlcat((char *)local_428,DAT_000be45c,0x400);
        sVar4 = strlen((char *)local_428);
        sVar9 = sVar4 + iVar3 * 2;
        if ((int)sVar9 < 0x400) {
          if (0 < iVar3) {
            pbVar6 = (byte *)((int)&local_508 + 3);
            puVar5 = local_428 + sVar4;
            pbVar8 = pbVar6 + iVar3;
            do {
              pbVar6 = pbVar6 + 1;
              uVar1 = *(uchar *)(DAT_000be460 + (uint)(*pbVar6 >> 4));
              puVar5[1] = *(uchar *)(DAT_000be460 + (*pbVar6 & 0xf));
              *puVar5 = uVar1;
              puVar5 = puVar5 + 2;
              sVar4 = sVar9;
            } while (pbVar6 != pbVar8);
          }
          local_428[sVar4] = '\n';
          local_428[sVar4 + 1] = '\0';
        }
        EVP_CIPHER_CTX_init(&EStack_4b4);
        iVar3 = EVP_EncryptInit_ex(&EStack_4b4,enc,(ENGINE *)0x0,auStack_4f4,local_504);
        if (((iVar3 == 0) ||
            (iVar3 = EVP_EncryptUpdate(&EStack_4b4,out,&local_50c,out,local_510), iVar3 == 0)) ||
           (iVar3 = EVP_EncryptFinal_ex(&EStack_4b4,out + local_50c,&local_510), iVar3 == 0)) {
          uVar7 = 0;
          EVP_CIPHER_CTX_cleanup(&EStack_4b4);
          goto LAB_000be2f0;
        }
        EVP_CIPHER_CTX_cleanup(&EStack_4b4);
        local_510 = local_510 + local_50c;
        goto LAB_000be372;
      }
    }
    uVar7 = 0;
  }
LAB_000be2f0:
  OPENSSL_cleanse(auStack_4f4,0x40);
  OPENSSL_cleanse(local_504,0x10);
  OPENSSL_cleanse(&EStack_4b4,0x8c);
  OPENSSL_cleanse(local_428,0x400);
  OPENSSL_cleanse(out,len);
  CRYPTO_free(out);
  return uVar7;
}

