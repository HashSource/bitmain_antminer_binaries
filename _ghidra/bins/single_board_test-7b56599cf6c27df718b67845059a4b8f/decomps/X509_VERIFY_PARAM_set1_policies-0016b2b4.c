
int X509_VERIFY_PARAM_set1_policies(X509_VERIFY_PARAM *param,stack_st_ASN1_OBJECT *policies)

{
  char *pcVar1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  int iVar4;
  
  if (param != (X509_VERIFY_PARAM *)0x0) {
    OPENSSL_sk_pop_free(param[1].name,(undefined *)0x17fc45);
    if (policies == (stack_st_ASN1_OBJECT *)0x0) {
      param[1].name = (char *)0x0;
      return 1;
    }
    pcVar1 = (char *)OPENSSL_sk_new_null();
    param[1].name = pcVar1;
    if (pcVar1 != (char *)0x0) {
      iVar4 = 0;
      while( true ) {
        iVar3 = OPENSSL_sk_num(policies);
        if (iVar3 <= iVar4) {
          param->flags = param->flags | 0x80;
          return 1;
        }
        pAVar2 = (ASN1_OBJECT *)OPENSSL_sk_value(policies,iVar4);
        pAVar2 = OBJ_dup(pAVar2);
        if (pAVar2 == (ASN1_OBJECT *)0x0) break;
        iVar3 = OPENSSL_sk_push(param[1].name,pAVar2);
        iVar4 = iVar4 + 1;
        if (iVar3 == 0) {
          ASN1_OBJECT_free(pAVar2);
          return 0;
        }
      }
    }
  }
  return 0;
}

