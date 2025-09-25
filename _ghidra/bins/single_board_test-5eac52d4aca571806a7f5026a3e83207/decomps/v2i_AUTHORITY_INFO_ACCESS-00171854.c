
int v2i_AUTHORITY_INFO_ACCESS(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  GENERAL_NAME *pGVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  ACCESS_DESCRIPTION *pAVar7;
  char *__s;
  int iVar8;
  CONF_VALUE CStack_34;
  
  iVar1 = OPENSSL_sk_num(param_3);
  iVar2 = OPENSSL_sk_new_reserve(0,iVar1);
  if (iVar2 == 0) {
    ERR_put_error(0x22,0x8b,0x41,"crypto/x509v3/v3_info.c",0x72);
  }
  else if (0 < iVar1) {
    iVar8 = 0;
    do {
      iVar6 = OPENSSL_sk_value(param_3,iVar8);
      iVar8 = iVar8 + 1;
      pAVar7 = ACCESS_DESCRIPTION_new();
      if (pAVar7 == (ACCESS_DESCRIPTION *)0x0) {
        iVar1 = 0x79;
LAB_00171912:
        ERR_put_error(0x22,0x8b,0x41,"crypto/x509v3/v3_info.c",iVar1);
LAB_0017191e:
        OPENSSL_sk_pop_free(iVar2,0x1717fd);
        return 0;
      }
      OPENSSL_sk_push(iVar2,pAVar7);
      __s = *(char **)(iVar6 + 4);
      pcVar3 = strchr(__s,0x3b);
      if (pcVar3 == (char *)0x0) {
        ERR_put_error(0x22,0x8b,0x8f,"crypto/x509v3/v3_info.c",0x80);
        goto LAB_0017191e;
      }
      CStack_34.name = pcVar3 + 1;
      CStack_34.value = *(char **)(iVar6 + 8);
      pGVar4 = v2i_GENERAL_NAME_ex(pAVar7->location,param_1,param_2,&CStack_34,0);
      if (pGVar4 == (GENERAL_NAME *)0x0) goto LAB_0017191e;
      pcVar3 = (char *)CRYPTO_strndup(*(undefined4 *)(iVar6 + 4),(int)pcVar3 - (int)__s,
                                      "crypto/x509v3/v3_info.c",0x88);
      if (pcVar3 == (char *)0x0) {
        iVar1 = 0x8a;
        goto LAB_00171912;
      }
      pAVar5 = OBJ_txt2obj(pcVar3,0);
      pAVar7->method = pAVar5;
      if (pAVar5 == (ASN1_OBJECT *)0x0) {
        ERR_put_error(0x22,0x8b,0x77,"crypto/x509v3/v3_info.c",0x90);
        ERR_add_error_data(2,"value=",pcVar3);
        CRYPTO_free(pcVar3);
        goto LAB_0017191e;
      }
      CRYPTO_free(pcVar3);
    } while (iVar1 != iVar8);
  }
  return iVar2;
}

