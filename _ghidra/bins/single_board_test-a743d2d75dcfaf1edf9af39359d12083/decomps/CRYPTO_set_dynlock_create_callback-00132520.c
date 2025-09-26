
void CRYPTO_set_dynlock_create_callback(dyn_create_function *dyn_create_function)

{
  dynlock_create_callback = dyn_create_function;
  return;
}

