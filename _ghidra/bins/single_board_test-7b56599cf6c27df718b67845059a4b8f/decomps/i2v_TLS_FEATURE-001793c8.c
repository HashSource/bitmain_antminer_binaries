
stack_st_CONF_VALUE *
i2v_TLS_FEATURE(undefined4 param_1,undefined4 param_2,stack_st_CONF_VALUE *param_3)

{
  ASN1_INTEGER *a;
  long lVar1;
  int iVar2;
  char *value;
  int iVar3;
  stack_st_CONF_VALUE *local_24 [2];
  
  local_24[0] = param_3;
  for (iVar3 = 0; iVar2 = OPENSSL_sk_num(param_2), iVar3 < iVar2; iVar3 = iVar3 + 1) {
    a = (ASN1_INTEGER *)OPENSSL_sk_value(param_2,iVar3);
    lVar1 = ASN1_INTEGER_get(a);
    value = "status_request";
    if ((lVar1 == 5) || (value = "status_request_v2", lVar1 == 0x11)) {
      X509V3_add_value((char *)0x0,value,local_24);
    }
    else {
      X509V3_add_value_int((char *)0x0,a,local_24);
    }
  }
  return local_24[0];
}

