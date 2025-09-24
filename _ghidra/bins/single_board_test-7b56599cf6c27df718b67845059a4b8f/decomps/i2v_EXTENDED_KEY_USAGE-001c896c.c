
stack_st_CONF_VALUE *
i2v_EXTENDED_KEY_USAGE(undefined4 param_1,undefined4 param_2,stack_st_CONF_VALUE *param_3)

{
  ASN1_OBJECT *a;
  int iVar1;
  int iVar2;
  stack_st_CONF_VALUE *local_6c;
  char acStack_68 [84];
  
  iVar2 = 0;
  local_6c = param_3;
  while( true ) {
    iVar1 = OPENSSL_sk_num(param_2);
    if (iVar1 <= iVar2) break;
    a = (ASN1_OBJECT *)OPENSSL_sk_value(param_2,iVar2);
    i2t_ASN1_OBJECT(acStack_68,0x50,a);
    X509V3_add_value((char *)0x0,acStack_68,&local_6c);
    iVar2 = iVar2 + 1;
  }
  return local_6c;
}

