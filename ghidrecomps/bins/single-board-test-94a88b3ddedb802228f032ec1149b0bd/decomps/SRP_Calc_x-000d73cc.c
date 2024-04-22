
BIGNUM * SRP_Calc_x(BIGNUM *param_1,char *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  uchar *to;
  EVP_MD *pEVar3;
  size_t sVar4;
  BIGNUM *pBVar5;
  uchar auStack_44 [20];
  EVP_MD_CTX EStack_30;
  
  if ((param_1 != (BIGNUM *)0x0 && param_2 != (char *)0x0) && (param_3 != (char *)0x0)) {
    iVar1 = BN_num_bits(param_1);
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    to = (uchar *)CRYPTO_malloc(iVar2 >> 3,DAT_000d74b8,0xdc);
    if (to != (uchar *)0x0) {
      EVP_MD_CTX_init(&EStack_30);
      pEVar3 = EVP_sha1();
      EVP_DigestInit_ex(&EStack_30,pEVar3,(ENGINE *)0x0);
      sVar4 = strlen(param_2);
      EVP_DigestUpdate(&EStack_30,param_2,sVar4);
      EVP_DigestUpdate(&EStack_30,DAT_000d74bc,1);
      sVar4 = strlen(param_3);
      EVP_DigestUpdate(&EStack_30,param_3,sVar4);
      EVP_DigestFinal_ex(&EStack_30,auStack_44,(uint *)0x0);
      pEVar3 = EVP_sha1();
      EVP_DigestInit_ex(&EStack_30,pEVar3,(ENGINE *)0x0);
      BN_bn2bin(param_1,to);
      iVar1 = BN_num_bits(param_1);
      iVar2 = iVar1 + 0xe;
      if (-1 < iVar1 + 7) {
        iVar2 = iVar1 + 7;
      }
      EVP_DigestUpdate(&EStack_30,to,iVar2 >> 3);
      CRYPTO_free(to);
      EVP_DigestUpdate(&EStack_30,auStack_44,0x14);
      EVP_DigestFinal_ex(&EStack_30,auStack_44,(uint *)0x0);
      EVP_MD_CTX_cleanup(&EStack_30);
      pBVar5 = BN_bin2bn(auStack_44,0x14,(BIGNUM *)0x0);
      return pBVar5;
    }
  }
  return (BIGNUM *)0x0;
}

