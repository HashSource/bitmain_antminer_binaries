
stack_st_CONF_VALUE *
i2v_EXTENDED_KEY_USAGE(undefined4 param_1,_STACK *param_2,stack_st_CONF_VALUE *param_3)

{
  ASN1_OBJECT *a;
  int iVar1;
  int iVar2;
  stack_st_CONF_VALUE *local_64;
  char acStack_60 [84];
  
  iVar2 = 0;
  local_64 = param_3;
  while( true ) {
    iVar1 = sk_num(param_2);
    if (iVar1 <= iVar2) break;
    a = (ASN1_OBJECT *)sk_value(param_2,iVar2);
    i2t_ASN1_OBJECT(acStack_60,0x50,a);
    X509V3_add_value((char *)0x0,acStack_60,&local_64);
    iVar2 = iVar2 + 1;
  }
  return local_64;
}

