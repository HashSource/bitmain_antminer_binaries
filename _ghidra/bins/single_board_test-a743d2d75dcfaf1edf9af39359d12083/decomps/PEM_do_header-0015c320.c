
int PEM_do_header(EVP_CIPHER_INFO *cipher,uchar *data,long *len,undefined1 *callback,void *u)

{
  size_t __n;
  EVP_MD *md;
  int iVar1;
  char *prompt;
  EVP_CIPHER *type;
  long lVar2;
  int local_4fc;
  long local_4f8;
  uchar auStack_4f4 [64];
  EVP_CIPHER_CTX EStack_4b4;
  uchar auStack_428 [1028];
  
  lVar2 = *len;
  local_4fc = 0;
  if (cipher->cipher == (EVP_CIPHER *)0x0) {
    return 1;
  }
  if (callback == (undefined1 *)0x0) {
    if (u == (void *)0x0) {
      prompt = EVP_get_pw_prompt();
      if (prompt == (char *)0x0) {
        prompt = "Enter PEM pass phrase:";
      }
      while (iVar1 = EVP_read_pw_string_min((char *)auStack_428,4,0x400,prompt,0), iVar1 == 0) {
        __n = strlen((char *)auStack_428);
        if (3 < (int)__n) goto LAB_0015c356;
        fprintf(stderr,"phrase is too short, needs to be at least %d chars\n",4);
      }
      ERR_put_error(9,100,0x6d,"pem_lib.c",0x6e);
      memset(auStack_428,0,0x400);
      goto LAB_0015c44a;
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
LAB_0015c356:
  if (0 < (int)__n) {
    type = cipher->cipher;
    md = EVP_md5();
    iVar1 = EVP_BytesToKey(type,md,cipher->iv,auStack_428,__n,1,auStack_4f4,(uchar *)0x0);
    if (iVar1 == 0) {
      return 0;
    }
    local_4f8 = lVar2;
    EVP_CIPHER_CTX_init(&EStack_4b4);
    iVar1 = EVP_DecryptInit_ex(&EStack_4b4,cipher->cipher,(ENGINE *)0x0,auStack_4f4,cipher->iv);
    if ((iVar1 == 0) ||
       (iVar1 = EVP_DecryptUpdate(&EStack_4b4,data,&local_4fc,data,local_4f8), iVar1 == 0)) {
      EVP_CIPHER_CTX_cleanup(&EStack_4b4);
      OPENSSL_cleanse(auStack_428,0x400);
      OPENSSL_cleanse(auStack_4f4,0x40);
    }
    else {
      iVar1 = EVP_DecryptFinal_ex(&EStack_4b4,data + local_4fc,&local_4f8);
      EVP_CIPHER_CTX_cleanup(&EStack_4b4);
      OPENSSL_cleanse(auStack_428,0x400);
      OPENSSL_cleanse(auStack_4f4,0x40);
      if (iVar1 != 0) {
        *len = local_4f8 + local_4fc;
        return 1;
      }
    }
    ERR_put_error(9,0x6a,0x65,"pem_lib.c",0x1e2);
    return 0;
  }
LAB_0015c44a:
  ERR_put_error(9,0x6a,0x68,"pem_lib.c",0x1c9);
  return 0;
}

