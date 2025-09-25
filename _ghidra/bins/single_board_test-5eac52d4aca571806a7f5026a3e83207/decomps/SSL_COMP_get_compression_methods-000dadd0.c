
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

stack_st_SSL_COMP * SSL_COMP_get_compression_methods(void)

{
  CRYPTO_THREAD_run_once(&ssl_load_builtin_comp_once,0xd91cd);
  return ssl_comp_methods;
}

