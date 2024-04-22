
BIGNUM * srp_Calc_k(BIGNUM *param_1,BIGNUM *param_2)

{
  int iVar1;
  int iVar2;
  uchar *to;
  EVP_MD *type;
  size_t cnt;
  BIGNUM *pBVar3;
  size_t cnt_00;
  uchar auStack_44 [20];
  EVP_MD_CTX EStack_30;
  
  iVar1 = BN_num_bits(param_1);
  iVar2 = BN_ucmp(param_2,param_1);
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    cnt_00 = iVar2 >> 3;
    to = (uchar *)CRYPTO_malloc(cnt_00,DAT_000d718c,0x5f);
    if (to != (uchar *)0x0) {
      BN_bn2bin(param_1,to);
      EVP_MD_CTX_init(&EStack_30);
      type = EVP_sha1();
      EVP_DigestInit_ex(&EStack_30,type,(ENGINE *)0x0);
      EVP_DigestUpdate(&EStack_30,to,cnt_00);
      memset(to,0,cnt_00);
      cnt = BN_bn2bin(param_2,to);
      EVP_DigestUpdate(&EStack_30,to + cnt,cnt_00 - cnt);
      EVP_DigestUpdate(&EStack_30,to,cnt);
      CRYPTO_free(to);
      EVP_DigestFinal_ex(&EStack_30,auStack_44,(uint *)0x0);
      EVP_MD_CTX_cleanup(&EStack_30);
      pBVar3 = BN_bin2bn(auStack_44,0x14,(BIGNUM *)0x0);
      return pBVar3;
    }
  }
  return (BIGNUM *)0x0;
}

