
int v2i_TLS_FEATURE(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint v;
  int iVar2;
  undefined4 *puVar3;
  ASN1_INTEGER *a;
  char *__s1;
  int iVar4;
  char *local_2c [2];
  
  iVar1 = OPENSSL_sk_new_null();
  if (iVar1 == 0) {
    ERR_put_error(0x22,0xa5,0x41,"crypto/x509v3/v3_tlsf.c",99);
  }
  else {
    for (iVar4 = 0; iVar2 = OPENSSL_sk_num(param_3), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      puVar3 = (undefined4 *)OPENSSL_sk_value(param_3,iVar4);
      __s1 = (char *)puVar3[2];
      if (__s1 != (char *)0x0) {
        iVar2 = strcasecmp(__s1,"status_request");
        if (iVar2 == 0) goto LAB_001750cc;
LAB_00175050:
        iVar2 = strcasecmp(__s1,"status_request_v2");
        if (iVar2 == 0) {
          v = 0x11;
        }
        else {
          v = strtol(__s1,local_2c,10);
          if ((*local_2c[0] != '\0' || __s1 == local_2c[0]) || (0xffff < v)) {
            ERR_put_error(0x22,0xa5,0x8f,"crypto/x509v3/v3_tlsf.c",0x77);
            ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
            goto LAB_001750ec;
          }
        }
        a = ASN1_INTEGER_new();
        if (a != (ASN1_INTEGER *)0x0) goto LAB_0017508e;
LAB_001750da:
        ERR_put_error(0x22,0xa5,0x41,"crypto/x509v3/v3_tlsf.c",0x80);
LAB_001750ec:
        OPENSSL_sk_pop_free(iVar1,0x105c85);
        return 0;
      }
      __s1 = (char *)puVar3[1];
      iVar2 = strcasecmp(__s1,"status_request");
      if (iVar2 != 0) goto LAB_00175050;
LAB_001750cc:
      a = ASN1_INTEGER_new();
      v = 5;
      if (a == (ASN1_INTEGER *)0x0) goto LAB_001750da;
LAB_0017508e:
      iVar2 = ASN1_INTEGER_set(a,v);
      if ((iVar2 == 0) || (iVar2 = OPENSSL_sk_push(iVar1,a), iVar2 < 1)) goto LAB_001750da;
    }
  }
  return iVar1;
}

