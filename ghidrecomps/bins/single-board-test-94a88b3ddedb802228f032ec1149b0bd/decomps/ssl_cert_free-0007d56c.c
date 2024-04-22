
void ssl_cert_free(void *param_1)

{
  int iVar1;
  
  if (param_1 != (void *)0x0) {
    iVar1 = CRYPTO_add_lock((int *)((int)param_1 + 0x16c),-1,0xd,DAT_0007d594,0x1cd);
    if (iVar1 < 1) {
      if (*(RSA **)((int)param_1 + 0x1c) != (RSA *)0x0) {
        RSA_free(*(RSA **)((int)param_1 + 0x1c));
      }
      if (*(DH **)((int)param_1 + 0x24) != (DH *)0x0) {
        DH_free(*(DH **)((int)param_1 + 0x24));
      }
      if (*(EC_KEY **)((int)param_1 + 0x2c) != (EC_KEY *)0x0) {
        EC_KEY_free(*(EC_KEY **)((int)param_1 + 0x2c));
      }
      if (*(X509 **)((int)param_1 + 0x3c) != (X509 *)0x0) {
        X509_free(*(X509 **)((int)param_1 + 0x3c));
        *(undefined4 *)((int)param_1 + 0x3c) = 0;
      }
      if (*(EVP_PKEY **)((int)param_1 + 0x40) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 0x40));
        *(undefined4 *)((int)param_1 + 0x40) = 0;
      }
      if (*(_STACK **)((int)param_1 + 0x48) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)((int)param_1 + 0x48),DAT_0007d878);
        *(undefined4 *)((int)param_1 + 0x48) = 0;
      }
      if (*(void **)((int)param_1 + 0x4c) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x4c));
        *(undefined4 *)((int)param_1 + 0x4c) = 0;
        *(undefined4 *)((int)param_1 + 0x50) = 0;
      }
      *(uint *)((int)param_1 + 0x54) = *(uint *)((int)param_1 + 0x54) & 0x100;
      if (*(X509 **)((int)param_1 + 0x58) != (X509 *)0x0) {
        X509_free(*(X509 **)((int)param_1 + 0x58));
        *(undefined4 *)((int)param_1 + 0x58) = 0;
      }
      if (*(EVP_PKEY **)((int)param_1 + 0x5c) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 0x5c));
        *(undefined4 *)((int)param_1 + 0x5c) = 0;
      }
      if (*(_STACK **)((int)param_1 + 100) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)((int)param_1 + 100),DAT_0007d878);
        *(undefined4 *)((int)param_1 + 100) = 0;
      }
      if (*(void **)((int)param_1 + 0x68) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x68));
        *(undefined4 *)((int)param_1 + 0x68) = 0;
        *(undefined4 *)((int)param_1 + 0x6c) = 0;
      }
      *(uint *)((int)param_1 + 0x70) = *(uint *)((int)param_1 + 0x70) & 0x100;
      if (*(X509 **)((int)param_1 + 0x74) != (X509 *)0x0) {
        X509_free(*(X509 **)((int)param_1 + 0x74));
        *(undefined4 *)((int)param_1 + 0x74) = 0;
      }
      if (*(EVP_PKEY **)((int)param_1 + 0x78) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 0x78));
        *(undefined4 *)((int)param_1 + 0x78) = 0;
      }
      if (*(_STACK **)((int)param_1 + 0x80) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)((int)param_1 + 0x80),DAT_0007d878);
        *(undefined4 *)((int)param_1 + 0x80) = 0;
      }
      if (*(void **)((int)param_1 + 0x84) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x84));
        *(undefined4 *)((int)param_1 + 0x84) = 0;
        *(undefined4 *)((int)param_1 + 0x88) = 0;
      }
      *(uint *)((int)param_1 + 0x8c) = *(uint *)((int)param_1 + 0x8c) & 0x100;
      if (*(X509 **)((int)param_1 + 0x90) != (X509 *)0x0) {
        X509_free(*(X509 **)((int)param_1 + 0x90));
        *(undefined4 *)((int)param_1 + 0x90) = 0;
      }
      if (*(EVP_PKEY **)((int)param_1 + 0x94) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 0x94));
        *(undefined4 *)((int)param_1 + 0x94) = 0;
      }
      if (*(_STACK **)((int)param_1 + 0x9c) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)((int)param_1 + 0x9c),DAT_0007d878);
        *(undefined4 *)((int)param_1 + 0x9c) = 0;
      }
      if (*(void **)((int)param_1 + 0xa0) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0xa0));
        *(undefined4 *)((int)param_1 + 0xa0) = 0;
        *(undefined4 *)((int)param_1 + 0xa4) = 0;
      }
      *(uint *)((int)param_1 + 0xa8) = *(uint *)((int)param_1 + 0xa8) & 0x100;
      if (*(X509 **)((int)param_1 + 0xac) != (X509 *)0x0) {
        X509_free(*(X509 **)((int)param_1 + 0xac));
        *(undefined4 *)((int)param_1 + 0xac) = 0;
      }
      if (*(EVP_PKEY **)((int)param_1 + 0xb0) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 0xb0));
        *(undefined4 *)((int)param_1 + 0xb0) = 0;
      }
      if (*(_STACK **)((int)param_1 + 0xb8) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)((int)param_1 + 0xb8),DAT_0007d878);
        *(undefined4 *)((int)param_1 + 0xb8) = 0;
      }
      if (*(void **)((int)param_1 + 0xbc) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0xbc));
        *(undefined4 *)((int)param_1 + 0xbc) = 0;
        *(undefined4 *)((int)param_1 + 0xc0) = 0;
      }
      *(uint *)((int)param_1 + 0xc4) = *(uint *)((int)param_1 + 0xc4) & 0x100;
      if (*(X509 **)((int)param_1 + 200) != (X509 *)0x0) {
        X509_free(*(X509 **)((int)param_1 + 200));
        *(undefined4 *)((int)param_1 + 200) = 0;
      }
      if (*(EVP_PKEY **)((int)param_1 + 0xcc) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 0xcc));
        *(undefined4 *)((int)param_1 + 0xcc) = 0;
      }
      if (*(_STACK **)((int)param_1 + 0xd4) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)((int)param_1 + 0xd4),DAT_0007d878);
        *(undefined4 *)((int)param_1 + 0xd4) = 0;
      }
      if (*(void **)((int)param_1 + 0xd8) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0xd8));
        *(undefined4 *)((int)param_1 + 0xd8) = 0;
        *(undefined4 *)((int)param_1 + 0xdc) = 0;
      }
      *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) & 0x100;
      if (*(X509 **)((int)param_1 + 0xe4) != (X509 *)0x0) {
        X509_free(*(X509 **)((int)param_1 + 0xe4));
        *(undefined4 *)((int)param_1 + 0xe4) = 0;
      }
      if (*(EVP_PKEY **)((int)param_1 + 0xe8) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 0xe8));
        *(undefined4 *)((int)param_1 + 0xe8) = 0;
      }
      if (*(_STACK **)((int)param_1 + 0xf0) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)((int)param_1 + 0xf0),DAT_0007d878);
        *(undefined4 *)((int)param_1 + 0xf0) = 0;
      }
      if (*(void **)((int)param_1 + 0xf4) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0xf4));
        *(undefined4 *)((int)param_1 + 0xf4) = 0;
        *(undefined4 *)((int)param_1 + 0xf8) = 0;
      }
      *(uint *)((int)param_1 + 0xfc) = *(uint *)((int)param_1 + 0xfc) & 0x100;
      if (*(X509 **)((int)param_1 + 0x100) != (X509 *)0x0) {
        X509_free(*(X509 **)((int)param_1 + 0x100));
        *(undefined4 *)((int)param_1 + 0x100) = 0;
      }
      if (*(EVP_PKEY **)((int)param_1 + 0x104) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)((int)param_1 + 0x104));
        *(undefined4 *)((int)param_1 + 0x104) = 0;
      }
      if (*(_STACK **)((int)param_1 + 0x10c) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)((int)param_1 + 0x10c),DAT_0007d878);
        *(undefined4 *)((int)param_1 + 0x10c) = 0;
      }
      if (*(void **)((int)param_1 + 0x110) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x110));
        *(undefined4 *)((int)param_1 + 0x110) = 0;
        *(undefined4 *)((int)param_1 + 0x114) = 0;
      }
      *(uint *)((int)param_1 + 0x118) = *(uint *)((int)param_1 + 0x118) & 0x100;
      if (*(void **)((int)param_1 + 0x124) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x124));
      }
      if (*(void **)((int)param_1 + 300) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 300));
      }
      if (*(void **)((int)param_1 + 0x134) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x134));
      }
      if (*(void **)((int)param_1 + 0x13c) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x13c));
      }
      if (*(void **)((int)param_1 + 0x11c) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x11c));
      }
      if (*(X509_STORE **)((int)param_1 + 0x150) != (X509_STORE *)0x0) {
        X509_STORE_free(*(X509_STORE **)((int)param_1 + 0x150));
      }
      if (*(X509_STORE **)((int)param_1 + 0x14c) != (X509_STORE *)0x0) {
        X509_STORE_free(*(X509_STORE **)((int)param_1 + 0x14c));
      }
      if (*(void **)((int)param_1 + 0x154) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x154));
      }
      custom_exts_free((int)param_1 + 0x15c);
      custom_exts_free((int)param_1 + 0x164);
      CRYPTO_free(param_1);
      return;
    }
  }
  return;
}

