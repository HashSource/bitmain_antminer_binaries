
void X509V3_string_free(X509V3_CTX *ctx,char *str)

{
  _func_4289 *p_Var1;
  
  if ((str != (char *)0x0) && (p_Var1 = ctx->db_meth->free_string, p_Var1 != (_func_4289 *)0x0)) {
    (*p_Var1)(ctx->db,str);
  }
  return;
}

