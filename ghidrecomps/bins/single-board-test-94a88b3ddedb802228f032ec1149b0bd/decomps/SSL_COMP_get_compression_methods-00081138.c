
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

stack_st_SSL_COMP * SSL_COMP_get_compression_methods(void)

{
  load_builtin_compressions();
  return ssl_comp_methods;
}

