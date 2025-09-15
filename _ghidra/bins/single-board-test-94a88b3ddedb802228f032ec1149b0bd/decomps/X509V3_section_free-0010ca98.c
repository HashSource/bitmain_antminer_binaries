
void X509V3_section_free(X509V3_CTX *ctx,stack_st_CONF_VALUE *section)

{
  _func_4290 *p_Var1;
  
  if ((section != (stack_st_CONF_VALUE *)0x0) &&
     (p_Var1 = ctx->db_meth->free_section, p_Var1 != (_func_4290 *)0x0)) {
    (*p_Var1)(ctx->db,section);
  }
  return;
}

