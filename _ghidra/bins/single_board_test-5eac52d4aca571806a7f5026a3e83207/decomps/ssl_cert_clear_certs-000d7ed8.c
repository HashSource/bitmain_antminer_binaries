
void ssl_cert_clear_certs(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != 0) {
    puVar1 = (undefined4 *)(param_1 + 0x14);
    do {
      puVar2 = puVar1 + 5;
      X509_free((X509 *)*puVar1);
      *puVar1 = 0;
      EVP_PKEY_free((EVP_PKEY *)puVar1[1]);
      puVar1[1] = 0;
      OPENSSL_sk_pop_free(puVar1[2],(undefined *)0x16a341);
      puVar1[2] = 0;
      CRYPTO_free((void *)puVar1[3]);
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1 = puVar2;
    } while (puVar2 != (undefined4 *)(param_1 + 200));
    return;
  }
  return;
}

