
void CRYPTO_set_dynlock_destroy_callback(dyn_destroy_function *dyn_destroy_function)

{
  dynlock_destroy_callback = dyn_destroy_function;
  return;
}

