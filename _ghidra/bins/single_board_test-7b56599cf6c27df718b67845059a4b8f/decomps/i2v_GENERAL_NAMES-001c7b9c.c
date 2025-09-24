
stack_st_CONF_VALUE *
i2v_GENERAL_NAMES(X509V3_EXT_METHOD *method,GENERAL_NAMES *gen,stack_st_CONF_VALUE *extlist)

{
  GENERAL_NAME *gen_00;
  int iVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  stack_st_CONF_VALUE *ret;
  
  iVar3 = 0;
  psVar2 = extlist;
  do {
    ret = psVar2;
    iVar1 = OPENSSL_sk_num(gen);
    if (iVar1 <= iVar3) {
      if (ret != (stack_st_CONF_VALUE *)0x0) {
        return ret;
      }
      psVar2 = (stack_st_CONF_VALUE *)OPENSSL_sk_new_null();
      return psVar2;
    }
    gen_00 = (GENERAL_NAME *)OPENSSL_sk_value(gen,iVar3);
    psVar2 = i2v_GENERAL_NAME(method,gen_00,ret);
    iVar3 = iVar3 + 1;
  } while (psVar2 != (stack_st_CONF_VALUE *)0x0);
  if (extlist != (stack_st_CONF_VALUE *)0x0) {
    return (stack_st_CONF_VALUE *)0x0;
  }
  OPENSSL_sk_pop_free(ret,0x1794f9);
  return (stack_st_CONF_VALUE *)0x0;
}

