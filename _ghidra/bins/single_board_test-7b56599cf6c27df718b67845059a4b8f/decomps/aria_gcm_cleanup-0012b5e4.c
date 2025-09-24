
undefined4 aria_gcm_cleanup(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  iVar3 = *(int *)(iVar1 + 0x2c8);
  iVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
  if (iVar3 != iVar2) {
    CRYPTO_free(*(void **)(iVar1 + 0x2c8));
  }
  return 1;
}

