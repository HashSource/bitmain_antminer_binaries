
BASIC_CONSTRAINTS * v2i_BASIC_CONSTRAINTS(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  BASIC_CONSTRAINTS *a;
  int iVar1;
  CONF_VALUE *value;
  char *__s1;
  int iVar2;
  
  a = BASIC_CONSTRAINTS_new();
  if (a == (BASIC_CONSTRAINTS *)0x0) {
    ERR_put_error(0x22,0x66,0x41,"crypto/x509v3/v3_bcons.c",0x3f);
  }
  else {
    iVar2 = 0;
    do {
      while( true ) {
        iVar1 = OPENSSL_sk_num(param_3);
        if (iVar1 <= iVar2) {
          return a;
        }
        value = (CONF_VALUE *)OPENSSL_sk_value(param_3,iVar2);
        __s1 = value->name;
        if (((*__s1 != 'C') || (__s1[1] != 'A')) || (__s1[2] != '\0')) break;
        iVar1 = X509V3_get_value_bool(value,&a->ca);
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) goto LAB_001c4402;
      }
      iVar1 = strcmp(__s1,"pathlen");
      if (iVar1 != 0) {
        ERR_put_error(0x22,0x66,0x6a,"crypto/x509v3/v3_bcons.c",0x4b);
        ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value);
        break;
      }
      iVar1 = X509V3_get_value_int(value,&a->pathlen);
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
LAB_001c4402:
    BASIC_CONSTRAINTS_free(a);
  }
  return (BASIC_CONSTRAINTS *)0x0;
}

