
void EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx)

{
  code *pcVar1;
  
  if (ctx != (EVP_PKEY_CTX *)0x0) {
    if ((*(int *)ctx != 0) && (pcVar1 = *(code **)(*(int *)ctx + 0x10), pcVar1 != (code *)0x0)) {
      (*pcVar1)();
    }
    EVP_PKEY_free(*(EVP_PKEY **)(ctx + 8));
    EVP_PKEY_free(*(EVP_PKEY **)(ctx + 0xc));
    ENGINE_finish(*(ENGINE **)(ctx + 4));
    CRYPTO_free(ctx);
    return;
  }
  return;
}

