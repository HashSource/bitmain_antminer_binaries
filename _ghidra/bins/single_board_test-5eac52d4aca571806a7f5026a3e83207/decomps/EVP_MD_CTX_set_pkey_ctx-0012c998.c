
void EVP_MD_CTX_set_pkey_ctx(EVP_MD_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  int iVar1;
  
  iVar1 = EVP_MD_CTX_test_flags(param_1,0x400);
  if (iVar1 == 0) {
    EVP_PKEY_CTX_free(param_1->pctx);
    param_1->pctx = param_2;
  }
  else {
    param_1->pctx = param_2;
  }
  if (param_2 != (EVP_PKEY_CTX *)0x0) {
    EVP_MD_CTX_set_flags(param_1,0x400);
    return;
  }
  EVP_MD_CTX_clear_flags(param_1,0x400);
  return;
}

