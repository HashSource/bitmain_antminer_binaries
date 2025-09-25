
EVP_PKEY * ssl_generate_pkey(EVP_PKEY *param_1)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  EVP_PKEY *local_14 [2];
  
  local_14[0] = (EVP_PKEY *)0x0;
  if (param_1 == (EVP_PKEY *)0x0) {
    local_14[0] = (EVP_PKEY *)0x0;
  }
  else {
    ctx = EVP_PKEY_CTX_new(param_1,(ENGINE *)0x0);
    if (((ctx != (EVP_PKEY_CTX *)0x0) && (iVar1 = EVP_PKEY_keygen_init(ctx), 0 < iVar1)) &&
       (iVar1 = EVP_PKEY_keygen(ctx,local_14), iVar1 < 1)) {
      EVP_PKEY_free(local_14[0]);
      local_14[0] = (EVP_PKEY *)0x0;
    }
    EVP_PKEY_CTX_free(ctx);
  }
  return local_14[0];
}

