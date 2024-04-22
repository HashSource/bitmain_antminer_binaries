
EVP_PKEY * ENGINE_load_public_key(ENGINE *e,char *key_id,UI_METHOD *ui_method,void *callback_data)

{
  EVP_PKEY *pEVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x97,0x43,DAT_000a72f4,0x89);
    pEVar1 = (EVP_PKEY *)0x0;
  }
  else {
    CRYPTO_lock(9,0x1e,DAT_000a72f4,0x8c);
    if (*(int *)(e + 0x5c) == 0) {
      CRYPTO_lock(10,0x1e,DAT_000a72f4,0x8e);
      ERR_put_error(0x26,0x97,0x75,DAT_000a72f4,0x8f);
      pEVar1 = (EVP_PKEY *)0x0;
    }
    else {
      CRYPTO_lock(10,0x1e,DAT_000a72f4,0x92);
      if (*(code **)(e + 0x48) == (code *)0x0) {
        ERR_put_error(0x26,0x97,0x7d,DAT_000a72f4,0x94);
        pEVar1 = (EVP_PKEY *)0x0;
      }
      else {
        pEVar1 = (EVP_PKEY *)(**(code **)(e + 0x48))(e,key_id,ui_method,callback_data);
        if (pEVar1 == (EVP_PKEY *)0x0) {
          ERR_put_error(0x26,0x97,0x81,DAT_000a72f4,0x9a);
        }
      }
    }
  }
  return pEVar1;
}

