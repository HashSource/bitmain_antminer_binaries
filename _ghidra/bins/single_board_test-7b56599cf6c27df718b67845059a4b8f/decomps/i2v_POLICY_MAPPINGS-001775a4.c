
stack_st_CONF_VALUE *
i2v_POLICY_MAPPINGS(undefined4 param_1,undefined4 param_2,stack_st_CONF_VALUE *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  stack_st_CONF_VALUE *local_bc;
  char acStack_b8 [80];
  char acStack_68 [80];
  
  iVar3 = 0;
  local_bc = param_3;
  while( true ) {
    iVar2 = OPENSSL_sk_num(param_2);
    if (iVar2 <= iVar3) break;
    puVar1 = (undefined4 *)OPENSSL_sk_value(param_2,iVar3);
    i2t_ASN1_OBJECT(acStack_b8,0x50,(ASN1_OBJECT *)*puVar1);
    i2t_ASN1_OBJECT(acStack_68,0x50,(ASN1_OBJECT *)puVar1[1]);
    X509V3_add_value(acStack_b8,acStack_68,&local_bc);
    iVar3 = iVar3 + 1;
  }
  return local_bc;
}

