
void CRYPTO_free_locked(void *ptr)

{
  if (free_debug_func != (code *)0x0) {
    (*free_debug_func)(ptr,0);
  }
  (*free_locked_func)(ptr);
  if (free_debug_func != (code *)0x0) {
    (*free_debug_func)(0,1);
  }
  return;
}

