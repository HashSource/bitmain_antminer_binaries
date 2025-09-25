
undefined4 pkey_siphash_init(EVP_PKEY_CTX *param_1)

{
  void *data;
  
  data = (void *)CRYPTO_zalloc(0x50,"crypto/siphash/siphash_pmeth.c",0x1f);
  if (data != (void *)0x0) {
    *(undefined4 *)((int)data + 4) = 4;
    EVP_PKEY_CTX_set_data(param_1,data);
    EVP_PKEY_CTX_set0_keygen_info(param_1,(int *)0x0,0);
    return 1;
  }
  ERR_put_error(0xf,0x7d,0x41,"crypto/siphash/siphash_pmeth.c",0x20);
  return 0;
}

