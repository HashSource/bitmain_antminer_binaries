
undefined4 aes_gcm_cleanup(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  if (iVar1 == 0) {
    return 0;
  }
  OPENSSL_cleanse((void *)(iVar1 + 0x100),0x1a8);
  iVar3 = *(int *)(iVar1 + 0x2a8);
  iVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
  if (iVar3 != iVar2) {
    CRYPTO_free(*(void **)(iVar1 + 0x2a8));
    return 1;
  }
  return 1;
}

