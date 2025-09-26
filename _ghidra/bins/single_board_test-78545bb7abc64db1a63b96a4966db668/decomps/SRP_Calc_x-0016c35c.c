
BIGNUM * SRP_Calc_x(BIGNUM *param_1,char *param_2,char *param_3)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  uchar *to;
  EVP_MD *pEVar2;
  size_t sVar3;
  int iVar4;
  BIGNUM *pBVar5;
  uchar auStack_34 [24];
  
  if ((param_1 == (BIGNUM *)0x0 || (param_3 == (char *)0x0 || param_2 == (char *)0x0)) ||
     (ctx = (EVP_MD_CTX *)EVP_MD_CTX_new(), ctx == (EVP_MD_CTX *)0x0)) {
    return (BIGNUM *)0x0;
  }
  iVar1 = BN_num_bits(param_1);
  iVar4 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar4 = iVar1 + 7;
  }
  to = (uchar *)CRYPTO_malloc(iVar4 >> 3,"crypto/srp/srp_lib.c",0x85);
  if (to != (uchar *)0x0) {
    pEVar2 = EVP_sha1();
    iVar4 = EVP_DigestInit_ex(ctx,pEVar2,(ENGINE *)0x0);
    if (iVar4 != 0) {
      sVar3 = strlen(param_2);
      iVar4 = EVP_DigestUpdate(ctx,param_2,sVar3);
      if ((iVar4 != 0) && (iVar4 = EVP_DigestUpdate(ctx,":",1), iVar4 != 0)) {
        sVar3 = strlen(param_3);
        iVar4 = EVP_DigestUpdate(ctx,param_3,sVar3);
        if (iVar4 != 0) {
          iVar4 = EVP_DigestFinal_ex(ctx,auStack_34,(uint *)0x0);
          if (iVar4 != 0) {
            pEVar2 = EVP_sha1();
            iVar4 = EVP_DigestInit_ex(ctx,pEVar2,(ENGINE *)0x0);
            if ((iVar4 != 0) && (iVar4 = BN_bn2bin(param_1,to), -1 < iVar4)) {
              iVar4 = BN_num_bits(param_1);
              iVar1 = iVar4 + 7;
              if (iVar1 < 0) {
                iVar1 = iVar4 + 0xe;
              }
              iVar4 = EVP_DigestUpdate(ctx,to,iVar1 >> 3);
              if (((iVar4 != 0) && (iVar4 = EVP_DigestUpdate(ctx,auStack_34,0x14), iVar4 != 0)) &&
                 (iVar4 = EVP_DigestFinal_ex(ctx,auStack_34,(uint *)0x0), iVar4 != 0)) {
                pBVar5 = BN_bin2bn(auStack_34,0x14,(BIGNUM *)0x0);
                goto LAB_0016c3c0;
              }
            }
          }
        }
      }
    }
  }
  pBVar5 = (BIGNUM *)0x0;
LAB_0016c3c0:
  CRYPTO_free(to);
  EVP_MD_CTX_free(ctx);
  return pBVar5;
}

