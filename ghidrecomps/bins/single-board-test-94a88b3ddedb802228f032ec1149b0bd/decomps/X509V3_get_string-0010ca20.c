
char * X509V3_get_string(X509V3_CTX *ctx,char *name,char *section)

{
  char *pcVar1;
  _func_4287 *p_Var2;
  
  if (((ctx->db == (void *)0x0) || (ctx->db_meth == (X509V3_CONF_METHOD *)0x0)) ||
     (p_Var2 = ctx->db_meth->get_string, p_Var2 == (_func_4287 *)0x0)) {
    ERR_put_error(0x22,0x8f,0x94,DAT_0010ca50,0x18a);
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (*p_Var2)(ctx->db,name,section);
  }
  return pcVar1;
}

