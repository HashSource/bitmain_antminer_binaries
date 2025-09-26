
undefined4 * SRP_VBASE_get1_by_user(undefined4 *param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  EVP_MD_CTX *ctx;
  EVP_MD *type;
  size_t sVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char *str;
  uchar auStack_40 [20];
  uchar auStack_2c [20];
  
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar4 = 0;
  do {
    iVar1 = OPENSSL_sk_num(*param_1);
    if (iVar1 <= iVar4) {
      if (param_1[2] == 0) {
        return (undefined4 *)0x0;
      }
      if (param_1[3] == 0) {
        return (undefined4 *)0x0;
      }
      if (param_1[4] == 0) {
        return (undefined4 *)0x0;
      }
      puVar2 = (undefined4 *)CRYPTO_malloc(0x18,"crypto/srp/srp_vfy.c",0xbf);
      if (puVar2 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      uVar9 = param_1[3];
      uVar10 = param_1[4];
      puVar2[1] = 0;
      puVar2[3] = uVar9;
      puVar2[4] = uVar10;
      puVar2[2] = 0;
      *puVar2 = 0;
      puVar2[5] = 0;
      if (param_2 == (char *)0x0) {
LAB_0016cf52:
        iVar4 = RAND_priv_bytes(auStack_40,0x14);
        if ((0 < iVar4) && (ctx = (EVP_MD_CTX *)EVP_MD_CTX_new(), ctx != (EVP_MD_CTX *)0x0)) {
          type = EVP_sha1();
          iVar4 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
          if (iVar4 == 0) goto LAB_0016d05a;
          pcVar3 = (char *)param_1[2];
          sVar5 = strlen(pcVar3);
          iVar4 = EVP_DigestUpdate(ctx,pcVar3,sVar5);
          if (iVar4 == 0) goto LAB_0016d05a;
          sVar5 = strlen(param_2);
          iVar4 = EVP_DigestUpdate(ctx,param_2,sVar5);
          if (iVar4 == 0) goto LAB_0016d05a;
          iVar4 = EVP_DigestFinal_ex(ctx,auStack_2c,(uint *)0x0);
          if (iVar4 == 0) goto LAB_0016d05a;
          EVP_MD_CTX_free(ctx);
          pBVar6 = BN_bin2bn(auStack_2c,0x14,(BIGNUM *)0x0);
          pBVar7 = BN_bin2bn(auStack_40,0x14,(BIGNUM *)0x0);
          puVar2[1] = pBVar6;
          puVar2[2] = pBVar7;
          if (pBVar7 != (BIGNUM *)0x0 && pBVar6 != (BIGNUM *)0x0) {
            return puVar2;
          }
        }
      }
      else {
        pcVar3 = CRYPTO_strdup(param_2,"crypto/srp/srp_vfy.c",0xd6);
        *puVar2 = pcVar3;
        if (pcVar3 != (char *)0x0) goto LAB_0016cf52;
      }
      ctx = (EVP_MD_CTX *)0x0;
LAB_0016d05a:
      EVP_MD_CTX_free(ctx);
      SRP_user_pwd_free(puVar2);
      return (undefined4 *)0x0;
    }
    puVar2 = (undefined4 *)OPENSSL_sk_value(*param_1,iVar4);
    iVar1 = strcmp((char *)*puVar2,param_2);
    iVar4 = iVar4 + 1;
  } while (iVar1 != 0);
  puVar8 = (undefined4 *)CRYPTO_malloc(0x18,"crypto/srp/srp_vfy.c",0xbf);
  if (puVar8 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar8[4] = 0;
  puVar8[3] = 0;
  uVar9 = puVar2[4];
  uVar10 = puVar2[3];
  *puVar8 = 0;
  puVar8[4] = uVar9;
  puVar8[3] = uVar10;
  pcVar3 = (char *)*puVar2;
  puVar8[5] = 0;
  puVar8[1] = 0;
  puVar8[2] = 0;
  str = (char *)puVar2[5];
  if (pcVar3 != (char *)0x0) {
    pcVar3 = CRYPTO_strdup(pcVar3,"crypto/srp/srp_vfy.c",0xd6);
    *puVar8 = pcVar3;
    if (pcVar3 == (char *)0x0) goto LAB_0016d04a;
  }
  if (str != (char *)0x0) {
    pcVar3 = CRYPTO_strdup(str,"crypto/srp/srp_vfy.c",0xd8);
    puVar8[5] = pcVar3;
    if (pcVar3 == (char *)0x0) goto LAB_0016d04a;
  }
  pBVar6 = BN_dup((BIGNUM *)puVar2[1]);
  pBVar7 = BN_dup((BIGNUM *)puVar2[2]);
  puVar8[1] = pBVar6;
  puVar8[2] = pBVar7;
  if (pBVar6 != (BIGNUM *)0x0 && pBVar7 != (BIGNUM *)0x0) {
    return puVar8;
  }
LAB_0016d04a:
  SRP_user_pwd_free(puVar8);
  return (undefined4 *)0x0;
}

