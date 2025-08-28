
undefined4 Curl_ssl_init(void)

{
  undefined4 uVar1;
  
  if (init_ssl != '\0') {
    return 1;
  }
  init_ssl = 1;
  uVar1 = Curl_ossl_init();
  return uVar1;
}

