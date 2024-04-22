
stack_st_CONF_VALUE *
i2v_POLICY_MAPPINGS(undefined4 param_1,_STACK *param_2,stack_st_CONF_VALUE *param_3)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  int iVar3;
  stack_st_CONF_VALUE *local_b4;
  char acStack_b0 [80];
  char acStack_60 [80];
  
  iVar3 = 0;
  local_b4 = param_3;
  while( true ) {
    iVar2 = sk_num(param_2);
    if (iVar2 <= iVar3) break;
    ppAVar1 = (ASN1_OBJECT **)sk_value(param_2,iVar3);
    i2t_ASN1_OBJECT(acStack_b0,0x50,*ppAVar1);
    i2t_ASN1_OBJECT(acStack_60,0x50,ppAVar1[1]);
    X509V3_add_value(acStack_b0,acStack_60,&local_b4);
    iVar3 = iVar3 + 1;
  }
  return local_b4;
}

