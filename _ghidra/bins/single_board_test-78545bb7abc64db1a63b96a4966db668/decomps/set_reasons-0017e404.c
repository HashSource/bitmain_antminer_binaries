
undefined4 set_reasons(int *param_1,char *param_2)

{
  int *piVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  char *__s2;
  int iVar6;
  ASN1_BIT_STRING *a;
  
  psVar2 = X509V3_parse_list(param_2);
  if (psVar2 == (stack_st_CONF_VALUE *)0x0) {
    return 0;
  }
  iVar6 = *param_1;
  if (iVar6 == 0) {
    for (; iVar3 = OPENSSL_sk_num(psVar2), iVar6 < iVar3; iVar6 = iVar6 + 1) {
      iVar3 = OPENSSL_sk_value(psVar2,iVar6);
      a = (ASN1_BIT_STRING *)*param_1;
      __s2 = *(char **)(iVar3 + 4);
      if (a == (ASN1_BIT_STRING *)0x0) {
        a = ASN1_BIT_STRING_new();
        *param_1 = (int)a;
        if (a == (ASN1_BIT_STRING *)0x0) goto LAB_0017e422;
      }
      piVar5 = &reason_flags;
      while (iVar3 = strcmp((char *)piVar5[2],__s2), iVar3 != 0) {
        piVar1 = piVar5 + 4;
        piVar5 = piVar5 + 3;
        if (*piVar1 == 0) goto LAB_0017e422;
      }
      iVar3 = ASN1_BIT_STRING_set_bit(a,*piVar5,1);
      if ((iVar3 == 0) || (piVar5[1] == 0)) goto LAB_0017e422;
    }
    uVar4 = 1;
  }
  else {
LAB_0017e422:
    uVar4 = 0;
  }
  OPENSSL_sk_pop_free(psVar2,0x1830d1);
  return uVar4;
}

