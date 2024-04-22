
ASN1_BIT_STRING *
v2i_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,stack_st_CONF_VALUE *nval)

{
  ASN1_STRING *a;
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  char *__s1;
  char *__s2;
  int iVar4;
  
  a = ASN1_STRING_type_new(3);
  if (a == (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,0x65,0x41,DAT_0010c30c,0x74);
  }
  else {
    iVar4 = 0;
    iVar1 = sk_num(&nval->stack);
    if (0 < iVar1) {
      do {
        puVar2 = (undefined4 *)sk_value(&nval->stack,iVar4);
        __s1 = *(char **)((int)method->usr_data + 4);
        if (__s1 == (char *)0x0) {
LAB_0010c2a6:
          ERR_put_error(0x22,0x65,0x6f,DAT_0010c30c,0x87);
          ERR_add_error_data(6,DAT_0010c314,*puVar2,DAT_0010c318,puVar2[1],DAT_0010c310,puVar2[2]);
          ASN1_STRING_free(a);
          return (ASN1_BIT_STRING *)0x0;
        }
        __s2 = (char *)puVar2[1];
        piVar3 = (int *)method->usr_data;
        while ((iVar1 = strcmp((char *)piVar3[2],__s2), iVar1 != 0 &&
               (iVar1 = strcmp(__s1,__s2), iVar1 != 0))) {
          __s1 = (char *)piVar3[4];
          HintPreloadData(piVar3 + 0x16);
          piVar3 = piVar3 + 3;
          if (__s1 == (char *)0x0) goto LAB_0010c2a6;
        }
        iVar1 = ASN1_BIT_STRING_set_bit(a,*piVar3,1);
        if (iVar1 == 0) {
          ERR_put_error(0x22,0x65,0x41,DAT_0010c30c,0x7e);
          ASN1_STRING_free(a);
          return (ASN1_BIT_STRING *)0x0;
        }
        if (piVar3[1] == 0) goto LAB_0010c2a6;
        iVar4 = iVar4 + 1;
        iVar1 = sk_num(&nval->stack);
      } while (iVar4 < iVar1);
    }
  }
  return a;
}

