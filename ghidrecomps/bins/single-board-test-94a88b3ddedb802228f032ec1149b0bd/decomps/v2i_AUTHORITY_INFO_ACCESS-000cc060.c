
_STACK * v2i_AUTHORITY_INFO_ACCESS(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  void *pvVar1;
  ASN1_OBJECT **data;
  char *pcVar2;
  GENERAL_NAME *pGVar3;
  ASN1_OBJECT *pAVar4;
  int iVar5;
  int iVar6;
  char *__s;
  size_t __n;
  CONF_VALUE CStack_34;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x8b,0x41,DAT_000cc1ac,0x9d);
  }
  else {
    iVar6 = 0;
    while( true ) {
      iVar5 = sk_num(param_3);
      if (iVar5 <= iVar6) break;
      pvVar1 = sk_value(param_3,iVar6);
      data = (ASN1_OBJECT **)ASN1_item_new(DAT_000cc1a8);
      if ((data == (ASN1_OBJECT **)0x0) || (iVar5 = sk_push(st,data), iVar5 == 0)) {
        iVar6 = 0xa5;
LAB_000cc128:
        ERR_put_error(0x22,0x8b,0x41,DAT_000cc1ac,iVar6);
LAB_000cc136:
        sk_pop_free(st,DAT_000cc1b0);
        return (_STACK *)0x0;
      }
      __s = *(char **)((int)pvVar1 + 4);
      pcVar2 = strchr(__s,0x3b);
      if (pcVar2 == (char *)0x0) {
        ERR_put_error(0x22,0x8b,0x8f,DAT_000cc1ac,0xab);
        sk_pop_free(st,DAT_000cc1b0);
        return (_STACK *)0x0;
      }
      __n = (int)pcVar2 - (int)__s;
      CStack_34.value = *(char **)((int)pvVar1 + 8);
      CStack_34.name = pcVar2 + 1;
      pGVar3 = v2i_GENERAL_NAME_ex((GENERAL_NAME *)data[1],param_1,param_2,&CStack_34,0);
      if (pGVar3 == (GENERAL_NAME *)0x0) goto LAB_000cc136;
      pcVar2 = (char *)CRYPTO_malloc(__n + 1,DAT_000cc1ac,0xb3);
      if (pcVar2 == (char *)0x0) {
        iVar6 = 0xb5;
        goto LAB_000cc128;
      }
      strncpy(pcVar2,*(char **)((int)pvVar1 + 4),__n);
      pcVar2[__n] = '\0';
      pAVar4 = OBJ_txt2obj(pcVar2,0);
      *data = pAVar4;
      if (pAVar4 == (ASN1_OBJECT *)0x0) {
        ERR_put_error(0x22,0x8b,0x77,DAT_000cc1ac,0xbd);
        ERR_add_error_data(2,DAT_000cc1b4,pcVar2);
        CRYPTO_free(pcVar2);
        sk_pop_free(st,DAT_000cc1b0);
        return (_STACK *)0x0;
      }
      CRYPTO_free(pcVar2);
      iVar6 = iVar6 + 1;
    }
  }
  return st;
}

