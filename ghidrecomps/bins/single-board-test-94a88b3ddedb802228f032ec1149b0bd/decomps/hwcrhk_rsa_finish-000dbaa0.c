
undefined4 hwcrhk_rsa_finish(RSA *param_1)

{
  undefined4 *ptr;
  
  ptr = (undefined4 *)RSA_get_ex_data(param_1,hndidx_rsa);
  if (ptr != (undefined4 *)0x0) {
    (*p_hwcrhk_RSAUnloadKey)(*ptr,0);
    CRYPTO_free(ptr);
    RSA_set_ex_data(param_1,hndidx_rsa,(void *)0x0);
  }
  return 1;
}

