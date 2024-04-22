
undefined4 Curl_ssl_init(void)

{
  undefined4 uVar1;
  
  if (*(char *)(DAT_0003c8fc + 8) != '\0') {
    return 1;
  }
  *(undefined *)(DAT_0003c8fc + 8) = 1;
  uVar1 = Curl_ossl_init();
  return uVar1;
}

