
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int PEM_ASN1_write_bio(undefined1 *i2d,char *name,BIO *bp,void *x,EVP_CIPHER *enc,uchar *kstr,
                      int klen,undefined1 *cb,void *u)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  EVP_MD *md;
  int iVar3;
  uint uVar4;
  uchar *out;
  EVP_CIPHER_CTX *ctx;
  int line;
  uchar *local_498;
  int local_484;
  int local_480;
  uchar *local_47c;
  uchar auStack_478 [16];
  uchar auStack_468 [64];
  uchar local_428 [1028];
  
  local_484 = 0;
  local_480 = 0;
  if (enc == (EVP_CIPHER *)0x0) {
    __s = (char *)0x0;
LAB_0014f80e:
    iVar1 = (*(code *)i2d)(x,0);
    if (0 < iVar1) {
      out = (uchar *)CRYPTO_malloc(iVar1 + 0x14,"crypto/pem/pem_lib.c",0x156);
      if (out == (uchar *)0x0) {
        ERR_put_error(9,0x69,0x41,"crypto/pem/pem_lib.c",0x158);
        uVar4 = 0;
        ctx = (EVP_CIPHER_CTX *)0x0;
        goto LAB_0014f7b0;
      }
      local_47c = out;
      local_484 = (*(code *)i2d)(x,&local_47c);
      if (enc == (EVP_CIPHER *)0x0) {
        local_428[0] = '\0';
        ctx = (EVP_CIPHER_CTX *)0x0;
      }
      else {
        if (kstr == (uchar *)0x0) {
          if (cb == (undefined1 *)0x0) {
            klen = PEM_def_callback((char *)local_428,0x400,1,u);
          }
          else {
            klen = (*(code *)cb)(local_428,0x400,1,u);
          }
          local_498 = local_428;
          if (klen < 1) {
            uVar4 = 0;
            ERR_put_error(9,0x69,0x6f,"crypto/pem/pem_lib.c",0x165);
            ctx = (EVP_CIPHER_CTX *)0x0;
            goto LAB_0014f7b0;
          }
          kstr = local_498;
        }
        local_498 = local_428;
        iVar3 = EVP_CIPHER_iv_length(enc);
        iVar3 = RAND_bytes(auStack_478,iVar3);
        if (iVar3 < 1) {
          uVar4 = 0;
          ctx = (EVP_CIPHER_CTX *)0x0;
          goto LAB_0014f7b0;
        }
        md = EVP_md5();
        iVar3 = EVP_BytesToKey(enc,md,auStack_478,kstr,klen,1,auStack_468,(uchar *)0x0);
        if (iVar3 == 0) {
          uVar4 = 0;
          ctx = (EVP_CIPHER_CTX *)0x0;
          goto LAB_0014f7b0;
        }
        if (kstr == local_498) {
          OPENSSL_cleanse(local_498,0x400);
        }
        local_428[0] = '\0';
        PEM_proc_type((char *)local_498,10);
        iVar3 = EVP_CIPHER_iv_length(enc);
        PEM_dek_info((char *)local_498,__s,iVar3,(char *)auStack_478);
        ctx = EVP_CIPHER_CTX_new();
        if (((ctx == (EVP_CIPHER_CTX *)0x0) ||
            (iVar3 = EVP_EncryptInit_ex(ctx,enc,(ENGINE *)0x0,auStack_468,auStack_478), iVar3 == 0))
           || ((iVar3 = EVP_EncryptUpdate(ctx,out,&local_480,out,local_484), iVar3 == 0 ||
               (iVar3 = EVP_EncryptFinal_ex(ctx,out + local_480,&local_484), iVar3 == 0)))) {
          uVar4 = 0;
          goto LAB_0014f7b0;
        }
        local_484 = local_480 + local_484;
      }
      local_484 = PEM_write_bio(bp,name,(char *)local_428,out,local_484);
      uVar4 = (uint)(0 < local_484);
      goto LAB_0014f7b0;
    }
    line = 0x150;
    iVar3 = 0xd;
  }
  else {
    iVar1 = EVP_CIPHER_nid(enc);
    __s = OBJ_nid2sn(iVar1);
    if (((__s != (char *)0x0) && (iVar1 = EVP_CIPHER_iv_length(enc), iVar1 != 0)) &&
       (iVar1 = EVP_CIPHER_iv_length(enc), iVar1 < 0x11)) {
      sVar2 = strlen(__s);
      iVar1 = EVP_CIPHER_iv_length(enc);
      if (sVar2 + 0x24 + iVar1 * 2 < 0x401) goto LAB_0014f80e;
    }
    line = 0x14a;
    iVar3 = 0x71;
  }
  iVar1 = 0;
  out = (uchar *)0x0;
  uVar4 = 0;
  ctx = (EVP_CIPHER_CTX *)0x0;
  ERR_put_error(9,0x69,iVar3,"crypto/pem/pem_lib.c",line);
LAB_0014f7b0:
  local_498 = local_428;
  OPENSSL_cleanse(auStack_468,0x40);
  OPENSSL_cleanse(auStack_478,0x10);
  EVP_CIPHER_CTX_free(ctx);
  OPENSSL_cleanse(local_498,0x400);
  CRYPTO_clear_free(out,iVar1,"crypto/pem/pem_lib.c",0x194);
  return uVar4;
}

