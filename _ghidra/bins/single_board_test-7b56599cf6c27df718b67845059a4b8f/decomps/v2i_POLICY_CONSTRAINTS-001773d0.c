
POLICY_CONSTRAINTS *
v2i_POLICY_CONSTRAINTS(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  POLICY_CONSTRAINTS *a;
  int iVar1;
  CONF_VALUE *value;
  int iVar2;
  char *__s1;
  
  a = POLICY_CONSTRAINTS_new();
  if (a == (POLICY_CONSTRAINTS *)0x0) {
    ERR_put_error(0x22,0x92,0x41,"crypto/x509v3/v3_pcons.c",0x40);
  }
  else {
    iVar2 = 0;
    do {
      while( true ) {
        iVar1 = OPENSSL_sk_num(param_3);
        if (iVar1 <= iVar2) {
          if ((a->inhibitPolicyMapping != (ASN1_INTEGER *)0x0) ||
             (a->requireExplicitPolicy != (ASN1_INTEGER *)0x0)) {
            return a;
          }
          ERR_put_error(0x22,0x92,0x97,"crypto/x509v3/v3_pcons.c",0x53);
          goto LAB_0017742e;
        }
        value = (CONF_VALUE *)OPENSSL_sk_value(param_3,iVar2);
        __s1 = value->name;
        iVar1 = strcmp(__s1,"requireExplicitPolicy");
        if (iVar1 == 0) break;
        iVar1 = strcmp(__s1,"inhibitPolicyMapping");
        if (iVar1 != 0) {
          ERR_put_error(0x22,0x92,0x6a,"crypto/x509v3/v3_pcons.c",0x4c);
          ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value
                            );
          goto LAB_0017742e;
        }
        iVar1 = X509V3_get_value_int(value,&a->inhibitPolicyMapping);
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) goto LAB_0017742e;
      }
      iVar1 = X509V3_get_value_int(value,&a->requireExplicitPolicy);
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
LAB_0017742e:
    POLICY_CONSTRAINTS_free(a);
  }
  return (POLICY_CONSTRAINTS *)0x0;
}

