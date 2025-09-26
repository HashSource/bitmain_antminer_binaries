
int PEM_do_header(EVP_CIPHER_INFO *cipher,uchar *data,long *len,undefined1 *callback,void *u)

{
  int iVar1;
  EVP_MD *md;
  EVP_CIPHER_CTX *ctx;
  EVP_CIPHER *type;
  long local_46c;
  uchar auStack_468 [64];
  uchar auStack_428 [1028];
  
  local_46c = *len;
  if (cipher->cipher == (EVP_CIPHER *)0x0) {
    return 1;
  }
  if (callback == (undefined1 *)0x0) {
    iVar1 = PEM_def_callback((char *)auStack_428,0x400,0,u);
  }
  else {
    iVar1 = (*(code *)callback)(auStack_428,0x400,0,u);
  }
  if (iVar1 < 0) {
    ERR_put_error(9,0x6a,0x68,"crypto/pem/pem_lib.c",0x1b2);
    return 0;
  }
  type = cipher->cipher;
  md = EVP_md5();
  iVar1 = EVP_BytesToKey(type,md,cipher->iv,auStack_428,iVar1,1,auStack_468,(uchar *)0x0);
  if ((iVar1 == 0) || (ctx = EVP_CIPHER_CTX_new(), ctx == (EVP_CIPHER_CTX *)0x0)) {
    return 0;
  }
  iVar1 = EVP_DecryptInit_ex(ctx,cipher->cipher,(ENGINE *)0x0,auStack_468,cipher->iv);
  if (iVar1 != 0) {
    iVar1 = EVP_DecryptUpdate(ctx,data,&local_46c,data,local_46c);
    if (iVar1 != 0) {
      *len = local_46c;
      iVar1 = EVP_DecryptFinal_ex(ctx,data + local_46c,&local_46c);
      if (iVar1 != 0) {
        *len = local_46c + *len;
        goto LAB_0014f1a0;
      }
    }
  }
  iVar1 = 0;
  ERR_put_error(9,0x6a,0x65,"crypto/pem/pem_lib.c",0x1cd);
LAB_0014f1a0:
  EVP_CIPHER_CTX_free(ctx);
  OPENSSL_cleanse(auStack_428,0x400);
  OPENSSL_cleanse(auStack_468,0x40);
  return iVar1;
}

