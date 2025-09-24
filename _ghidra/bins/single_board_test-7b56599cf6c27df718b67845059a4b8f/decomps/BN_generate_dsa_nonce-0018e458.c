
bool BN_generate_dsa_nonce
               (BIGNUM *param_1,BIGNUM *param_2,undefined4 param_3,void *param_4,size_t param_5,
               BN_CTX *param_6)

{
  int iVar1;
  uchar *s;
  int iVar2;
  BIGNUM *pBVar3;
  size_t __n;
  bool bVar4;
  uint num;
  uint local_1e4;
  undefined1 auStack_1e0 [64];
  uchar auStack_1a0 [64];
  undefined1 auStack_160 [96];
  SHA512_CTX SStack_100;
  
  iVar1 = BN_num_bits(param_2);
  iVar2 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar2 = iVar1 + 7;
  }
  num = (iVar2 >> 3) + 8;
  s = (uchar *)CRYPTO_malloc(num,"crypto/bn/bn_rand.c",0xdf);
  if (s != (uchar *)0x0) {
    iVar2 = BN_bn2binpad(param_3,auStack_160,0x60);
    if (iVar2 < 0) {
      ERR_put_error(3,0x8c,0x75,"crypto/bn/bn_rand.c",0xea);
    }
    else {
      local_1e4 = 0;
      if (num != 0) {
        do {
          iVar2 = RAND_priv_bytes(auStack_1e0,0x40);
          if (iVar2 != 1) goto LAB_0018e514;
          SHA512_Init(&SStack_100);
          SHA512_Update(&SStack_100,&local_1e4,4);
          SHA512_Update(&SStack_100,auStack_160,0x60);
          SHA512_Update(&SStack_100,param_4,param_5);
          SHA512_Update(&SStack_100,auStack_1e0,0x40);
          SHA512_Final(auStack_1a0,&SStack_100);
          __n = num - local_1e4;
          if (0x3f < __n) {
            __n = 0x40;
          }
          memcpy(s + local_1e4,auStack_1a0,__n);
          local_1e4 = local_1e4 + __n;
        } while (local_1e4 < num);
      }
      pBVar3 = BN_bin2bn(s,num,param_1);
      if (pBVar3 != (BIGNUM *)0x0) {
        iVar2 = BN_div((BIGNUM *)0x0,param_1,param_1,param_2,param_6);
        bVar4 = iVar2 == 1;
        goto LAB_0018e516;
      }
    }
  }
LAB_0018e514:
  bVar4 = false;
LAB_0018e516:
  CRYPTO_free(s);
  OPENSSL_cleanse(auStack_160,0x60);
  return bVar4;
}

