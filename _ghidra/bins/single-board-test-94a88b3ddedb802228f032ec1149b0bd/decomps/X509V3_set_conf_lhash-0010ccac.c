
void X509V3_set_conf_lhash(X509V3_CTX *ctx,lhash_st_CONF_VALUE *lhash)

{
  ctx->db = lhash;
  ctx->db_meth = (X509V3_CONF_METHOD *)conf_lhash_method;
  return;
}

