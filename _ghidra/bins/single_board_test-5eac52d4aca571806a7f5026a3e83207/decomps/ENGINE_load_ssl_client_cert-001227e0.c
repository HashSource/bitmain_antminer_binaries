
int ENGINE_load_ssl_client_cert
              (ENGINE *e,SSL *s,stack_st_X509_NAME *ca_dn,X509 **pcert,EVP_PKEY **ppkey,
              stack_st_X509 **pother,UI_METHOD *ui_method,void *callback_data)

{
  int iVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xc2,0x43,"crypto/engine/eng_pkey.c",0x7a);
    return 0;
  }
  CRYPTO_THREAD_write_lock(global_engine_lock);
  if (*(int *)(e + 0x54) == 0) {
    CRYPTO_THREAD_unlock(global_engine_lock);
    ERR_put_error(0x26,0xc2,0x75,"crypto/engine/eng_pkey.c",0x81);
  }
  else {
    CRYPTO_THREAD_unlock(global_engine_lock);
    if (*(code **)(e + 0x44) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00122836. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(e + 0x44))(e,s,ca_dn,pcert);
      return iVar1;
    }
    ERR_put_error(0x26,0xc2,0x7d,"crypto/engine/eng_pkey.c",0x87);
  }
  return 0;
}

