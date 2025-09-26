
void pkey_poly1305_cleanup(EVP_PKEY_CTX *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    CRYPTO_clear_free(puVar1[2],*puVar1,"crypto/poly1305/poly1305_pmeth.c",0x2f);
    CRYPTO_clear_free(puVar1,0x100,"crypto/poly1305/poly1305_pmeth.c",0x30);
    EVP_PKEY_CTX_set_data(param_1,(void *)0x0);
    return;
  }
  return;
}

