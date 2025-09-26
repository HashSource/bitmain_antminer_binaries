
void CRYPTO_set_dynlock_lock_callback(dyn_lock_function *dyn_lock_function)

{
  dynlock_lock_callback = dyn_lock_function;
  return;
}

