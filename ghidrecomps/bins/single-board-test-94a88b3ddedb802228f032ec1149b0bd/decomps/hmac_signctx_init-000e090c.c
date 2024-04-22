
undefined4 hmac_signctx_init(int param_1,EVP_MD_CTX *param_2)

{
  HMAC_CTX_set_flags((HMAC_CTX *)(*(int *)(param_1 + 0x14) + 0x14),param_2->flags & 0xfffffeff);
  EVP_MD_CTX_set_flags(param_2,0x100);
  param_2->update = int_update + 1;
  return 1;
}

