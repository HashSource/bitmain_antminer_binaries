
ASN1_BIT_STRING *
v2i_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,stack_st_CONF_VALUE *nval)

{
  ASN1_BIT_STRING *a;
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  char *__s1;
  char *__s2;
  int iVar4;
  
  a = ASN1_BIT_STRING_new();
  if (a == (ASN1_BIT_STRING *)0x0) {
    ERR_put_error(0x22,0x65,0x41,"crypto/x509v3/v3_bitst.c",0x43);
    return (ASN1_BIT_STRING *)0x0;
  }
  iVar4 = 0;
  iVar1 = OPENSSL_sk_num(nval);
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)OPENSSL_sk_value(nval,iVar4);
      __s1 = *(char **)((int)method->usr_data + 4);
      if (__s1 == (char *)0x0) {
LAB_001d2380:
        ERR_put_error(0x22,0x65,0x6f,"crypto/x509v3/v3_bitst.c",0x56);
        ERR_add_error_data(6,"section:",*puVar2,",name:",puVar2[1],",value:",puVar2[2]);
        ASN1_BIT_STRING_free(a);
        return (ASN1_BIT_STRING *)0x0;
      }
      __s2 = (char *)puVar2[1];
      piVar3 = (int *)method->usr_data;
      while ((iVar1 = strcmp((char *)piVar3[2],__s2), iVar1 != 0 &&
             (iVar1 = strcmp(__s1,__s2), iVar1 != 0))) {
        __s1 = (char *)piVar3[4];
        HintPreloadData(piVar3 + 0x16);
        piVar3 = piVar3 + 3;
        if (__s1 == (char *)0x0) goto LAB_001d2380;
      }
      iVar1 = ASN1_BIT_STRING_set_bit(a,*piVar3,1);
      if (iVar1 == 0) {
        ERR_put_error(0x22,0x65,0x41,"crypto/x509v3/v3_bitst.c",0x4d);
        ASN1_BIT_STRING_free(a);
        return (ASN1_BIT_STRING *)0x0;
      }
      if (piVar3[1] == 0) goto LAB_001d2380;
      iVar4 = iVar4 + 1;
      iVar1 = OPENSSL_sk_num(nval);
    } while (iVar4 < iVar1);
  }
  return a;
}

