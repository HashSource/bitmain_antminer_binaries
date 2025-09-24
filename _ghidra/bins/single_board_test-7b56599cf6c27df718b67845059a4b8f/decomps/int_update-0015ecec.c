
undefined4 int_update(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  EVP_PKEY_CTX *ctx;
  void *pvVar1;
  
  ctx = (EVP_PKEY_CTX *)EVP_MD_CTX_pkey_ctx();
  pvVar1 = EVP_PKEY_CTX_get_data(ctx);
  SipHash_Update((int)pvVar1 + 0x10,param_2,param_3);
  return 1;
}

