
void X509V3_set_conf_lhash(X509V3_CTX *ctx,lhash_st_CONF_VALUE *lhash)

{
  X509V3_CONF_METHOD *pXVar1;
  
  pXVar1 = DAT_0010ccb4;
  ctx->db = lhash;
  ctx->db_meth = pXVar1;
  return;
}

