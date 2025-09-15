
void X509V3_set_nconf(X509V3_CTX *ctx,CONF *conf)

{
  ctx->db = conf;
  ctx->db_meth = (X509V3_CONF_METHOD *)&nconf_method;
  return;
}

