
EVP_PKEY * ENGINE_load_private_key(ENGINE *e,char *key_id,UI_METHOD *ui_method,void *callback_data)

{
  EVP_PKEY *pEVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x96,0x43,DAT_000a7254,0x6a);
    pEVar1 = (EVP_PKEY *)0x0;
  }
  else {
    CRYPTO_lock(9,0x1e,DAT_000a7254,0x6d);
    if (*(int *)(e + 0x5c) == 0) {
      CRYPTO_lock(10,0x1e,DAT_000a7254,0x6f);
      ERR_put_error(0x26,0x96,0x75,DAT_000a7254,0x70);
      pEVar1 = (EVP_PKEY *)0x0;
    }
    else {
      CRYPTO_lock(10,0x1e,DAT_000a7254,0x73);
      if (*(code **)(e + 0x44) == (code *)0x0) {
        ERR_put_error(0x26,0x96,0x7d,DAT_000a7254,0x76);
        pEVar1 = (EVP_PKEY *)0x0;
      }
      else {
        pEVar1 = (EVP_PKEY *)(**(code **)(e + 0x44))(e,key_id,ui_method,callback_data);
        if (pEVar1 == (EVP_PKEY *)0x0) {
          ERR_put_error(0x26,0x96,0x80,DAT_000a7254,0x7c);
        }
      }
    }
  }
  return pEVar1;
}

