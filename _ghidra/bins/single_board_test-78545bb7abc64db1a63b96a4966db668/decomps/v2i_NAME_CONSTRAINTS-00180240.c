
NAME_CONSTRAINTS *
v2i_NAME_CONSTRAINTS(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  NAME_CONSTRAINTS *a;
  GENERAL_NAME *pGVar1;
  stack_st_GENERAL_SUBTREE *psVar2;
  int iVar3;
  int iVar4;
  GENERAL_SUBTREE *a_00;
  int iVar5;
  char *__s1;
  NAME_CONSTRAINTS *pNVar6;
  CONF_VALUE CStack_34;
  
  a = NAME_CONSTRAINTS_new();
  if (a == (NAME_CONSTRAINTS *)0x0) {
LAB_001802f0:
    a_00 = (GENERAL_SUBTREE *)0x0;
LAB_001802f2:
    ERR_put_error(0x22,0x93,0x41,"crypto/x509v3/v3_ncons.c",0xa1);
LAB_00180304:
    NAME_CONSTRAINTS_free(a);
    GENERAL_SUBTREE_free(a_00);
    return (NAME_CONSTRAINTS *)0x0;
  }
  iVar5 = 0;
  do {
    iVar3 = OPENSSL_sk_num(param_3);
    if (iVar3 <= iVar5) {
      return a;
    }
    iVar3 = OPENSSL_sk_value(param_3,iVar5);
    __s1 = *(char **)(iVar3 + 4);
    iVar4 = strncmp(__s1,"permitted",9);
    if ((iVar4 == 0) && (__s1[9] != '\0')) {
      CStack_34.name = __s1 + 10;
      CStack_34.value = *(char **)(iVar3 + 8);
      a_00 = GENERAL_SUBTREE_new();
      pNVar6 = a;
    }
    else {
      iVar4 = strncmp(__s1,"excluded",8);
      if ((iVar4 != 0) || (__s1[8] == '\0')) {
        a_00 = (GENERAL_SUBTREE *)0x0;
        ERR_put_error(0x22,0x93,0x8f,"crypto/x509v3/v3_ncons.c",0x8e);
        goto LAB_00180304;
      }
      CStack_34.name = __s1 + 9;
      pNVar6 = (NAME_CONSTRAINTS *)&a->excludedSubtrees;
      CStack_34.value = *(char **)(iVar3 + 8);
      a_00 = GENERAL_SUBTREE_new();
    }
    if (a_00 == (GENERAL_SUBTREE *)0x0) goto LAB_001802f0;
    pGVar1 = v2i_GENERAL_NAME_ex(a_00->base,param_1,param_2,&CStack_34,1);
    if (pGVar1 == (GENERAL_NAME *)0x0) goto LAB_00180304;
    psVar2 = pNVar6->permittedSubtrees;
    if (psVar2 == (stack_st_GENERAL_SUBTREE *)0x0) {
      psVar2 = (stack_st_GENERAL_SUBTREE *)OPENSSL_sk_new_null();
      pNVar6->permittedSubtrees = psVar2;
      if (psVar2 == (stack_st_GENERAL_SUBTREE *)0x0) goto LAB_001802f2;
    }
    iVar3 = OPENSSL_sk_push(psVar2,a_00);
    if (iVar3 == 0) goto LAB_001802f2;
    iVar5 = iVar5 + 1;
  } while( true );
}

