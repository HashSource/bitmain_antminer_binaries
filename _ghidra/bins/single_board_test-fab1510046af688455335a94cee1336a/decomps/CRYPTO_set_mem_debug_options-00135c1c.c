
void CRYPTO_set_mem_debug_options(long bits)

{
  if (set_debug_options_func != (code *)0x0) {
    (*set_debug_options_func)(bits);
  }
  return;
}

