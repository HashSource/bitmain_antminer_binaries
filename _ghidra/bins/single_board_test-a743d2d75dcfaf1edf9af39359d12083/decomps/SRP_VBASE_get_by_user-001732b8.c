
undefined4 * SRP_VBASE_get_by_user(undefined4 *param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  EVP_MD *type;
  size_t sVar5;
  BIGNUM *a;
  BIGNUM *pBVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uchar auStack_58 [20];
  uchar auStack_44 [20];
  EVP_MD_CTX EStack_30;
  
  if (param_1 == (undefined4 *)0x0) {
LAB_001733ca:
    puVar2 = (undefined4 *)0x0;
  }
  else {
    iVar4 = 0;
    do {
      iVar1 = sk_num((_STACK *)*param_1);
      if (iVar1 <= iVar4) {
        if ((((param_1[2] != 0) && (param_1[3] != 0)) && (param_1[4] != 0)) &&
           (puVar2 = (undefined4 *)CRYPTO_malloc(0x18,"srp_vfy.c",0xc9), puVar2 != (undefined4 *)0x0
           )) {
          uVar7 = param_1[3];
          uVar8 = param_1[4];
          puVar2[1] = 0;
          puVar2[3] = uVar7;
          puVar2[4] = uVar8;
          puVar2[2] = 0;
          *puVar2 = 0;
          puVar2[5] = 0;
          if (param_2 == (char *)0x0) {
LAB_00173330:
            iVar4 = RAND_pseudo_bytes(auStack_58,0x14);
            if (-1 < iVar4) {
              EVP_MD_CTX_init(&EStack_30);
              type = EVP_sha1();
              EVP_DigestInit_ex(&EStack_30,type,(ENGINE *)0x0);
              pcVar3 = (char *)param_1[2];
              sVar5 = strlen(pcVar3);
              EVP_DigestUpdate(&EStack_30,pcVar3,sVar5);
              sVar5 = strlen(param_2);
              EVP_DigestUpdate(&EStack_30,param_2,sVar5);
              EVP_DigestFinal_ex(&EStack_30,auStack_44,(uint *)0x0);
              EVP_MD_CTX_cleanup(&EStack_30);
              a = BN_bin2bn(auStack_44,0x14,(BIGNUM *)0x0);
              pBVar6 = BN_bin2bn(auStack_58,0x14,(BIGNUM *)0x0);
              puVar2[1] = a;
              puVar2[2] = pBVar6;
              if ((a != (BIGNUM *)0x0) && (pBVar6 != (BIGNUM *)0x0)) {
                return puVar2;
              }
              goto LAB_001733a8;
            }
          }
          else {
            pcVar3 = BUF_strdup(param_2);
            *puVar2 = pcVar3;
            if (pcVar3 != (char *)0x0) goto LAB_00173330;
          }
          a = (BIGNUM *)puVar2[1];
LAB_001733a8:
          BN_free(a);
          BN_clear_free((BIGNUM *)puVar2[2]);
          CRYPTO_free((void *)*puVar2);
          CRYPTO_free((void *)puVar2[5]);
          CRYPTO_free(puVar2);
          return (undefined4 *)0x0;
        }
        goto LAB_001733ca;
      }
      puVar2 = (undefined4 *)sk_value((_STACK *)*param_1,iVar4);
      iVar1 = strcmp((char *)*puVar2,param_2);
      iVar4 = iVar4 + 1;
    } while (iVar1 != 0);
  }
  return puVar2;
}

