
void Curl_ssl_cleanup(void)

{
  int iVar1;
  
  iVar1 = DAT_0003c914;
  if (*(char *)(DAT_0003c914 + 8) != '\0') {
    Curl_ossl_cleanup();
    *(undefined *)(iVar1 + 8) = 0;
  }
  return;
}

