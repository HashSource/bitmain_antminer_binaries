
undefined4 pkey_gost_mac_init(EVP_PKEY_CTX *param_1)

{
  void *__s;
  
  __s = CRYPTO_malloc(0x28,"gost_pmeth.c",0x19a);
  if (__s != (void *)0x0) {
    memset(__s,0,0x28);
    EVP_PKEY_CTX_set_data(param_1,__s);
    return 1;
  }
  return 0;
}

