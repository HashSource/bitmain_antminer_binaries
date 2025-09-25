
undefined4 hmac_signctx_init(int param_1,EVP_MD_CTX *param_2)

{
  ulong flags;
  HMAC_CTX *ctx;
  
  ctx = *(HMAC_CTX **)(*(int *)(param_1 + 0x14) + 0x14);
  flags = EVP_MD_CTX_test_flags(param_2,-0x101);
  HMAC_CTX_set_flags(ctx,flags);
  EVP_MD_CTX_set_flags(param_2,0x100);
  EVP_MD_CTX_set_update_fn(param_2,0x130299);
  return 1;
}

