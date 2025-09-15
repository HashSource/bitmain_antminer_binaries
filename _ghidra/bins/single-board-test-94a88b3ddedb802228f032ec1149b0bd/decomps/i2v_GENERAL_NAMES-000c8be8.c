
stack_st_CONF_VALUE *
i2v_GENERAL_NAMES(X509V3_EXT_METHOD *method,GENERAL_NAMES *gen,stack_st_CONF_VALUE *extlist)

{
  GENERAL_NAME *gen_00;
  int iVar1;
  _STACK *p_Var2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    iVar1 = sk_num(&gen->stack);
    if (iVar1 <= iVar3) break;
    gen_00 = (GENERAL_NAME *)sk_value(&gen->stack,iVar3);
    extlist = i2v_GENERAL_NAME(method,gen_00,extlist);
    iVar3 = iVar3 + 1;
  }
  if (extlist != (stack_st_CONF_VALUE *)0x0) {
    return extlist;
  }
  p_Var2 = sk_new_null();
  return (stack_st_CONF_VALUE *)p_Var2;
}

