
undefined4 cmac_signctx_init(undefined4 param_1,EVP_MD_CTX *param_2)

{
  EVP_MD_CTX_set_flags(param_2,0x100);
  param_2->update = int_update + 1;
  return 1;
}

