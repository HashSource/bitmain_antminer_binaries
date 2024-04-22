
BIGNUM * SRP_Calc_u(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  int iVar1;
  int iVar2;
  void *__s;
  EVP_MD *type;
  BIGNUM *a;
  size_t __n;
  uchar auStack_4c [20];
  EVP_MD_CTX EStack_38;
  
  if ((((param_1 != (BIGNUM *)0x0 && param_2 != (BIGNUM *)0x0) && (param_3 != (BIGNUM *)0x0)) &&
      (iVar1 = BN_ucmp(param_1,param_3), iVar1 < 0)) &&
     (iVar1 = BN_ucmp(param_2,param_3), iVar1 < 0)) {
    iVar2 = BN_num_bits(param_3);
    iVar1 = iVar2 + 0xe;
    if (-1 < iVar2 + 7) {
      iVar1 = iVar2 + 7;
    }
    __n = iVar1 >> 3;
    __s = CRYPTO_malloc(__n << 1,DAT_000d7264,0x84);
    if (__s != (void *)0x0) {
      memset(__s,0,__n);
      EVP_MD_CTX_init(&EStack_38);
      type = EVP_sha1();
      EVP_DigestInit_ex(&EStack_38,type,(ENGINE *)0x0);
      iVar1 = BN_bn2bin(param_1,(uchar *)((int)__s + __n));
      EVP_DigestUpdate(&EStack_38,(void *)((int)__s + iVar1),__n);
      iVar1 = BN_bn2bin(param_2,(uchar *)((int)__s + __n));
      EVP_DigestUpdate(&EStack_38,(void *)((int)__s + iVar1),__n);
      CRYPTO_free(__s);
      EVP_DigestFinal_ex(&EStack_38,auStack_4c,(uint *)0x0);
      EVP_MD_CTX_cleanup(&EStack_38);
      a = BN_bin2bn(auStack_4c,0x14,(BIGNUM *)0x0);
      if (a != (BIGNUM *)0x0) {
        if (a->top != 0) {
          return a;
        }
        BN_free(a);
        return (BIGNUM *)0x0;
      }
    }
  }
  return (BIGNUM *)0x0;
}

