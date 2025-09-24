
/* WARNING: Type propagation algorithm not settling */

stack_st_CONF_VALUE *
i2v_AUTHORITY_INFO_ACCESS
          (X509V3_EXT_METHOD *param_1,undefined4 param_2,stack_st_CONF_VALUE *param_3)

{
  undefined4 *puVar1;
  stack_st_CONF_VALUE *psVar2;
  size_t sVar3;
  size_t sVar4;
  char *buf;
  int iVar5;
  stack_st_CONF_VALUE *psVar6;
  int iVar7;
  char acStack_78 [84];
  
  iVar7 = 0;
  psVar6 = param_3;
  while( true ) {
    iVar5 = OPENSSL_sk_num(param_2);
    if (iVar5 <= iVar7) {
      if (param_3 != (stack_st_CONF_VALUE *)0x0 || psVar6 != (stack_st_CONF_VALUE *)0x0) {
        return psVar6;
      }
      psVar6 = (stack_st_CONF_VALUE *)OPENSSL_sk_new_null(param_2);
      return psVar6;
    }
    puVar1 = (undefined4 *)OPENSSL_sk_value(param_2,iVar7);
    psVar2 = i2v_GENERAL_NAME(param_1,(GENERAL_NAME *)puVar1[1],psVar6);
    if (psVar2 == (stack_st_CONF_VALUE *)0x0) break;
    iVar5 = OPENSSL_sk_value(psVar2,iVar7);
    i2t_ASN1_OBJECT(acStack_78,0x50,(ASN1_OBJECT *)*puVar1);
    iVar7 = iVar7 + 1;
    sVar3 = strlen(acStack_78);
    sVar4 = strlen(*(char **)(iVar5 + 4));
    sVar3 = sVar4 + sVar3 + 4;
    buf = (char *)CRYPTO_malloc(sVar3,"crypto/x509v3/v3_info.c",0x52);
    psVar6 = psVar2;
    if (buf == (char *)0x0) break;
    BIO_snprintf(buf,sVar3,"%s - %s",acStack_78,*(undefined4 *)(iVar5 + 4));
    CRYPTO_free(*(void **)(iVar5 + 4));
    *(char **)(iVar5 + 4) = buf;
  }
  ERR_put_error(0x22,0x8a,0x41,"crypto/x509v3/v3_info.c",0x5e);
  if (psVar6 == (stack_st_CONF_VALUE *)0x0 || param_3 != (stack_st_CONF_VALUE *)0x0) {
    return (stack_st_CONF_VALUE *)0x0;
  }
  OPENSSL_sk_pop_free(psVar6,0x1794f9);
  return (stack_st_CONF_VALUE *)0x0;
}

