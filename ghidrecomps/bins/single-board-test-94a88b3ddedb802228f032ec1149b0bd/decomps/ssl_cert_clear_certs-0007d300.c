
void ssl_cert_clear_certs(int param_1)

{
  if (param_1 != 0) {
    if (*(X509 **)(param_1 + 0x3c) != (X509 *)0x0) {
      X509_free(*(X509 **)(param_1 + 0x3c));
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    if (*(EVP_PKEY **)(param_1 + 0x40) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(param_1 + 0x40));
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
    if (*(_STACK **)(param_1 + 0x48) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0x48),DAT_0007d568);
      *(undefined4 *)(param_1 + 0x48) = 0;
    }
    if (*(void **)(param_1 + 0x4c) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x4c));
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
    }
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0x100;
    if (*(X509 **)(param_1 + 0x58) != (X509 *)0x0) {
      X509_free(*(X509 **)(param_1 + 0x58));
      *(undefined4 *)(param_1 + 0x58) = 0;
    }
    if (*(EVP_PKEY **)(param_1 + 0x5c) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(param_1 + 0x5c));
      *(undefined4 *)(param_1 + 0x5c) = 0;
    }
    if (*(_STACK **)(param_1 + 100) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 100),DAT_0007d568);
      *(undefined4 *)(param_1 + 100) = 0;
    }
    if (*(void **)(param_1 + 0x68) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x68));
      *(undefined4 *)(param_1 + 0x68) = 0;
      *(undefined4 *)(param_1 + 0x6c) = 0;
    }
    *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0x100;
    if (*(X509 **)(param_1 + 0x74) != (X509 *)0x0) {
      X509_free(*(X509 **)(param_1 + 0x74));
      *(undefined4 *)(param_1 + 0x74) = 0;
    }
    if (*(EVP_PKEY **)(param_1 + 0x78) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(param_1 + 0x78));
      *(undefined4 *)(param_1 + 0x78) = 0;
    }
    if (*(_STACK **)(param_1 + 0x80) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0x80),DAT_0007d568);
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
    if (*(void **)(param_1 + 0x84) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x84));
      *(undefined4 *)(param_1 + 0x84) = 0;
      *(undefined4 *)(param_1 + 0x88) = 0;
    }
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0x100;
    if (*(X509 **)(param_1 + 0x90) != (X509 *)0x0) {
      X509_free(*(X509 **)(param_1 + 0x90));
      *(undefined4 *)(param_1 + 0x90) = 0;
    }
    if (*(EVP_PKEY **)(param_1 + 0x94) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(param_1 + 0x94));
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    if (*(_STACK **)(param_1 + 0x9c) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0x9c),DAT_0007d568);
      *(undefined4 *)(param_1 + 0x9c) = 0;
    }
    if (*(void **)(param_1 + 0xa0) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0xa0));
      *(undefined4 *)(param_1 + 0xa0) = 0;
      *(undefined4 *)(param_1 + 0xa4) = 0;
    }
    *(uint *)(param_1 + 0xa8) = *(uint *)(param_1 + 0xa8) & 0x100;
    if (*(X509 **)(param_1 + 0xac) != (X509 *)0x0) {
      X509_free(*(X509 **)(param_1 + 0xac));
      *(undefined4 *)(param_1 + 0xac) = 0;
    }
    if (*(EVP_PKEY **)(param_1 + 0xb0) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(param_1 + 0xb0));
      *(undefined4 *)(param_1 + 0xb0) = 0;
    }
    if (*(_STACK **)(param_1 + 0xb8) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0xb8),DAT_0007d568);
      *(undefined4 *)(param_1 + 0xb8) = 0;
    }
    if (*(void **)(param_1 + 0xbc) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0xbc));
      *(undefined4 *)(param_1 + 0xbc) = 0;
      *(undefined4 *)(param_1 + 0xc0) = 0;
    }
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0x100;
    if (*(X509 **)(param_1 + 200) != (X509 *)0x0) {
      X509_free(*(X509 **)(param_1 + 200));
      *(undefined4 *)(param_1 + 200) = 0;
    }
    if (*(EVP_PKEY **)(param_1 + 0xcc) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(param_1 + 0xcc));
      *(undefined4 *)(param_1 + 0xcc) = 0;
    }
    if (*(_STACK **)(param_1 + 0xd4) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0xd4),DAT_0007d568);
      *(undefined4 *)(param_1 + 0xd4) = 0;
    }
    if (*(void **)(param_1 + 0xd8) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0xd8));
      *(undefined4 *)(param_1 + 0xd8) = 0;
      *(undefined4 *)(param_1 + 0xdc) = 0;
    }
    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0x100;
    if (*(X509 **)(param_1 + 0xe4) != (X509 *)0x0) {
      X509_free(*(X509 **)(param_1 + 0xe4));
      *(undefined4 *)(param_1 + 0xe4) = 0;
    }
    if (*(EVP_PKEY **)(param_1 + 0xe8) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(param_1 + 0xe8));
      *(undefined4 *)(param_1 + 0xe8) = 0;
    }
    if (*(_STACK **)(param_1 + 0xf0) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0xf0),DAT_0007d568);
      *(undefined4 *)(param_1 + 0xf0) = 0;
    }
    if (*(void **)(param_1 + 0xf4) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0xf4));
      *(undefined4 *)(param_1 + 0xf4) = 0;
      *(undefined4 *)(param_1 + 0xf8) = 0;
    }
    *(uint *)(param_1 + 0xfc) = *(uint *)(param_1 + 0xfc) & 0x100;
    if (*(X509 **)(param_1 + 0x100) != (X509 *)0x0) {
      X509_free(*(X509 **)(param_1 + 0x100));
      *(undefined4 *)(param_1 + 0x100) = 0;
    }
    if (*(EVP_PKEY **)(param_1 + 0x104) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(param_1 + 0x104));
      *(undefined4 *)(param_1 + 0x104) = 0;
    }
    if (*(_STACK **)(param_1 + 0x10c) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0x10c),DAT_0007d568);
      *(undefined4 *)(param_1 + 0x10c) = 0;
    }
    if (*(void **)(param_1 + 0x110) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x110));
      *(undefined4 *)(param_1 + 0x110) = 0;
      *(undefined4 *)(param_1 + 0x114) = 0;
    }
    *(uint *)(param_1 + 0x118) = *(uint *)(param_1 + 0x118) & 0x100;
  }
  return;
}

