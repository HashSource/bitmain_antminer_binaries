
void ssl_x509_store_ctx_init_ossl_(void)

{
  ssl_x509_store_ctx_idx =
       CRYPTO_get_ex_new_index
                 (5,0,"SSL for verify callback",(undefined1 *)0x0,(undefined1 *)0x0,
                  (undefined1 *)0x0);
  ssl_x509_store_ctx_init_ossl_ret_ = ~ssl_x509_store_ctx_idx >> 0x1f;
  return;
}

