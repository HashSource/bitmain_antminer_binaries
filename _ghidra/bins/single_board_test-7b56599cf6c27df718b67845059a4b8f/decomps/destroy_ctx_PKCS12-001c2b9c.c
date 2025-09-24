
void destroy_ctx_PKCS12(undefined4 *param_1)

{
  OPENSSL_sk_pop_free(*param_1,0x1c4075);
  *param_1 = 0;
  return;
}

