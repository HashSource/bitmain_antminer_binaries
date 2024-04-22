
int Curl_ossl_init(void)

{
  int iVar1;
  
  OPENSSL_load_builtin_modules();
  ENGINE_load_builtin_engines();
  CONF_modules_load_file((char *)0x0,(char *)0x0,0x30);
  SSL_load_error_strings();
  iVar1 = SSL_library_init();
  if (iVar1 != 0) {
    OPENSSL_add_all_algorithms_noconf();
    iVar1 = 1;
  }
  return iVar1;
}

