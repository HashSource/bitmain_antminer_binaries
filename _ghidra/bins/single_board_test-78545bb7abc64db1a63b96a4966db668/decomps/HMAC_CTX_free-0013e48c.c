
void HMAC_CTX_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    EVP_MD_CTX_reset(param_1[2]);
    EVP_MD_CTX_reset(param_1[3]);
    EVP_MD_CTX_reset(param_1[1]);
    *param_1 = 0;
    EVP_MD_CTX_free(param_1[2]);
    EVP_MD_CTX_free(param_1[3]);
    EVP_MD_CTX_free(param_1[1]);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

