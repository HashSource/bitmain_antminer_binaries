
undefined4 CMS_RecipientInfo_kari_set0_pkey(int param_1,EVP_PKEY *param_2)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (*(EVP_PKEY_CTX **)(iVar2 + 0x14) != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar2 + 0x14));
    *(undefined4 *)(iVar2 + 0x14) = 0;
  }
  if (param_2 == (EVP_PKEY *)0x0) {
    return 1;
  }
  ctx = EVP_PKEY_CTX_new(param_2,(ENGINE *)0x0);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    return 0;
  }
  iVar1 = EVP_PKEY_derive_init(ctx);
  if (iVar1 == 0) {
    EVP_PKEY_CTX_free(ctx);
    return 0;
  }
  *(EVP_PKEY_CTX **)(iVar2 + 0x14) = ctx;
  return 1;
}

