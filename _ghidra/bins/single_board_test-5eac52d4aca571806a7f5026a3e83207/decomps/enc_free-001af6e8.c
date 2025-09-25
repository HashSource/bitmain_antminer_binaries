
undefined4 enc_free(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = BIO_get_data();
  if (iVar1 != 0) {
    EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(iVar1 + 0x14));
    CRYPTO_clear_free(iVar1,0x1140,"crypto/evp/bio_enc.c",99,param_4);
    BIO_set_data(param_1,0);
    BIO_set_init(param_1,0);
    return 1;
  }
  return 0;
}

