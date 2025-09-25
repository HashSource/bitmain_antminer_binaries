
void evp_app_cleanup_int(void)

{
  if (app_pkey_methods != 0) {
    OPENSSL_sk_pop_free(app_pkey_methods,0x12ee45);
    return;
  }
  return;
}

