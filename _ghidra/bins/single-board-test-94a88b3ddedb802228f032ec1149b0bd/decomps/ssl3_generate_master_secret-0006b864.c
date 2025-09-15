
int ssl3_generate_master_secret(int param_1,uchar *param_2,void *param_3,size_t param_4)

{
  size_t sVar1;
  int iVar2;
  uchar *md;
  size_t local_74;
  EVP_MD_CTX EStack_70;
  uchar auStack_58 [64];
  
  EVP_MD_CTX_init(&EStack_70);
  EVP_DigestInit_ex(&EStack_70,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),(ENGINE *)0x0);
  EVP_DigestUpdate(&EStack_70,"A",1);
  EVP_DigestUpdate(&EStack_70,param_3,param_4);
  EVP_DigestUpdate(&EStack_70,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
  EVP_DigestUpdate(&EStack_70,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
  EVP_DigestFinal_ex(&EStack_70,auStack_58,&local_74);
  EVP_DigestInit_ex(&EStack_70,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),(ENGINE *)0x0);
  EVP_DigestUpdate(&EStack_70,param_3,param_4);
  EVP_DigestUpdate(&EStack_70,auStack_58,local_74);
  EVP_DigestFinal_ex(&EStack_70,param_2,&local_74);
  sVar1 = local_74;
  EVP_DigestInit_ex(&EStack_70,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),(ENGINE *)0x0);
  EVP_DigestUpdate(&EStack_70,&DAT_00140cf8,2);
  EVP_DigestUpdate(&EStack_70,param_3,param_4);
  EVP_DigestUpdate(&EStack_70,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
  EVP_DigestUpdate(&EStack_70,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
  EVP_DigestFinal_ex(&EStack_70,auStack_58,&local_74);
  EVP_DigestInit_ex(&EStack_70,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),(ENGINE *)0x0);
  EVP_DigestUpdate(&EStack_70,param_3,param_4);
  EVP_DigestUpdate(&EStack_70,auStack_58,local_74);
  EVP_DigestFinal_ex(&EStack_70,param_2 + sVar1,&local_74);
  md = param_2 + sVar1 + local_74;
  iVar2 = sVar1 + local_74;
  EVP_DigestInit_ex(&EStack_70,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),(ENGINE *)0x0);
  EVP_DigestUpdate(&EStack_70,&DAT_0013cb90,3);
  EVP_DigestUpdate(&EStack_70,param_3,param_4);
  EVP_DigestUpdate(&EStack_70,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
  EVP_DigestUpdate(&EStack_70,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
  EVP_DigestFinal_ex(&EStack_70,auStack_58,&local_74);
  EVP_DigestInit_ex(&EStack_70,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),(ENGINE *)0x0);
  EVP_DigestUpdate(&EStack_70,param_3,param_4);
  EVP_DigestUpdate(&EStack_70,auStack_58,local_74);
  EVP_DigestFinal_ex(&EStack_70,md,&local_74);
  EVP_MD_CTX_cleanup(&EStack_70);
  OPENSSL_cleanse(auStack_58,0x40);
  return iVar2 + local_74;
}

