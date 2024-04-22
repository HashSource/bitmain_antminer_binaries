
int ENGINE_load_ssl_client_cert
              (ENGINE *e,SSL *s,stack_st_X509_NAME *ca_dn,X509 **pcert,EVP_PKEY **ppkey,
              stack_st_X509 **pother,UI_METHOD *ui_method,void *callback_data)

{
  int iVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xc2,0x43,DAT_000a738c,0xa8);
    iVar1 = 0;
  }
  else {
    CRYPTO_lock(9,0x1e,DAT_000a738c,0xab);
    if (*(int *)(e + 0x5c) == 0) {
      CRYPTO_lock(10,0x1e,DAT_000a738c,0xad);
      ERR_put_error(0x26,0xc2,0x75,DAT_000a738c,0xaf);
      iVar1 = 0;
    }
    else {
      CRYPTO_lock(10,0x1e,DAT_000a738c,0xb2);
      if (*(code **)(e + 0x4c) == (code *)0x0) {
        ERR_put_error(0x26,0xc2,0x7d,DAT_000a738c,0xb5);
        iVar1 = 0;
      }
      else {
        iVar1 = (**(code **)(e + 0x4c))(e,s,ca_dn,pcert,ppkey,pother,ui_method,callback_data);
      }
    }
  }
  return iVar1;
}

