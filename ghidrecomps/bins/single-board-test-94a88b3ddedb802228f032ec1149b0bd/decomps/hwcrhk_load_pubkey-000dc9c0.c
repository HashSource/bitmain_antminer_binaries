
EVP_PKEY * hwcrhk_load_pubkey(void)

{
  int iVar1;
  char *file;
  EVP_PKEY *pkey;
  int lib;
  rsa_st *prVar2;
  rsa_st *r;
  
  pkey = (EVP_PKEY *)hwcrhk_load_privkey();
  iVar1 = DAT_000dca44;
  if (pkey != (EVP_PKEY *)0x0) {
    if (pkey->type == 6) {
      CRYPTO_lock(9,10,DAT_000dca48,0x36a);
      r = (pkey->pkey).rsa;
      prVar2 = RSA_new();
      (pkey->pkey).rsa = prVar2;
      file = DAT_000dca48;
      prVar2->n = r->n;
      r->n = (BIGNUM *)0x0;
      prVar2->e = r->e;
      r->e = (BIGNUM *)0x0;
      CRYPTO_lock(10,10,file,0x371);
      RSA_free(r);
    }
    else {
      lib = *(int *)(DAT_000dca44 + 0x1c);
      if (lib == 0) {
        lib = ERR_get_next_error_library();
        *(int *)(iVar1 + 0x1c) = lib;
      }
      ERR_put_error(lib,0x6a,0x67,DAT_000dca48,0x378);
      EVP_PKEY_free(pkey);
      pkey = (EVP_PKEY *)0x0;
    }
  }
  return pkey;
}

