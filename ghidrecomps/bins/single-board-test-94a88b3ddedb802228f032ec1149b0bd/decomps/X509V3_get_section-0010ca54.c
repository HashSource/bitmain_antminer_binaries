
stack_st_CONF_VALUE * X509V3_get_section(X509V3_CTX *ctx,char *section)

{
  stack_st_CONF_VALUE *psVar1;
  _func_4288 *p_Var2;
  
  if (((ctx->db == (void *)0x0) || (ctx->db_meth == (X509V3_CONF_METHOD *)0x0)) ||
     (p_Var2 = ctx->db_meth->get_section, p_Var2 == (_func_4288 *)0x0)) {
    ERR_put_error(0x22,0x8e,0x94,DAT_0010ca84,0x196);
    psVar1 = (stack_st_CONF_VALUE *)0x0;
  }
  else {
    psVar1 = (*p_Var2)(ctx->db,section);
  }
  return psVar1;
}

