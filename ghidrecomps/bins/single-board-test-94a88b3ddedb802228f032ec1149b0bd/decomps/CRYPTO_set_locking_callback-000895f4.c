
void CRYPTO_set_locking_callback(func *func)

{
  OPENSSL_init();
  locking_callback = func;
  return;
}

