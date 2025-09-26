
void cmac_key_free(EVP_PKEY *param_1)

{
  CMAC_CTX *ctx;
  
  ctx = (CMAC_CTX *)EVP_PKEY_get0(param_1);
  CMAC_CTX_free(ctx);
  return;
}

