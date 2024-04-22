
char ** SRP_VBASE_get_by_user(_STACK **param_1,char *param_2)

{
  int iVar1;
  char **ppcVar2;
  char *pcVar3;
  int iVar4;
  EVP_MD *type;
  size_t sVar5;
  BIGNUM *a;
  BIGNUM *pBVar6;
  _STACK *p_Var7;
  _STACK *p_Var8;
  uchar auStack_58 [20];
  uchar auStack_44 [20];
  EVP_MD_CTX EStack_30;
  
  if (param_1 == (_STACK **)0x0) {
LAB_000d8146:
    ppcVar2 = (char **)0x0;
  }
  else {
    iVar4 = 0;
    do {
      iVar1 = sk_num(*param_1);
      if (iVar1 <= iVar4) {
        if ((((param_1[2] != (_STACK *)0x0) && (param_1[3] != (_STACK *)0x0)) &&
            (param_1[4] != (_STACK *)0x0)) &&
           (ppcVar2 = (char **)CRYPTO_malloc(0x18,DAT_000d814c,0xc9), ppcVar2 != (char **)0x0)) {
          p_Var7 = param_1[3];
          p_Var8 = param_1[4];
          ppcVar2[1] = (char *)0x0;
          ppcVar2[3] = (char *)p_Var7;
          ppcVar2[4] = (char *)p_Var8;
          ppcVar2[2] = (char *)0x0;
          *ppcVar2 = (char *)0x0;
          ppcVar2[5] = (char *)0x0;
          if (param_2 == (char *)0x0) {
LAB_000d80ac:
            iVar4 = RAND_pseudo_bytes(auStack_58,0x14);
            if (-1 < iVar4) {
              EVP_MD_CTX_init(&EStack_30);
              type = EVP_sha1();
              EVP_DigestInit_ex(&EStack_30,type,(ENGINE *)0x0);
              p_Var7 = param_1[2];
              sVar5 = strlen((char *)p_Var7);
              EVP_DigestUpdate(&EStack_30,p_Var7,sVar5);
              sVar5 = strlen(param_2);
              EVP_DigestUpdate(&EStack_30,param_2,sVar5);
              EVP_DigestFinal_ex(&EStack_30,auStack_44,(uint *)0x0);
              EVP_MD_CTX_cleanup(&EStack_30);
              a = BN_bin2bn(auStack_44,0x14,(BIGNUM *)0x0);
              pBVar6 = BN_bin2bn(auStack_58,0x14,(BIGNUM *)0x0);
              ppcVar2[1] = (char *)a;
              ppcVar2[2] = (char *)pBVar6;
              if ((a != (BIGNUM *)0x0) && (pBVar6 != (BIGNUM *)0x0)) {
                return ppcVar2;
              }
              goto LAB_000d8124;
            }
          }
          else {
            pcVar3 = BUF_strdup(param_2);
            *ppcVar2 = pcVar3;
            if (pcVar3 != (char *)0x0) goto LAB_000d80ac;
          }
          a = (BIGNUM *)ppcVar2[1];
LAB_000d8124:
          BN_free(a);
          BN_clear_free((BIGNUM *)ppcVar2[2]);
          CRYPTO_free(*ppcVar2);
          CRYPTO_free(ppcVar2[5]);
          CRYPTO_free(ppcVar2);
          return (char **)0x0;
        }
        goto LAB_000d8146;
      }
      ppcVar2 = (char **)sk_value(*param_1,iVar4);
      iVar1 = strcmp(*ppcVar2,param_2);
      iVar4 = iVar4 + 1;
    } while (iVar1 != 0);
  }
  return ppcVar2;
}

