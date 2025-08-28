
EVP_PKEY * hwcrhk_load_pubkey(void)

{
  EVP_PKEY *pkey;
  RSA *pRVar1;
  RSA *r;
  
  pkey = (EVP_PKEY *)hwcrhk_load_privkey();
  if (pkey != (EVP_PKEY *)0x0) {
    if (pkey->type == 6) {
      CRYPTO_lock(9,10,"e_chil.c",0x36a);
      r = (pkey->pkey).rsa;
      pRVar1 = RSA_new();
      (pkey->pkey).rsa = pRVar1;
      pRVar1->n = r->n;
      r->n = (BIGNUM *)0x0;
      pRVar1->e = r->e;
      r->e = (BIGNUM *)0x0;
      CRYPTO_lock(10,10,"e_chil.c",0x371);
      RSA_free(r);
    }
    else {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(HWCRHK_lib_error_code,0x6a,0x67,"e_chil.c",0x378);
      EVP_PKEY_free(pkey);
      pkey = (EVP_PKEY *)0x0;
    }
  }
  return pkey;
}

