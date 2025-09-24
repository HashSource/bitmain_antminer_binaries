
EVP_PKEY * ENGINE_load_public_key(ENGINE *e,char *key_id,UI_METHOD *ui_method,void *callback_data)

{
  EVP_PKEY *pEVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x97,0x43,"crypto/engine/eng_pkey.c",0x5b);
    pEVar1 = (EVP_PKEY *)0x0;
  }
  else {
    CRYPTO_THREAD_write_lock(global_engine_lock);
    if (*(int *)(e + 0x54) == 0) {
      CRYPTO_THREAD_unlock(global_engine_lock);
      ERR_put_error(0x26,0x97,0x75,"crypto/engine/eng_pkey.c",0x61);
      pEVar1 = (EVP_PKEY *)0x0;
    }
    else {
      CRYPTO_THREAD_unlock(global_engine_lock);
      if (*(code **)(e + 0x40) == (code *)0x0) {
        ERR_put_error(0x26,0x97,0x7d,"crypto/engine/eng_pkey.c",0x66);
        pEVar1 = (EVP_PKEY *)0x0;
      }
      else {
        pEVar1 = (EVP_PKEY *)(**(code **)(e + 0x40))(e,key_id,ui_method,callback_data);
        if (pEVar1 == (EVP_PKEY *)0x0) {
          ERR_put_error(0x26,0x97,0x81,"crypto/engine/eng_pkey.c",0x6c);
        }
      }
    }
  }
  return pEVar1;
}

