
int PEM_do_header(EVP_CIPHER_INFO *cipher,uchar *data,long *len,undefined1 *callback,void *u)

{
  FILE **ppFVar1;
  size_t __n;
  EVP_MD *md;
  int iVar2;
  char *prompt;
  EVP_CIPHER *type;
  long lVar3;
  int local_4fc;
  long local_4f8;
  uchar auStack_4f4 [64];
  EVP_CIPHER_CTX EStack_4b4;
  uchar auStack_428 [1028];
  
  lVar3 = *len;
  local_4fc = 0;
  if (cipher->cipher == (EVP_CIPHER *)0x0) {
    return 1;
  }
  if (callback == (undefined1 *)0x0) {
    if (u == (void *)0x0) {
      prompt = EVP_get_pw_prompt();
      ppFVar1 = DAT_000bdca8;
      if (prompt == (char *)0x0) {
        prompt = DAT_000bdca4;
      }
      while (iVar2 = EVP_read_pw_string_min((char *)auStack_428,4,0x400,prompt,0), iVar2 == 0) {
        __n = strlen((char *)auStack_428);
        if (3 < (int)__n) goto LAB_000bdb16;
        fprintf(*ppFVar1,DAT_000bdca0,4);
      }
      ERR_put_error(9,100,0x6d,DAT_000bdc9c,0x6e);
      memset(auStack_428,0,0x400);
      goto LAB_000bdc0a;
    }
    __n = strlen((char *)u);
    if (0x3ff < (int)__n) {
      __n = 0x400;
    }
    memcpy(auStack_428,u,__n);
  }
  else {
    __n = (*(code *)callback)(auStack_428,0x400);
  }
LAB_000bdb16:
  if (0 < (int)__n) {
    type = cipher->cipher;
    md = EVP_md5();
    iVar2 = EVP_BytesToKey(type,md,cipher->iv,auStack_428,__n,1,auStack_4f4,(uchar *)0x0);
    if (iVar2 == 0) {
      return 0;
    }
    local_4f8 = lVar3;
    EVP_CIPHER_CTX_init(&EStack_4b4);
    iVar2 = EVP_DecryptInit_ex(&EStack_4b4,cipher->cipher,(ENGINE *)0x0,auStack_4f4,cipher->iv);
    if ((iVar2 == 0) ||
       (iVar2 = EVP_DecryptUpdate(&EStack_4b4,data,&local_4fc,data,local_4f8), iVar2 == 0)) {
      EVP_CIPHER_CTX_cleanup(&EStack_4b4);
      OPENSSL_cleanse(auStack_428,0x400);
      OPENSSL_cleanse(auStack_4f4,0x40);
    }
    else {
      iVar2 = EVP_DecryptFinal_ex(&EStack_4b4,data + local_4fc,&local_4f8);
      EVP_CIPHER_CTX_cleanup(&EStack_4b4);
      OPENSSL_cleanse(auStack_428,0x400);
      OPENSSL_cleanse(auStack_4f4,0x40);
      if (iVar2 != 0) {
        *len = local_4f8 + local_4fc;
        return 1;
      }
    }
    ERR_put_error(9,0x6a,0x65,DAT_000bdc9c,0x1e2);
    return 0;
  }
LAB_000bdc0a:
  ERR_put_error(9,0x6a,0x68,DAT_000bdc9c,0x1c9);
  return 0;
}

