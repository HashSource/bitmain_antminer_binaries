
undefined4 set_reasons(int *param_1,char *param_2)

{
  int *piVar1;
  _STACK *st;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  char *__s2;
  int iVar6;
  ASN1_BIT_STRING *a;
  
  st = &X509V3_parse_list(param_2)->stack;
  if ((st == (_STACK *)0x0) || (iVar6 = *param_1, iVar6 != 0)) {
    return 0;
  }
  do {
    iVar2 = sk_num(st);
    if (iVar2 <= iVar6) {
      uVar5 = 1;
LAB_000ca6d2:
      sk_pop_free(st,(func *)0xc7009);
      return uVar5;
    }
    pvVar3 = sk_value(st,iVar6);
    a = (ASN1_BIT_STRING *)*param_1;
    __s2 = *(char **)((int)pvVar3 + 4);
    if (a == (ASN1_BIT_STRING *)0x0) {
      a = ASN1_BIT_STRING_new();
      *param_1 = (int)a;
      if (a != (ASN1_BIT_STRING *)0x0) goto LAB_000ca6aa;
LAB_000ca6d0:
      uVar5 = 0;
      goto LAB_000ca6d2;
    }
LAB_000ca6aa:
    piVar4 = &reason_flags;
    while (iVar2 = strcmp((char *)piVar4[2],__s2), iVar2 != 0) {
      piVar1 = piVar4 + 4;
      piVar4 = piVar4 + 3;
      if (*piVar1 == 0) goto LAB_000ca6d0;
    }
    iVar2 = ASN1_BIT_STRING_set_bit(a,*piVar4,1);
    if ((iVar2 == 0) || (piVar4[1] == 0)) goto LAB_000ca6d0;
    iVar6 = iVar6 + 1;
  } while( true );
}

