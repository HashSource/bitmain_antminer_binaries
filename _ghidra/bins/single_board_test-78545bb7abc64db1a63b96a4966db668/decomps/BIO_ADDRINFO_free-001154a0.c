
void BIO_ADDRINFO_free(addrinfo *param_1)

{
  addrinfo *paVar1;
  
  if (param_1 == (addrinfo *)0x0) {
    return;
  }
  if (param_1->ai_family != 1) {
    freeaddrinfo(param_1);
    return;
  }
  do {
    paVar1 = param_1->ai_next;
    CRYPTO_free(param_1->ai_addr);
    CRYPTO_free(param_1);
    param_1 = paVar1;
  } while (paVar1 != (addrinfo *)0x0);
  return;
}

