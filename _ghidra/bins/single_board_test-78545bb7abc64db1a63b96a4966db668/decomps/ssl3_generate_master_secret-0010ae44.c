
undefined4
ssl3_generate_master_secret(int param_1,uchar *param_2,void *param_3,size_t param_4,int *param_5)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  size_t cnt;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *__s;
  size_t local_6c;
  uchar auStack_68 [68];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx == (EVP_MD_CTX *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x184,0x41,"ssl/s3_enc.c",0x1e9);
    uVar2 = 0;
  }
  else {
    iVar4 = 0;
    iVar3 = 0;
    do {
      iVar1 = EVP_DigestInit_ex(ctx,*(EVP_MD **)(*(int *)(param_1 + 0x4d0) + 0x94),(ENGINE *)0x0);
      if (iVar1 < 1) {
LAB_0010af42:
        ossl_statem_fatal(param_1,0x50,0x184,0x44,"ssl/s3_enc.c",0x1fc);
        EVP_MD_CTX_free(ctx);
        OPENSSL_cleanse(auStack_68,0x40);
        return 0;
      }
      __s = (char *)(&salt_25519)[iVar3];
      cnt = strlen(__s);
      iVar1 = EVP_DigestUpdate(ctx,__s,cnt);
      if ((((iVar1 < 1) || (iVar1 = EVP_DigestUpdate(ctx,param_3,param_4), iVar1 < 1)) ||
          (iVar1 = EVP_DigestUpdate(ctx,(void *)(*(int *)(param_1 + 0x7c) + 0xac),0x20), iVar1 < 1))
         || (iVar1 = EVP_DigestUpdate(ctx,(void *)(*(int *)(param_1 + 0x7c) + 0x8c),0x20), iVar1 < 1
            )) goto LAB_0010af42;
      iVar1 = EVP_DigestFinal_ex(ctx,auStack_68,&local_6c);
      if (((iVar1 < 1) ||
          (iVar1 = EVP_DigestInit_ex(ctx,*(EVP_MD **)(*(int *)(param_1 + 0x4d0) + 0x90),
                                     (ENGINE *)0x0), iVar1 < 1)) ||
         ((iVar1 = EVP_DigestUpdate(ctx,param_3,param_4), iVar1 < 1 ||
          ((iVar1 = EVP_DigestUpdate(ctx,auStack_68,local_6c), iVar1 < 1 ||
           (iVar1 = EVP_DigestFinal_ex(ctx,param_2,&local_6c), iVar1 < 1)))))) goto LAB_0010af42;
      iVar3 = iVar3 + 1;
      param_2 = param_2 + local_6c;
      iVar4 = iVar4 + local_6c;
    } while (iVar3 != 3);
    EVP_MD_CTX_free(ctx);
    OPENSSL_cleanse(auStack_68,0x40);
    uVar2 = 1;
    *param_5 = iVar4;
  }
  return uVar2;
}

