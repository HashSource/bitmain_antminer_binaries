
undefined4
cms_kek_cipher(uchar **param_1,int *param_2,uchar *param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  uchar *out;
  undefined4 uVar2;
  EVP_CIPHER_CTX *ctx;
  uint local_70;
  int local_6c;
  uchar auStack_68 [68];
  
  ctx = (EVP_CIPHER_CTX *)(param_5 + 0x18);
  local_70 = EVP_CIPHER_CTX_key_length(ctx);
  if (0x40 < local_70) {
    return 0;
  }
  iVar1 = EVP_PKEY_derive(*(EVP_PKEY_CTX **)(param_5 + 0x14),auStack_68,&local_70);
  if ((((iVar1 < 1) ||
       (iVar1 = EVP_CipherInit_ex(ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_68,(uchar *)0x0,
                                  param_6), iVar1 == 0)) ||
      (iVar1 = EVP_CipherUpdate(ctx,(uchar *)0x0,&local_6c,param_3,param_4), iVar1 == 0)) ||
     (out = (uchar *)CRYPTO_malloc(local_6c,DAT_000d6aa0,0x105), out == (uchar *)0x0)) {
    uVar2 = 0;
  }
  else {
    iVar1 = EVP_CipherUpdate(ctx,out,&local_6c,param_3,param_4);
    if (iVar1 == 0) {
      OPENSSL_cleanse(auStack_68,local_70);
      CRYPTO_free(out);
      uVar2 = 0;
      goto LAB_000d6a36;
    }
    uVar2 = 1;
    *param_1 = out;
    *param_2 = local_6c;
  }
  OPENSSL_cleanse(auStack_68,local_70);
LAB_000d6a36:
  EVP_CIPHER_CTX_cleanup(ctx);
  EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(param_5 + 0x14));
  *(undefined4 *)(param_5 + 0x14) = 0;
  return uVar2;
}

