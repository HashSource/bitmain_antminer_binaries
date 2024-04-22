
_STACK * i2v_AUTHORITY_INFO_ACCESS(X509V3_EXT_METHOD *param_1,_STACK *param_2,_STACK *param_3)

{
  ASN1_OBJECT **ppAVar1;
  void *pvVar2;
  size_t sVar3;
  size_t sVar4;
  char *dst;
  int iVar5;
  int iVar6;
  char acStack_70 [80];
  
  iVar6 = 0;
  while (iVar5 = sk_num(param_2), iVar6 < iVar5) {
    ppAVar1 = (ASN1_OBJECT **)sk_value(param_2,iVar6);
    param_3 = &i2v_GENERAL_NAME(param_1,(GENERAL_NAME *)ppAVar1[1],(stack_st_CONF_VALUE *)param_3)->
               stack;
    if (param_3 == (_STACK *)0x0) goto LAB_000cc030;
    pvVar2 = sk_value(param_3,iVar6);
    i2t_ASN1_OBJECT(acStack_70,0x50,*ppAVar1);
    sVar3 = strlen(acStack_70);
    sVar4 = strlen(*(char **)((int)pvVar2 + 4));
    sVar3 = sVar3 + sVar4 + 5;
    dst = (char *)CRYPTO_malloc(sVar3,DAT_000cc04c,0x7f);
    if (dst == (char *)0x0) {
      ERR_put_error(0x22,0x8a,0x41,DAT_000cc04c,0x82);
      return (_STACK *)0x0;
    }
    BUF_strlcpy(dst,acStack_70,sVar3);
    BUF_strlcat(dst,DAT_000cc050,sVar3);
    BUF_strlcat(dst,*(char **)((int)pvVar2 + 4),sVar3);
    CRYPTO_free(*(void **)((int)pvVar2 + 4));
    *(char **)((int)pvVar2 + 4) = dst;
    iVar6 = iVar6 + 1;
  }
  if (param_3 == (_STACK *)0x0) {
LAB_000cc030:
    param_3 = sk_new_null();
  }
  return param_3;
}

