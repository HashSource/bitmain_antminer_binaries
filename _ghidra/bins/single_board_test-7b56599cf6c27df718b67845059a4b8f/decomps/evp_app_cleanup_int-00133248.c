
void evp_app_cleanup_int(void)

{
  if (app_pkey_methods != 0) {
    OPENSSL_sk_pop_free(app_pkey_methods,0x133095);
    return;
  }
  return;
}

