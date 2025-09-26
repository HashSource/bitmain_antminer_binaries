
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long CRYPTO_get_mem_debug_options(void)

{
  code *pcVar1;
  
  pcVar1 = get_debug_options_func;
  if (get_debug_options_func != (code *)0x0) {
    pcVar1 = (code *)(*get_debug_options_func)();
  }
  return (long)pcVar1;
}

